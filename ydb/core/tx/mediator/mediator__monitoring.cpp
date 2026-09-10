#include "mediator_impl.h"

#include <ydb/core/base/mon_auth.h>

#include <library/cpp/monlib/service/pages/mon_page.h>
#include <library/cpp/monlib/service/pages/templates.h>

#include <util/stream/format.h>
#include <util/string/cast.h>
#include <util/string/strip.h>

#include <optional>

#define YDB_LOG_THIS_FILE_COMPONENT NKikimrServices::TX_MEDIATOR

namespace NKikimr {
namespace NTxMediator {

using NTabletFlatExecutor::TTransactionBase;
using NTabletFlatExecutor::TTransactionContext;

namespace {

    constexpr TStringBuf BallastSizeParam = "ballastSize";

    // Everything the page shows is read-only, only setting the ballast mutates
    // the tablet and thus has to come through the admin-only secure subpath.
    bool IsPublicMediatorDevUiRequest(const TCgiParameters &cgi) {
        return !cgi.Has(BallastSizeParam);
    }

    TString BuildBallastFormAction(TStringBuf pathInfo, ui64 tabletId) {
        if (!HasTabletDevUiSecureSubtree(AppData(), TTabletTypes::Mediator) || IsTabletDevUiSecurePath(pathInfo)) {
            return "?";
        }
        return TStringBuilder() << TABLET_DEV_UI_SECURE_MON_RELATIVE_PATH << "?TabletID=" << tabletId;
    }

    // A plain byte count, optionally with a binary size suffix, e.g. "512M".
    std::optional<ui64> ParseBallastSize(TStringBuf value) {
        value = StripString(value);
        if (value.empty()) {
            return std::nullopt;
        }

        ui64 multiplier = 1;
        switch (value.back()) {
            case 'T': case 't': multiplier = ui64(1) << 40; break;
            case 'G': case 'g': multiplier = ui64(1) << 30; break;
            case 'M': case 'm': multiplier = ui64(1) << 20; break;
            case 'K': case 'k': multiplier = ui64(1) << 10; break;
            default: break;
        }
        if (multiplier != 1) {
            value.Chop(1);
        }

        ui64 size = 0;
        if (!TryFromString(value, size)) {
            return std::nullopt;
        }
        if (size > Max<ui64>() / multiplier) {
            return std::nullopt;
        }

        return size * multiplier;
    }

    void SendHtml(const TActorId &to, TStringBuf body, const TActorContext &ctx) {
        TStringStream str;
        HTML(str) {
            DIV_CLASS("row") {
                DIV_CLASS("col-md-12") { str << body; }
            }
        }
        ctx.Send(to, new NMon::TEvRemoteHttpInfoRes(str.Str()));
    }

}

struct TTxMediator::TTxSetBallast : public TTransactionBase<TTxMediator> {
    const ui64 Size;
    const TActorId ReplyTo;

    TTxSetBallast(TSelf *mediator, ui64 size, const TActorId &replyTo)
        : TBase(mediator)
        , Size(size)
        , ReplyTo(replyTo)
    {}

    TTxType GetTxType() const override { return TXTYPE_SET_BALLAST; }

    bool Execute(TTransactionContext &txc, const TActorContext&) override {
        NIceDb::TNiceDb db(txc.DB);
        db.Table<Schema::State>().Key(Schema::State::BallastSize).Update(
            NIceDb::TUpdate<Schema::State::StateValue>(Size));
        return true;
    }

    void Complete(const TActorContext &ctx) override {
        YDB_LOG_NOTICE_CTX(ctx, "TTxSetBallast Complete",
            {"tablet", Self->TabletID()},
            {"size", Size});

        // Only allocate once the new size is durable, so that a restart cannot
        // resurrect a ballast the operator has already dropped.
        Self->SetBallastSize(Size, ctx);

        TStringStream str;
        str << "Ballast set to " << Size << " bytes (" << HumanReadableSize(Size, SF_BYTES) << ")";
        if (Size != Self->Ballast.GetSize()) {
            str << ", but the memory could not be reserved";
        }
        SendHtml(ReplyTo, str.Str(), ctx);
    }
};

ITransaction* TTxMediator::CreateTxSetBallast(ui64 size, const TActorId &replyTo) {
    return new TTxSetBallast(this, size, replyTo);
}

void TTxMediator::RenderAppPage(const NMon::TEvRemoteHttpInfo::TPtr &ev, const TActorContext &ctx) {
    const TString formAction = BuildBallastFormAction(ev->Get()->PathInfo(), TabletID());

    TStringStream str;
    HTML(str) {
        DIV_CLASS("row") {
            DIV_CLASS("col-md-12") {
                H3_CLASS("") { str << "Mediator " << TabletID(); }
                TABLE_CLASS("table table-condensed") {
                    TABLEBODY() {
                        TABLER() {
                            TABLED() { str << "CompleteStep"; }
                            TABLED() { str << VolatileState.CompleteStep; }
                        }
                        TABLER() {
                            TABLED() { str << "LatestKnownStep"; }
                            TABLED() { str << VolatileState.LatestKnownStep; }
                        }
                        TABLER() {
                            TABLED() { str << "Ballast"; }
                            TABLED() {
                                str << Ballast.GetSize() << " bytes ("
                                    << HumanReadableSize(Ballast.GetSize(), SF_BYTES) << ")";
                                if (!Ballast.IsFullyTouched()) {
                                    str << ", " << HumanReadableSize(Ballast.GetTouchedSize(), SF_BYTES)
                                        << " committed so far";
                                }
                            }
                        }
                    }
                }
            }
        }

        DIV_CLASS("row") {
            DIV_CLASS("col-md-12") {
                // Explicit action: without EnableTabletDevUiSecurePath everything stays on
                // /app, with it the read-only page stays on /app and setting the ballast
                // moves to /app/secure.
                str << "<form class=\"form-horizontal\" action=\"" << formAction << "\" method=\"get\">";
                DIV_CLASS("control-group") {
                    LABEL_CLASS_FOR("control-label", "ballastSize") { str << "Ballast size"; }
                    DIV_CLASS("controls") {
                        str << "<input type='hidden' name='TabletID' value='" << TabletID() << "'/>";
                        str << "<input type='text' id='ballastSize' name='" << BallastSizeParam
                            << "' value='" << Ballast.GetSize() << "'/>";
                        str << "<button type='submit' class='btn btn-primary btn-sm'>Set</button>";
                        str << "<span class='help-inline'>bytes, or with a K/M/G/T suffix</span>";
                    }
                }
                str << "</form>";
            }
        }
    }

    ctx.Send(ev->Sender, new NMon::TEvRemoteHttpInfoRes(str.Str()));
}

bool TTxMediator::OnRenderAppHtmlPage(NMon::TEvRemoteHttpInfo::TPtr ev, const TActorContext &ctx) {
    if (!Executor() || !Executor()->GetStats().IsActive) {
        if (ev) {
            SendHtml(ev->Sender, "Tablet is not active", ctx);
        }
        return false;
    }

    if (!ev) {
        return true;
    }

    const TCgiParameters cgi = ev->Get()->Cgi();

    if (!IsTabletDevUiAccessAllowed(
            AppData(ctx),
            ev->Get()->PathInfo(),
            ev->Get()->GetUserToken(),
            IsPublicMediatorDevUiRequest(cgi)))
    {
        ctx.Send(ev->Sender, new NMon::TEvRemoteBinaryInfoRes(NMonitoring::HTTPFORBIDDEN));
        return true;
    }

    if (cgi.Has(BallastSizeParam)) {
        const std::optional<ui64> size = ParseBallastSize(cgi.Get(BallastSizeParam));
        if (!size) {
            SendHtml(ev->Sender, "Bad ballast size, expected a byte count with an optional K/M/G/T suffix", ctx);
            return true;
        }

        Execute(CreateTxSetBallast(*size, ev->Sender), ctx);
        return true;
    }

    RenderAppPage(ev, ctx);
    return true;
}

}
}

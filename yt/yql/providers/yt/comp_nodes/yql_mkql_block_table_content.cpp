#include "yql_mkql_block_table_content.h"
#include "yql_mkql_file_list.h"

#include <yql/essentials/minikql/computation/mkql_computation_node_impl.h>
#include <yql/essentials/minikql/mkql_node_cast.h>
#include <yql/essentials/minikql/defs.h>

#include <yql/essentials/public/udf/udf_value.h>

#include <util/generic/vector.h>
#include <util/generic/string.h>
#include <util/generic/size_literals.h>

namespace NYql {

using namespace NKikimr;
using namespace NKikimr::NMiniKQL;

class TYtBlockTableContentWrapper : public TMutableComputationNode<TYtBlockTableContentWrapper> {
    typedef TMutableComputationNode<TYtBlockTableContentWrapper> TBaseComputation;
public:
    TYtBlockTableContentWrapper(TComputationMutables& mutables, NCommon::TCodecContext& codecCtx,
        TVector<TString>&& files, const TString& inputSpec, TType* listType, bool decompress, std::optional<ui64> expectedRowCount)
        : TBaseComputation(mutables)
        , Files_(std::move(files))
        , Decompress_(decompress)
        , ExpectedRowCount_(std::move(expectedRowCount))
    {
        Spec_.SetUseBlockInput();
        Spec_.SetInputBlockRepresentation(TMkqlIOSpecs::EBlockRepresentation::BlockStruct);
        Spec_.SetIsTableContent();
        Spec_.Init(codecCtx, inputSpec, {}, {}, AS_TYPE(TListType, listType)->GetItemType(), {}, TString());
    }

    NUdf::TUnboxedValuePod DoCalculate(TComputationContext& ctx) const {
        return ctx.HolderFactory.Create<TFileListValue>(Spec_, ctx.HolderFactory, Files_, Decompress_, 4, 1_MB, ExpectedRowCount_);
    }

private:
    void RegisterDependencies() const final {}

    TMkqlIOSpecs Spec_;
    TVector<TString> Files_;
    const bool Decompress_;
    const std::optional<ui64> ExpectedRowCount_;
};

IComputationNode* WrapYtBlockTableContent(NCommon::TCodecContext& codecCtx,
    TComputationMutables& mutables, TCallable& callable, TStringBuf pathPrefix)
{
    MKQL_ENSURE(callable.GetInputsCount() == 5, "Expected 5 arguments");
    TString uniqueId(AS_VALUE(TDataLiteral, callable.GetInput(0))->AsValue().AsStringRef());
    const ui32 tablesCount = AS_VALUE(TDataLiteral, callable.GetInput(1))->AsValue().Get<ui32>();
    TString inputSpec(AS_VALUE(TDataLiteral, callable.GetInput(2))->AsValue().AsStringRef());
    const bool decompress = AS_VALUE(TDataLiteral, callable.GetInput(3))->AsValue().Get<bool>();

    std::optional<ui64> length;
    TTupleLiteral* lengthTuple = AS_VALUE(TTupleLiteral, callable.GetInput(4));
    if (lengthTuple->GetValuesCount() > 0) {
        MKQL_ENSURE(lengthTuple->GetValuesCount() == 1, "Expect 1 element in the length tuple");
        length = AS_VALUE(TDataLiteral, lengthTuple->GetValue(0))->AsValue().Get<ui64>();
    }

    TVector<TString> files;
    for (ui32 index = 0; index < tablesCount; ++index) {
        files.push_back(TStringBuilder() << pathPrefix << uniqueId << '_' << index);
    }

    return new TYtBlockTableContentWrapper(mutables, codecCtx, std::move(files), inputSpec,
        callable.GetType()->GetReturnType(), decompress, length);
}

} // NYql

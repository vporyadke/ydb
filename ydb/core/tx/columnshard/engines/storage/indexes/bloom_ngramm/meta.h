#pragma once
#include <ydb/core/tx/columnshard/engines/storage/indexes/portions/meta.h>
namespace NKikimr::NOlap::NIndexes::NBloomNGramm {

class TIndexMeta: public TIndexByColumns {
public:
    static TString GetClassNameStatic() {
        return "BLOOM_NGRAMM_FILTER";
    }
private:
    using TBase = TIndexByColumns;
    std::shared_ptr<arrow::Schema> ResultSchema;
    ui32 NGrammSize = 3;
    ui32 FilterSizeBytes = 512;
    ui32 RecordsCount = 10000;
    ui32 HashesCount = 2;
    static inline auto Registrator = TFactory::TRegistrator<TIndexMeta>(GetClassNameStatic());
    void Initialize() {
        AFL_VERIFY(!ResultSchema);
        std::vector<std::shared_ptr<arrow::Field>> fields = {std::make_shared<arrow::Field>("", arrow::boolean())};
        ResultSchema = std::make_shared<arrow::Schema>(fields);
        AFL_VERIFY(TConstants::CheckHashesCount(HashesCount));
        AFL_VERIFY(TConstants::CheckFilterSizeBytes(FilterSizeBytes));
        AFL_VERIFY(TConstants::CheckNGrammSize(NGrammSize));
        AFL_VERIFY(TConstants::CheckRecordsCount(RecordsCount));
    }

protected:
    virtual TConclusionStatus DoCheckModificationCompatibility(const IIndexMeta& newMeta) const override {
        const auto* bMeta = dynamic_cast<const TIndexMeta*>(&newMeta);
        if (!bMeta) {
            return TConclusionStatus::Fail(
                "cannot read meta as appropriate class: " + GetClassName() + ". Meta said that class name is " + newMeta.GetClassName());
        }
        if (HashesCount != bMeta->HashesCount) {
            return TConclusionStatus::Fail("cannot modify hashes count");
        }
        if (NGrammSize != bMeta->NGrammSize) {
            return TConclusionStatus::Fail("cannot modify ngramm size");
        }
        return TBase::CheckSameColumnsForModification(newMeta);
    }
    virtual void DoFillIndexCheckers(const std::shared_ptr<NRequest::TDataForIndexesCheckers>& info, const NSchemeShard::TOlapSchema& schema) const override;

    virtual TString DoBuildIndexImpl(TChunkedBatchReader& reader, const ui32 recordsCount) const override;

    virtual bool DoDeserializeFromProto(const NKikimrSchemeOp::TOlapIndexDescription& proto) override {
        AFL_VERIFY(TBase::DoDeserializeFromProto(proto));
        AFL_VERIFY(proto.HasBloomNGrammFilter());
        auto& bFilter = proto.GetBloomNGrammFilter();
        if (bFilter.HasRecordsCount()) {
            RecordsCount = bFilter.GetRecordsCount();
            if (!TConstants::CheckRecordsCount(RecordsCount)) {
                return false;
            }
        }
        if (!MutableDataExtractor().DeserializeFromProto(bFilter.GetDataExtractor())) {
            return false;
        }
        HashesCount = bFilter.GetHashesCount();
        if (!TConstants::CheckHashesCount(HashesCount)) {
            return false;
        }
        NGrammSize = bFilter.GetNGrammSize();
        if (!TConstants::CheckNGrammSize(NGrammSize)) {
            return false;
        }
        FilterSizeBytes = bFilter.GetFilterSizeBytes();
        if (!TConstants::CheckFilterSizeBytes(FilterSizeBytes)) {
            return false;
        }
        if (!bFilter.HasColumnId() || !bFilter.GetColumnId()) {
            return false;
        }
        AddColumnId(bFilter.GetColumnId());
        Initialize();
        return true;
    }
    virtual void DoSerializeToProto(NKikimrSchemeOp::TOlapIndexDescription& proto) const override {
        auto* filterProto = proto.MutableBloomNGrammFilter();
        AFL_VERIFY(TConstants::CheckNGrammSize(NGrammSize));
        AFL_VERIFY(TConstants::CheckFilterSizeBytes(FilterSizeBytes));
        AFL_VERIFY(TConstants::CheckHashesCount(HashesCount));
        AFL_VERIFY(TConstants::CheckRecordsCount(RecordsCount));
        filterProto->SetRecordsCount(RecordsCount);
        filterProto->SetNGrammSize(NGrammSize);
        filterProto->SetFilterSizeBytes(FilterSizeBytes);
        filterProto->SetHashesCount(HashesCount);
        filterProto->SetColumnId(GetColumnId());
        *filterProto->MutableDataExtractor() = GetDataExtractor().SerializeToProto();
    }

public:
    TIndexMeta() = default;
    TIndexMeta(const ui32 indexId, const TString& indexName, const TString& storageId, const ui32 columnId, const TReadDataExtractorContainer& dataExtractor, const ui32 hashesCount,
        const ui32 filterSizeBytes, const ui32 nGrammSize, const ui32 recordsCount)
        : TBase(indexId, indexName, columnId, storageId, dataExtractor)
        , NGrammSize(nGrammSize)
        , FilterSizeBytes(filterSizeBytes)
        , RecordsCount(recordsCount)
        , HashesCount(hashesCount)
    {
        Initialize();
    }

    virtual TString GetClassName() const override {
        return GetClassNameStatic();
    }
};

}   // namespace NKikimr::NOlap::NIndexes

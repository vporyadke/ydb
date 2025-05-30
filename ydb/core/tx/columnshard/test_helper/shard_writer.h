#pragma once
#include <ydb/core/tx/data_events/events.h>
#include <ydb/core/testlib/basics/runtime.h>
#include <ydb/core/tx/columnshard/test_helper/columnshard_ut_common.h>

#include <ydb/library/accessor/accessor.h>

#include <contrib/libs/apache/arrow/cpp/src/arrow/record_batch.h>

namespace NKikimr::NTxUT {

class TShardWriter {
private:
    TTestBasicRuntime& Runtime;
    const ui64 TabletId;
    const ui64 PathId;
    const ui64 LockId;
    YDB_ACCESSOR(ui64, SchemaVersion, 1);
    YDB_ACCESSOR(ui64, OwnerId, 0);
    YDB_ACCESSOR(ui64, LockNodeId, 1);
    const TActorId Sender;

private:
    [[nodiscard]] NKikimrDataEvents::TEvWriteResult StartCommitImpl(const ui64 txId);

public:
    TShardWriter(TTestBasicRuntime& runtime, const ui64 tabletId, const ui64 pathId, const ui64 lockId)
        : Runtime(runtime)
        , TabletId(tabletId)
        , PathId(pathId)
        , LockId(lockId)
        , Sender(Runtime.AllocateEdgeActor())
    {
    }

    const TActorId& GetSender() const {
        return Sender;
    }
    void StartCommitFail(const ui64 txId);
    [[nodiscard]] NTxUT::TPlanStep StartCommit(const ui64 txId);
    [[nodiscard]] NKikimrDataEvents::TEvWriteResult::EStatus Abort(const ui64 txId);

    [[nodiscard]] NKikimrDataEvents::TEvWriteResult::EStatus Write(
        const std::shared_ptr<arrow::RecordBatch>& batch, const std::vector<ui32>& columnIds, const ui64 txId);
};

}   // namespace NKikimr::NTxUT

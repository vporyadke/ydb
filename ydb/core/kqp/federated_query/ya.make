LIBRARY()

SRCS(
    kqp_federated_query_actors.cpp
    kqp_federated_query_helpers.cpp
)

PEERDIR(
    ydb/core/base
    ydb/core/fq/libs/db_id_async_resolver_impl
    ydb/core/fq/libs/grpc
    ydb/library/db_pool/protos
    ydb/library/yql/providers/common/http_gateway
    ydb/library/yql/providers/generic/connector/libcpp
    ydb/library/yql/providers/solomon/gateway
    yt/yql/providers/yt/comp_nodes/dq/llvm14
    yt/yql/providers/yt/gateway/native
    yt/yql/providers/yt/lib/yt_download
)

YQL_LAST_ABI_VERSION()

END()

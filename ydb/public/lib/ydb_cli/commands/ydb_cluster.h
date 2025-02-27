#pragma once

#include "ydb_command.h"
#include "ydb_common.h"

#include <util/generic/set.h>

namespace NYdb::NConsoleClient::NCluster {

class TCommandCluster : public TClientCommandTree {
public:
    TCommandCluster();
};

class TCommandClusterBootstrap : public TYdbCommand {
    TString SelfAssemblyUUID;

public:
    TCommandClusterBootstrap();
    void Config(TConfig& config) override;
    void Parse(TConfig& config) override;
    int Run(TConfig& config) override;
};

class TCommandClusterDump : public TYdbCommand {
public:
    TCommandClusterDump();
    void Config(TConfig& config) override;
    void Parse(TConfig& config) override;
    int Run(TConfig& config) override;

private:
    TString FilePath;
};

} // namespace NYdb::NConsoleClient::NCluster

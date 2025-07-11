# -*- coding: utf-8 -*-
from ydb.tests.stress.reconfig_state_storage_workload.workload import WorkloadRunner
from reconfig_state_storage_workload_test import ReconfigStateStorageWorkloadTest


class TestReconfigSchemeBoardWorkload(ReconfigStateStorageWorkloadTest):
    def test_scheme_board(self):
        with WorkloadRunner(self.client, self.cluster, 'reconfig_scheme_board_workload', 120, "SchemeBoard") as runner:
            runner.run()

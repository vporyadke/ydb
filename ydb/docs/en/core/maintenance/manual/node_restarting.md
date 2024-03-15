# Safe restart and shutdown of nodes

## Stopping/restarting a YDB process on a node {#restart_process}

To make sure that the process is stoppable, follow these steps.

1. Access the node via SSH.

1. Execute the command

   ```bash
   ydbd cms request restart host {node_id} --user {user} --duration 60 --dry --reason 'some-reason'
   ```

   If the process is stoppable, you'll see `ALLOW`.

1. Stop the process

   ```bash
   sudo service ydbd stop
   ```

1. Restart the process if needed

   ```bash
    sudo service ydbd start
   ```

## Replacing equipment {#replace_hardware}

Before replacing equipment, make sure that the YDB process is [stoppable](#restart_process).
If the replacement is going to take a long time, first move all the VDisks from this node and wait until replication is complete.
After replication is complete, you can safely shut down the node.

## Safe shutdown/restart of dynamic nodes

To make sure that disabling a dynamic node doesn't affect query handling, it is recommended to do the following:

1. Mark the node as inactive. This does not change anything, but ensures no new tablets will be started on the node.
2. Drain the node from tablets.
3. Shut down the node.
4. (Only for restart) After restarting the node, mark it as active again.

Those operations can be performed either manually in [Hive web-viewer](../embedded_monitoring/hive.md) or via GRPC API.

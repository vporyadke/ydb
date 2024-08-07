TExecFunc arrow_any_in() { return MakeIndirectExec<true, true>(&any_in); }
TExecFunc arrow_any_out() { return MakeIndirectExec<true, false>(&any_out); }
TExecFunc arrow_anyarray_in() { return MakeIndirectExec<true, false>(&anyarray_in); }
TExecFunc arrow_anyarray_out() { return MakeIndirectExec<true, false>(&anyarray_out); }
TExecFunc arrow_anyarray_recv() { return MakeIndirectExec<true, false>(&anyarray_recv); }
TExecFunc arrow_anyarray_send() { return MakeIndirectExec<true, false>(&anyarray_send); }
TExecFunc arrow_anycompatible_in() { return MakeIndirectExec<true, true>(&anycompatible_in); }
TExecFunc arrow_anycompatible_out() { return MakeIndirectExec<true, false>(&anycompatible_out); }
TExecFunc arrow_anycompatiblearray_in() { return MakeIndirectExec<true, false>(&anycompatiblearray_in); }
TExecFunc arrow_anycompatiblearray_out() { return MakeIndirectExec<true, false>(&anycompatiblearray_out); }
TExecFunc arrow_anycompatiblearray_recv() { return MakeIndirectExec<true, false>(&anycompatiblearray_recv); }
TExecFunc arrow_anycompatiblearray_send() { return MakeIndirectExec<true, false>(&anycompatiblearray_send); }
TExecFunc arrow_anycompatiblemultirange_in() { return MakeIndirectExec<true, false>(&anycompatiblemultirange_in); }
TExecFunc arrow_anycompatiblemultirange_out() { return MakeIndirectExec<true, false>(&anycompatiblemultirange_out); }
TExecFunc arrow_anycompatiblenonarray_in() { return MakeIndirectExec<true, true>(&anycompatiblenonarray_in); }
TExecFunc arrow_anycompatiblenonarray_out() { return MakeIndirectExec<true, false>(&anycompatiblenonarray_out); }
TExecFunc arrow_anycompatiblerange_in() { return MakeIndirectExec<true, false>(&anycompatiblerange_in); }
TExecFunc arrow_anycompatiblerange_out() { return MakeIndirectExec<true, false>(&anycompatiblerange_out); }
TExecFunc arrow_anyelement_in() { return MakeIndirectExec<true, true>(&anyelement_in); }
TExecFunc arrow_anyelement_out() { return MakeIndirectExec<true, false>(&anyelement_out); }
TExecFunc arrow_anyenum_in() { return MakeIndirectExec<true, true>(&anyenum_in); }
TExecFunc arrow_anyenum_out() { return MakeIndirectExec<true, false>(&anyenum_out); }
TExecFunc arrow_anymultirange_in() { return MakeIndirectExec<true, false>(&anymultirange_in); }
TExecFunc arrow_anymultirange_out() { return MakeIndirectExec<true, false>(&anymultirange_out); }
TExecFunc arrow_anynonarray_in() { return MakeIndirectExec<true, true>(&anynonarray_in); }
TExecFunc arrow_anynonarray_out() { return MakeIndirectExec<true, false>(&anynonarray_out); }
TExecFunc arrow_anyrange_in() { return MakeIndirectExec<true, false>(&anyrange_in); }
TExecFunc arrow_anyrange_out() { return MakeIndirectExec<true, false>(&anyrange_out); }
TExecFunc arrow_cideq() { return MakeIndirectExec<true, true>(&cideq); }
TExecFunc arrow_cidin() { return MakeIndirectExec<true, true>(&cidin); }
TExecFunc arrow_cidout() { return MakeIndirectExec<true, false>(&cidout); }
TExecFunc arrow_cidrecv() { return MakeIndirectExec<true, true>(&cidrecv); }
TExecFunc arrow_cidsend() { return MakeIndirectExec<true, false>(&cidsend); }
TExecFunc arrow_cstring_in() { return MakeIndirectExec<true, false>(&cstring_in); }
TExecFunc arrow_cstring_out() { return MakeIndirectExec<true, false>(&cstring_out); }
TExecFunc arrow_cstring_recv() { return MakeIndirectExec<true, false>(&cstring_recv); }
TExecFunc arrow_cstring_send() { return MakeIndirectExec<true, false>(&cstring_send); }
TExecFunc arrow_event_trigger_in() { return MakeIndirectExec<false, true>(&event_trigger_in); }
TExecFunc arrow_event_trigger_out() { return MakeIndirectExec<true, false>(&event_trigger_out); }
TExecFunc arrow_fdw_handler_in() { return MakeIndirectExec<false, true>(&fdw_handler_in); }
TExecFunc arrow_fdw_handler_out() { return MakeIndirectExec<true, false>(&fdw_handler_out); }
TExecFunc arrow_ginhandler() { return MakeIndirectExec<true, true>(&ginhandler); }
TExecFunc arrow_hashmacaddr() { return MakeIndirectExec<true, true>(&hashmacaddr); }
TExecFunc arrow_hashmacaddrextended() { return MakeIndirectExec<true, true>(&hashmacaddrextended); }
TExecFunc arrow_index_am_handler_in() { return MakeIndirectExec<false, true>(&index_am_handler_in); }
TExecFunc arrow_index_am_handler_out() { return MakeIndirectExec<true, false>(&index_am_handler_out); }
TExecFunc arrow_internal_in() { return MakeIndirectExec<false, true>(&internal_in); }
TExecFunc arrow_internal_out() { return MakeIndirectExec<true, false>(&internal_out); }
TExecFunc arrow_language_handler_in() { return MakeIndirectExec<false, true>(&language_handler_in); }
TExecFunc arrow_language_handler_out() { return MakeIndirectExec<true, false>(&language_handler_out); }
TExecFunc arrow_macaddr_and() { return MakeIndirectExec<true, false>(&macaddr_and); }
TExecFunc arrow_macaddr_cmp() { return MakeIndirectExec<true, true>(&macaddr_cmp); }
TExecFunc arrow_macaddr_eq() { return MakeIndirectExec<true, true>(&macaddr_eq); }
TExecFunc arrow_macaddr_ge() { return MakeIndirectExec<true, true>(&macaddr_ge); }
TExecFunc arrow_macaddr_gt() { return MakeIndirectExec<true, true>(&macaddr_gt); }
TExecFunc arrow_macaddr_in() { return MakeIndirectExec<true, false>(&macaddr_in); }
TExecFunc arrow_macaddr_le() { return MakeIndirectExec<true, true>(&macaddr_le); }
TExecFunc arrow_macaddr_lt() { return MakeIndirectExec<true, true>(&macaddr_lt); }
TExecFunc arrow_macaddr_ne() { return MakeIndirectExec<true, true>(&macaddr_ne); }
TExecFunc arrow_macaddr_not() { return MakeIndirectExec<true, false>(&macaddr_not); }
TExecFunc arrow_macaddr_or() { return MakeIndirectExec<true, false>(&macaddr_or); }
TExecFunc arrow_macaddr_out() { return MakeIndirectExec<true, false>(&macaddr_out); }
TExecFunc arrow_macaddr_recv() { return MakeIndirectExec<true, false>(&macaddr_recv); }
TExecFunc arrow_macaddr_send() { return MakeIndirectExec<true, false>(&macaddr_send); }
TExecFunc arrow_macaddr_sortsupport() { return MakeIndirectExec<true, true>(&macaddr_sortsupport); }
TExecFunc arrow_macaddr_trunc() { return MakeIndirectExec<true, false>(&macaddr_trunc); }
TExecFunc arrow_mxid_age() { return MakeIndirectExec<true, true>(&mxid_age); }
TExecFunc arrow_pg_ddl_command_in() { return MakeIndirectExec<true, true>(&pg_ddl_command_in); }
TExecFunc arrow_pg_ddl_command_out() { return MakeIndirectExec<true, false>(&pg_ddl_command_out); }
TExecFunc arrow_pg_ddl_command_recv() { return MakeIndirectExec<true, true>(&pg_ddl_command_recv); }
TExecFunc arrow_pg_ddl_command_send() { return MakeIndirectExec<true, false>(&pg_ddl_command_send); }
TExecFunc arrow_pg_node_tree_in() { return MakeIndirectExec<true, false>(&pg_node_tree_in); }
TExecFunc arrow_pg_node_tree_out() { return MakeIndirectExec<true, false>(&pg_node_tree_out); }
TExecFunc arrow_pg_node_tree_recv() { return MakeIndirectExec<true, false>(&pg_node_tree_recv); }
TExecFunc arrow_pg_node_tree_send() { return MakeIndirectExec<true, false>(&pg_node_tree_send); }
TExecFunc arrow_shell_in() { return MakeIndirectExec<false, true>(&shell_in); }
TExecFunc arrow_shell_out() { return MakeIndirectExec<true, false>(&shell_out); }
TExecFunc arrow_spg_text_choose() { return MakeIndirectExec<true, true>(&spg_text_choose); }
TExecFunc arrow_spg_text_config() { return MakeIndirectExec<true, true>(&spg_text_config); }
TExecFunc arrow_spg_text_inner_consistent() { return MakeIndirectExec<true, true>(&spg_text_inner_consistent); }
TExecFunc arrow_spg_text_leaf_consistent() { return MakeIndirectExec<true, true>(&spg_text_leaf_consistent); }
TExecFunc arrow_spg_text_picksplit() { return MakeIndirectExec<true, true>(&spg_text_picksplit); }
TExecFunc arrow_table_am_handler_in() { return MakeIndirectExec<false, true>(&table_am_handler_in); }
TExecFunc arrow_table_am_handler_out() { return MakeIndirectExec<true, false>(&table_am_handler_out); }
TExecFunc arrow_trigger_in() { return MakeIndirectExec<false, true>(&trigger_in); }
TExecFunc arrow_trigger_out() { return MakeIndirectExec<true, false>(&trigger_out); }
TExecFunc arrow_tsm_handler_in() { return MakeIndirectExec<false, true>(&tsm_handler_in); }
TExecFunc arrow_tsm_handler_out() { return MakeIndirectExec<true, false>(&tsm_handler_out); }
TExecFunc arrow_tsvectorin() { return MakeIndirectExec<true, false>(&tsvectorin); }
TExecFunc arrow_tsvectorout() { return MakeIndirectExec<true, false>(&tsvectorout); }
TExecFunc arrow_tsvectorrecv() { return MakeIndirectExec<true, false>(&tsvectorrecv); }
TExecFunc arrow_tsvectorsend() { return MakeIndirectExec<true, false>(&tsvectorsend); }
TExecFunc arrow_void_in() { return MakeIndirectExec<true, true>(&void_in); }
TExecFunc arrow_void_out() { return MakeIndirectExec<true, false>(&void_out); }
TExecFunc arrow_void_recv() { return MakeIndirectExec<true, true>(&void_recv); }
TExecFunc arrow_void_send() { return MakeIndirectExec<true, false>(&void_send); }
TExecFunc arrow_xid8_larger() { return MakeIndirectExec<true, true>(&xid8_larger); }
TExecFunc arrow_xid8_smaller() { return MakeIndirectExec<true, true>(&xid8_smaller); }
TExecFunc arrow_xid8cmp() { return MakeIndirectExec<true, true>(&xid8cmp); }
TExecFunc arrow_xid8eq() { return MakeIndirectExec<true, true>(&xid8eq); }
TExecFunc arrow_xid8ge() { return MakeIndirectExec<true, true>(&xid8ge); }
TExecFunc arrow_xid8gt() { return MakeIndirectExec<true, true>(&xid8gt); }
TExecFunc arrow_xid8in() { return MakeIndirectExec<true, true>(&xid8in); }
TExecFunc arrow_xid8le() { return MakeIndirectExec<true, true>(&xid8le); }
TExecFunc arrow_xid8lt() { return MakeIndirectExec<true, true>(&xid8lt); }
TExecFunc arrow_xid8ne() { return MakeIndirectExec<true, true>(&xid8ne); }
TExecFunc arrow_xid8out() { return MakeIndirectExec<true, false>(&xid8out); }
TExecFunc arrow_xid8recv() { return MakeIndirectExec<true, true>(&xid8recv); }
TExecFunc arrow_xid8send() { return MakeIndirectExec<true, false>(&xid8send); }
TExecFunc arrow_xid8toxid() { return MakeIndirectExec<true, true>(&xid8toxid); }
TExecFunc arrow_xid_age() { return MakeIndirectExec<true, true>(&xid_age); }
TExecFunc arrow_xideq() { return MakeIndirectExec<true, true>(&xideq); }
TExecFunc arrow_xidin() { return MakeIndirectExec<true, true>(&xidin); }
TExecFunc arrow_xidneq() { return MakeIndirectExec<true, true>(&xidneq); }
TExecFunc arrow_xidout() { return MakeIndirectExec<true, false>(&xidout); }
TExecFunc arrow_xidrecv() { return MakeIndirectExec<true, true>(&xidrecv); }
TExecFunc arrow_xidsend() { return MakeIndirectExec<true, false>(&xidsend); }

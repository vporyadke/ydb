TExecFunc arrow_dsynonym_init() { return TGenericExec<TPgDirectFunc<&dsynonym_init>, true, true, TArgs_dsynonym_init_Policy>({}); }
TExecFunc arrow_dsynonym_lexize() { return TGenericExec<TPgDirectFunc<&dsynonym_lexize>, true, true, TArgs_dsynonym_lexize_Policy>({}); }
TExecFunc arrow_elem_contained_by_multirange() { return TGenericExec<TPgDirectFunc<&elem_contained_by_multirange>, true, true, TArgs_elem_contained_by_multirange_Policy>({}); }
TExecFunc arrow_hash_multirange() { return TGenericExec<TPgDirectFunc<&hash_multirange>, true, true, TArgs_hash_multirange_Policy>({}); }
TExecFunc arrow_hash_multirange_extended() { return TGenericExec<TPgDirectFunc<&hash_multirange_extended>, true, true, TArgs_hash_multirange_extended_Policy>({}); }
TExecFunc arrow_hypothetical_cume_dist_final() { return TGenericExec<TPgDirectFunc<&hypothetical_cume_dist_final>, false, true, TDefaultArgsPolicy>({}); }
TExecFunc arrow_hypothetical_dense_rank_final() { return TGenericExec<TPgDirectFunc<&hypothetical_dense_rank_final>, false, true, TDefaultArgsPolicy>({}); }
TExecFunc arrow_hypothetical_percent_rank_final() { return TGenericExec<TPgDirectFunc<&hypothetical_percent_rank_final>, false, true, TDefaultArgsPolicy>({}); }
TExecFunc arrow_hypothetical_rank_final() { return TGenericExec<TPgDirectFunc<&hypothetical_rank_final>, false, true, TDefaultArgsPolicy>({}); }
TExecFunc arrow_mode_final() { return TGenericExec<TPgDirectFunc<&mode_final>, false, true, TArgs_mode_final_Policy>({}); }
TExecFunc arrow_multirange_adjacent_multirange() { return TGenericExec<TPgDirectFunc<&multirange_adjacent_multirange>, true, true, TArgs_multirange_adjacent_multirange_Policy>({}); }
TExecFunc arrow_multirange_adjacent_range() { return TGenericExec<TPgDirectFunc<&multirange_adjacent_range>, true, true, TArgs_multirange_adjacent_range_Policy>({}); }
TExecFunc arrow_multirange_after_multirange() { return TGenericExec<TPgDirectFunc<&multirange_after_multirange>, true, true, TArgs_multirange_after_multirange_Policy>({}); }
TExecFunc arrow_multirange_after_range() { return TGenericExec<TPgDirectFunc<&multirange_after_range>, true, true, TArgs_multirange_after_range_Policy>({}); }
TExecFunc arrow_multirange_agg_transfn() { return TGenericExec<TPgDirectFunc<&multirange_agg_transfn>, false, true, TArgs_multirange_agg_transfn_Policy>({}); }
TExecFunc arrow_multirange_before_multirange() { return TGenericExec<TPgDirectFunc<&multirange_before_multirange>, true, true, TArgs_multirange_before_multirange_Policy>({}); }
TExecFunc arrow_multirange_before_range() { return TGenericExec<TPgDirectFunc<&multirange_before_range>, true, true, TArgs_multirange_before_range_Policy>({}); }
TExecFunc arrow_multirange_cmp() { return TGenericExec<TPgDirectFunc<&multirange_cmp>, true, true, TArgs_multirange_cmp_Policy>({}); }
TExecFunc arrow_multirange_constructor0() { return TGenericExec<TPgDirectFunc<&multirange_constructor0>, true, false, TArgs_multirange_constructor0_Policy>({}); }
TExecFunc arrow_multirange_constructor1() { return TGenericExec<TPgDirectFunc<&multirange_constructor1>, true, false, TArgs_multirange_constructor1_Policy>({}); }
TExecFunc arrow_multirange_constructor2() { return TGenericExec<TPgDirectFunc<&multirange_constructor2>, true, false, TDefaultArgsPolicy>({}); }
TExecFunc arrow_multirange_contained_by_multirange() { return TGenericExec<TPgDirectFunc<&multirange_contained_by_multirange>, true, true, TArgs_multirange_contained_by_multirange_Policy>({}); }
TExecFunc arrow_multirange_contained_by_range() { return TGenericExec<TPgDirectFunc<&multirange_contained_by_range>, true, true, TArgs_multirange_contained_by_range_Policy>({}); }
TExecFunc arrow_multirange_contains_elem() { return TGenericExec<TPgDirectFunc<&multirange_contains_elem>, true, true, TArgs_multirange_contains_elem_Policy>({}); }
TExecFunc arrow_multirange_contains_multirange() { return TGenericExec<TPgDirectFunc<&multirange_contains_multirange>, true, true, TArgs_multirange_contains_multirange_Policy>({}); }
TExecFunc arrow_multirange_contains_range() { return TGenericExec<TPgDirectFunc<&multirange_contains_range>, true, true, TArgs_multirange_contains_range_Policy>({}); }
TExecFunc arrow_multirange_empty() { return TGenericExec<TPgDirectFunc<&multirange_empty>, true, true, TArgs_multirange_empty_Policy>({}); }
TExecFunc arrow_multirange_eq() { return TGenericExec<TPgDirectFunc<&multirange_eq>, true, true, TArgs_multirange_eq_Policy>({}); }
TExecFunc arrow_multirange_ge() { return TGenericExec<TPgDirectFunc<&multirange_ge>, true, true, TArgs_multirange_ge_Policy>({}); }
TExecFunc arrow_multirange_gt() { return TGenericExec<TPgDirectFunc<&multirange_gt>, true, true, TArgs_multirange_gt_Policy>({}); }
TExecFunc arrow_multirange_in() { return TGenericExec<TPgDirectFunc<&multirange_in>, true, false, TArgs_multirange_in_Policy>({}); }
TExecFunc arrow_multirange_intersect() { return TGenericExec<TPgDirectFunc<&multirange_intersect>, true, false, TArgs_multirange_intersect_Policy>({}); }
TExecFunc arrow_multirange_intersect_agg_transfn() { return TGenericExec<TPgDirectFunc<&multirange_intersect_agg_transfn>, true, false, TArgs_multirange_intersect_agg_transfn_Policy>({}); }
TExecFunc arrow_multirange_le() { return TGenericExec<TPgDirectFunc<&multirange_le>, true, true, TArgs_multirange_le_Policy>({}); }
TExecFunc arrow_multirange_lower() { return TGenericExec<TPgDirectFunc<&multirange_lower>, true, true, TArgs_multirange_lower_Policy>({}); }
TExecFunc arrow_multirange_lower_inc() { return TGenericExec<TPgDirectFunc<&multirange_lower_inc>, true, true, TArgs_multirange_lower_inc_Policy>({}); }
TExecFunc arrow_multirange_lower_inf() { return TGenericExec<TPgDirectFunc<&multirange_lower_inf>, true, true, TArgs_multirange_lower_inf_Policy>({}); }
TExecFunc arrow_multirange_lt() { return TGenericExec<TPgDirectFunc<&multirange_lt>, true, true, TArgs_multirange_lt_Policy>({}); }
TExecFunc arrow_multirange_minus() { return TGenericExec<TPgDirectFunc<&multirange_minus>, true, false, TArgs_multirange_minus_Policy>({}); }
TExecFunc arrow_multirange_ne() { return TGenericExec<TPgDirectFunc<&multirange_ne>, true, true, TArgs_multirange_ne_Policy>({}); }
TExecFunc arrow_multirange_out() { return TGenericExec<TPgDirectFunc<&multirange_out>, true, false, TArgs_multirange_out_Policy>({}); }
TExecFunc arrow_multirange_overlaps_multirange() { return TGenericExec<TPgDirectFunc<&multirange_overlaps_multirange>, true, true, TArgs_multirange_overlaps_multirange_Policy>({}); }
TExecFunc arrow_multirange_overlaps_range() { return TGenericExec<TPgDirectFunc<&multirange_overlaps_range>, true, true, TArgs_multirange_overlaps_range_Policy>({}); }
TExecFunc arrow_multirange_overleft_multirange() { return TGenericExec<TPgDirectFunc<&multirange_overleft_multirange>, true, true, TArgs_multirange_overleft_multirange_Policy>({}); }
TExecFunc arrow_multirange_overleft_range() { return TGenericExec<TPgDirectFunc<&multirange_overleft_range>, true, true, TArgs_multirange_overleft_range_Policy>({}); }
TExecFunc arrow_multirange_overright_multirange() { return TGenericExec<TPgDirectFunc<&multirange_overright_multirange>, true, true, TArgs_multirange_overright_multirange_Policy>({}); }
TExecFunc arrow_multirange_overright_range() { return TGenericExec<TPgDirectFunc<&multirange_overright_range>, true, true, TArgs_multirange_overright_range_Policy>({}); }
TExecFunc arrow_multirange_recv() { return TGenericExec<TPgDirectFunc<&multirange_recv>, true, false, TArgs_multirange_recv_Policy>({}); }
TExecFunc arrow_multirange_send() { return TGenericExec<TPgDirectFunc<&multirange_send>, true, false, TArgs_multirange_send_Policy>({}); }
TExecFunc arrow_multirange_union() { return TGenericExec<TPgDirectFunc<&multirange_union>, true, false, TArgs_multirange_union_Policy>({}); }
TExecFunc arrow_multirange_upper() { return TGenericExec<TPgDirectFunc<&multirange_upper>, true, true, TArgs_multirange_upper_Policy>({}); }
TExecFunc arrow_multirange_upper_inc() { return TGenericExec<TPgDirectFunc<&multirange_upper_inc>, true, true, TArgs_multirange_upper_inc_Policy>({}); }
TExecFunc arrow_multirange_upper_inf() { return TGenericExec<TPgDirectFunc<&multirange_upper_inf>, true, true, TArgs_multirange_upper_inf_Policy>({}); }
TExecFunc arrow_multirangesel() { return TGenericExec<TPgDirectFunc<&multirangesel>, true, true, TArgs_multirangesel_Policy>({}); }
TExecFunc arrow_ordered_set_transition() { return TGenericExec<TPgDirectFunc<&ordered_set_transition>, false, true, TArgs_ordered_set_transition_Policy>({}); }
TExecFunc arrow_ordered_set_transition_multi() { return TGenericExec<TPgDirectFunc<&ordered_set_transition_multi>, false, true, TDefaultArgsPolicy>({}); }
TExecFunc arrow_percentile_cont_float8_final() { return TGenericExec<TPgDirectFunc<&percentile_cont_float8_final>, false, true, TArgs_percentile_cont_float8_final_Policy>({}); }
TExecFunc arrow_percentile_cont_float8_multi_final() { return TGenericExec<TPgDirectFunc<&percentile_cont_float8_multi_final>, false, false, TArgs_percentile_cont_float8_multi_final_Policy>({}); }
TExecFunc arrow_percentile_cont_interval_final() { return TGenericExec<TPgDirectFunc<&percentile_cont_interval_final>, false, false, TArgs_percentile_cont_interval_final_Policy>({}); }
TExecFunc arrow_percentile_cont_interval_multi_final() { return TGenericExec<TPgDirectFunc<&percentile_cont_interval_multi_final>, false, false, TArgs_percentile_cont_interval_multi_final_Policy>({}); }
TExecFunc arrow_percentile_disc_final() { return TGenericExec<TPgDirectFunc<&percentile_disc_final>, false, true, TArgs_percentile_disc_final_Policy>({}); }
TExecFunc arrow_percentile_disc_multi_final() { return TGenericExec<TPgDirectFunc<&percentile_disc_multi_final>, false, false, TArgs_percentile_disc_multi_final_Policy>({}); }
TExecFunc arrow_pg_get_constraintdef() { return TGenericExec<TPgDirectFunc<&pg_get_constraintdef>, true, false, TArgs_pg_get_constraintdef_Policy>({}); }
TExecFunc arrow_pg_get_constraintdef_ext() { return TGenericExec<TPgDirectFunc<&pg_get_constraintdef_ext>, true, false, TArgs_pg_get_constraintdef_ext_Policy>({}); }
TExecFunc arrow_pg_get_expr() { return TGenericExec<TPgDirectFunc<&pg_get_expr>, true, false, TArgs_pg_get_expr_Policy>({}); }
TExecFunc arrow_pg_get_expr_ext() { return TGenericExec<TPgDirectFunc<&pg_get_expr_ext>, true, false, TArgs_pg_get_expr_ext_Policy>({}); }
TExecFunc arrow_pg_get_function_arg_default() { return TGenericExec<TPgDirectFunc<&pg_get_function_arg_default>, true, false, TArgs_pg_get_function_arg_default_Policy>({}); }
TExecFunc arrow_pg_get_function_arguments() { return TGenericExec<TPgDirectFunc<&pg_get_function_arguments>, true, false, TArgs_pg_get_function_arguments_Policy>({}); }
TExecFunc arrow_pg_get_function_identity_arguments() { return TGenericExec<TPgDirectFunc<&pg_get_function_identity_arguments>, true, false, TArgs_pg_get_function_identity_arguments_Policy>({}); }
TExecFunc arrow_pg_get_function_result() { return TGenericExec<TPgDirectFunc<&pg_get_function_result>, true, false, TArgs_pg_get_function_result_Policy>({}); }
TExecFunc arrow_pg_get_function_sqlbody() { return TGenericExec<TPgDirectFunc<&pg_get_function_sqlbody>, true, false, TArgs_pg_get_function_sqlbody_Policy>({}); }
TExecFunc arrow_pg_get_functiondef() { return TGenericExec<TPgDirectFunc<&pg_get_functiondef>, true, false, TArgs_pg_get_functiondef_Policy>({}); }
TExecFunc arrow_pg_get_indexdef() { return TGenericExec<TPgDirectFunc<&pg_get_indexdef>, true, false, TArgs_pg_get_indexdef_Policy>({}); }
TExecFunc arrow_pg_get_indexdef_ext() { return TGenericExec<TPgDirectFunc<&pg_get_indexdef_ext>, true, false, TArgs_pg_get_indexdef_ext_Policy>({}); }
TExecFunc arrow_pg_get_partition_constraintdef() { return TGenericExec<TPgDirectFunc<&pg_get_partition_constraintdef>, true, false, TArgs_pg_get_partition_constraintdef_Policy>({}); }
TExecFunc arrow_pg_get_partkeydef() { return TGenericExec<TPgDirectFunc<&pg_get_partkeydef>, true, false, TArgs_pg_get_partkeydef_Policy>({}); }
TExecFunc arrow_pg_get_ruledef() { return TGenericExec<TPgDirectFunc<&pg_get_ruledef>, true, false, TArgs_pg_get_ruledef_Policy>({}); }
TExecFunc arrow_pg_get_ruledef_ext() { return TGenericExec<TPgDirectFunc<&pg_get_ruledef_ext>, true, false, TArgs_pg_get_ruledef_ext_Policy>({}); }
TExecFunc arrow_pg_get_serial_sequence() { return TGenericExec<TPgDirectFunc<&pg_get_serial_sequence>, true, false, TArgs_pg_get_serial_sequence_Policy>({}); }
TExecFunc arrow_pg_get_statisticsobjdef() { return TGenericExec<TPgDirectFunc<&pg_get_statisticsobjdef>, true, false, TArgs_pg_get_statisticsobjdef_Policy>({}); }
TExecFunc arrow_pg_get_statisticsobjdef_columns() { return TGenericExec<TPgDirectFunc<&pg_get_statisticsobjdef_columns>, true, false, TArgs_pg_get_statisticsobjdef_columns_Policy>({}); }
TExecFunc arrow_pg_get_statisticsobjdef_expressions() { return TGenericExec<TPgDirectFunc<&pg_get_statisticsobjdef_expressions>, true, false, TArgs_pg_get_statisticsobjdef_expressions_Policy>({}); }
TExecFunc arrow_pg_get_triggerdef() { return TGenericExec<TPgDirectFunc<&pg_get_triggerdef>, true, false, TArgs_pg_get_triggerdef_Policy>({}); }
TExecFunc arrow_pg_get_triggerdef_ext() { return TGenericExec<TPgDirectFunc<&pg_get_triggerdef_ext>, true, false, TArgs_pg_get_triggerdef_ext_Policy>({}); }
TExecFunc arrow_pg_get_userbyid() { return TGenericExec<TPgDirectFunc<&pg_get_userbyid>, true, false, TArgs_pg_get_userbyid_Policy>({}); }
TExecFunc arrow_pg_get_viewdef() { return TGenericExec<TPgDirectFunc<&pg_get_viewdef>, true, false, TArgs_pg_get_viewdef_Policy>({}); }
TExecFunc arrow_pg_get_viewdef_ext() { return TGenericExec<TPgDirectFunc<&pg_get_viewdef_ext>, true, false, TArgs_pg_get_viewdef_ext_Policy>({}); }
TExecFunc arrow_pg_get_viewdef_name() { return TGenericExec<TPgDirectFunc<&pg_get_viewdef_name>, true, false, TArgs_pg_get_viewdef_name_Policy>({}); }
TExecFunc arrow_pg_get_viewdef_name_ext() { return TGenericExec<TPgDirectFunc<&pg_get_viewdef_name_ext>, true, false, TArgs_pg_get_viewdef_name_ext_Policy>({}); }
TExecFunc arrow_pg_get_viewdef_wrap() { return TGenericExec<TPgDirectFunc<&pg_get_viewdef_wrap>, true, false, TArgs_pg_get_viewdef_wrap_Policy>({}); }
TExecFunc arrow_pg_jit_available() { return TGenericExec<TPgDirectFunc<&pg_jit_available>, true, true, TArgs_pg_jit_available_Policy>({}); }
TExecFunc arrow_pg_lsn_cmp() { return TGenericExec<TPgDirectFunc<&pg_lsn_cmp>, true, true, TArgs_pg_lsn_cmp_Policy>({}); }
TExecFunc arrow_pg_lsn_eq() { return TGenericExec<TPgDirectFunc<&pg_lsn_eq>, true, true, TArgs_pg_lsn_eq_Policy>({}); }
TExecFunc arrow_pg_lsn_ge() { return TGenericExec<TPgDirectFunc<&pg_lsn_ge>, true, true, TArgs_pg_lsn_ge_Policy>({}); }
TExecFunc arrow_pg_lsn_gt() { return TGenericExec<TPgDirectFunc<&pg_lsn_gt>, true, true, TArgs_pg_lsn_gt_Policy>({}); }
TExecFunc arrow_pg_lsn_hash() { return TGenericExec<TPgDirectFunc<&pg_lsn_hash>, true, true, TArgs_pg_lsn_hash_Policy>({}); }
TExecFunc arrow_pg_lsn_hash_extended() { return TGenericExec<TPgDirectFunc<&pg_lsn_hash_extended>, true, true, TArgs_pg_lsn_hash_extended_Policy>({}); }
TExecFunc arrow_pg_lsn_in() { return TGenericExec<TPgDirectFunc<&pg_lsn_in>, true, true, TArgs_pg_lsn_in_Policy>({}); }
TExecFunc arrow_pg_lsn_larger() { return TGenericExec<TPgDirectFunc<&pg_lsn_larger>, true, true, TArgs_pg_lsn_larger_Policy>({}); }
TExecFunc arrow_pg_lsn_le() { return TGenericExec<TPgDirectFunc<&pg_lsn_le>, true, true, TArgs_pg_lsn_le_Policy>({}); }
TExecFunc arrow_pg_lsn_lt() { return TGenericExec<TPgDirectFunc<&pg_lsn_lt>, true, true, TArgs_pg_lsn_lt_Policy>({}); }
TExecFunc arrow_pg_lsn_mi() { return TGenericExec<TPgDirectFunc<&pg_lsn_mi>, true, false, TArgs_pg_lsn_mi_Policy>({}); }
TExecFunc arrow_pg_lsn_mii() { return TGenericExec<TPgDirectFunc<&pg_lsn_mii>, true, true, TArgs_pg_lsn_mii_Policy>({}); }
TExecFunc arrow_pg_lsn_ne() { return TGenericExec<TPgDirectFunc<&pg_lsn_ne>, true, true, TArgs_pg_lsn_ne_Policy>({}); }
TExecFunc arrow_pg_lsn_out() { return TGenericExec<TPgDirectFunc<&pg_lsn_out>, true, false, TArgs_pg_lsn_out_Policy>({}); }
TExecFunc arrow_pg_lsn_pli() { return TGenericExec<TPgDirectFunc<&pg_lsn_pli>, true, true, TArgs_pg_lsn_pli_Policy>({}); }
TExecFunc arrow_pg_lsn_recv() { return TGenericExec<TPgDirectFunc<&pg_lsn_recv>, true, true, TArgs_pg_lsn_recv_Policy>({}); }
TExecFunc arrow_pg_lsn_send() { return TGenericExec<TPgDirectFunc<&pg_lsn_send>, true, false, TArgs_pg_lsn_send_Policy>({}); }
TExecFunc arrow_pg_lsn_smaller() { return TGenericExec<TPgDirectFunc<&pg_lsn_smaller>, true, true, TArgs_pg_lsn_smaller_Policy>({}); }
TExecFunc arrow_range_adjacent_multirange() { return TGenericExec<TPgDirectFunc<&range_adjacent_multirange>, true, true, TArgs_range_adjacent_multirange_Policy>({}); }
TExecFunc arrow_range_after_multirange() { return TGenericExec<TPgDirectFunc<&range_after_multirange>, true, true, TArgs_range_after_multirange_Policy>({}); }
TExecFunc arrow_range_agg_finalfn() { return TGenericExec<TPgDirectFunc<&range_agg_finalfn>, false, false, TArgs_range_agg_finalfn_Policy>({}); }
TExecFunc arrow_range_agg_transfn() { return TGenericExec<TPgDirectFunc<&range_agg_transfn>, false, true, TArgs_range_agg_transfn_Policy>({}); }
TExecFunc arrow_range_before_multirange() { return TGenericExec<TPgDirectFunc<&range_before_multirange>, true, true, TArgs_range_before_multirange_Policy>({}); }
TExecFunc arrow_range_contained_by_multirange() { return TGenericExec<TPgDirectFunc<&range_contained_by_multirange>, true, true, TArgs_range_contained_by_multirange_Policy>({}); }
TExecFunc arrow_range_contains_multirange() { return TGenericExec<TPgDirectFunc<&range_contains_multirange>, true, true, TArgs_range_contains_multirange_Policy>({}); }
TExecFunc arrow_range_merge_from_multirange() { return TGenericExec<TPgDirectFunc<&range_merge_from_multirange>, true, false, TArgs_range_merge_from_multirange_Policy>({}); }
TExecFunc arrow_range_overlaps_multirange() { return TGenericExec<TPgDirectFunc<&range_overlaps_multirange>, true, true, TArgs_range_overlaps_multirange_Policy>({}); }
TExecFunc arrow_range_overleft_multirange() { return TGenericExec<TPgDirectFunc<&range_overleft_multirange>, true, true, TArgs_range_overleft_multirange_Policy>({}); }
TExecFunc arrow_range_overright_multirange() { return TGenericExec<TPgDirectFunc<&range_overright_multirange>, true, true, TArgs_range_overright_multirange_Policy>({}); }
TExecFunc arrow_spg_quad_choose() { return TGenericExec<TPgDirectFunc<&spg_quad_choose>, true, true, TArgs_spg_quad_choose_Policy>({}); }
TExecFunc arrow_spg_quad_config() { return TGenericExec<TPgDirectFunc<&spg_quad_config>, true, true, TArgs_spg_quad_config_Policy>({}); }
TExecFunc arrow_spg_quad_inner_consistent() { return TGenericExec<TPgDirectFunc<&spg_quad_inner_consistent>, true, true, TArgs_spg_quad_inner_consistent_Policy>({}); }
TExecFunc arrow_spg_quad_leaf_consistent() { return TGenericExec<TPgDirectFunc<&spg_quad_leaf_consistent>, true, true, TArgs_spg_quad_leaf_consistent_Policy>({}); }
TExecFunc arrow_spg_quad_picksplit() { return TGenericExec<TPgDirectFunc<&spg_quad_picksplit>, true, true, TArgs_spg_quad_picksplit_Policy>({}); }
TExecFunc arrow_spghandler() { return TGenericExec<TPgDirectFunc<&spghandler>, true, true, TArgs_spghandler_Policy>({}); }
TExecFunc arrow_system_user() { return TGenericExec<TPgDirectFunc<&system_user>, true, false, TArgs_system_user_Policy>({}); }

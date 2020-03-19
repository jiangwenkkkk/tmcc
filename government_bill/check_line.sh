#!/usr/bin/env bash



#cat /Users/james/Downloads/sxw/NO_key | sed -n "a_merge_event_type_tm"

table_names="
b_template_map_switch
b_object_define
b_map_parser_group
b_sepfile
b_sep_field
b_asn1_field
b_filed_check
b_file_name_rule
check_combine
check_rule
check_subrule
check_argument
b_checkfile_accu_desc
b_checkfile_accu
ds_region_prov
ds_busi_region_flow
login_statement
"

rm /Users/james/Documents/结算值班/sxw/redo;
for name in $table_names
do
    sed -n "/~\<$name\>/p" /Users/james/Documents/结算值班/sxw/NO_key >> /Users/james/Documents/结算值班/sxw/redo;
done




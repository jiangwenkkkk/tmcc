#!/usr/bin/env bash

#sed -n -e '/<div class=\"info\">/,/<\/div>/p' *.html
#sed -n -e '/<div>/p' -e '/<div class=\"info\">/,/<\/div>/p' *.html
#sed -n -e '/`check_relation`/p' -e '//,/<\/div>/p' /Users/james/Downloads/comm_2019-05-06.sql
#sed -n -e '/`check_relation`/p' -e '/`check_relation`/,/CHARSET=utf8;/p' /Users/james/Downloads/comm_2019-05-06.sql


table="
check_relation
Check_Rule
check_subrule
Check_Argument
check_function
check_combine
b_file_name_rule
b_sepfile
b_tap3file
b_sepblockinfo
b_tap3blockinfo
b_sep_field
b_asn1_field
b_asn1_tag_seq
b_checkfile_accu_desc
b_checkfile_accu
b_checkfile_accu_result
trans_file_type
b_switch_type
b_switch_info
b_template_map_switch
b_template_type
b_object_type
b_object_define
b_map_parser_group
wf_module
"

for name in $table
do
#    sed -n  -e "/\`$name\`/,/CHARSET=utf8;/p" /Users/james/Downloads/mvno_comm_2019-05-10.sql
    sed -n  -e "/'$name'/p"  /Users/james/Downloads/comm_2019-05-06.sql
done

#sed -n  -e "/\`check_relation\`/,/CHARSET=utf8;/p" /Users/james/Downloads/comm_2019-05-06.sql
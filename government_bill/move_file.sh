#!/bin/bash
export `NLS_LANG=SIMPLIFIED CHINESE_CHINA.AL32UTF8`
filepath=/mvno/gather1/sxw
sqlname=""
sqlstatement=""
outputdb()
{
sqlplus -S MVNO_COMM/sh36!DB37y5_sh<< EOF
set head off;
set feedback off;
set pages 0;
set trimout on;
set trimspool on;
set verify off;
set linesize 1000;
spool $csvfile
$sqlstatement $sqlname ;
spool off;
exit;
EOF
}
cat /mvno/gather1/a.txt|
while read line
do
     sqlname=`echo $line | cut -d \~ -f 2`
     sqlstatement=`echo $line | cut -d \~ -f 1`
     csvfile="$filepath/$sqlname_.csv"
     logpath="$filepath/$sqlname_.log"
     echo `date`"start">>$logpath
     outputdb
     echo `date`"end">>$logpath
     iconv  -f gbk -t UTF-8 $sqlname_.csv  > $sqlname.csv
#     `gzip $sqlname.csv`


expect -c "
spawn scp $sqlname jsapp@10.130.236.110:/data07/dump/sxw/
expect {
\"*assword\" {set timeout 300; send \"CYH_test@2018\n\";}
\"yes/no\" {send \"yes\r\"; exp_continue;}
}
expect eof"

     rm $sqlname.csv

done
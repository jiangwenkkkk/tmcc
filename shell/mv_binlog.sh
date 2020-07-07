#!/bin/sh
LOG_FILE="/app/sr/script/mv_auditFile.log"
v_date=`date -d "-2 days" +%Y%m%d`


binlogfilepath="/data1/teledb/mysql/data/mysql*/binlog"
binlogfilepath_bak="/data6/binlog_bak"
logfilefilter=mysql-bin.*

echo $auditfilefilter
echo "[`date +\"%Y/%m/%d %H:%M:%S\"`] start move "$v_date >>$LOG_FILE


if [ -d "$auditfilepath" ];then
    cd $auditfilepath
    num=`find  .  -type f -mmin +1  -name "BOSSNM_0_3253_40206*" |wc -l`
    echo $num

    if [ $num -gt 0 ];then
        find  .  -type f -mmin +1  -name "BOSSNM_0_3253_40206*" |xargs  -i mv {} $auditfilepath_bak
    else
        echo "[`date +\"%Y/%m/%d %H:%M:%S\"`] have no file to mv,do not to do ">>$LOG_FILE;
    fi

else
  echo "[`date +\"%Y/%m/%d %H:%M:%S\"`] no such path "$auditfilepath>>$LOG_FILE;
  exit 1;
fi


if [ $? -eq 0 ];then
    echo "[`date +\"%Y/%m/%d %H:%M:%S\"`] move auditfile success">>$LOG_FILE
else
    echo "[`date +\"%Y/%m/%d %H:%M:%S\"`] move auditfile fail ">>$LOG_FILE
	fi
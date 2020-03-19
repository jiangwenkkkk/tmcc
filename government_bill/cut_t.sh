#!/usr/bin/env bash

echo "SELECT ACCT_ID ||'|'|| CREDIT_GRADE ||'|'|| CREDIT_AMOUNT ||'|'|| EXCEPTION_AMOUNT ||'|'|| to_char(EFF_DATE,'YYYY-MM-DD HH24:MI:SS') ||'|'|| BILLING_CYCLE_ID ||'|'|| ORG_ID ||'|'|| CREDIT_LEVEL ||'|'|| CREDIT_LEVEL_AMOUNT ||'|'|| SERV_ID ||'|'|| to_char(EXP_DATE,'YYYY-MM-DD HH24:MI:SS') ||'|'|| ACCT_CREDIT_ID ||'|'|| INSTANCE_ID ||'|'|| to_char(CREATED_DATE,'YYYY-MM-DD HH24:MI:SS') ||'|'|| to_char(OPER_DATE,'YYYY-MM-DD HH24:MI:SS') ||'|'|| PARTNER_ID  from~acct_credit"|
while read line
do
    sqlname=`echo $line | cut -d \~ -f 2`
    sqlstatement=`echo $line | cut -d \~ -f 1`
    echo $sqlname
    echo $sqlstatement
done

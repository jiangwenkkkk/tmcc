#!/usr/bin/env bash

a="select cast(sum(split(nvl(numfive,''),',')[0]+split(nvl(numfive,''),',')[1]) as bigint), cast(sum(split(numfour,',')[1]+ split(numfour,',')[2]) as bigint) from hi_qdcx.rm_qdcx_5g  LATERAL VIEW explode(split(rgfiveg,"#")) rg AS numfive LATERAL VIEW explode(split(rgfourg,"#")) rg AS numfour where  date_no = "20200201" and rm_qdcx_5g.provinceid =10 and rgfiveg!='';"

for b in  991 99 971 951 931 898 891 871 851 791 771 731 591 571 551 531 471 451 431 371 351 311 29 28 27 25 23 22 21 20 10
do
    for datea in 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
    do
        c="select cast(sum(split(nvl(numfive,''),',')[0]+split(nvl(numfive,''),',')[1]) as bigint), cast(sum(split(numfour,',')[1]+ split(numfour,',')[2]) as bigint) from hi_qdcx.rm_qdcx_5g  LATERAL VIEW explode(split(rgfiveg,\"#\")) rg AS numfive LATERAL VIEW explode(split(rgfourg,\"#\")) rg AS numfour where  date_no = \"202002"
        c+=$datea\"" and rm_qdcx_5g.provinceid =$b and rgfiveg!='';"
        echo $c >> tmp.sql

    done
done
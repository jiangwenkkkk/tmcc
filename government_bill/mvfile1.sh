#!/usr/bin/env bash

tables="
bc_rule_cata
"




for line in $tables
do
if [ ! "$line.prop" ];
then rm $line.prop
fi

txt="sh=135.127.20.170\nsP=8100\nsu=comm\nsp=a#34kl!29F\ndio\nzk='{\"zkUrl\":\"135.125.162.200:10014,135.125.162.201:10014,135.125.162.202:10014\",\"namespace\":\"udal_cluster/tenant_1\",\"digest\":\"udal_zk:9222ABC820ADB25CCE75899F235F937E\"}'\ncid='/dbproxy_cluster/dbproxy_cluster_0000000506'\nmaster\nrt=8\nct=64\nx='<etl><schemas><schema src=\"comm\" des=\"dump\"><tables><table src=\""$line"\" exclusiveColumn=\"\"></table></tables></schema></schemas></etl>'\neC\neF\ndD=/home/secure/udal/dump/src/data_5\n"

echo -e $txt >> $line.prop
./start -opt $line.prop -eD /data/udal/src/dump/tmp
#rm $line.prop
done

#txt="sh=135.127.20.170\nsP=8100\nsu=comm\nsp=a#34kl!29F\ndio\nzk='{\"zkUrl\":\"135.125.162.200:10014,135.125.162.201:10014,135.125.162.202:10014\",\"namespace\":\"udal_cluster/tenant_1\",\"digest\":\"udal_zk:9222ABC820ADB25CCE75899F235F937E\"}'\ncid='/dbproxy_cluster/dbproxy_cluster_0000000506'\nmaster\nrt=8\nct=64\nx='<etl><schemas><schema src=\"comm\" des=\"dump\"><tables>\\ \n<table src=\""$line"\" exclusiveColumn=\"\"></table>\\ \n</tables></schema></schemas></etl>'\neC\neF\ndD=/home/secure/udal/dump/src/data_5\n"

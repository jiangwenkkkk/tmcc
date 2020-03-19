#!/usr/bin/env bash

/usr/local/bin/expect << EOF
     spawn scp a.csv jsapp@10.130.236.110:/data07/dump/sxw/
     expect {
      "jsapp@10.130.236.110's password:" {send "CYH_test@2018\n"}
      }


EOF


expect -c "
spawn scp a.csv jsapp@10.130.236.110:/data07/dump/sxw/
expect {
\"*assword\" {set timeout 300; send \"CYH_test@2018\n\";}
\"yes/no\" {send \"yes\r\"; exp_continue;}
}
expect eof"
#!/bin/bash

#windos和linux会导致换行符的问题

#while循环读取文件的一行字符串，
#for是默认空格为分隔符，导致字符串会被分割
#

function funSendCommand() {

cat $@|while read sum
do
    ip=$(echo $sum | awk -F ";" '{print $1}')
    name=$(echo $sum | awk -F ";" '{print $2}')
    password=$(echo $sum | awk -F ";" '{print $3}')
    command=$(echo $sum|awk -F ";" '{print $4}')

    echo $sum -- $ip -- $name -- pass $password -- $command
    /usr/bin/expect <<-EOF
set timeout 30;
spawn ssh $name@$ip -p 5151
expect {
 "*yes/no" { send "yes\r"; exp_continue}
 "*ssword:" { send "$password\r";}
}

expect "*$ "
send "echo -n $ip;echo $command /jsdata/tmp.txt\r"


expect "*$ "
send "echo -----------------------------------------------------------------\r

expect "*$ "
send "exit\r"

EOF
  done
}

function findnull() {
  echo -e '\n\nThere is some ip cannot totaly check!!!!!!(Disconnected or too much info......)'
  diff t_ip_list_proc.txt t_ip_list_proc1.txt | grep "^>" | cut -d ' ' -f 2
}

function audit_check() {
  echo $0 $1 $2
  x1=$(cat $1 | wc -l)
  x2=$(cat $2 | wc -l)
  [[ $x1 -ne $x2 ]] && findnull
}

# 清理数据文件
ls ./file_script/file_num.log* | xargs -i rm {}

n=1
cat ip_command_stop | while read args
do
  (
  echo "args" -- $args
    tmp_ip=`echo $args|awk -F ";" '{print $1}'`

#    funSendCommand $args >./file_script/file_num.log_$tmp_ip
    funSendCommand ip_command_stop
  ) &
  let n++
done


#ls ./process_script/_process.log_* | sort -t : -n -k 4 | xargs -i cat {} >process_log12.txt
#ls ./file_script/file_num.log_* | sort -t : -n -k 4 | xargs -i cat {} >fileNumLog12.txt


#sed -i 's/\r$//' fileNumLog12.txt
#cat fileNumLog12.txt > hhell.txt
#sed -i '/^10.142.234.*/!d' fileNumLog12.txt
#sed -i '/^10.142.234.*/!d' hhell.txt

#cat fileNumLog12.txt|awk -F : '{if ($2 > 0) print $1 ":" $2 "error"; else print $1 ":" $2 "ritht";}'
#cat hhell.txt|awk -F : '{if ($2 > 0) print $1 ":" $2 "error"; else print $1 ":" $2 "ritht";}'
#
#sed fileNumLog12.txt|awk -F : '{if ($2 > 0) print $1 ":" $2 " error"; else print $1 ":" $2 "ritht";}'
#
#
#
#awk '{print $1}' fileNumLog12.txt | sort -u >t_ip_list_proc.txt
#cut -d ';' -f 1 name_passwd_ip_roam1.ini | sort >t_ip_list_proc1.txt
#
#audit_check t_ip_list_proc.txt t_ip_list_proc.txt
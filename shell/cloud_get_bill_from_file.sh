#!/usr/bin/env bash

#从源文件提取话单到目录文件
#
#
#source="/Users/james/Downloads/bill_cloud/1061_backup*

source=$1


dest=$2
file_type=$3
mode=$4


echo source "=" $source
echo dest "=" $dest
echo file_type "=" $file_type



#files=`find $source -name "$3"`


#files=`find /Users/james/Downloads/bill_cloud/1061_backup_201911/ -name "T630*"`
echo $files;

#tmp="/Users/james/Downloads/bill_cloud/1061_backup_201911/2019113008/T90_B201911_tNGN_GO_010_1061_topic_172_P1_O5074398800_o105"
#gawk 'BEGIN{FS="^"} {print $2}' $tmp
#
#拷贝文件加目录到目标文件夹下面
echo $file_type

for flow in '61' '54' '41' '46' '47' '48' '49' '37'; do
    grep_typ=10${flow}_backup_2019\\\(09\\\|10\\\|11\\\)

    files_all=`find $source -name $file_type|grep $grep_typ`
#    echo $files_all

    for file_item in $files_all ; do
       tar -cpf - $file_item|tar -xpf - -C  $dest
    done

    files=`find $dest -name "$file_type"|grep -v ".bak\$"`
    for file in $files ; do
        echo $file | xargs gawk 'BEGIN{FS="^"} {if (match($13, "^124[1-3]") ) print $0 > file}' file="$file.bak"
        rm $file
    done

done



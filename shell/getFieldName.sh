#!/usr/bin/env bash

 mysql -h 10.142.234.129 -P 9018 -u roam -pJTsmSQL@19 -Droam_data < ./getAllTablesStruct.sql > tableStruct.txt

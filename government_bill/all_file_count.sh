#!/usr/bin/env bash

file_dir=`ls -lh /Users/james/Documents/MVNO_COMM2|awk '{ print $9 }'`

for line in  $file_dir
do
    cd /Users/james/Documents/MVNO_COMM2
    wc -l ./$line/*/*.csv >> /Users/james/jameswork/james_clion/testpoco/government_bill/result.txt
#    find /Users/james/Documents/MVNO_COMM2/$
done
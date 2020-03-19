#!/usr/bin/env bash

file='/Users/james/Documents/tmp.result'

awk -F ' ' '{ split($2,a,"."); print $1" "$2" "a[1]*256*256*256+a[2]*256*256+a[3]*256+a[4]}' $file > result.txt

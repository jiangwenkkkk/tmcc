#!/usr/bin/env bash

tables=`find /Users/james/Documents/turn_sell/tmp/COMM -name "*.csv"`
tables=`find /Users/james/Documents/turn_sell/tmp/COMM -name "*b_info_product_offer.csv"`
echo $tables
for table in $tables
do
echo $table
cp $table /Users/james/Documents/turn_sell/tmp/sr
done


tables=`ll /Users/james/Documents/turn_sell/tmp/sr`

for table in $tables
do
sed "" $table
done

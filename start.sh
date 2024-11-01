#!/bin/bash

###   root -l -b -q 'histo_new.C("2024-06-20_16-11-53",0)'

indirs=()

count=0
while read str
do
        count=$[ count + 1 ]
        indirs+=($str)
        echo "Line contents are : $str "
done < runs_list_ch2_t50_scan2.dat
echo "count: $count "

list=( 0 )

for (( i = 0; i < $count; i++ ))
do
	for n in ${list[@]}
	do
		root -l -b -q 'histo_new.C("'${indirs[i]}'",'${n}')'
	done
done

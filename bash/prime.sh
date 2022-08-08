#!/bin/bash

read -p "Enter start (2-X): " start
read -p "Enter end (2-X): " end

if [ $start -gt 1 ]
then
for ((i=$start;i<=$end;i++))
do
	flag=0
	for ((j=2;j<$i;j++))
	do
		if [ $(( $i%$j )) -eq 0 ]
		then
			flag=1
		fi
	done
	if [ $flag -eq 0 ]
	then
		echo "$i "
	fi
done
else
	echo "Invalid Input"
fi

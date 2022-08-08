#!/bin/bash
declare -a arr

read -p "Enter n>> " n

echo "Enter numbers one by one"

for (( i=0; i<n; i++ ))
do
	read arr[$i]
done

big=${arr[0]}

for (( i=1; i<n; i++ ))
do
	if [ ${arr[$i]} -gt $big ]
	then
		big=${arr[$i]}
	fi
done

echo "Largest number is : $big"
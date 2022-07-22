#!/bin/bash
echo "Enter the strings one by one"
read str1
read str2
if [[ "$str1" == "$str2" ]]
then
echo "$str1 is equal to $str2"
else if [ "$str1" \> "$str2" ]
then
echo "$str1 is greater than $str2"
else
echo "$str2 is greater than $str1"
fi
fi
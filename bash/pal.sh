#!/bin/bash

echo "Enter the string to check it's palindrome or not"
read str1
length=${#str1}
for((i=$length-1;i>=0;i--))
do
	str2="$str2${str1:$i:1}"
done


if [ $str1 == $str2 ]
then
 	echo "$str1 is a palindrome"
else 
	echo "$str1 is not a palindrome"
fi
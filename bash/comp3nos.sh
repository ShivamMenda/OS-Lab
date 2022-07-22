#!/bin/bash
echo "Enter num 1"
read num1
echo "Enter num 2"
read num2
echo "Enter num 3"
read num3

if [ $num1 -gt $num2 ]
then
    if [ $num1 -gt $num3 ]
    then
    echo "$num1 is the greatest num"
    else
    echo "$num3 is the greatest num"
    fi
else
if [ $num2 -gt $num1 ]
then
    if [ $num2 -gt $num3 ]
    then
    echo "$num2 is the greatest num"
    else
    echo "$num3 is the greatest num"
    fi
fi
fi

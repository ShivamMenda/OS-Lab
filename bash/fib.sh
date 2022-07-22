#!/bin/bash
n1=0
n2=1
echo "Enter the no of terms"
read n
echo "The first $n elements of fib series"
echo
echo $n1
echo $n2
for (( i=2;i<$n;i++ ))
do
    n3=$((n1+n2))
    echo $n3
    n1=$n2
    n2=$n3
done


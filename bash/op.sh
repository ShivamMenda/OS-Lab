echo "Enter numbers"
echo "Enter a"
read a
echo "Enter b"
read b
echo "--OPS--"
echo "1.ADD"
echo "2.SUB"
echo "3.MUL"
echo "4.DIV"
echo "5.EXIT"

echo "Enter choice"
read n

case $n in
1)echo "The sum is $(($a + $b))" ;;
2)echo "The diff is $(($a - $b))" ;;
3)echo "The mul is $(($a * $b))" ;;
4)echo "The sum is $(($a / $b))" ;;
5)echo "Exit"
break;;
esac

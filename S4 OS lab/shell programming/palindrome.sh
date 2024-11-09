echo "Enter a num:"
set -f
read num1
temp=$num1
num2=0
t=0
while [ $temp != 0 ]
do
	t=`expr $temp % 10`
	num2=`expr $num2 + $t`
	num2=`expr $num2 * 10`
	temp=`expr $temp / 10`
done
num2=`expr $num2 / 10`
if [ $num1 == $num2 ]
then
echo "Is a palindrome"
else
echo "not a palindrome"
fi

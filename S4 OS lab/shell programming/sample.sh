echo "Enter a value"
read a
if [ $a -ge 10 ] 
then 
echo "greater than 10"
else
echo "less than 10"
fi
while [ $a != 0 ]
do 
echo $a
a=`expr $a - 1`
done

echo "enter  case"
read a
case $a in 
1) echo 1
   ;;
2) echo 2
   ;;
3) echo 3
   ;;
*) echo invalid
   ;;
esac






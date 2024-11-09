echo "Enter a num"
read a
i=2
l=`expr $a / 2`
while [ $i -le $l ]
	do
	r=`expr $a % $i`
	if [ $r == 0 ]
		then 
		echo "non prime"
		exit
	fi
	i=`expr $i + 1`
	done
echo "prime"


echo enter the limit
read limit
term1=1
term2=1
i=0
while [ $i -le $limit ] 
	do
	echo $term1
	temp=$term1
	term1=$term2
	term2=`expr $term2 + $temp`
	i=`expr $i + 1`
done
echo finished
exit

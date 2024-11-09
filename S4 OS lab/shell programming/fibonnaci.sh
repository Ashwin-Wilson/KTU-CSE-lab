 echo "Ente a num"
 read a 
 temp=0
 term=1
 s=0
 count=0
 echo fibonnaci
 while [ $a != $count ]
	 do
	 echo $term
	 s=`expr $term + $temp`
	 temp=$term
	 term=$s
	 count=`expr $count + 1`
 done


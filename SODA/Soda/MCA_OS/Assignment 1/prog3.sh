while true
do
	echo "Enter a five number digit - "
	read num
	len=`expr length "$num"`
	if [ $len -eq 5 ]
	then
		sum=0
		while [ $num -gt 0 ]
		do
		r=`expr $num % 10`
		sum=`expr $sum + $r`
		num=`expr $num / 10`
		done
		echo "the sum $sum"
		break
	else
		echo "Please enter 5 digit number only!!!"
	fi
done

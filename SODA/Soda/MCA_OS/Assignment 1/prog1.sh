while true
do
	echo "Enter the length of the Rectangle - "
	read l
	echo $l | grep "^[0-9]*$"
	val=`echo $?`
	if [ $val -ne 0 ]
	then
		echo "Not a number!!! Enter number only"
		continue
	fi
	echo "Enter the breadth of the Rectangle - "
	read b
	echo $b | grep "^[0-9]*$"
	val=`echo $?`
	if [ $val -ne 0 ]
	then
		echo "Not a number!!! Enter number only"
		continue
	fi
	area=`expr $l \* $b`
	echo "The area of the Rectangle - $area"
	p=`expr $l + $b`
	perimeter=`expr $p \* 2`
	echo "The perimeter of the Rectangle - $perimeter"
	break
done

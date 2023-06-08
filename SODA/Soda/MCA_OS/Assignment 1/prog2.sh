while true
do
echo "Enter basic monthly salary of an employee- "
read s
echo "$s" | grep "^[0-9]*$"
val=`echo $?`
if [ $val -eq 0 ]
then
		da1=`expr $s \* 42`
		da=`expr $da1 / 100`

		it1=`expr $s \* 20`
		it=`expr $it1 / 100`

		pf1=`expr $s \* 8`
		pf=`expr $pf1 / 100`

		netsalary1=`expr $s + $da`
		netsalary2=`expr $netsalary1 - $it`
		netsalary3=`expr $netsalary2 - $pf`
		echo "The net salary : $netsalary3"
		break
else
        echo "Invalid input...Enter integer only!!!"
fi
done

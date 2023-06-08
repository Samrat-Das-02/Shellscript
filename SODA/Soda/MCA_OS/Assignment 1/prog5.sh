while [ 1 ]
do
echo "Enter User name"
read name
check=0
while read line
do
usname=`echo $line | cut -f 1 -d ":"` 
	if [ "$usname" = "$name" ]
	then
		echo "Username - $usname"
		usid=`echo $line | cut -f 3 -d ":"` 
		echo "User Id - $usid"
		grpid=`echo $line | cut -f 4 -d ":"` 
		echo "Group Id - $grpid"
		usidinf=`echo $line | cut -f 5 -d ":"`
		user1=`echo "$usidinf" | cut -f 1 -d ","` 
		echo "User Id Information - $user1"
		hd=`echo $line | cut -f 6 -d ":"` 
		echo "Home Details - $hd"
		logs=`echo $line | cut -f 7 -d ":"` 
		echo "Login Shell- $logs"
		check=`expr $check + 1`
	fi
done < /etc/passwd
if [ $check -eq 0 ]
then
	echo "The user does not exist"
else
	break
fi
done

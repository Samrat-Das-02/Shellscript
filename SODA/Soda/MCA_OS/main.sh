while true
do
echo "--------------"
echo "1.Assignment 1"
echo "2.Assignment 2"
echo "3.Assignment 3"
echo "4.Assignment 4"
echo "5.Exit"
echo "--------------"

echo -n "Enter option::"
read option

if [ $option = 1 ]
then 
	echo "You are in assignment 1"
	cd ./Assignment\ 1
	files=`ls -l | awk '{print $9}'`
	no=1	
	for file in $files
	do
		echo $no". "$file
		no=$(( no + 1 ))
	done
	echo "--------------"
	echo -n "Enter choice::"
	read choice
	if [ $choice = 1 ]
	then
		sh prog1.sh
	elif [ $choice = 2 ]
	then
		sh prog2.sh
	elif [ $choice = 3 ]
	then
		sh prog3.sh
	elif [ $choice = 4 ]
	then
		sh prog4.sh
	elif [ $choice = 5 ]
	then
		sh prog5.sh
	else
		echo "Wrong Choice!!!"
	fi
elif [ $option = 2 ]
then
	echo "You are in assignment 2"
	cd ./Assignment\ 2
	files=`ls -l | awk '{print $9}'`
	no=1
	for file in $files
	do
		echo $no". "$file
		no=$(( no + 1 ))
	done
	echo "--------------"
	echo -n "Enter choice::"
	read choice
	if [ $choice = 1 ]
	then
		sh prog1.sh
	elif [ $choice = 2 ]
	then
		sh prog2.sh
	elif [ $choice = 3 ]
	then
		sh prog3.sh
	elif [ $choice = 4 ]
	then
		sh prog4.sh
	elif [ $choice = 5 ]
	then
		sh prog5.sh
	else
		echo "Wrong Choice!!!"
	fi
elif [ $option = 3 ]
then
	echo "You are in assignment 3"
	cd ./Assignment\ 3
	files=`ls -l | awk '{print $9}'`
	no=1
	for file in $files
	do
		echo $no". "$file
		no=$(( no + 1 ))
	done
	echo "--------------"
	echo -n "Enter choice::"
	read choice
	if [ $choice = 1 ]
	then
		sh prog1.sh
	elif [ $choice = 2 ]
	then
		sh prog2.sh
	elif [ $choice = 3 ]
	then
		sh prog3.sh
	elif [ $choice = 4 ]
	then
		sh prog4.sh
	elif [ $choice = 5 ]
	then
		sh prog5.sh
	else
		echo "Wrong Choice!!!"
	fi
elif [ $option = 4 ]
then
	echo "You are in assignment 4"
	cd ./Assignment\ 4
	files=`ls -l | awk '{print $9}'`
	no=1
	for file in $files
	do
		echo $no". "$file
		no=$(( no + 1 ))
	done
	echo "--------------"
	echo -n "Enter choice::"
	read choice
	if [ $choice = 1 ]
	then
		 ./prog1
	elif [ $choice = 2 ]
	then
		./prog2
	elif [ $choice = 3 ]
	then
		./prog3
	elif [ $choice = 4 ]
	then
		./prog4
	else
		echo "Wrong Choice!!!"
	fi
elif [ $option = 5 ]
then
	exit
else
	echo "Invalid choice"
fi
cd ..
done


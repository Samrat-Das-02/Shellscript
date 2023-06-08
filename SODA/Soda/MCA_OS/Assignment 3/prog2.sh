count=0
echo "Files that are present in the current directory::"
for file in *
do
	echo -n $file " "
	count=$(( count +1 ))
done
echo "\nTotal count of files and directory is $count"
for file in *
do
    if [ -f $file ]
    then
        echo "$file is a regular file"
    elif [ -d $file ]
    then
        echo "$file is a directory"
    fi
done

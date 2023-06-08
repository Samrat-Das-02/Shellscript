for file in `ls`
do
    if [ -f $file ]
    then
        echo "$file is a regular file"
    elif [ -d $file ]
    then
        echo "$file is a directory"
    fi
done

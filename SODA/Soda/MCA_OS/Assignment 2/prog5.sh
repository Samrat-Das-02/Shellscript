while true
do
	echo "Enter directory name::"
	read i

	if [ -d $i ]
	then
			echo "Disk Space occupied by the directory $i"
			bytes=`du -bs $i | cut -f1`
			echo "Size in byte $bytes"
			kilobytes=`du -sk $i | cut -f1`
			echo "Size in kilobyte $kilobytes KB"
			megabytes=`du -sm $i | cut -f1`
			echo "Size in megabyte $megabytes MB"
			break;
	else
			echo "Please enter a valid directory"
	fi
done 

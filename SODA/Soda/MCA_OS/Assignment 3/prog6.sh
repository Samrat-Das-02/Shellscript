count=0
files=`ls *.sh`
for file in $files
do
	count=$(( count + 1 ))
done
echo "Total number of shell scripts is::$count"

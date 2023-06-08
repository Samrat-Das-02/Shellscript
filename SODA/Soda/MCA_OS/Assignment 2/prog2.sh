#paths=`echo $PATH`
IFS=:
#set $paths
for path in $PATH
do
	echo "Directory name-->$path"
	permission=`ls -ld $path | cut -d" " -f1`
	echo "permission:: $permission "
	echo -n "modification time:: "
	ls -ld $path | cut -d" " -f8
	echo ""
done

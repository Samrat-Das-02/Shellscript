echo "BEFORE"
ls
find . -name '~*' -type f -delete
echo "AFTER removing temporary files"
ls

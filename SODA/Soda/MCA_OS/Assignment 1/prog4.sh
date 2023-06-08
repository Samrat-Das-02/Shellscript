echo "Enter a five number digit - "
read num
sum=0
while [ $num -gt 0 ]
do
r=`expr $num % 10`
t=`expr $sum \* 10`
sum=`expr $t + $r`
num=`expr $num / 10`
done
echo "the sum $sum"

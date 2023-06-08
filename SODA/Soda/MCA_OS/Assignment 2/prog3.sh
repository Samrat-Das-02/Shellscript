vendor_id=`grep -m 1 'vendor_id' /proc/cpuinfo`

model_name=`grep -m 1 'model name' /proc/cpuinfo`

cpu_MHz=`grep -m 1 'cpu MHz' /proc/cpuinfo`

cache_size=`grep -m 1 'cache size' /proc/cpuinfo`


echo "CPU information-->"

echo "$vendor_id"
echo "$model_name"
echo "$cpu_MHz"
echo "$cache_size"


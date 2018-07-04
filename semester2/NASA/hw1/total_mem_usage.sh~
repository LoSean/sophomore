#!/usr/bin/env bash
#total memory usage of a whole grade
#2016/3/3

if [ "$1" == "" ]; then
	echo usage : ./total_mem_usage.sh grade
	exit 1
fi

grade=$1
vsz=0

#create tmp file
#tmpfile=$(mktemp total_mem.XXXXXX)

IFS=$'\n'
#show complete information for each process
line=( $(ps -aux | grep "^$grade") ) 
unset IFS

i=0
while [ "${line[i]}" != "" ]; do
#	echo ${line[i]}
	set -- ${line[i]}
	vsz=$(($vsz + $5))
	i=$(($i + 1))
done

#while read line; do
	#cut string into short segments
#	set -- $line
	#only output the first 3 characters
#	if [ $(echo $1 | cut -c1-3) = $grade ]; then
#		vsz=$(($vsz + $5))
#	fi
#done < $tmpfile

#rm $tmpfile

echo $vsz

exit 0

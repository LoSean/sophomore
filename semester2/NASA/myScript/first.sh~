#!/bin/bash 
#	hello world !
#	2016/2/2

rightNow=$(date +"%x %r %Z")

echo "hello world !!"
echo "host name: $HOSTNAME"
echo "current time: $rightNow"
echo -n "please enter a file name :"
i=4
read -s -t 3 file
while [ ! -f "$file" ] && [ $i -gt 0 ]; do
	echo -e "\a$file does not exist"
	echo "you still have chances $i"
	echo -n "please enter a file name :"
	read -s -t 3 file
	i=$((i-1))
done
if [ -f "$file" ]; then
	echo "file name: $file"
	for j in $(cat $file); do
		echo $j
	done
fi

echo -e "================\n$0"
echo "$1" 1>&2
exit 0

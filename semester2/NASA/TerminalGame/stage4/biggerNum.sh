#!/usr/bin/env bash

i=1

while [ $i -le $3 ] && read num1 ; do
	i=$(($i+1))
done < $1

i=1

while [ $i -le $3 ] && read num2 ; do
	i=$(($i+1))	
done < $2

if [ $num1 -gt $num2 ]; then
	echo $num1
else
	echo $num2
fi

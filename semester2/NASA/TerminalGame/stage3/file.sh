#!/usr/bin/env bash

i=1

while [ $i -le 100  ]; do
	if [ $(($i % 2)) -eq 1 ]; then
		echo $i > $i
	else
		echo $(($i * 2)) > $i
	fi
	i=$(($i+1))
done



#!/bin/sh

if [ "$1" != "add" ] && [ "$1" != "del" ] || [ "$2" = "" ]; then
	echo "usage: ./macFilter.sh [add|del] \$mac_address"
fi

#if ! echo "$1" | grep -q '^[0-9][0-9]:[0-9][0-9]:[0-9][0-9]:[0-9][0-9]:[0-9][0-9]:[0-9][0-9]$'; then
#	echo "1"
#	exit 0
#fi

if [ "$1" = "add" ]; then
	wl -i wl0.1 mac $1
elif [ "$1" = "del" ]; then
	touch tmp
	for i in $(wl -i wl0.1 mac)
	do
		if [ "$i" != "mac" ] && [ "$i" != "$2" ]; then
			echo "$i " >> tmp
		fi
	done
	wl -i wl0.1 mac none
	for i in $(cat tmp)
	do
		wl -i wl0.1 mac $i
	done
	rm tmp
fi

echo "0"
exit 0

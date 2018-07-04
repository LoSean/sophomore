#!/bin/sh

for i in $(ps aux | cut -c1-3 | sort | uniq | grep "^[a-z][0-9][0-9]"); do
	echo -n "$i "
	./total_mem_usage.sh $i
done

exit 0

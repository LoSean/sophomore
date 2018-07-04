#!/usr/bin/env bash

for ((i = 1; i <= 100; i++)) ; do
	rm $i
done

rm *~

exit 0

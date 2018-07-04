#!/usr/bin/env bash
#2016/3/19
#lvm resize

fsck -f /dev/nasavg/home_ta
resize2fs /dev/nasavg/home_ta 100G
echo "y" | lvresize -L -100GiB /dev/nasavg/home_ta
resize2fs /dev/nasavg/home_ta

fsck -f /dev/nasavg/home_student
lvresize -l +100%Free /dev/nasavg/home_student
resize2fs /dev/nasavg/home_student

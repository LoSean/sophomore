#!/usr/bin/env bash
#2016/3/17
#hard disk partition and lvm

parted --script -a optimal /dev/sda \
	mklabel gpt \
	mkpart primary 0% 200GiB \
	mkpart primary 200GiB 100% \
	set 2 lvm on \
	print
mkfs -t vfat /dev/sda1

pvcreate /dev/sda2 /dev/sdb 
vgcreate nasavg /dev/sda2 /dev/sdb
lvcreate -L 300GiB -n home_student nasavg
lvcreate -l 100%Free -n home_ta nasavg
mkfs -t ext4 /dev/nasavg/home_student
mkfs -t ext4 /dev/nasavg/home_ta


#clean the first 1049kByte
#dd if=/dev/zero of=/dev/sdx bs=1 count=1049KB

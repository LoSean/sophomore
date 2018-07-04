#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage long sys_min(long num1, long num2){
	printk("min system call!\n");
	return (num1<num2)?num1:num2;
}

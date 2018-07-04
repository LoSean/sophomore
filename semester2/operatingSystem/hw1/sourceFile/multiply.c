#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage long sys_multiply(long num1, long num2){
	printk("multiply system call!\n");
	return (num1*num2);
}

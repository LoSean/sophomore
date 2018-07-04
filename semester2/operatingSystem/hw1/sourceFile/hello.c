#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage long sys_hello(void){
	printk("hello system call!\n");
	return 0;
}

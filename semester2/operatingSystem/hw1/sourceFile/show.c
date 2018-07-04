#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage sys_show(void){
	printk("(1)\nstudentID:b03902001\nName:Ting-Hsuan Lo\n");
	printk("(2)\nstudentID:b03902027\nName:Guan-Jun Wang\n");
	return 0;
}

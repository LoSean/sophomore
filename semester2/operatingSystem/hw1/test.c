#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
	/* system call hello */
	syscall(349);
	/* system call show studentID/Name */
	syscall(350);
	/* system call multiply */
	printf("%ld\n", syscall(351, 10, 3));
	/* system call min */
	printf("%ld\n", syscall(352, 314, 159));
	return 0;
}

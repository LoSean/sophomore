#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sched.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#define THREADNUM 2

void setCpuAffinity(void){
	cpu_set_t mask;
/*to initialise the mask*/
	CPU_ZERO((void *)&mask);
/*to run on specific cpu*/
	CPU_SET(0, &mask);
/*set affinity; the first parameter is the pid (zero for the current process)*/
	if (sched_setaffinity(0, sizeof(mask), &mask) != 0){
		perror("fail to set affinity\n");
		exit(1);
	}
	return;
}

void *work(void *threadId){
/*	struct timeval t0, t1;
	float elapsed;	
	int count = 0;
	
	gettimeofday(&t0, 0);
	gettimeofday(&t1, 0);
	while(timedifference_msec(t0, t1) <= 500){
		gettimeofday(&t1, 0);
		count++;
		if (count % 50 == 0)
*/	
	int i;
	clock_t t1, t2;
	t1 = t2 = clock();	
	while((t2-t1)/(double)(CLOCKS_PER_SEC) <= 0.5){	
		i++;
		t2 = clock();
		if ((t2-t1)/(double)(CLOCKS_PER_SEC) >= 0.5)
			break;
		if (i % 100000 == 0)
			fprintf(stderr, "Thread %d is running.\n", *((int *)threadId));
		t2 = clock();
	}
	printf("time = %lf\n", (t2-t1)/(double)(CLOCKS_PER_SEC));
//	}
	pthread_exit(0);
}

int main(int argc, char* argv[]){
	struct sched_param param;
	setCpuAffinity();
	if (argc >= 2 && strcmp(argv[1], "SCHED_FIFO") == 0) {
		param.sched_priority = sched_get_priority_max(SCHED_FIFO);
		if (param.sched_priority == -1) {
			fprintf(stderr, "fall to set priority\n");
			exit(1);
		}
		/*(pid, schedule policy, const struct sched_param)*/
		if (sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1){
			fprintf(stderr, "fail to set scheduler\n");
			exit(1);
		}
	}

	pthread_t threads[THREADNUM];
	int threadId[THREADNUM];
	int i;
	for (i = 0; i < THREADNUM; i++){
		threadId[i] = i;
		if (pthread_create(&threads[i], NULL, work, (void *)&threadId[i]) != 0) {
			perror("fail to create threads\n");
			exit(1);
		}
		printf("Thread %d was created.\n", i);
	}
	for (i = 0; i < THREADNUM; i++){
		pthread_join(threads[i], NULL);
	}
	return 0;
}

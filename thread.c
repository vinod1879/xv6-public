
#include "types.h"
#include "thread.h"

int thread_create(void (*func)(void), void (*arg))
{
	int tid;
	void *stack = malloc(1024);
  
  	tid = clone(stack, 1024);

	if (tid == 0) {
		func();
		printf(1, "Freeing stack\n");
    	free(stack);
    	printf(1, "Exiting\n");
    	exit();
	}
	return tid;
}

int thread_id(void)
{
	return 0;
}

void thread_exit(void)
{
	return;
}

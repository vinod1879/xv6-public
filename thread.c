
#include "types.h"
#include "thread.h"

int thread_create(void (*func)(void), void (*arg))
{
	int tid;
	void *stack = malloc(4096);
  
  	tid = clone2(func, arg, stack);

	return tid;
}

int thread_wait(void) {
	return wait();
}

int thread_id(void)
{
	return 0;
}

void thread_exit(void)
{
	exit();
}

/*void thread_int(struct lock_t lock) {
	lock = 0;
}

void thread_acquire(struct lock_t lock) {

}*/

#include "types.h"
#include "user.h"
#include "thread.h"
#include "x86.h"

int thread_create(void (*func)(), void (*arg))
{
	int tid;
	void *stack = malloc(4096);
  
  	tid = clone2(func, arg, stack);

	return tid;
}

int thread_wait(void) {
	return join();
}

int thread_id(void)
{
	return gettid();
}

void lock_init(struct lock_t *tlock) {
	tlock->lock = 0;
}

void thread_lock(struct lock_t *tlock) {
	 while(xchg(&tlock->lock, 1) != 0)
      ;
}

void thread_unlock(struct lock_t *tlock) {
	xchg(&tlock->lock, 0);
}

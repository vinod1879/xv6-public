
#include "types.h"
#include "user.h"
#include "thread.h"

int thread_create(void (*func)(), void (*arg))
{
	int tid;
	void *stack = malloc(4096);

    tid = clone2(func, arg, stack);

	return tid;
}

int thread_wait(void) {
    void *stack;

	int tid = join(&stack);

    if (stack)
        free(stack);

    return tid;
}

int thread_id(void)
{
	return gettid();
}

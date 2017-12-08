#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

struct lock_t tlock;
int count = 0;
// TEST CODE TAKEN FROM:
// http://pages.cs.wisc.edu/~cs537-3/Projects/threads.c

void print_numbers(int);
void print_strings(char *str);

int 
main() {

    int tid,i;
    int arg = 12;
    lock_init(&tlock);
    for (i = 0; i < 1000; i++) {
        tid = thread_create(&print_numbers, (void*)arg);
        thread_wait();
        printf(2, "Thread Finished: %d\n", tid);
    }

	exit();
	return 0;
}

void 
print_numbers(int i) 
{
    int j = 0;
    while (j < i) {
        thread_lock(&tlock);
        count++;
        printf(1, "Hello I am thread %d incremented %d\n",thread_id(), count);
        thread_unlock(&tlock);
        j += 1;
    }

    exit();
}



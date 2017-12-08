#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

// TEST CODE TAKEN FROM:
// http://pages.cs.wisc.edu/~cs537-3/Projects/threads.c
// int stack[4096] __attribute__ ((aligned (4096)));
// int x = 0;

// int main(int argc, char *argv[]) {
//   printf(1, "Stack is at %p\n", stack);
//   // int tid = fork();
//   int tid = clone(stack, 4096);

//   if (tid < 0) {
//     printf(2, "error!\n");
//   } else if (tid == 0) {
//     // child
//     for(;;) {
//       x++;
//       sleep(100);
//     }
//   } else {
//     // parent
//     for(;;) {
//       printf(1, "x = %d\n", x);
//       sleep(100);
//     }
//   }

//   exit();
// }


void print_numbers(int);
void print_strings(char *str);

int 
main() {

	int tid, i;
    int arg = 12;
    //char *arg3 = "H2G2";

    for (i = 0; i < 10; i++) {
        tid = thread_create(&print_numbers, (void*)arg);

        thread_wait();
        printf(1, "Thread Finished: %d\n", tid);
    }

	exit();
	return 0;
}

void 
print_numbers(int i) 
{
    int j = 0;

    while (j < i) {
        int me = thread_id();
        printf(1, "Hello I am thread %d saying %d\n", me, j);
        sleep(10);
        j += 1;
    }
    
    exit();
}

void 
print_strings(char *str) 
{
    printf(1, "%s\n", str);
    exit();
}

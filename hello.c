#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.c"

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

	int tid1, tid2, tid3;
    int arg = 42;
    int arg2 = 50;
    char *arg3 = "H2G2";

	tid1 = thread_create(&print_numbers, (void*)arg);

    tid2 = thread_create(&print_numbers, (void*)arg2);

    tid3 = thread_create(&print_strings, (void*)arg3);

	printf(1, "Hello world: %d\n", tid1);

    printf(1, "Hello world: %d\n", tid2);

    printf(1, "Hello world: %d\n", tid3);

    tid1 = thread_wait();
    tid2 = thread_wait();
    tid3 = thread_wait();

	exit();
	return 0;
}

void 
print_numbers(int i) 
{
	printf(1, "%d\n", i);
    exit();
}

void 
print_strings(char *str) 
{
    printf(1, "%s\n", str);
    exit();
}

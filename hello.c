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


void print_numbers();

int 
main() {

	int tid = 10;

	tid = thread_create(&print_numbers, 0);
	printf(1, "Hello world: %d\n", tid);

	tid = thread_wait();

	exit();
	return 0;
}

void 
print_numbers(void) 
{
	int i = 42;
	printf(1, "%d\n", i);
    exit();
}

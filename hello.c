#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.c"

void print_numbers();

int 
main() {

	int tid;

	tid = thread_create(&print_numbers, 0);
	printf(1, "Hello world: %d\n", tid);

	exit();
	return 0;
}

void 
print_numbers(void) 
{
	int i = 42;
	printf(1, "%d", i);
}

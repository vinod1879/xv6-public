
#ifndef THREAD_H
#define THREAD_H

int thread_create(void (*func)(), void (*arg));
int thread_id(void);
void thread_exit(void);
int thread_wait(void);

#endif // THREAD_H


#ifndef THREAD_H
#define THREAD_H

struct lock_t {
    uint lock;
};
int thread_create(void (*func)(), void (*arg));
int thread_id(void);
void thread_exit(void);
int thread_wait(void);
void lock_init(struct lock_t *);
void thread_lock(struct lock_t *);
void thread_unlock(struct lock_t *);

#endif // THREAD_H

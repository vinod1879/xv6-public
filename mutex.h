
#ifndef MUTEX_H
#define MUTEX_H

struct lock_t {
    uint lock;
};

struct mutex_t {
  struct lock_t lock;
  int owner;
  int value;
};

void lock_init(struct lock_t *);
void thread_lock(struct lock_t *);
void thread_unlock(struct lock_t *);

int mutex_init(struct mutex_t *mutex);
int mutex_lock(struct mutex_t *mutex);
int mutex_unlock(struct mutex_t *mutex);

#endif // MUTEX_H

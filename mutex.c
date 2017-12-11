
#include "types.h"
#include "user.h"
#include "stat.h"
#include "mutex.h"
#include "x86.h"


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

int 
mutex_init(struct mutex_t *mutex) 
{
    lock_init(&mutex->lock);
    thread_lock(&mutex->lock);
    
    if (mutex->value == 0) {

        mutex->owner = getpid();
        thread_unlock(&mutex->lock);
        return 0;
    }

    thread_unlock(&mutex->lock);
    return -1;
}

int
mutex_lock(struct mutex_t *mutex) {

    int pid = getpid();
    thread_lock(&mutex->lock);
  
    if (mutex->owner == pid) {

        mutex->value += 1;
    }
    else {
        while(mutex->value > 0) {
          sleep(1);
        }
    }

    thread_unlock(&mutex->lock);
    return 0;
}

int
mutex_unlock(struct mutex_t *mutex) {
    int pid = getpid();
    thread_lock(&mutex->lock);
  
    if (mutex->owner == pid) {

        mutex->value -= 1;

        if (mutex->value == 0) {
            mutex->owner = 0;
        }
    }
    
    thread_unlock(&mutex->lock);
    return 0;
}

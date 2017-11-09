#ifndef LOCK_H
#define LOCK_H

#include "threads/semaphore.h"

/* Lock */
struct lock {
    struct thread *holder; /* Thread holding lock (for debugging) */
    struct semaphore semaphore; /* Binary semaphore controlling access */
    
    /*Added */
    struct list_elem elem;
    int largest_priority;
    /*End Added */
};

void lock_init(struct lock *);
void lock_acquire(struct lock *);
bool lock_try_acquire(struct lock *);
void lock_release(struct lock *);
bool lock_held_by_current_thread(const struct lock *);
bool locks_compare(const struct list_elem *, const struct list_elem *, void *);

#endif /* UCSC CMPS111 */

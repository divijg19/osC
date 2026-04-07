#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
sem_t chopstick[N];

void *philosopher(void *num) {
  int i = *(int *)num;

  sem_wait(&chopstick[i]);
  sem_wait(&chopstick[(i + 1) % N]);

  printf("Philosopher %d Eating\n", i);

  sem_post(&chopstick[i]);
  sem_post(&chopstick[(i + 1) % N]);
}

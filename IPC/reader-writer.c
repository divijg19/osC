#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

int readcount = 0;
sem_t mutex, wrt;

void *reader(void *r) {
  sem_wait(&mutex);
  readcount++;
  if (readcount == 1)
    sem_wait(&wrt);
  sem_post(&mutex);

  printf("Reading...\n");

  sem_wait(&mutex);
  readcount--;
  if (readcount == 0)
    sem_post(&wrt);
  sem_post(&mutex);
}

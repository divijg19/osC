#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define SIZE 5

int buffer[SIZE], in = 0, out = 0;
sem_t empty, full, mutex;

void *producer(void *p) {
  int item;
  for (int i = 0; i < 10; i++) {
    item = i;
    sem_wait(&empty);
    sem_wait(&mutex);

    buffer[in] = item;
    printf("Produced: %d\n", item);
    in = (in + 1) % SIZE;

    sem_post(&mutex);
    sem_post(&full);
  }
  return 0;
}

void *consumer(void *c) {
  int item;
  for (int i = 0; i < 10; i++) {
    sem_wait(&full);
    sem_wait(&mutex);

    item = buffer[out];
    printf("Consumed: %d\n", item);
    out = (out + 1) % SIZE;

    sem_post(&mutex);
    sem_post(&empty);
  }
  return 0;
}

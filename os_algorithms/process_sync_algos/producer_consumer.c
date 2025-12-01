#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

// sem_t is the data type for semaphores


#define BUFFER_SIZE 10 // define the buffer size

// shared buffer
int buffer[BUFFER_SIZE];    //initialize buffer array
int in = 0, out = 0;        // declare two variable in & out

// Semaphores
sem_t mutex; // binary semaphore mutual exclusion 
sem_t empty; // counts empty slots
sem_t full;  // counts filled slots

void *producer(void *arg) {
    int item;

    while(1) {
        item = rand() % 100; // produce an item

        sem_wait(&empty); // Is there an empty slot? If yes, take it. If no, wait.
        sem_wait(&mutex); 

        buffer[in] = item; // write to the empty slot
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full); // I just filled a slot, so empty count decreses

        sleep(1);
    }
}


void *consumer(void *arg) {
    int item;

    while(1) {
        sem_wait(&full); // wait for filled slot
        sem_wait(&mutex); // Enter critical section

        item = buffer[out]; // Read from the slot
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty); // I just emptied a slot, so empty count increases

        sleep(3);
    }
}

int main(){
    pthread_t prod, cons;

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}
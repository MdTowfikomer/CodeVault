#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Shared variables
sem_t mutex;     // Controls access to readcount
sem_t wrt;       // Controls writer access

int readcount = 0;
int data = 0;    // Shared data


void *reader(void *arg) {
    int id = *(int *)arg;          

    while (1) {
        sem_wait(&mutex);      // Lock readcount
        readcount++;
        if (readcount == 1) {
            sem_wait(&wrt);    // First reader blocks writers
        }
        sem_post(&mutex);      // Unlock readcount
        // ----- Reading section -----
        printf("Reader %d reads data = %d\n", id, data);
        // ----------------------------
        sem_wait(&mutex);
        readcount--;
        if (readcount == 0) {
            sem_post(&wrt);    // Last reader allows writers
        }
        sem_post(&mutex);

        sleep(1);
    }
}


void *writer(void *arg) {
    int id = *(int *)arg;  

    while (1) {
        sem_wait(&wrt);        // Exclusive access
        // ----- Writing section -----
        data++;
        printf("Writer %d writes data = %d\n", id, data);
        // ----------------------------
        sem_post(&wrt);

        sleep(1);
    }
}

int main() {
    pthread_t rtid[3], wtid[2];
    int r_id[3] = {1, 2, 3};
    int w_id[2] = {1, 2};

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader threads
    for (int i = 0; i < 3; i++)
        pthread_create(&rtid[i], NULL, reader, &r_id[i]);

    // Create writer threads
    for (int i = 0; i < 2; i++)
        pthread_create(&wtid[i], NULL, writer, &w_id[i]);

    // Join threads
    for (int i = 0; i < 3; i++)
        pthread_join(rtid[i], NULL);

    for (int i = 0; i < 2; i++)
        pthread_join(wtid[i], NULL);

    return 0;
}

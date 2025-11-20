#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;     // mutex for readcount, wrt for writer
int readcount = 0;    // number of readers
int data = 0;         // shared data

void *reader(void *arg) {
    int id = *(int *)arg;//-

    sem_wait(&mutex); //1
    readcount++; 
    if (readcount == 1)
        sem_wait(&wrt);   // first reader blocks writer
    sem_post(&mutex);

    printf("Reader %d is reading data = %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);   // last reader releases writer
    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;

    sem_wait(&wrt);       // writer waits
    data++;
    printf("Writer %d wrote data = %d\n", id, data);
    sleep(1);
    sem_post(&wrt);

    return NULL;
}

int main() {
    pthread_t r[5], w[5];
    int id[5];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < 5; i++) {
        id[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &id[i]);
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

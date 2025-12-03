#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5 
#define LEFT(i) (i)
#define RIGHT(i) ((i+1)%N)

sem_t mutex;
sem_t forks[N];

void* philosopher(void *arg){
    int id = *(int *)arg;

    while(1){
        printf("Philosopher %d is thinking\n", id);
        sleep(1);

        sem_wait(&mutex);

        sem_wait(&forks[LEFT(id)]);
        sem_wait(&forks[RIGHT(id)]);

        sem_post(&mutex);

        printf("Philosopher %d is eating\n", id);
        sleep(1);

        sem_post(&forks[LEFT(id)]);
        sem_post(&forks[RIGHT(id)]);

        printf("Philosopher %d is finished eating\n", id);
    }
}

int main(){
    pthread_t tid[N];
    int ids[N];

    sem_init(&mutex, 0, 1);

    for(int i =0 ; i < N; i++){
        sem_init(&forks[i], 0, 1);
    }

    for(int i= 0; i < N; i++){
        ids[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &ids[i]);
    }

    for(int i= 0; i < N; i++){
        pthread_join(tid[i], NULL);
    }

    return 0;
}
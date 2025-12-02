#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5           // Number of philosophers
#define LEFT(i)  (i)               // Left fork index
#define RIGHT(i) ((i + 1) % N)     // Right fork index

sem_t forks[N];       // Fork semaphores
sem_t mutex;          // Arbitrator to avoid deadlock

void *philosopher(void *arg) {
    int id = *(int *)arg;

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking\n", id);
        sleep(1);

        // Request permission to pick up forks
        sem_wait(&mutex);

        // Pick up left fork
        sem_wait(&forks[LEFT(id)]);
        // Pick up right fork
        sem_wait(&forks[RIGHT(id)]);

        sem_post(&mutex);  // Release permission

        // Eating
        printf("Philosopher %d is eating\n", id);
        sleep(1);

        // Put down forks
        sem_post(&forks[LEFT(id)]);
        sem_post(&forks[RIGHT(id)]);

        printf("Philosopher %d finished eating\n", id);
    }
}

int main() {
    pthread_t tid[N];
    int ids[N];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &ids[i]);
    }

    // Join threads
    for (int i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}

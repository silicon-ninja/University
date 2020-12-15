#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include <stdlib.h>

sem_t mutex;
sem_t db;
int rc=0,wc=0;

void *reader(int x) {
    int i = (int) x;
    sem_wait(&mutex);
    rc = rc + 1;
    if (rc == 1)
        sem_wait(&db);
    sem_post(&mutex);
    printf("Reader %d enters the system\n",i);
    sem_wait(&mutex);
    rc = rc - 1;
    if (rc == 0)
        sem_post(&db);
    sem_post(&mutex);
    printf("Reader %d leaves the system\n",i);
}

void *writer(int x) {
    int i = (int) x;
    sem_wait(&db);
    printf("Writer %d enters the system\n",i);
    sem_post(&db);
    printf("Writer %d leaves the system\n",i);
}

int main() {
    int n = 3;
    pthread_t read[n], write[n];
    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);
    for (int i = 0; i < n; i++){
        pthread_create(&write[i], NULL, writer, i + 1);
        pthread_create(&read[i], NULL, reader, i + 1);      
    }
    for (int i = 0; i < n; i++){
        pthread_join(write[i], NULL);
        pthread_join(read[i], NULL);
    }
}
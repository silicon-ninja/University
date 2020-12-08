// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t mutex; 

void* helloworld(void* arg) 
{ 
	sem_wait(&mutex); 
	printf("\nHello Srikanth......\n"); 
	printf("\nBye Srikanth.....\n"); 
	sem_post(&mutex); 
} 


int main() 
{ 
	sem_init(&mutex, 0, 1); 
	pthread_t t1,t2; 
	pthread_create(&t1,NULL,helloworld,NULL); 
	sleep(2); 
	pthread_create(&t2,NULL,helloworld,NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	sem_destroy(&mutex); 
	return 0; 
} 


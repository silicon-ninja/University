#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>
#include <string.h>
#include <semaphore.h> 
#include <unistd.h> 
// K Srikanth 17ETCS002124
pthread_t *producers;
pthread_t *consumers;
sem_t mutex,empty,full;
int *buf,buf_pos=-1,producer_count,consumer_count,buf_len;
int item_count=-1,total_items,consumed_item_count=-1;
int produce(pthread_t self){
	int i =0;
	int item = 1 + rand()%total_items;
	while(!pthread_equal(*(producers+i),self) && i<producer_count){
		i++;
	}
	printf("Producer %d Produced Item %d \n",i+1,item);
	return item;
}

void consume(int p,pthread_t self){
	int i =0,b;
	while(!pthread_equal(*(consumers+i),self) && i<consumer_count){
		i++;
	}
	b=i;
	printf("Buffer :");
	for ( i = 0; i <=buf_pos; ++i){
		printf("%d",*(buf+i));
	}
	printf("\n Consumer %d consumed item %d \n ",b+1,p);
	printf("Current buffer length is %d\n",buf_pos);
}

void *producer (void*args){
	while (item_count<total_items){
		int item = produce(pthread_self());
		sem_wait(&empty);
		sem_wait(&mutex);
		buf_pos++;
		*(buf + buf_pos) = item;
		++item_count;
		sem_post(&mutex);
		sem_post(&empty);
		sleep(1+rand()%3);
	}
	pthread_exit(NULL);
	return NULL;
}
void *consumer (void*args){
	int c;
	while (consumed_item_count<total_items){
		sem_wait(&full);
		sem_wait(&mutex);
		c = *(buf + buf_pos);
		consume(c,pthread_self());
		--buf_pos;
		++consumed_item_count;
		sem_post(&mutex);
		sem_post(&empty);
		sleep(1+rand()%3);
	}
	pthread_exit(NULL);
	return NULL;
}
int main(void){
	int i, error;
	srand(time(NULL));
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	printf("Home Many items to be produced ?");
	scanf("%d",&total_items);
	printf("Home Many number of producers ? : ");
	scanf("%d",&producer_count);
	producers = (pthread_t*) malloc(producer_count*sizeof(pthread_t));
	printf("Enter the Number of Consumers : ");
	scanf("%d",&consumer_count);
	consumers = (pthread_t*) malloc(consumer_count*sizeof(pthread_t));
	printf("Enter the Buffer Capacity : ");
	scanf("%d",&buf_len);
	buf = (int*) malloc (buf_len*sizeof(int));
	sem_init(&empty,0,buf_len);
	for ( i = 0; i < producer_count; i++){
		error = pthread_create(producers+i,NULL,&producer,NULL);
		if(error!=0){
			printf("\nError Creating Producer %d: %s\n",i+1,strerror(error));
		}else{
			printf("\nCreated Producer !! %d \n",i+1);
		}}
	for ( i = 0; i < consumer_count; i++){
	error = pthread_create(consumers+i,NULL,&consumer,NULL);
	if(error!=0){
		printf("\nError Creating Consumer %d: %s\n",i+1,strerror(error));
	}else{
		printf("\nCreated Consumer!! %d \n",i+1);
	}}
	for ( i = 0; i < producer_count; i++){
		pthread_join(*(producers+i),NULL);
	}
	for ( i = 0; i < consumer_count; i++){
		pthread_join(*(consumers+i),NULL);
	}
	return 0;
	}
	



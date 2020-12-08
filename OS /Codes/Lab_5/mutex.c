#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[2];
// K Srikanth 17ETCS002124
pthread_mutex_t lock;
void* Helloworld(void *arg){
    pthread_mutex_lock(&lock);
    printf("\n Hello Srikanth.....i am mutex\n");
    printf("\n Bye Srikanth..... \n");
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main(void){
    int i = 0;
    int err;
    if (pthread_mutex_init(&lock, NULL) != 0){
        printf("\n mutex init failed\n");
        return 1;
    }
    while(i < 2){
        err = pthread_create(&(tid[i]), NULL, &Helloworld, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}


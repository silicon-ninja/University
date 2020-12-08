#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
# define Threads_Num 3

// K Srikanth 17ETCS002124

void * printstatement(void * tid)
{
    int id;
    id = (int)tid;

   printf("Hello World !! \nIf you are wondering i was created by thread %d.\n",id);
   pthread_exit(NULL);
}

int main()
{
    int error;
   pthread_t threads[Threads_Num];   
    for (int i = 0; i < Threads_Num; i++)
    {
        printf("Creating a thread in main %d \n",i);
        error = pthread_create(&threads[i],NULL,printstatement,(void*) i);
        if(error){
            printf("Opps ... !! There was a error while creating thread CODE : %d \n",error);
            exit(-1);
        }
    }
    
    pthread_exit(NULL);
   return 0;
}



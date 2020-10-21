#include<stdio.h> 
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
int main()
{   
    int x,y;
    int add,sub,mull;
    float div;
    printf("Enter The First Number : ");
    scanf("%d",&x);
     printf("Enter The Second Number : ");
    scanf("%d",&y);
    int f = fork();
    if (f==0)
    {
        add = x + y ;
        printf("This is a child process \n Additon result for %d and % is %d  \n %d is the parent process id \n",x,y,add,getppid());
    }
    else 
    {
       int f1 = fork();
        if (f1 == 0){
            sub = x - y;
            printf("This is a child process \n %d is answer for sub  \n %d is the child's parent process id \n",sub,getppid());
        }
        else {
            int f2 = fork();
            if (f2 == 0){
                mull = x*y;
                printf("This is a child process \n %d is answer for mull \n %d is the child's parent process id \n",mull,getppid());
            }
            else {
                div = (float) x/y; 
                printf("This is a child process \n %f is answer for div \n %d is the parent process id \n",div,getpid());
                wait(NULL);
               
        }
        }
    }
return 0;
}






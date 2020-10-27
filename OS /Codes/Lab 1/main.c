#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
int main()
{
    printf("K Srikanth 17ETCS002124\n");
    printf("\n");
    int x,y;
    int add,sub,mull;
    float div;
    printf("Enter the First Number: ");
    scanf("%d",&x);
    printf("Enter the Second Number: ");
    scanf("%d",&y);
    printf("\n");
    printf("*************************\n");
    printf("\n");
    int f = fork();
    if (f==0)
    {
        add = x+y ;
        printf("The Addition Result of x = %d and y = %d is %d \n The Process ID is %d \n The Parent Process ID is %d\n",x,y,add,getpid(),getppid());
        printf("\n");
    }
    else{
       int f2 = fork();
        if (f2 == 0){
            sub = x-y ;
            printf("The Subtraction Result of x = %d and y = %d is %d \n The Process ID is %d \n The Parent Process ID is %d\n",x,y,sub,getpid(),getppid());
            printf("\n");
        }
        else {
            int f3 = fork();
            if (f3 == 0){
                mull = x * y;
                printf("The Multiplication Result of x = %d and y = %d is %d \n The Process ID is %d \n The Parent Process ID is %d\n",x,y,mull,getpid(),getppid());
                printf("\n");
            }
            else{
                div = x / y ;
                printf("The Division Result of x = %d and y = %d is %f \n The Process ID is %d \n The Parent Process ID is %d\n",x,y,div,getpid(),getppid());
                printf("\n");
                wait(NULL);
        }}}
    return 0;
}





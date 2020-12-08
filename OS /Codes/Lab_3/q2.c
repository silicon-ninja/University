#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// K Srikanth 17ETCS002124

void *marks(int *arg)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + arg[i];
    }
    pthread_exit(sum);
}

int main()
{
    pthread_t thread1, thread2;
    void *s1, *s2;
    int i, marks1[5], marks2[5];

    printf("Enter the Marks of Studnet 1 : \n");
    printf("*********************************\n");
    for (i = 0; i < 5; i++)
    {
        printf("Enter the marks of Subject %d \n", (i + 1));
        scanf("%d", &marks1[i]);
    }
    printf("\n");
    printf("Enter the Marks of Studnet 2 : \n");
    printf("*********************************\n");
    for (i = 0; i < 5; i++)
    {
        printf("Enter the marks of Subject %d \n", (i + 1));
        scanf("%d", &marks2[i]);
    }

    pthread_create(&thread1, NULL, marks, (void *)marks1);
    pthread_join(thread1, &s1);
    pthread_create(&thread2, NULL, marks, (void *)marks2);
    pthread_join(thread1, &s2);
    printf("\n");

    printf("Total Marks of Student 1 is %d \n", s1);
    printf("Total Marks of Student 2 is %d \n", s2);
    printf("\n");
    if (s1 > s2)
    {
        printf("Student 1 has the Highest Marks. \n");
    }
    else
    {
        printf("Student 2 has the Highest Marks. \n");
    }

    return 0;
}
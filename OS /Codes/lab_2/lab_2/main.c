#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/// Case 1


//int main()
//{
//    printf("K Srikanth 17ETCS002124\n");
//    printf("--------- CASE-1 ---------\n");
//    printf("**************************\n");
//    char buff[1000] ;
//    int fd = open("/Users/srikanthkandarp/Desktop/Os_texts/Case_1/test1.txt", O_RDONLY );
//    read(fd, buff, sizeof(buff));
//    printf("fd = %d \n", fd);
//    int fd1 = open("/Users/srikanthkandarp/Desktop/Os_texts/Case_1/test1output.txt", O_WRONLY );
//    write(fd1, buff, sizeof(buff));
//    close(fd);
//    close(fd1);
//    return 0;
//}

//// Case 2

//int main()
//{
//    printf("K Srikanth 17ETCS002124\n");
//    printf("--------- CASE-2 ---------\n");
//    printf("**************************\n");
//    FILE *input_file, *output_file;
//    char buffer[100];
//    input_file = fopen("/Users/srikanthkandarp/Desktop/Os_texts/Case_2/test2.txt","r");
//    output_file = fopen("/Users/srikanthkandarp/Desktop/Os_texts/Case_2/test2output.txt","w");
//
//    if (!input_file)
//        exit(1);
//
//    while (fgets(buffer,100, input_file)!=NULL)
//        fputs(buffer, output_file);
//
//
//    fclose(input_file);
//    fclose(output_file);
//    return 0;;
//}

//// Case 3

//extern int errno;
//int main()
//{
//    printf("K Srikanth 17ETCS002124\n");
//    printf("--------- CASE-3 ---------\n");
//    printf("**************************\n");
//    char buff[15];
//    int fd = open("/Users/srikanthkandarp/Desktop/Os_texts/Case_3/test3.txt", O_RDONLY );
//    int fd1 = open("/Users/srikanthkandarp/Desktop/Os_texts/Case_3/test3output.txt", O_WRONLY );
//    read(fd, buff, sizeof(buff));
//    write(fd1, buff, sizeof(buff));
//    close(fd);
//    close(fd1);
//    if (fd ==-1)
//    {
//        printf("C Program Error Number % d\n", errno);
//        perror("Program");
//    }
//    return 0;
//}

//// Case 4


//int main()
//{
//    printf("K Srikanth 17ETCS002124\n");
//    printf("--------- CASE-4 ---------\n");
//    printf("**************************\n");
//    char buff[1000] ;
//    int fd = open("/Users/srikanthkandarp/Desktop/Os_texts/Case_4/test4.txt", O_RDONLY );
//    read(fd, buff, sizeof(buff));
//    int fd1 = open("/Users/srikanthkandarp/Desktop/Os_texts/Case_4/test4output.txt", O_WRONLY | O_CREAT, S_IWRITE | S_IWUSR);
//    write(fd1, buff, sizeof(buff));
//
//    close(fd);
//    close(fd1);
//
//    return 0;
//}

// Case 5

//int main()
//{
//    printf("K Srikanth 17ETCS002124\n");
//    printf("--------- CASE-5 ---------\n");
//    printf("**************************\n");
//    FILE *input_file, *output_file;
//    char buffer[100];
//    input_file = fopen("/Users/srikanthkandarp/Desktop/Os_texts/Case_5/test5.txt","r");
//    output_file = fopen("/Users/srikanthkandarp/Documents/Case_5/test5output.txt","w");
//    if (!input_file)
//        exit(1);
//    while (fgets(buffer,100, input_file)!=NULL)
//        fputs(buffer, output_file);
//    fclose(input_file);
//    fclose(output_file);
//    return 0;;
//}a


// Case 6
//
//extern int errno;
//int main()
//{
//    printf("K Srikanth 17ETCS002124\n");
//    printf("--------- CASE-6 ---------\n");
//    printf("**************************\n");
//    char buff[15];
//    int fd = open("/Users/srikanthkandarp/Desktop/Os_texts/Case_6/test6.txt", O_RDONLY );
//    int fd1 = open("/Users/srikanthkandarp/Desktop/Os_texts/Case_6/test6output.txt", O_WRONLY );
//    read(fd, buff, sizeof(buff));
//    write(fd1, buff, sizeof(buff));
//    close(fd);
//    close(fd1);
//    if (fd ==-1)
//    {
//        printf("C Program Error Number % d\n", errno);
//        perror("Program");
//    }
//    return 0;
//}






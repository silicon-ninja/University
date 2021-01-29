#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Declaration Section 17ETCS002124 K Srikanth
    int *partitions_size;
    int *partitions;
    int *processes;
    int *partition_order;
    int n, nl;
    int loop = 0;
    int i, j;
    printf("Enter the Number of Partitions : ");
    scanf("%d", &n);
    partition_order = (int *)malloc(sizeof(int) * n);
    processes = (int *)malloc(sizeof(int) * nl);
    partitions_size = (int *)malloc(sizeof(int) * n);
    partitions = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Partition %d Size :", i + 1);
        scanf("%d", (partitions_size + i));
        partitions[i] = 0;
    }
    printf("The Partitions are : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d |", partitions_size[i]);
    }
    printf("\n");
    printf("Enter the Number of Processes : ");
    scanf("%d", &nl);
    for (i = 0; i < nl; i++)
    {
        printf("Enter the Partition %d Size :", i + 1);
        scanf("%d", (processes + i));
    }
    printf("Enter the Choice : \n");
    printf("Press 1 For First Fit \n");
    printf("Press 2 For Best Fit \n");
    printf("Press 3 For Worst Fit \n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\n");
        for (i = 0; i < nl; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (partitions[j] == 0 && *(processes + i) <= partitions_size[j])
                {
                    partitions[j] = i + 1;
                    *(processes + i) = 0;
                    printf("Executing First Fit Algorithm  \nPartitions after sorting : \n");
                    printf("Process %d fit in Partition %d \n", partitions[j], j + 1);
                    break;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            if (processes[i] != 0)
            {
                printf("Process %d Size %d Couldn't Fit\n", i + 1, processes[i]);
            }
        }
        return (EXIT_SUCCESS);
        break;

    case 2:
        for (i = 0; i < n; i++){
            partition_order[i] = i;}
        for (i = 0; i < (n - 1); i++){
            for (j = 0; j < (n - i - 1); j++){
                if (partitions_size[j] > partitions_size[j + 1]){
                    int temp = partitions_size[j];
                    partitions_size[j] = partitions_size[j + 1];
                    partitions_size[j + 1] = temp;
                    temp = partition_order[j];
                    partition_order[j] = partition_order[j + 1];
                    partition_order[j + 1] = temp;}}}
        printf("\n");
        printf("Executing Best Fit Algorithm \nPartitions after sorting : \n");
        for (i = 0; i < n; i++){
            printf("%d |", partitions_size[i]);}
        printf("\n");
        for (i = 0; i < nl; i++){
            for (j = 0; j < n; j++){
                if (partitions[j] == 0 && *(processes + i) <= partitions_size[j]){
                    partitions[j] = i + 1;
                    printf("Process %d [Size = %d] fit in partition %d [Size =%d]\n", i + 1, 
                    processes[i], partition_order[j] + 1, partitions_size[j]);
                    processes[i] = 0;
                    break;}} }
        break;

    case 3:
        for (i = 0; i < n; i++){
            partition_order[i] = i;}
        for (i = 0; i < (n - 1); i++) {
            for (j = 0; j < (n - i - 1); j++){
                if (partitions_size[j] > partitions_size[j + 1]){
                    int temp = partitions_size[j];
                    partitions_size[j] = partitions_size[j + 1];
                    partitions_size[j + 1] = temp;
                    temp = partition_order[j];
                    partition_order[j] = partition_order[j + 1];
                    partition_order[j + 1] = temp;}}}
        printf("\n");
        printf("Executing Worst Fit Algorithm  \nPartitions after sorting : \n");
        for (i = 0; i < nl; i++){
            printf("%d |", partitions_size[i]);}
        printf("\n");
        for (i = 0; i < nl; i++){
            for (j = n - 1; j > -1; j--){
                if (partitions[j] == 0 && *(processes + i) <= partitions_size[j]){
                    partitions[j] = i + 1;
                    printf("Process %d [Size = %d] fit in partition %d [Size =%d]\n", i + 1, 
                    processes[i], partition_order[j] + 1, partitions_size[j]);
                    processes[i] = 0;
                    break;}}}
        break;
        default:
        break;
    }
}
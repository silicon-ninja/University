#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// K Srikanth 17ETCS002124

void swap(int*a,int*b){
    int temp;
    temp =*a;
    *a=*b;
    *b=temp;
}


void priorityScheduling(){
    // K Srikanth 17ETCS002124
    int i,j,n,max;
    float total_waiting_time=0,total_turnaround_time=0;
    printf("Priority Scheduling Algorithm \n");
    printf("********************************\n");
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    int burst_time[n],priority[n],waiting_time[n],turnaround_time[n],process[n];
    printf("Enter the bust time and priority of each process: \n ");
    for (i=0; i<n;i++) {
        printf("Process - [%d] \n",i+1);
        printf("Burst Time : ");
        scanf("%d",&burst_time[i]);
        printf("Priority : ");
        scanf("%d",&priority[i]);
        process[i]=i+1;
       
    }
    for(i=0;i<n;i++){
        max=i;
        for (j=i+1; j<n;j++){
            if( priority[j]> priority[max])
            max=j;
        }
        swap(&priority[i], &priority[max]);
        swap(&burst_time[i],&burst_time[max]);
        swap(&process[i],&process[max]);
    }
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];
    
    for (i=1; i<n; i++) {
        waiting_time[i] = burst_time[i-1]+waiting_time[i-1];
        total_waiting_time = total_waiting_time + waiting_time[i];
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_turnaround_time = total_turnaround_time + turnaround_time[i];
    }
        printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time");
    for (i=0; i<n; i++) {
        printf("\nProcess[%d]\t\t%d\t\t\t\t%d\t\t\t\t\t%d",process[i],burst_time[i],waiting_time[i],turnaround_time[i]);
        
    }
    printf("\nAverage Waiting Time =%f",total_waiting_time/n);
    printf("\nAverage Turn Around Time=%f\n",total_turnaround_time/n);
    printf("\n");
}



void roundRobinScheduling(){
    // K Srikanth 17ETCS002124

    int i,j,n,time_slice,remain_process,flag=0,time;
    float wait_time =0,turn_around_time=0;
    printf("\nRound Robin Scheduling Algorithm\n");
    printf("********************************\n");
    printf("\nEnter the number of processes :");
    scanf("%d",&n);
    remain_process = n;
    int burst_time[n],process[n],running_time[n];
    printf("Enter the bust time each process: \n ");
    for (i=0; i<n; i++) {
        printf("Process - [%d]\n",i+1);
        printf("Burst Time : ");
        scanf("%d",&burst_time[i]);
        running_time[i] = burst_time[i];
        process[i]=i+1;
    }
    printf("Enter the value of Time Slice :");
    scanf("%d",&time_slice);
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time \n");
    
    for (time=0,i=0;remain_process!=0;) {
        if (running_time[i]<=time_slice && running_time[i]>0) {
            time=time+running_time[i];
            running_time[i]=0;
            flag=1;
        }
        else if (running_time[i]>0){
            running_time[i]-=time_slice;
            time+=time_slice;
        }
        if (running_time[i]==0 && flag==1) {
            remain_process --;
            printf("Process[%d]\t\t%d\t\t\t\t%d\t\t\t\t\t\t%d\n",i+1,burst_time[i],time-burst_time[i],time);
            wait_time+=time-burst_time[i];
            turn_around_time+=time;
            flag=0;
        }
        if (i==n-1)i=0;
        else i++;
        }
    printf("\nAverage Waiting Time =%f",wait_time/n);
    printf("\nAverage Turn Around Time=%f\n",turn_around_time/n);
    printf("\n");
}


    
int main(){
     // K Srikanth 17ETCS002124
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,priorityScheduling,(void*)NULL);
    pthread_join(thread1,NULL);
  

    pthread_create(&thread2,NULL,roundRobinScheduling,(void*)NULL);
    pthread_join(thread2,NULL);
    return 0;
}

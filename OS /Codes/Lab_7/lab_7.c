#include <stdio.h>
# define P 5
#define R 3

void calculateNeed(int need[P][R],int maxm[P][R],int allot[P][R]){
    printf ("Needed resources matrix \n");
    for(int i=0;i<P;i++){
        for (int j=0;j<R;j++){
            need[i][j] = maxm[i][j] - allot [i][j];
            printf("%d",need[i][j] );
        }
        printf("\n");
    }
}

int isSafe(int avail[],int maxm[][R],int allot[][R]){
    int need[P][R];
    calculateNeed(need,maxm,allot);
    int finish[P]={0};
    int safSeq[P];
    int work[R];
    for(int i=0;i<R;i++)
        work[i] = avail[i];
    
    int count = 0;
    while(count<P)
    {
        int found =0; 
        for(int p=0;p<P;p++)
        {
            if(finish[p]==0)
            {
                int j;
                for (j = 0; j < R; j++){
                  if(need[p][j]>work[j])
                        break;
                  if(j == R)
                  {
                      for (int k =0;k<R;k++)
                          work[k] += allot [p][k];
                    safSeq[count++] = p;
                    finish[p]=1;
                    found = 1;
                  }  
                }
            }
            if (found ==0){
                printf("System is not in safe state");
                return 0;
            }
        }
        printf("System is in safe state \nSafe sequence is :");
        for (int i = 0; i < P; i++)
        {
            printf("%d",safSeq[i]);
        }
    }
}

int main(){
    int maxm[P][R],allot[P][R],avail[P][R];
    printf("Maximum Allocatoin Matrix\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++){
            scanf("%d",&maxm[P][R]);
        } 
    }
        printf("Allocated Resources Matrix\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++){
            scanf("%d",&allot[P][R]);
        } 
    }    printf("Available Instances of Each Resource \n");
        for (int j = 0; j < R; j++){
            scanf("%d",&avail[P][R]);
        } 
    isSafe(avail,maxm,allot);
    return 0;
}
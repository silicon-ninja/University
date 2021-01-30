#include <stdio.h>
#include <stdlib.h>
#include<time.h>
// K Srikanth 17ETCS002124
int main(int argc, char** argv) {
    int nframes,i;
    printf("Enter the Number of Frames :");
    scanf("%d",&nframes);     
    int sdata[nframes];      
    int rdata[nframes];     
    printf("Input the data to be transmitted \n");
    for(i=0;i<nframes;i++)
    {
        scanf("%d",&sdata[i]);
    }
    for(i=0;i<nframes;i++)
    {
        printf("Frame %d has been sent.\n",i+1);
        if(rand()%2==0)    
        {
            rdata[i]=sdata[i];
            printf("Frame %d is successfully received.\n",i+1);
         }
        else               
        {
            printf("Timed out! Initiating re-transmission.\n");
            i=i-1;
        }
    }
    printf("The Frames received are :");
    for(i=0;i<nframes;i++)
    {
        printf("%d ",rdata[i]);
    }
    return (EXIT_SUCCESS);
}


#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(int argc, char** argv) {
    int nframes,i;
    printf("How many frames? ");
    scanf("%d",&nframes);     
    int sdata[nframes];      //SENDER SIDE BUFFER
    int rdata[nframes];      //RECIEVER SIDE BUFFER
    printf("Input the data to be transmitted ");
    for(i=0;i<nframes;i++)
    {
        scanf("%d",&sdata[i]);
    }
    for(i=0;i<nframes;i++)
    {
        printf("Frame %d has been sent.\n",i+1);
        if(rand()%2==0)    //ACKNOWLEDGEMENT RECEIVED
        {
            rdata[i]=sdata[i];
            printf("Frame %d is successfully received.\n",i+1);
         }
        else               //NO ACKNOWLEDGEMENT RECEIVED
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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    srand(time(0));                          //set random seed
    int n,sender_window_size=0;              //declaration
    printf("Input window size: ");           
    scanf("%d",&sender_window_size);        // input sender_window size
    printf("how many frames? ");
    scanf("%d",&n);                          
    int frames[n],i,j;
    printf("Sender Message :  ");
    for(i=0;i<n;i++)
        scanf("%d",&frames[i]);             // input message in n frames
    
    int last_ack,bottom,sent=0;
                              //last_ack: to store last received acknowledgement
                              // bottom: position pointing bottom of window
                              // sent: total number of packets sent
    do{
        
        printf("Frames Transmitted: ");
                                // send until window is full
        for(i=sent;i<sent+sender_window_size && i<n;i++)
        {
            printf("%d  ",i+1);         
        }
        printf("\n");
        printf("Frames Acknowledged: ");
        bottom=sent;
        for(j=0;j<sender_window_size && sent<n ;j++){ //RECEIVER SIDE
            last_ack=sent+random()%2;        //generate acknowledgement using random()
            if(last_ack==sent+1){           //check if acknowledgement recieved is same as bottom element
                printf("%d   ",bottom+j+1);  //print acknowledgement for recieved
                sent++;                     // acknowledgement meaning successfully sent
            }                               //slide the window by 1 and check for next bottom most element
            else{
                printf("\nNAK for frame-%d received\n",bottom+j+1);
                printf("initiating retransmisson");     
                break;                      // NAK received retransmit from that frame
            }
        }
        printf("\n");
    }while(sent<n);                        // repeat until all frames received
    printf("%d frames successfully sent\n",sent);
    printf("Message recieved  at reciever :");
    for(i=0;i<sent;i++){
            printf("%d  ",frames[i]);       //display message at reciever end
        }
    return (EXIT_SUCCESS);
}

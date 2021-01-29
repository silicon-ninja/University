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
    
    int last_ack,bottom,sent=0,nak=0,frame_no;
                              //last_ack: to store last received acknowledgement
                              // bottom: position pointing bottom of window
                              // sent: total number of packets sent
                              // nak holds the value where frame is lost 
                              // frame_no holds current frame number inspected 
    do{
        if(nak){                //if nak present
            printf("NAK %d retransmitted \n",nak);  //retransmit
            printf("cumulative ACK %d received\n",sent);    //collect cumulative acknowledgement
            nak=0;              //reset nak to 0
        }
        printf("Frames Transmitted: ");
                                // Transmit until window is full
        for(i=sent;i<sent+sender_window_size && i<n;i++)
        {
            printf("%d  ",i+1);         
        }
        printf("\n");
        bottom=sent;
        for(j=0;j<sender_window_size && sent<n ;j++){ //RECEIVER SIDE
            last_ack=sent+random()%2;        //generate acknowledgement using random()
            frame_no=bottom+j+1;
            if(last_ack==sent+1){           //check if acknowledgement recieved is same as bottom element
                if(nak)
                    printf("Frame %d received, ACK-%d received   \n",frame_no,nak-1);     
                                            // if nak present, send last ACK received
                else
                    printf("Frame %d received, ACK-%d received   \n",frame_no,frame_no);  
                                             //print acknowledgement for recieved
                sent++;                     // acknowledgement meaning successfully sent
            }                               //slide the window by 1 and check for next bottom most element
            else{
                printf("Frame %d transmission failed,",frame_no);       
                printf("NAK-%d received   \n",frame_no);     //transmission failed, resend
                printf("initiating retransmisson\n"); 
                nak=bottom+j+1;                         //update NAK
                sent++;
                                     // NAK received retransmit from that frame
            }
        }
    }while(sent<n || nak);                        // repeat until all frames received
    printf("%d frames successfully sent\n",sent);
    printf("Message recieved  at reciever :");
    for(i=0;i<sent;i++){
            printf("%d  ",frames[i]);       //display message at reciever end
        }
    return (EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// K Srikanth 17ETCS002124
int main(int argc, char **argv)
{
    srand(time(0));
    int n, sender_window_size = 0;
    printf("Enter the Input Window Size : ");
    scanf("%d", &sender_window_size);
    printf("Enter the Number of Frames :");
    scanf("%d", &n);
    int frames[n], i, j;
    printf("Sender Message :  ");
    for (i = 0; i < n; i++)
        scanf("%d", &frames[i]);
    int last_ack, bottom, sent = 0, nak = 0, frame_no;
    do
    {
        if (nak)
        {
            printf("NAK %d retransmitted \n", nak);
            printf("Cumulative ACK %d received\n", sent);
            nak = 0;
        }
        printf("Frames Transmitted: ");

        for (i = sent; i < sent + sender_window_size && i < n; i++)
        {
            printf("%d  ", i + 1);
        }
        printf("\n");
        bottom = sent;
        for (j = 0; j < sender_window_size && sent < n; j++)
        {
            last_ack = sent + random() % 2;
            frame_no = bottom + j + 1;
            if (last_ack == sent + 1)
            {
                if (nak)
                    printf("Frame %d received, ACK-%d received   \n", frame_no, nak - 1);

                else
                    printf("Frame %d received, ACK-%d received   \n", frame_no, frame_no);

                sent++;
            }
            else
            {
                printf("Frame %d transmission failed,", frame_no);
                printf("NAK-%d received   \n", frame_no);
                printf("Initiating Retransmisson\n");
                nak = bottom + j + 1;
                sent++;
            }
        }
    } while (sent < n || nak);
    printf("%d frames successfully sent\n", sent);
    printf("Message recieved  at reciever :");
    for (i = 0; i < sent; i++)
    {
        printf("%d  ", frames[i]);
    }
    return (EXIT_SUCCESS);
}

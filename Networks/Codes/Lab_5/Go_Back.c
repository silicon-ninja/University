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
    printf("Enter the Number of Frames : ");
    scanf("%d", &n);
    int frames[n], i, j;
    printf("Sender Message :  ");
    for (i = 0; i < n; i++)
        scanf("%d", &frames[i]);
    int last_ack, bottom, sent = 0;
    do
    {
        printf("Frames Transmitted: ");
        for (i = sent; i < sent + sender_window_size && i < n; i++)
        {
            printf("%d  ", i + 1);
        }
        printf("\n");
        printf("Frames Acknowledged: ");
        bottom = sent;
        for (j = 0; j < sender_window_size && sent < n; j++)
        {
            last_ack = sent + random() % 2;
            if (last_ack == sent + 1)
            {
                printf("%d   ", bottom + j + 1);
                sent++;
            }
            else
            {
                printf("\nNAK for frame-%d received\n", bottom + j + 1);
                printf("Initiating Retransmisson");
                break;
            }
        }
        printf("\n");
    } while (sent < n);
    printf("%d Frame's successfully sent\n", sent);
    printf("Message recieved  at reciever :");
    for (i = 0; i < sent; i++)
    {
        printf("%d  ", frames[i]);
    }
    return (EXIT_SUCCESS);
}

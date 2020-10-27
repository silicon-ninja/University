#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1-D Parity

void oneD_Parity(char input[100],int choice){

    int count_1=0;

    for(int i=0;i<strlen(input);i++){
        if(input[i]=='1') {
            count_1++;
            }
        }

    switch (choice) {
        case 1:
            if (count_1%2==0) {
                strcat(input,"0");
                printf("The even encoded data parity is %s \n",input);
            }else{
                strcat(input,"1");
                printf("The even encoded data parity is %s \n",input);
            }
           
            printf("\n");
            break;
            

        case 2:
            if (count_1%2!=0) {
                strcat(input,"0");
                printf("The odd encoded data parity is %s \n",input);
            }else{
                strcat(input,"1");
                printf("The odd encoded data parity is %s \n",input);
                
            }
           
            printf("\n");
            break;
          
            default: printf("Invalid Input \n");
            break;
    }
    }

// 2-D Parity

void twoD_Parity(char input[100][100],int choice,int rows,int columns){
    for (int i=0;i<rows;i++) {
        int count=0;
        for(int j=0;j<strlen(input[i]);j++){
            if(input[i][j]=='1') {
                count++;
                }
        }
        switch (choice) {
            case 1:
                if(count%2==0) {
                    strcat(input[i],"0");
                    printf("The Even encoded data parity is %s \n",input[i]);
                }else{
                    strcat(input[i],"1");
                    printf("The Even encoded data parity is %s \n",input[i]);
                    }
               
              
                break;
            case 2:
                if(count%2!=0) {
                    strcat(input[i],"0");
                    printf("The Odd encoded data parity is %s \n",input[i]);
                }else{
                    strcat(input[i],"1");
                    printf("The Odd encoded data parity is %s \n",input[i]);
                    }
                
                break;
            default:
                break;
        }
        
    }
    for (int i=0; i<columns+1;i++) {
        int count =0;
        int j=0;
        for (;j<rows;j++) {
            if (input[j][i]=='1'){
                count++;
            }
        }
        switch (choice) {
            case 1:
                if(count%2==0) {
                    input[j][i]='0';
                    
                }else{
                    input[j][i]='1';
                    }
                break;
            case 2:
                if(count%2!=0) {
                    input[j][i]='0';
                    
                }else{
                    input[j][i]='1';
                    }
                break;
            default:
                break;
        }
        
    }
    switch (choice) {
        case 1:
            input[rows][columns+1] = '\0';
            printf("The Even encoded data parity is %s \n",input[rows]);
            
            printf("\n");
            break;
        case 2:
            input[rows][columns+1] = '\0';
            printf("The Odd encoded data parity is %s \n",input[rows]);
           
            printf("\n");
            break;
        default:
            break;
    }
       
}

int main() {
    printf("K Srikanth 17ETCS002124\n");
    int choice2;
    char input[100];
    char input2[100][100];
    int choice;
    int rows,columns;
    while (1) {
        printf("-------------------------\n");
        
        
        
        printf("Menu\n");
        printf("-------------------------\n");
    printf("Press 1 for 1-D Parity \n");
    printf("Press 2 for 2-D Parity  \n");
    printf("Press 3 to Quit \n");
        printf("-------------------------\n");
        
    scanf("%d",&choice);

   
        switch (choice) {
            case 1:
               
                printf("Enter the data in 0's and 1's : ");
                scanf("%s",&input);
                printf("Choose the method to encode the give data \n");
                printf("Press 1 for 1-D Even Parity \n");
                printf("Press 2 for 1-D Odd Parity \n");
                scanf("%d",&choice2);
                printf("\n");
                oneD_Parity(input,choice2);
                
                break;
            case 2:
                printf("Enter the Number of Rows : ");
                scanf("%d",&rows);
                printf("Enter the data in 0's and 1's : \n");
                for (int i=0; i<rows; i++) {
                    scanf("%s",&input2[i]);
                }
                columns = strlen(input2[0]);
                printf("Choose the method to encode the give data \n");
                printf("Press 1 for 2-D Even Parity \n");
                printf("Press 2 for 2-D Odd Parity \n");
                scanf("%d",&choice2);
                printf("\n");
                twoD_Parity(input2, choice2,rows, columns);
                
                break;

            case 3:
                exit(0);
            default:
                break;
        }
    }


    return 0;
}






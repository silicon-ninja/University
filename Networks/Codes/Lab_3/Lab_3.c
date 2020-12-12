#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define nodes 10
struct router{
    int x,y;};
// K Srikanth 17ETCS002124
struct router r[nodes];
int main(){
    int i,j,range;
    float d[nodes][nodes];
    printf("Input the Following 10 Routers : in X & Y Positions\n");
    for ( i = 0; i < nodes; i++){
      scanf("%d %d",&r[i].x,&r[i].y);
    }
    i =0,j=0;
    printf("Distances Between Each Router and Other Router from 0 to 9\n");
    for (i = 0; i < nodes; i++){
        printf("Router_%d\t |",i);
        for ( j = 0; j < nodes; j++) {
            d[i][j]=sqrt(pow((abs((r[i].x)-(r[j].x))),2)+pow((abs((r[i].y)-(r[j].y))),2));      
            printf("%.2f |",d[i][j]); }
        printf("\n");
    }
    printf("\nInput the Router Number : ");
    scanf("%d",&i);
    printf("Enter the Range : ");
    scanf("%d",&range);
    printf("The Router found with in %d units from %d are \t",range,i);
    for (j = 0; j<=nodes-1; j++){
        if(d[i][j]<=range && d[i][j]>0){
            printf("%d\t",j);}
    }
    
}


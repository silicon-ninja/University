#include <stdio.h>
struct Router{
    int distance[20];
    int through[20];
} rt[10];
// K Srikanth 17ETCS002124
int main(){
    int n,i,j,k,changes=0;
    printf("\n How Many Routers Btw in the network ? : " );
    scanf("%d",&n);
    printf("\n Input the cost matrix (1000 for not link) :\n");
    printf("\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        scanf("%d",&rt[i].distance[j]);
        rt[i].through[j]=j;}
    do {
        changes = 0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        for(k=0;k<n;k++)
        if(rt[i].distance[j]>rt[i].distance[k]+rt[k].distance[j]){
            rt[i].distance[j]=rt[i].distance[k]+rt[k].distance[j];
            rt[i].through[j]=k;
            changes ++; }
    } while (changes!=0);
    for(i=0;i<n;i++){
       printf("\n Distance Vector Table for %d Router\n",i);
       for ( j = 0; j< n; j++){
           printf("\t Destination: %d via: %d Distance: %d\n",j,rt[i].through[j],rt[i].distance[j]);}
    }
    printf("\n\n");
}



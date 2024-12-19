#include<stdio.h>
int knapsack(int m,int w,int weights[],int values[]){
    if(m==0 || w==0){
        return 0;
    }
    if(weights[m-1]>w){
        return kanpsasck(m-1,w,weights,values);
    }
    int include=values[m-1]+kanpsasck(m-1,w-weights[m-1],weights,values);
    int exclude=kanpsasck(m-1,w,weights,values);
    return include>exclude ? include : exclude;
}
int main(){
    int m,w;
    scanf("%d%d",&m,&w);
    int weights[m],values[m];
    for(int i=0;i<m;i++){
        scanf("%d%d",&weights[i],&values[i]);
    }
    int max=knapsack(m,w,weights,values);
    printf("%d",max);
}

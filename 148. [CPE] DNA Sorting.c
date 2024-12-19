#include<stdio.h>
struct DNA{
    char string[52];
    int order;
 };
 int main(){
    int time;
    scanf("%d",&time);
    int n,m;
    while(time--){
        scanf("%d%d",&n,&m);
        struct DNA* dnaArray=malloc(m*sizeof(struct DNA));
        for(int i=0;i<m;i++){
            dnaArray[i].order=0;
            scanf("%s",dnaArray[i].string);
            for(int j=0;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(dnaArray[i].string[j]>dnaArray[i].string[k]){
                        dnaArray[i].order++;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            int min=500;
            int index;
            for(int j=0;j<m;j++){
                if(dnaArray[j].order<min){
                    min=dnaArray[j].order;
                    index=j;
                }
            }
            dnaArray[index].order=500;
            /*
            int integer1,integer2,t;
            for(int k=n-2;k>=0;k--){
                for(int q=0;q<=k;q++){
                    integer1=dnaArray[index].string[q];
                    integer2=dnaArray[index].string[q+1];
                    if(integer1>integer2){
                        t=integer2;
                        dnaArray[index].string[q+1]=integer1;
                        dnaArray[index].string[q]=t;
                    }
                }
            }
            */
            printf("%s",dnaArray[index].string);
            printf("\n");
        }
    }
 }

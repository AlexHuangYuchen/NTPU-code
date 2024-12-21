#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    char med[16];
    int time;
};
int main(){
    int T;
    scanf("%d",&T);
    int n,k;
    while(T--){
        scanf("%d%d",&n,&k);
        int f[n];
        struct data*eat=malloc(n*sizeof(struct data));
        for(int i=0;i<n;i++){
            scanf("%s%d",eat[i].med,&eat[i].time);
            f[i]=eat[i].time;
        }
        int cont=k;
        int t=0;
        while(1){
            t++;
            for(int i=0;i<n;i++){
                if(eat[i].time==t &&cont>0){
                    printf("%d %s\n",t,eat[i].med);
                    eat[i].time+=f[i];
                    //printf("下一次t要%d\n",eat[i].time);
                    cont--;
                }
            }
            if(cont==0){
                    break;
                }
        }
        free(eat);
    }
}

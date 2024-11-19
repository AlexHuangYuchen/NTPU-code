#include<stdio.h>
int main(){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            printf("*");
            if(i==1 || i==n){
               for(int j=2;j<n;j++){
                   printf("*");
                }
             }
             else{
                 for(int j=2;j<n;j++){
                   printf(" ");
                }
             }
            printf("*");
            printf("\n");
        }
}

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    double sum=0.;
    int temp=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            temp*=j;
        }
        sum+=(double)i/temp;
        temp=1;
    }
    printf("%.5lf",sum);
}

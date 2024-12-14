#include<stdio.h>
int s(int n){
    int sum;
    if(n==1){
        return 1;
    }
    sum=n*n+s(n-1);
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",s(n));
}

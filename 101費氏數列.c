#include<stdio.h>
void getFib(int n){
    int l=0,r=1;
    int temp;
    n-=2;
    printf("0 1");
    for(int i=0;i<n;i++){
        printf(" %d",l+r);
        temp=r;
        r=l+r;
        l=temp;
    }
}
int main(){
        int n;
        scanf("%d",&n);
        getFib(n);
}

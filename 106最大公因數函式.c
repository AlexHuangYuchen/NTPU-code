#include<stdio.h>
void gcd(int a,int b) {
    int ans;
    int c;
    int A=a,B=b;
    while(b!=0){
        c=b;
        b=a%b;
        a=c;
    }
    printf("%d與%d的最大公因數為%d",A,B,a);
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    gcd(a,b);
}

#include<stdio.h>
void swap(int *x, int *y) {
   int temp;
   temp=*y;
   *y=*x;
   *x=temp;
}
int main(){
    int a;
    int b;
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("%d %d",a,b);
}

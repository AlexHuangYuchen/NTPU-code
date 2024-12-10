#include<stdio.h>
int mysum(int *a, int size) {
  int sum=0;
  for(int i=0;i<4;i++){
     sum+=a[i];
  }
  return sum;
}
int main(){
    int a[4];
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    int size=sizeof(a)/sizeof(int);
    printf("%d",mysum(a,size));
}

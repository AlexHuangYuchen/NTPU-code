#include<stdio.h>
void mid(int a[5], int n){
    int temp;
    for(int i=4;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(a[i]>a[i+1]){
                temp=a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
            }
        }
    }
    printf("Median = %d",a[2]);
}
int main(){
    int a[5];
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    mid(a,5);
}

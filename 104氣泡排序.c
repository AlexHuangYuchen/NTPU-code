#include<stdio.h>
void bubble_sort(int data[]){
    int temp;
    for(int i=3;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(data[j]>data[j+1]){
                temp=data[j+1];
                data[j+1]=data[j];
                data[j]=temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        if(i==4){
            printf("%d",data[4]);
            break;
        }
        printf("%d ",data[i]);
    }
}
int main(){
    int data[5];
    for(int i=0;i<5;i++){
        scanf("%d",&data[i]);
    }
    bubble_sort(data);
}

#include<stdio.h>
void bubble(int *arr){
    int temp;
    for(int i=3;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
         }
    }
    for(int i=0;i<5;i++){
        if(i==4){
            printf("%d",arr[i]);
        }
        else{
             printf("%d ",arr[i]);
        }
    }
}
int main(){
    int arr[5];
    int i;
    for( i=0 ; i<5 ; i++)
    {
        scanf("%d",&arr[i]);
    }
    bubble(arr);
}

#include<stdio.h>
void array_add(int *data1,int *data2,int size){
    for(int i=0;i<size;i++){
        data1[i]=data1[i]+data2[i];
    }

}
int main(){
    int data1[4] ;
    int data2[4] ;
    int size = sizeof(data1) / sizeof(data1[0]);
    for(int i = 0; i < 4; i++) {
          scanf("%d", &data1[i]);
    }
    for(int i = 0; i < 4; i++) {
          scanf("%d", &data2[i]);
    }
    array_add(data1, data2, size);
    for(int i = 0; i < size; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");
    return 0;
}

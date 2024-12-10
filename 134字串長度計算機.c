#include<stdio.h>
int sum=0;
void len(char *arr){
    int c=0;
    while(arr[c]!='\0'){
        sum++;
        c++;
    }
    printf("%d",sum);
}
int main(){
    char arr[60];
    scanf("%s",arr);
    //printf("%c",arr[0]);
    len(arr);
}

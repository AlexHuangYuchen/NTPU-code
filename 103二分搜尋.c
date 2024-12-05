#include<stdio.h>
#include<stdbool.h>
int binarysearch(int iptr[ ],int search,int len){
    int target=-1;
    int target_index;
    int rightmost,leftmost;
    int r=len-1,l=0;
    bool endearly=1;
    for(int i=0;i<len;i++){
        if(iptr[i]==search){
            endearly=0;
        }
    }
    if(endearly==1){
        return -1;
    }
    while(1){
        target_index=(rightmost+leftmost)/2;
        target=iptr[(rightmost+leftmost)/2];
        if(search>target){
            leftmost=target_index+1;
            rightmost=r;
            l=leftmost+1;
        }
        else if(search<target){
            rightmost=target_index-1;
            leftmost=l;
            r=rightmost-1;
        }
        else if(search==target){
            break;
        }
    }
    return target_index;
}
int main(){
    int search,ans;
    scanf("%d",&search);
    int data[]={3, 7, 14, 20, 23, 32, 41, 44, 56, 57, 73, 89, 93};
    ans=binarysearch(data,search,sizeof(data)/sizeof(int));
    if(ans<0){
        printf("沒找到");
    }
    else{
        printf("在第 %d 筆資料找到 %d",ans+1,search);
    }
}

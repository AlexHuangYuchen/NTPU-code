#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void isPalindrome(int n){
    //printf("%d\n",n);
    if(n<0){
        printf("false");
        return 0;
    }
    int a[100];
    memset(a,-1,sizeof(a));
    int p=n;
    //printf("%d\n",p);
    int c=0;
    while(p!=0){
        //printf("%d\n",p%10);
        a[c]=p%10;
        p/=10;
        //printf("%d ",a[c]);
        c++;
    }
    //printf("\n");
    bool check=1;
    int len=c-1;
    if(c%2!=0){
        c-=1;
    }
    for(int i=0;i<c/2;i++){
        if(a[i]!=a[len-i]){
            check=0;
            break;
        }
    }
    if(check==1){
        printf("true");
    }
    else{
        printf("false");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    isPalindrome(n);
}

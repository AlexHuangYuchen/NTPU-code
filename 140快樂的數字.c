#include<stdio.h>
#include<stdbool.h>
int next_n(int n) {//��X�U�@��n
    int sum=0;
    int t=n;
    while(t!=0){
        sum+=(t%10)*(t%10);
        t/=10;
    }
    return sum;
}
////////////
bool contains(int* history, int size, int n) {//�P�_ n=1 �άO���J�`��
    for(int i=0;i<size;i++){
        if(n==history[i]){
            return 1;
        }
    }
    return 0;
}
///////////
#include<string.h>
bool isHappy(int n) {//�P�_�O���O�ּ֪��Ʀr
    int size=0;
    int history[5000];
    memset(history,-1,sizeof(history));
    int c=0;
    while(n!=1){
        size++;
        history[size]=n;
        if(contains(history,size,n)==1){
            return 0;
        }
        n=next_n(n);
    }
    return 1;
}
////////////
int main(){
    int n;
    scanf("%d", &n);
    if (isHappy(n)==1) {
        printf("true");
    }
    else {
        printf("false");
    }
}

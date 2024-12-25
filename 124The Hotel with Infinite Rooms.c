#include<stdio.h>
int D_size(int S, int D) {
    int sum=0;
    while(1){
        sum+=S;
        if(sum>=D){
            return S;
        }
        S++;
    }
}
int main(){
    int S, D;
    scanf("%d %d", &S, &D);
    printf("%d", D_size(S, D));
}


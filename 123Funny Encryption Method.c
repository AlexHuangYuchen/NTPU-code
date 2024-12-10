#include<stdio.h>
int bin(int N) {
    int x=0;
    while(1){
        if(N%2==1){
            x++;
        }
        N/=2;
        if(N<2){
            if(N==1){
                x++;
            }
            break;
        }
    }
    return x;
}
int hex(int N) {
    int y=0;
    int temp;
    while(N>0){
        temp=N%10;
        while(1){
                if(temp%2==1){
                    y++;
                }
                temp/=2;
                if(temp<2){
                    if(temp==1){
                        y++;
                    }
                    break;
                }
        }
        N/=10;
   }
   return y;
}
int main(){
    int N, b1, b2;
    scanf("%d", &N);
    b1 = bin(N);
    //printf("%d\n",b1);
    b2 = hex(N);
    printf("%d %d", b1, b2);
}

#include <stdio.h>
int f(int n) {
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    if(sum<10){
        return sum;
    }
    f(sum);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;

}

#include <stdio.h>
int f91(int n) {
    int sum;
    if(n>=101){
            return n-10;
    }
    sum=f91(f91(n+11));
    return sum;
}
int main(){

    int n;
    scanf("%d", &n);
    printf("f91(%d) = %d\n", n, f91(n));
    return 0;

}

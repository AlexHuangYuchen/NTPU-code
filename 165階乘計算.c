#include <stdio.h>
 int fac(int n) {
    int sum;
    if(n==1){
        return 1;
    }
    sum=n*fac(n-1);
    return sum;
}
int main(){

    int n;
    scanf("%d", &n);
    printf("%d", fac(n));
    return 0;

}

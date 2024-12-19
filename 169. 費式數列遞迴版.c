#include <stdio.h>
 int fibr(int n) {
    if(n==1 ){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    return fibr(n-1)+fibr(n-2);
}
int main() {
 int n;
 scanf("%d", &n);
 printf("%d", fibr(n));

}

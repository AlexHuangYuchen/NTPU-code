#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<stdbool.h>
 bool rangePerfectSquare(int left, int right, int target) {
    right=left*left;
    if(right==target){
        return 1;
    }
    else if(right>target){
        return 0;
    }
    return rangePerfectSquare(left+1,right,target);
 }

int main() {
    int a;
    scanf("%d", &a);
    //printf("%d\n", INT_MAX);
    bool ans = rangePerfectSquare(1, INT_MAX, a);

    if (ans) {
        printf("true");
    }
    else {
        printf("false");
    }
    printf("\n");
    return 0;
}

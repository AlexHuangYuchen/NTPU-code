#include <stdio.h>
#include <stdlib.h>
void permute(int* a, int l, int r, int n) {
    if(l==r){
        for(int i=0;i<n;i++){
            printf("%d",a[i]);
        }
         printf("\n");
    }
    else{
        for(int i=l;i<=r;i++){
            swap(&a[l],&a[i]);
            permute(a,l+1,r,n);
            swap(&a[l],&a[i]);
        }
    }
}

void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int n, i;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    permute(a, 0, n - 1, n);
    free(a);
    return 0;
}

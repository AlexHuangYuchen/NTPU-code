#include<stdio.h>
int max(int* iptr, int n) {
    int m=-1;
    iptr--;
    for(int i=n-1;i>=0;i--){
        //printf("%d\n",*iptr);
        if(*iptr>m){
            m=*iptr;
        }
        iptr--;
    }
    return m;
}
int main(){
    int n, i;
    int array[100];
    int* iptr;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[i]));
        iptr = &(array[i]);
        //printf("%d\n",*iptr);
        iptr++;//換下一個元素
    }
    //printf("%d\n",*iptr);
    printf("%d\n", max(iptr, n));
}

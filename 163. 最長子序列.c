#include <stdio.h>
int lcs(int* text1, int* text2, int m, int n) {///找最長子序列
    if(m==0 || n==0){
        return 0;
    }
    if(text1[m-1]==text2[n-1]){
        return 1+lcs(text1, text2, m - 1, n - 1);
    }
    else{
        return lcs(text1,text2,m-1,n)>lcs(text1,text2,m,n-1) ? lcs(text1,text2,m-1,n) : lcs(text1,text2,m,n-1);
    }
}
void int_to_array(int* array1, int value, int index) {///將整數的每一位存入陣列中
    for(int i=0;i<index;i++){
        array1[i]=value%10;
        value/=10;
    }
    int temp;
    for(int j=0;j<index/2;j++){
        temp=array1[j];
        array1[j]=array1[index-1-j];
        array1[index-1-j]=temp;
    }
}

int main() {
    int ans = 0;
    int text1[100] = { 0 };
    int text2[100] = { 0 };
    int t1, t2, m, n;

    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &t1);
    scanf("%d", &t2);

    int_to_array(text1, t1, m);
    int_to_array(text2, t2, n);
    ans = lcs(text1, text2, m, n);
    printf("%d", ans);
    return 0;
}

#include<stdio.h>
#include<stdbool.h>
int extractMax(int* stone, int stoneSize) {///取最大元素
    int max=-10;
    int index;
    for(int i=0;i<stoneSize;i++){
        if(stone[i]>=max){
            max=stone[i];
            index=i;
        }
    }
    stone[index]=-1;
    return max;
}
void insert(int* stone, int stoneSize, int value) {///用y-x取代原本的y
    for(int i=0;i<stoneSize;i++){
        if(stone[i]==-1){
            stone[i]=value;
            break;
        }
    }
}
int lastStoneWeight(int* stones, int stonesSize) {///題目演算法
    while(1){
        int m1=extractMax(stones,stonesSize);
        int m2=extractMax(stones,stonesSize);
        if(m2==-1){
            if(m1==-1){
                return 0;
            }
            else if(m1!=-1){
                return m1;
            }
        }
        else if(m1!=-1 && m2!=-1){
            insert(stones,stonesSize,m1-m2);
        }
    }

}
int main(){
    int n = 0;
    int ans;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ans = lastStoneWeight(a, n);
    printf("%d", ans);
    free(a);
}

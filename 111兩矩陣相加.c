#include<stdio.h>
void plusm(int (*a)[3], int (*b)[3], int (*c)[3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}
int main(){
    int a[3][3], b[3][3], c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }
    plusm(a,b,c);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}

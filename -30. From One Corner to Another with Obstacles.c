#include<stdio.h>
int n[13][13]={0};
int climb(int current_r,int current_c,int r,int c){
    if(current_r<0 || current_c>c){
        return 0;
    }
    else if(current_r==0 && current_c==c-1){
        return 1;
    }
    else if(n[current_r][current_c]==0){
        return 0;
    }
    return climb(current_r-1,current_c,r,c)+climb(current_r,current_c+1,r,c);
}
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&n[i][j]);
        }
    }
    printf("%d",climb(r-1,0,r,c));
}


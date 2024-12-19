#include<stdio.h>
int  walk(int r,int c,int o_r,int o_c){
    if(r==0 && c==o_c-1){
        return 1;
    }
    else if(r<0 || c>o_c-1){
        return 0;
    }
    else{
        return walk(r-1,c,o_r,o_c)+ walk(r,c+1,o_r,o_c);
    }
}
int main(){
    int r,c;
    int ways=0;
    scanf("%d%d",&r,&c);
    int o_r=r,o_c=c;
    printf("%d",walk(r-1,0,o_r,o_c));
}

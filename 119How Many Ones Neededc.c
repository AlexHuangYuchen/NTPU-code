#include<stdio.h>
int count_ones(int dec_num) {
    int cont=0;
    if(dec_num<2){
        cont++;
        return cont;
    }
    while(dec_num>=2){
        if(dec_num%2==1){
            cont++;
        }
        dec_num/=2;
        if(dec_num==1){
            cont++;
        }
    }
    return cont;
}
int main(){
    int a,b;
    while(1){
        scanf("%d%d",&a,&b);
        if(a==0 && b==0){
            return 0;
        }
        int total_ones_num=0;
        for(int i=a;i<=b;i++){
            total_ones_num+=count_ones(i);
            //printf("%d\n",count_ones(i));
        }
        printf("%d\n",total_ones_num);
    }
}

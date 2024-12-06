#include<stdio.h>
int lcm(int a, int b) {
    int max,min;
    if(a>b){
        max=a;
        min=b;
    }
    else{
        max=b;
        min=a;
    }
    int c=1;
    int m=max;
    //printf("%d %d\n",max,min);
    while(max%min!=0){
        max=m*c;
        c++;
        //printf("%d\n",max);
    }
   return max;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int result= lcm(a,b);
    printf("%d",result);
}

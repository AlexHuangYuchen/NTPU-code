#include<stdio.h>
void power(double *a, double *b, double *res){
    *res=1;
    int p=*a;
    for(int i=1;i<=*b;i++){
        (*res)*=p;
        //printf("%lf\n",*res);
    }
}
int main(){
    double a;
    double b;
    double res;

    scanf("%lf %lf", &a, &b);

    power(&a, &b, &res);
    printf("%.1lf^%.1lf=%.1lf\n", a, b, res);

    return 0;
}

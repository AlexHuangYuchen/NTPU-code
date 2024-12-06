#include<stdio.h>
void years(int year) {
    if((year%4==0&&year%100!=0)||year%400==0){
        printf("%d是閏年",year);
    }
    else{
        printf("%d是平年",year);
    }

}
int main(){
    int year;
    scanf("%d",&year);
    years(year);
}

#include<stdio.h>
void years(int year) {
    if((year%4==0&&year%100!=0)||year%400==0){
        printf("%d�O�|�~",year);
    }
    else{
        printf("%d�O���~",year);
    }

}
int main(){
    int year;
    scanf("%d",&year);
    years(year);
}

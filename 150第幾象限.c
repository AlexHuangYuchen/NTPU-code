#include<stdio.h>
struct point_t {
    double x;
    double y;
};
typedef struct point_t point_t;
point_t find;
int main(){
    scanf("%lf%lf",&(find.x),&(find.y));
    if(find.x<0){
        if(find.y>0){
            printf("�ĤG�H��");
        }
        else{
            printf("�ĤT�H��");
        }
    }
    else{
        if(find.y<0){
            printf("�ĥ|�H��");
        }
        else{
            printf("�Ĥ@�H��");
        }
    }
}

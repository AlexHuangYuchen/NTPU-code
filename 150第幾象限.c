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
            printf("第二象限");
        }
        else{
            printf("第三象限");
        }
    }
    else{
        if(find.y<0){
            printf("第四象限");
        }
        else{
            printf("第一象限");
        }
    }
}

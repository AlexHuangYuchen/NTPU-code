#include<stdio.h>
struct Student
{
    char studentName[20];
    int score;
};
typedef struct Student student;
int main(){
    int max=-1;
    int sum=0;
    int index;
    student ave[3];
    for(int i=0;i<3;i++){
        scanf("%s%d",ave[i].studentName,&ave[i].score);
        sum+=ave[i].score;
        if(ave[i].score>max){
            max=ave[i].score;
            index=i;
        }
    }
    printf("avg = %d\nmax = %s",sum/3,ave[index].studentName);
}

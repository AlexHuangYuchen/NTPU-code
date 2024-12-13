#include<stdio.h>
#include<stdlib.h>
typedef struct matrix {
    int row, col;
    int* data;
} *MATRIX;
int main(){
  MATRIX two[2];//每個two[i]是指向結構的指標
  for(int i=0;i<2;i++){
    two[i]=malloc(sizeof(struct matrix));
  }
  scanf("%d %d",&(two[0]->row),&(two[0]->col));
  //printf("%d %d\n",two[i]->row,two[i]->col);
  two[0]->data=malloc(two[0]->row*two[0]->col*sizeof(int));
  for(int i=0;i<two[0]->row*two[0]->col;i++){
        scanf("%d",&(two[0]->data[i]));
  }
  scanf("%d %d",&(two[1]->row),&(two[1]->col));
  //printf("%d %d\n",two[i]->row,two[i]->col);
  two[1]->data=malloc(two[1]->row*two[1]->col*sizeof(int));
  for(int i=0;i<two[1]->row*two[1]->col;i++){
        scanf("%d",&(two[1]->data[i]));
  }
  if(two[0]->row==two[1]->row && two[0]->col==two[1]->col){
        for(int i=0;i<two[0]->row*two[0]->col;i++){
            if((i+1)%two[0]->col==0){
                printf("%d\n",two[0]->data[i]+two[1]->data[i]);
            }
            else{
                 printf("%d ",two[0]->data[i]+two[1]->data[i]);
            }
        }
  }
  else{
    printf("不可相加\n");
  }
  /*
  free(two[0]);
  free(two[1]);
  free(two[0]->data);
  free(two[1]->data);
   */
}

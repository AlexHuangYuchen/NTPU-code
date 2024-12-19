#include<stdio.h>
int row,col,map[400][400],lakes[10000]={0},cont=-1;
int find(int r,int c){
    if(map[r][c]==0 || map[r][c]==-1){
        return 0;
    }
    int sum=1;
    map[r][c]=-1;
    if(r+1<row){
        sum+=find(r+1,c);
    }
    if(r-1>=0){
        sum+=find(r-1,c);
    }
    if(c+1<col){
        sum+=find(r,c+1);
    }
    if(c-1>=0){
        sum+=find(r,c-1);
    }
    return sum;

}
int main(){
    scanf("%d%d",&row,&col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(map[i][j]==1){
                cont++;
                lakes[cont]=find(i,j);
                //printf("%d\n",lakes[cont]);
            }
        }
    }
    //printf("%d\n",cont);
    int temp;
    for(int i=cont-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(lakes[j]<lakes[j+1]){
                temp=lakes[j+1];
                lakes[j+1]=lakes[j];
                lakes[j]=temp;
            }
        }
    }
    for(int i=0;i<=cont;i++){
        printf("%d\n",lakes[i]);
    }
}

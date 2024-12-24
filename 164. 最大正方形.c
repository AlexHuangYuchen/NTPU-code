#include <stdio.h>
#include <stdlib.h>
int min(int a,int b){
    return a<b ? a:b;
}
void findMaximalSquare(int** matrix, int rows, int cols, int *maxEdge) {
    *maxEdge=0;
    for(int i=0;i<rows+1;i++){////記得要加1
        for(int j=0;j<cols+1;j++){////記得要加1
            if(matrix[i][j]>*maxEdge){
                *maxEdge=matrix[i][j];
            }
            if(i-1<0 || j-1<0||matrix[i][j]==0||matrix[i-1][j-1]==0 ){
                continue;
            }
            matrix[i][j]=1+min(min(matrix[i-1][j],matrix[i][j-1]),matrix[i-1][j-1]);
            if(matrix[i][j]>*maxEdge){
                *maxEdge=matrix[i][j];
            }
        }
    }
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int** matrix = (int**)malloc(row * sizeof(int*));
    int i, j, tmp;
    for (i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &tmp);
            matrix[i][j] = tmp;
        }
    }

    int maxEdge = 0;
    findMaximalSquare(matrix, row - 1, col - 1, &maxEdge);

    printf("%d", maxEdge * maxEdge);
    for (i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);

}

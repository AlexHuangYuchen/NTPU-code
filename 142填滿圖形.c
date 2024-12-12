#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void floodFill(int** image, int imageSize, int sr, int sc, int newColor) {
    int tar=image[sr][sc];
    void spread(int x,int y){
        if(x<0 || x>=imageSize || y<0 || y>=imageSize || image[x][y]!=tar){
            return;///空回傳值 提早結束
        }
        else{
            image[x][y]=newColor;
            spread(x+1,y);
            spread(x-1,y);
            spread(x,y+1);
            spread(x,y-1);
        }
    }
    spread(sr,sc);
}
int main() {
    int n;
    int sr, sc, newColor;
    scanf("%d", & n);
    int** p = NULL;
    p = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        p[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            scanf("%d", &tmp);
            p[i][j] = tmp;
        }
    }
    scanf("%d", &sr);
    scanf("%d", &sc);
    scanf("%d", &newColor);
    floodFill(p, n, sr, sc, newColor);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
    return 0;

}

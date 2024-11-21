#include<stdio.h>
int main(){
    int n;
    int  o=92;
    //printf("%c\n",o);
    scanf("%d",&n);
    int po=65,ne=65;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(po>90){
                po=(po-90)+64;
            }
            if(j==i){
                printf("%c",po);
            }
            else{
                printf("%c ",po);
            }
            po++;
        }
        printf(" %c ",o);
        for(int k=1;k<=n-i+1;k++){
             if(ne>90){
                ne=(ne-90)+64;
            }
            printf("%c ",ne);
            ne++;
        }
        printf("\n");
    }
}

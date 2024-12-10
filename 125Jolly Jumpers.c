#include<stdio.h>
#include<math.h>
void Jolly_Jumpers(int Array[], int size) {
    int n[size-1];
    for(int i=0;i<size-1;i++){
        n[i]=abs(Array[i]-Array[i+1]);
        //printf("%d\n",n[i]);
    }
    int cont=size-1;
    for(int i=1;i<=size-1;i++){
        for(int j=0;j<size-1;j++){
            if(i==n[j]){
                cont--;
                break;
            }
        }
    }
    if(cont==0){
        printf("Jolly");
    }
    else if(cont!=0){
        printf("Not jolly");
    }
}
int main(){
    int size;
    scanf("%d", &size);
    int Array[100];
    for (int i = 0; i < size; i++) {
        scanf("%d", &Array[i]);
    }
    Jolly_Jumpers(Array, size);
}

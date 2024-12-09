#include<stdio.h>
void ID_Check(char ID[]) {
   int a=ID[0];
   int n;
   if(a==73){
        n=34;
   }
   else if(a==79){
        n=35;
   }
   else if(a>73 && a<79){
        n=a-65+10-1;
   }
   else if(a>79){
         n=a-65+10-2;
   }
   else{
        n=a-65+10;
   }
   printf("%d\n",n);
   int sum=0;
   sum+=(n/10)+(n%10)*9;
   //printf("%d\n",sum);
   for(int i=8;i>=1;i--){
        sum+=i*(ID[(9-i)]-48);
         //printf("%d\n",sum);
   }
   sum+=(ID[9]-48);
   //printf("%d\n",sum);
   if(sum%10==0){
        printf("real\n");
   }
   else{
        printf("fake\n");
   }
}
int main(){
    char ID[100];
    while (scanf("%s", ID) != EOF) {
        ID_Check(ID);
    }
}

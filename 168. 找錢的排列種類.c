#include <stdio.h>
 int moneyPerm(int k){
     if(k==0){
        return 1;
     }
     else if(k<0){
        return 0;
     }
    return moneyPerm(k-10)+moneyPerm(k-5)+moneyPerm(k-1);
}
int main(){
  int money;
  scanf("%d", &money);
  printf("%d", moneyPerm(money));
  return 0;
}

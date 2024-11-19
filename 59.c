#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main(){
    int a;
    scanf("%d",&a);
    char n[100];
    int cont=0;
    bool huei=1;
    //printf("%d",strlen(n)-1);
    int endindex;
    int length;
    long long int ten;
    long long int posi=0,nega=0;
    long long int A;
    int c=0;
    char rem;
    double overf=pow(2,31)-1;
    for(int i=0;i<a;i++){
           scanf("%s",&n);
           endindex=strlen(n)-1;
           length=strlen(n);
            cont=0;
            int A2;
           while(1){
                    huei=1;
                    posi=0;
                    nega=0;
                    /*
                    for(int o=0;o<=endindex;o++){
                        printf("%c",n[o]);
                    }
                    printf("\n");
                    */
                    for(int j=0;j<=(length/2)-1;j++){
                        if(n[j]!=n[endindex-j]){
                            huei=0;
                            break;
                        }
                    }
                    ///檢查是否回文
                    if(huei==1 && cont!=0){
                        printf("%d %d\n",cont,A2);
                       break;
                    }
                    else{
                        ten=1;
                        for(int k=endindex;k>=0;k--){
                            //inverse[endindex]=n[endindex-k];
                            posi+=(n[k]-48)*ten;
                            nega+=(n[endindex-k]-48)*ten;
                            ten*=10;
                        }
                        //printf("%d %d %d\n",posi,nega,posi+nega);
                        A=posi+nega;
                        A2=A;
                        if(posi+nega>overf){
                            printf("overflow!\n");
                            break;
                        }
                        else{
                            c=0;
                            while(A!=0){
                                rem=(A%10)+'0';
                                //printf(" %c",rem);
                                n[c]=rem;
                                A/=10;
                                c++;
                            }
                            endindex=c-1;
                            length=c;
                            /*
                            printf("\n");
                            printf("endindex=%d length=%d",endindex,length);
                            printf("\n");
                            */
                            cont++;
                        }
                    }

           }

    }
}

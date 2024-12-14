#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

typedef struct pair {
    int frequency;
    char charASCII;
} pair;

void print(pair* myData)
{
    int i;
    for (i=0 ; i<95 ; i++)
        (myData[i].frequency==0)?printf(""):printf("%d %d\n",myData[i].charASCII,myData[i].frequency);
}

int main()
{
    struct pair* myData=(struct pair*)malloc(95*sizeof(struct pair));
    int i, len, flag=0;
    char str[9999];

    while (gets(str)!=NULL) {
        int len=strlen(str);
        if (flag!=0) printf("\n");
        flag++;
        for(int i=0;i<95;i++){
            myData[i].frequency=0;
            myData[i].charASCII=i+32;

        }
        int integer;
        for(int i=0;i<len;i++){
            integer=str[i];
            if(integer>=32 && integer<=126){
                myData[integer-32].frequency++;
            }
        }
        struct pair temp;
        int inte_b,inte_a;
        for(int i=93;i>=0;i--){
            for(int j=0;j<=i;j++){
                inte_b=myData[j].charASCII;
                inte_a=myData[j+1].charASCII;
                if(myData[j].frequency>=myData[j+1].frequency && inte_b<inte_a){
                    temp=myData[j+1];
                    myData[j+1]=myData[j];
                    myData[j]=temp;
                }
            }
        }
        print(myData);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int num;
    int mod;
    int Even_Odd;
} List;

int main(){
    int N, M;
    int x, y;
    scanf("%d%d", &N, &M);


    struct List *list = malloc(N * sizeof(struct List));
    if (list == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }


    for (int i = 0; i < N; i++) {
        scanf("%d", &list[i].num);
        list[i].mod = list[i].num % M;
        list[i].Even_Odd = (list[i].num % 2 == 0) ? 1 : 0;
    }

    struct List temp;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {

            if (list[j].mod > list[j + 1].mod) {
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }

            else if (list[j].mod == list[j + 1].mod) {

                if (list[j].Even_Odd == 1 && list[j + 1].Even_Odd == 0) {
                    temp = list[j + 1];
                    list[j + 1] = list[j];
                    list[j] = temp;
                }

                else if (list[j].Even_Odd == 1 && list[j + 1].Even_Odd == 1) {
                    if (list[j].num > list[j + 1].num) {
                        temp = list[j + 1];
                        list[j + 1] = list[j];
                        list[j] = temp;
                    }
                }

                else if (list[j].Even_Odd == 0 && list[j + 1].Even_Odd == 0) {
                    if (list[j].num < list[j + 1].num) {
                        temp = list[j + 1];
                        list[j + 1] = list[j];
                        list[j] = temp;
                    }
                }
            }
        }
    }


    scanf("%d%d", &x, &y);


    printf("%d %d\n", N, M);
    for (int i = 0; i < N; i++) {
        printf("%d\n", list[i].num);
    }
    printf("0 0\n");


    free(list);
    return 0;
}


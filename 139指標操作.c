int main() {
    int n = 5;
    int a[5];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int *p = a;
    printf("%d ", *p);//�d��:�L�X��e���Ъ���
    printf("%d ", *p);//�L�X��e���Ъ��ȫ�A���ФU��
    p++;
    printf("%d ", *p);//�L�X��e���Ъ��ȫ�A�ӭ�+1
    *p+=1;
    p++;
    printf("%d ", *p);//���ФU����A�A�L�X��e���Ъ���
    *p+=1;
    printf("%d ", *p);//�����e���Ъ���+1�A�A�L�X��e���Ъ���
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

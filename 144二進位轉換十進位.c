#include<stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
// val : 紀錄0或1
// next : 記錄下一個結構
int getDecimalValue(struct ListNode* head)
{
    int len[31]={0},cont=-1;
    // add your code
    int p;
    int  sum=0;
    while(head!=NULL){
        /*
        cont++;
        len[cont]=temp->val;
        */
        sum = (sum << 1) | head->val;
        head=head->next;
    }
    /*
    int c=cont;
    for(int i=0;i<=cont;i++){
        p=1;
        for(int i=0;i<c;i++){
            p*=2;
        }
        sum+=len[i]*p;
        c--;
    }
    */
    return sum;
}
void Construct(struct ListNode* node, int length, int num)
{
    int a;
    scanf("%d", &a);
    node->val = a;

    if(num >= length)
    {
        node->next = NULL;
        return;
    }
    node -> next = (struct ListNode* )malloc(sizeof(struct ListNode));
    num++;
    Construct(node->next, length, num);
}

int main()
{
    struct ListNode *head;
    int n, a, length;
    head = (struct ListNode* )malloc(sizeof(struct ListNode));
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &length);
        Construct(head, length, 1);
        int ans = getDecimalValue(head);
        printf("%d\n", ans);
    }
}

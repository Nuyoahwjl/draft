#include <stdio.h>
#include <stdlib.h>
typedef struct Dnode
{
    int data;
    struct Dnode *prior,*next;
    // DuLinkList prior,next;
} *DuLinkList;

void adjust(DuLinkList L);
int main()
{
    //创建双向循环链表
    DuLinkList head,tail;
    head=(DuLinkList)malloc(sizeof(struct Dnode));
    head->data=0;
    head->prior=head;
    head->next=head;
    tail=head;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        DuLinkList p=(DuLinkList)malloc(sizeof(struct Dnode));
        p->data=temp;
        {
            tail->next=p;
            p->prior=tail;
            p->next=head;
            head->prior=p;
            tail=p;
        }
    }
    adjust(head);
    DuLinkList q=head->next;
    while(q!=head)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    return 0;
}

void adjust(DuLinkList L)
{
    DuLinkList first=L->next;
    DuLinkList last=L->prior;
    while(first!=last&&first->next!=last)
    {
        DuLinkList p=first->next;
        first->next=p->next;
        p->next->prior=first;
        DuLinkList q=last->next;
        last->next=p;
        p->next=q;
        q->prior=p;
        p->prior=last;

        first=first->next;
    }
}
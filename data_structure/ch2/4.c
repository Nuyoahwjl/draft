#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE,*LinkList;

LinkList creat(void);
void TriLinkList (LinkList A,LinkList B,LinkList C);

int main()
{
    LinkList A,B,C;
    A=creat();
    B=creat();
    C=creat();
    TriLinkList(A,B,C);
    for(LinkList p=A->next;p!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
    return 0;
}

LinkList creat(void)
{
    LinkList head=(LinkList)malloc(sizeof(NODE));
    LinkList tail=head;
    int temp;
    scanf("%d",&temp);
    while(temp!=0)
    {
        LinkList p=(LinkList)malloc(sizeof(NODE));
        p->data=temp;
        tail->next=p;
        tail=p;
        scanf("%d",&temp);
    }
    tail->next=NULL;
    return head;
}

void TriLinkList (LinkList A,LinkList B,LinkList C)
{
    LinkList D=(LinkList)malloc(sizeof(NODE));
    LinkList tail=D;
    LinkList tempB=B,tempC=C;
    B=B->next;
    C=C->next;
    free(tempB);
    free(tempC);
    //合并B、C存至D中并释放B、C
    {
        while(B!=NULL&&C!=NULL){
            if(B->data==C->data){
                //创建新节点
                LinkList p=(LinkList)malloc(sizeof(NODE));
                p->data=B->data;
                tail->next=p;
                tail=p;
                //删除旧节点
                tempB=B;
                tempC=C;
                B=B->next;
                C=C->next;
                free(tempB);
                free(tempC);
            }
            else if(B->data>C->data){
                tempC=C;
                C=C->next;
                free(tempC);
            }
            else{
                tempB=B;
                B=B->next;
                free(tempB);                
            }
        }
        tail->next=NULL;
        if(B==NULL){
            for(LinkList q=C;q!=NULL; ){
            LinkList temp=q;
            q=q->next;
            free(temp);
            }
        }
        else{
            for(LinkList q=B;q!=NULL; ){
            LinkList temp=q;
            q=q->next;
            free(temp);
            }
        }
    }
    //从A中删除D中元素
    LinkList p=A,q=A->next;
    D=D->next;
    while(q!=NULL&&D!=NULL){
        if(q->data==D->data){
            p->next=q->next;
            LinkList temp=q,tempD=D;;
            q=q->next;
            D=D->next;
            free(temp);
            free(tempD);
        }
        else if(q->data>D->data){
            LinkList tempD=D;
            D=D->next;
            free(tempD);
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
}
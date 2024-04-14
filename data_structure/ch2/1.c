#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
typedef struct
{
    int *elem;
    int length;
    int listsize;
}Sqlist;

int insert(Sqlist *L,int x);
int main()
{
    Sqlist *L;
    L->elem=(int *)malloc(sizeof(int)*LIST_INIT_SIZE);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    int temp;
    int i=0;
    scanf("%d",&temp);
    while(temp!=0)
    {
        L->elem[i++]=temp;
        L->length++;
        scanf("%d",&temp);
    }
    scanf("%d",&temp);
    insert(L,temp);
    for(int j=0;j<L->length;j++)
        printf("%d ",L->elem[j]);
    return 0;
}

int insert(Sqlist *L,int x)
{
    if(L->length>=L->listsize)
    {
        int *newbase=(int *)realloc(L->elem,sizeof(int)*(L->listsize+LISTINCREMENT));
        if(newbase)
        {
            L->elem=newbase;
            L->listsize+=LISTINCREMENT;
        }
    }
    if(L->length==0)
    {
        L->elem[0]=x;
        L->length++;
    }
    else
    {
        int i=0;
        while(L->elem[i]<x)
        {
            i++;
        }
        for(int j=L->length;j>i;j--)
        {
            L->elem[j]=L->elem[j-1];
        }
        L->elem[i]=x;
        L->length++;
    }
    return 1;
}
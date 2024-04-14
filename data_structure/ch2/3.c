#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

SqList creat(void);
void TriSqList(SqList *A,SqList B,SqList C);

int main()
{
    SqList A=creat(),B=creat(),C=creat();

    TriSqList(&A,B,C);
    for(int k=0;k<A.length;k++)
        printf("%d ",A.elem[k]);
    return 0;
}

SqList creat()
{
    SqList L;
    L.elem=(int *)malloc(sizeof(int)*LIST_INIT_SIZE);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    int temp;
    scanf("%d",&temp);
    int i=0;
    while(temp!=0)
    {
        if(L.length>=L.listsize)
        {
            int *newbase=(int *)realloc(L.elem,sizeof(int)*(L.listsize+LISTINCREMENT));
            if(newbase)
            {
                L.elem=newbase;
                L.listsize+=LISTINCREMENT;
            }
        }
        L.elem[i++]=temp;
        L.length++;
        scanf("%d",&temp);
    }
    return L;
}

void TriSqList(SqList *A,SqList B,SqList C)
{
    SqList temp;
    temp.listsize=B.length<=C.length?B.length:C.length;
    temp.elem=(int *)malloc(sizeof(int)*temp.listsize);
    temp.length=0;
    int num=0;
    int i=0,j=0;
    while(i<B.length&&j<C.length)
    {
        if(B.elem[i]==C.elem[j])
        {
            temp.elem[num++]=B.elem[i];
            temp.length++;
            i++;
            j++;
        }
        else if(B.elem[i]<C.elem[j])
            i++;
            else
            j++;
    }
    for(int k=0;k<temp.length;k++)
    {
        int l=0;
        while(temp.elem[k]!=A->elem[l]&&l<A->length)
        {
            l++;
        }
        if(l<A->length)
        {
            for(l;l<A->length-1;l++)
            {
                A->elem[l]=A->elem[l+1];
            }
            A->length--;
        }
    }
}

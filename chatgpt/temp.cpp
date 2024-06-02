#include <stdio.h>
#include <stdlib.h>
typedef int status;
#define OK 1
typedef struct{
    int data;
    Node* lchild;
    Node* rchild;
}Node,*BiTree;

status PreOrder(BiTree T)
{
    BiTree stack[100];
    int top=0;
    stack[top++]=T;
    while(top)
    {
        T=stack[top-1];
        while(T)
        {
            printf("%d ",T->data);
            T=T->lchild;
            stack[top++]=T;
        }
        top--;
        if(top)
        {
            T=stack[--top];
            stack[top++]=T->rchild;
        }
    }
    return OK;
}
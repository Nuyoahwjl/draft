#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct TWSTACK{
    int elem[N];
    int top1,top2;
}TWSTACK;

void inistack(TWSTACK S)
{
    S.top1=0;
    S.top2=N-1;
}

int push(TWSTACK S,int i,int e)
{
    if(i==1)
    {
        if(S.top1<=S.top2)
        {
            S.elem[S.top1]=e;
            S.top1++;
            return 1;
        }
        else return 0;
    }
    else
    {
        if(S.top1<=S.top2)
        {
            S.elem[S.top2]=e;
            S.top2--;
            return 1;
        }
        else return 0;
    }
}

int pop(TWSTACK S,int i,int e)
{
    if(i==1)
    {
        if(S.top1>0)
        {
            S.top1--;
            e=S.elem[S.top1];
            return 1;
        }
        else return 0;
    }
    else
    {
        if(S.top2<N-1)
        {
            S.top2++;
            e=S.elem[S.top2];
            return 1;
        }
        else return 0;
    }
}
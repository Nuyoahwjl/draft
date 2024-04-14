#define N 100
#define MAXLENGTH 100

#include <stdio.h>
typedef struct TWSTACK{
    int elem[N];
    int top1,top2;
}TWSTACK;
typedef struct QUEUE
{
    int elem[MAXLENGTH];
    int front,length; 
}QUEUE;

int main()
{
    TWSTACK S;
    int e,f;
    QUEUE Q;
    inistack(S);
    iniQueue(Q);
    char c;
    while((c=getchar())!='@')
    {
        push(S,1,c);
        enQueue(Q,c);
    }
    while(1)
    {
        if(pop(S,1,e)!=deQueue(Q,f))
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}


int pop(TWSTACK S,int i,int e)
{
    if(i==1)
    {
        if(S.top1>0)
        {
            S.top1--;
            e=S.elem[S.top1];
            return e;
        }
        else return -1;
    }
    else
    {
        if(S.top2<N-1)
        {
            S.top2++;
            e=S.elem[S.top2];
            return e;
        }
        else return -1;
    }
}

int deQueue(QUEUE Q, int e)
//将Q队首元素出队，赋值给e。成功出队返回1，否则返回0
{
/***************begin***************/
    if(Q.length==0)
    {
        return -1;
    }
    else
    {
        e=Q.elem[Q.front];
        Q.front=(Q.front+1)%MAXLENGTH;
        Q.length--;
        return e;
    }
/*************** end ***************/
}



// int isPalindrome(char *str)
// //判断字符串str是否回文，是则返回1，否则返回0
// {
// /**********begin**********/
// QUEUE Q,O;
// iniQueue(Q);
// int n=0;
// while((*(str+n))!='@'){
//     enQueue(Q,(*(str+n)));
//     n++;
// }
// while(n){
//     char e;
//     deQueue(Q,e);
//     if(e!=*(str+n-1)){
//     return 0;
//     }
//     n--;
// }

return 1;
/********** end **********/
}
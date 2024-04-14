#include <stdio.h>
#define MAXLENGTH 100
typedef struct QUEUE
{
    int elem[MAXLENGTH];
    int front,length;
}QUEUE;
//在下面的begin和end间填写相应代码
void iniQueue(QUEUE Q)
//该函数实现初始化Q
{
/***************begin***************/
    Q.front=0;
    Q.length=0;
/*************** end ***************/
}
int enQueue(QUEUE Q,int e)
//将元素e入队Q。成功入栈返回1，否则返回0
{
/***************begin***************/
    if(Q.length<MAXLENGTH)
    {
        Q.elem[(Q.front+Q.length)%MAXLENGTH]=e;
        Q.length++;
        return 1;
    }
    else
    {
        return 0;
    }
/*************** end ***************/
}
int deQueue(QUEUE Q, int e)
//将Q队首元素出队，赋值给e。成功出队返回1，否则返回0
{
/***************begin***************/
    if(Q.length==0)
    {
        return 0;
    }
    else
    {
        e=Q.elem[Q.front];
        Q.front=(Q.front+1)%MAXLENGTH;
        Q.length--;
        return 1;
    }
/*************** end ***************/
}
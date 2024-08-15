#include <stdio.h>
int stack[200000];
int top=0;
void push(int x)
{
    stack[top++]=x;
}
int pop(void)
{
    return stack[--top];
}
void search()
{
    int max=0;
    for(int i=0;i<top;i++)
    {
        if(stack[i]>max)
            max=stack[i];
    }
    printf("%d\n",max);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int op;
        scanf("%d",&op);
        switch (op)
        {
        case 0:
            int x;
            scanf("%d",&x);
            push(x);
            break;
        case 1:
        {
            if(top)
                pop();
            break;
        }
        case 2:
            search();
        default:
            break;
        }
    }
    return 0;
}
#include <stdio.h>
#define INT_MAX 100000000
int suanfa(int a[],int n,int arrsize)
{
    if(n>arrsize)
        printf("ERROR");
    else
    {
        a[0]=2;
        int flag=1;
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]*2*(i+1);
            if(a[i]>INT_MAX)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            for(int i=0;i<n;i++)
                printf("%d ",a[i]);
        }
        else
            printf("ERROR");
    }
    return 0;
}

int main()
{
    int n,arrsize;
    scanf("%d %d",&n,&arrsize);
    int a[arrsize];
    suanfa(a,n,arrsize);
    // int a,b;
    // scanf("%d%d",&a,&b);
    // printf("%d",a+b);
    return 0;
}
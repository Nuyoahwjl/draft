#include<stdio.h>
#include<stdlib.h>
void ShiftRightCircular(int *A,int n,int k)
{
/************** begin *****************/
    if(k>0) k=k%n;
    else if(k==0) return;
         else k=n-(-k)%n;
    int temp[k];
    for(int i=k-1;i>=0;i--)
        temp[i]=A[--n];
    n+=k;
    for(int i=n-1;i>=k;i--)
        A[i]=A[i-k];
    for(int i=0;i<k;i++)
        A[i]=temp[i];
/**************  end  *****************/
}

int main()
{
    int n,k;
    int *p;
    scanf("%d %d",&n,&k);
    p=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        p[i]=i+1;
    ShiftRightCircular(p,n,k);
    for(int i=0;i<n;i++)
        printf(" %d",p[i]);
    return 0;
}
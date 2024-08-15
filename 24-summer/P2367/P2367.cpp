//差分数组
#include <stdio.h>
int a[5000001];
int d[5000001];
int main()
{
    int n,p;
    int min=1e9;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        d[i]=a[i]-a[i-1];
        //a[i] = d[1] + d[2] + ... + d[i]
    }
    for(int i=0;i<p;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        d[x]+=z;
        d[y+1]-=z;
        //对于区间[x, y]内的每个元素加上z,我们可以通过对d[x]加上z,d[y + 1]减去z来实现。
        //d[x]+=z表示从位置x开始,每个元素都加上z。
        //d[y + 1]-=z表示从位置y + 1开始,每个元素都减去z,即区间[x, y]之后的元素不再受到影响。
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+d[i];
        if(min>a[i])
            min=a[i];
    }
    printf("%d",min);
    return 0;
}

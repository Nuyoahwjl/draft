// #include <stdio.h>
// typedef struct 
// {
//     int l,r;
// }node;

// int main()
// {
//     node a[100001];
//     a[1].l=0;
//     a[1].r=0;
//     int N,M;
//     scanf("%d",&N);
//     int flag[N+1];
//     for(int i=1;i<=N;i++)
//         flag[i]=1;
//     for(int i=2;i<=N;i++)
//     {
//         int k,p;
//         scanf("%d%d",&k,&p);
//         if(p==0)
//         {
//             a[i].l=a[k].l;
//             a[i].r=k;
//             a[a[k].l].r=i;
//             a[k].l=i;
//         }
//         if(p==1)
//         {
//             a[i].r=a[k].r;
//             a[i].l=k;
//             a[a[k].r].l=i;
//             a[k].r=i;
//         }
//     }
//     scanf("%d",&M);
//     for(int i=0;i<M;i++)
//     {
//         int x;
//         scanf("%d",&x);
//         flag[x]=0;
//     }
//     int begin=0;
//     for(int i=1;i<=N;i++)
//         if(a[i].l==0) begin=i;
//     while(a[begin].r!=0)
//     {
//         if(flag[begin])
//             printf("%d ",begin);
//         begin=a[begin].r;
//     }
//     return 0;
// }

#include <stdio.h>
typedef struct {
    int l, r;
} node;
int main() {
    node a[100001];
    for (int i = 0; i < 100001; i++) {
        a[i].l = 0;
        a[i].r = 0;
    }

    int N, M;
    scanf("%d", &N);
    int flag[N + 1];
    for (int i = 1; i <= N; i++) {
        flag[i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        int k, p;
        scanf("%d %d", &k, &p);
        if (p == 0) {  // 插入到 k 的左边
            a[i].l = a[k].l;
            a[i].r = k;
            if (a[k].l != 0) {
                a[a[k].l].r = i;
            }
            a[k].l = i;
        } else if (p == 1) {  // 插入到 k 的右边
            a[i].r = a[k].r;
            a[i].l = k;
            if (a[k].r != 0) {
                a[a[k].r].l = i;
            }
            a[k].r = i;
        }
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        flag[x] = 0;
    }

    int begin = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i].l == 0) {
            begin = i;
            break;
        }
    }

    while (a[begin].r != 0) {
        if (flag[begin]) {
            printf("%d ", begin);
        }
        begin = a[begin].r;
    }
    if (flag[begin]) {  // 输出最后一个节点
        printf("%d", begin);
    }
    // printf("\n");  // 如果需要换行
    return 0;
}

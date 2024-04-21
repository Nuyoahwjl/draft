// 将i,j压缩为一个longlong数据
#include<cstdio>
#include<map>
using namespace std;
int n,q,p,k;
map<long long,int>b;
long long i,j;
int main()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d%lld%lld",&p,&i,&j);
		if(p==1)
		{
			scanf("%d",&k);
			b[i*1000000+j]=k;
		}
		else printf("%d\n",b[i*1000000+j]);
	}
	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// typedef struct P3613
// {
//     long long i,j,k;
//     struct P3613 *next;
// }*node;

// void search(node head,long long i,long long j);

// int main()
// {
//     int n,q,p;
//     long long i,j,k;
//     node head;
//     head=(node)malloc(sizeof(P3613));
//     head->next=NULL;
//     node tail=head;
//     scanf("%d%d",&n,&q);
//     while(q--)
//     {
//         scanf("%d",&p);
//         if(p==1)
//         {
//             scanf("%lld%lld%lld",&i,&j,&k);
//             node temp=(node)malloc(sizeof(P3613));
//             temp->i=i;
//             temp->j=j;
//             temp->k=k;
//             temp->next=NULL;
//             tail->next=temp;
//             tail=temp;
//         }
//         else if(p==2)
//         {
//             scanf("%lld%lld",&i,&j);
//             search(head,i,j);
//         }
//     }
//     return 0;
// }

// void search(node head,long long i,long long j)
// {
//     node p=head->next;
//     while(p!=NULL)
//     {
//         if(p->i==i&&p->j==j)
//             printf("%lld\n",p->k);
//         p=p->next;
//     }
// }
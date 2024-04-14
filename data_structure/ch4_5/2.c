//稀疏矩阵加法
#include <stdio.h>
#define  MAXSIZE 10000
typedef int ElemType;
typedef struct  {
   int       i,j;//非零元行、列下标
   ElemType    e;
 } Triple;        //三元组定义
typedef struct  {
   Triple  data[MAXSIZE+1];   //三元组从下标1开始存放
   int  mu,nu,tu;         //对于矩阵的行数、列数和非零元素值
 } TSMatrix;              //三元组顺序表的定义

TSMatrix ADD(TSMatrix A, TSMatrix B);
int main()
{
	TSMatrix A[3],B,C;
   int i,j;
   for(i=0;i<2;i++)
   {
   		scanf("%d%d%d",&A[i].mu,&A[i].nu,&A[i].tu);
   		for(j=1;j<=A[i].tu;j++)
   		 	scanf("%d%d%d",&A[i].data[j].i,&A[i].data[j].j,&A[i].data[j].e);
   }
   A[2]=ADD(A[0],A[1]);
   printf("%d %d %d\n",A[2].mu,A[2].nu,A[2].tu);
   for(i=1;i<=A[2].tu;i++)
   		printf("%d %d %d     ",A[2].data[i].i,A[2].data[i].j,A[2].data[i].e);
	return 1;
}

TSMatrix ADD(TSMatrix A, TSMatrix B) {
    TSMatrix C;
    C.mu = A.mu;
    C.nu = A.nu;
    C.tu = 0;

    int a = 1, b = 1, c = 1;// 表示在矩阵 A、B 和 C 中当前处理的非零元素的索引

    
    while (a <= A.tu && b <= B.tu) {
        if (A.data[a].i < B.data[b].i || (A.data[a].i == B.data[b].i && A.data[a].j < B.data[b].j)) 
        {
            C.data[c++] = A.data[a++];
        } 
        else if (A.data[a].i > B.data[b].i || (A.data[a].i == B.data[b].i && A.data[a].j > B.data[b].j)) 
        {
            C.data[c++] = B.data[b++];
        } 
        else 
        {
            ElemType sum = A.data[a].e + B.data[b].e;
            if (sum != 0) {
                C.data[c].i = A.data[a].i;
                C.data[c].j = A.data[a].j;
                C.data[c].e = sum;
                c++;
            }
            a++;
            b++;
        }
    }

    while (a <= A.tu) {
        C.data[c++] = A.data[a++];
    }

    while (b <= B.tu) {
        C.data[c++] = B.data[b++];
    }

    C.tu = c - 1; // 更新 C 中实际的非零元素数量
    return C;
}

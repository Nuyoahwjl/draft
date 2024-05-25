// #include <stdio.h>
// #include <stdlib.h>

// int MidNum(int a[],int n);
// int mid(int a[],int low,int high,int k);
// int part(int a[],int low,int high);

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",a+i);
//     }
//     printf("mid:%d",MidNum(a,n));
//     return 0;
// }

// int MidNum(int a[],int n)
// {
//     if(n%2==1)
//     {
//         return mid(a,0,n-1,n/2);
//     }
//     else 
//     {
//         int mid1=mid(a,0,n-1,n/2);
//         int mid2=mid(a,0,n-1,n/2+1);
//         return (mid1+mid2)/2;
//     }
// }

// int mid(int a[],int low,int high,int k)
// {
//     if(high==low) return a[low];
//     int p=part(a,low,high);
//     if(p==k) return a[k];
//     else if(p>k)
//         return mid(a,low,p-1,k);
//     else return mid(a,p+1,high,k);
// }

// int part(int a[],int low,int high)
// {
//     int flag=a[low];
//     while(low<high)
//     {
//         while(low<high&&a[high]>=flag) high--;
//         a[low]=a[high];
//         while(low<high&&a[low]<=flag) low++;
//         a[high]=a[low];
//     }
//     a[low]=flag;
//     return low;
// }


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // 定义数组最大长度

// 函数声明
int findMedian(int a[], int n);
int findKthSmallest(int a[], int low, int high, int k);
int partition(int a[], int low, int high);

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Invalid input.\n");
        return 1;
    }

    int *a = (int *)malloc(n * sizeof(int)); // 动态分配内存
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid input.\n");
            free(a); // 释放动态分配的内存
            return 1;
        }
    }

    int median = findMedian(a, n);
    printf("Median: %d\n", median);

    free(a); // 释放动态分配的内存
    return 0;
}

// 寻找中位数的函数
int findMedian(int a[], int n) {
    if (n % 2 == 1) {
        return findKthSmallest(a, 0, n - 1, n / 2);
    } else {
        int mid1 = findKthSmallest(a, 0, n - 1, n / 2);
        int mid2 = findKthSmallest(a, 0, n - 1, n / 2 + 1);
        return (mid1 + mid2) / 2;
    }
}

// 在数组中寻找第k小的元素的函数
int findKthSmallest(int a[], int low, int high, int k) {
    if (high == low) return a[low];

    int p = partition(a, low, high);
    if (p == k) return a[k];
    else if (p > k) return findKthSmallest(a, low, p - 1, k);
    else return findKthSmallest(a, p + 1, high, k);
}

// 分区函数
int partition(int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot) low++;
        a[high] = a[low];
    }
    a[high] = pivot; // 移动pivot到正确的位置
    return high;
}

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

int deque[MAXN]; // 双端队列，存储的是数组a中的下标
int a[MAXN];     // 输入的数组
int minRes[MAXN]; // 最小值结果
int maxRes[MAXN]; // 最大值结果

// 用于处理滑动窗口最小值和最大值
void slidingWindow(int n, int k) {
    int front = 0, back = 0; // 初始化双端队列的头尾指针
    
    // 求最小值
    for (int i = 0; i < n; ++i) {
        // 移出窗口外的元素
        if (front < back && deque[front] < i - k + 1)
            front++;
        // 保持队列递增
        while (front < back && a[deque[back - 1]] >= a[i])
            back--;
        deque[back++] = i;
        // 从窗口开始大小为k时，记录结果
        if (i >= k - 1)
            minRes[i - k + 1] = a[deque[front]];
    }
    
    // 重置队列指针，用于求最大值
    front = back = 0;
    
    // 求最大值
    for (int i = 0; i < n; ++i) {
        // 移出窗口外的元素
        if (front < back && deque[front] < i - k + 1)
            front++;
        // 保持队列递减
        while (front < back && a[deque[back - 1]] <= a[i])
            back--;
        deque[back++] = i;
        // 从窗口开始大小为k时，记录结果
        if (i >= k - 1)
            maxRes[i - k + 1] = a[deque[front]];
    }
    
    // 输出结果
    for (int i = 0; i <= n - k; ++i)
        printf("%d ", minRes[i]);
    printf("\n");
    for (int i = 0; i <= n - k; ++i)
        printf("%d ", maxRes[i]);
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    
    slidingWindow(n, k);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3000000  // 最大 n 的值

int a[MAX_N + 1];
int f[MAX_N + 1];
int stack[MAX_N + 1];
int top = -1;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 单调栈的实现
    for (int i = 1; i <= n; i++) {
        while (top >= 0 && a[stack[top]] < a[i]) {
            f[stack[top]] = i;
            top--;
        }
        stack[++top] = i;
    }

    // 栈中剩下的元素没有更大的元素，所以赋值为 0
    while (top >= 0) {
        f[stack[top]] = 0;
        top--;
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    return 0;
}

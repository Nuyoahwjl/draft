#include <stdio.h>

#define MAXN 30

int n;
int matrix[MAXN][MAXN];

// 使用DFS将从边界可以到达的所有0标记为-1
void markEdgeConnectedZeros(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return;
    if (matrix[x][y] != 0) return;

    matrix[x][y] = -1;

    markEdgeConnectedZeros(x - 1, y); // 上
    markEdgeConnectedZeros(x + 1, y); // 下
    markEdgeConnectedZeros(x, y - 1); // 左
    markEdgeConnectedZeros(x, y + 1); // 右
}

int main() {
    scanf("%d", &n);
    
    // 输入方阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 处理边界的0，标记能从边界到达的0
    for (int i = 0; i < n; i++) {
        markEdgeConnectedZeros(i, 0);       // 左边界
        markEdgeConnectedZeros(i, n - 1);   // 右边界
        markEdgeConnectedZeros(0, i);       // 上边界
        markEdgeConnectedZeros(n - 1, i);   // 下边界
    }

    // 将闭合圈内部的0填涂为2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = 2;
            }
        }
    }

    // 将标记为-1的格子还原为0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

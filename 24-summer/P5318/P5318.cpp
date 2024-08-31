#include <stdio.h>
#include <stdbool.h>

// 使用全局变量定义最大节点数
#define MAX_NODES 1005

// DFS 函数声明
void DFS(bool G[MAX_NODES][MAX_NODES], bool visited[], int n, int start);

// BFS 函数声明
void BFS(bool G[MAX_NODES][MAX_NODES], bool visited[], int n, int start);

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    // 使用 MAX_NODES 限定的二维数组
    bool G[MAX_NODES][MAX_NODES] = {0};
    bool visited[MAX_NODES] = {0};

    // 初始化图的邻接矩阵
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = 1;
    }

    // 执行 DFS，从节点 1 开始
    DFS(G, visited, n, 1);
    printf("\n");
    // 重置 visited 数组
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
    }
    // 执行 BFS，从节点 1 开始
    BFS(G, visited, n, 1);
    return 0;
}

void DFS(bool G[MAX_NODES][MAX_NODES], bool visited[], int n, int start) {
    visited[start] = true;
    printf("%d ", start);

    for (int i = 1; i <= n; i++) {
        if (G[start][i] && !visited[i]) {
            DFS(G, visited, n, i);
        }
    }
}

void BFS(bool G[MAX_NODES][MAX_NODES], bool visited[], int n, int start) {
    int queue[MAX_NODES], front = 0, rear = 0;
    visited[start] = true;
    printf("%d ", start);
    queue[rear++] = start;
    while(front < rear) {
        int v = queue[front++];
        for (int i = 1; i <= n; i++) {
            if (G[v][i] && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
}





// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // 定义常量
// #define MAX_N 100005

// // 邻接表节点结构
// typedef struct Node {
//     int vertex;
//     struct Node* next;
// } Node;

// // 全局变量
// Node* adjList[MAX_N];
// int visited[MAX_N];
// int n, m;

// // 添加边到邻接表
// void addEdge(int u, int v) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->vertex = v;
//     newNode->next = adjList[u];
//     adjList[u] = newNode;
// }

// // DFS递归实现
// void DFS(int v) {
//     visited[v] = 1;
//     printf("%d ", v);
    
//     // 遍历邻接表
//     Node* temp = adjList[v];
//     while (temp) {
//         if (!visited[temp->vertex]) {
//             DFS(temp->vertex);
//         }
//         temp = temp->next;
//     }
// }

// // BFS实现
// void BFS(int start) {
//     int queue[MAX_N], front = 0, rear = 0;
    
//     visited[start] = 1;
//     queue[rear++] = start;
    
//     while (front < rear) {
//         int v = queue[front++];
//         printf("%d ", v);
        
//         Node* temp = adjList[v];
//         while (temp) {
//             if (!visited[temp->vertex]) {
//                 visited[temp->vertex] = 1;
//                 queue[rear++] = temp->vertex;
//             }
//             temp = temp->next;
//         }
//     }
// }

// // 比较函数，用于按节点编号升序排序
// int cmp(const void* a, const void* b) {
//     return (*(int*)a - *(int*)b);
// }

// // 排序邻接表
// void sortAdjList() {
//     for (int i = 1; i <= n; i++) {
//         int neighbors[MAX_N], cnt = 0;
//         Node* temp = adjList[i];
//         while (temp) {
//             neighbors[cnt++] = temp->vertex;
//             temp = temp->next;
//         }
        
//         // 对邻接表进行排序
//         qsort(neighbors, cnt, sizeof(int), cmp);
        
//         // 重新构造邻接表
//         adjList[i] = NULL;
//         for (int j = cnt - 1; j >= 0; j--) {
//             addEdge(i, neighbors[j]);
//         }
//     }
// }

// int main() {
//     scanf("%d %d", &n, &m);
    
//     // 初始化邻接表
//     for (int i = 1; i <= n; i++) {
//         adjList[i] = NULL;
//     }
    
//     // 读取图的边
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         scanf("%d %d", &u, &v);
//         addEdge(u, v);
//     }
    
//     // 对邻接表进行排序，保证访问顺序
//     sortAdjList();
    
//     // 执行DFS
//     memset(visited, 0, sizeof(visited));
//     DFS(1);
//     printf("\n");
    
//     // 执行BFS
//     memset(visited, 0, sizeof(visited));
//     BFS(1);
//     printf("\n");
    
//     return 0;
// }

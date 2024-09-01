#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000
#define MAX_M 200000

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX_N + 1];
int rank[MAX_N + 1];
Edge edges[MAX_M];

// 并查集的查找操作，带路径压缩
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 并查集的合并操作，按秩合并
void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// 边的比较函数，用于按权重排序
int compare_edges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    qsort(edges, M, sizeof(Edge), compare_edges);

    int edge_count = 0;
    int total_weight = 0;

    for (int i = 0; i < M; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            union_sets(edges[i].u, edges[i].v);
            total_weight += edges[i].weight;
            edge_count++;

            if (edge_count == N - 1) {
                break;
            }
        }
    }

    if (edge_count == N - 1) {
        printf("%d\n", total_weight);
    } else {
        printf("orz\n");
    }

    return 0;
}

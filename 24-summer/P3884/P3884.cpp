// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// typedef struct BiTNode
// {
//     int data;
//     struct BiTNode *lchild, *rchild;
// } BiTNode, *BiTree;

// void insert(int f,int s);
// BiTree find(BiTree T,int key);
// // void PreOrderTraverse(BiTree T, void (*visit)(BiTree));
// // void visit(BiTree T);
// int depth(BiTree T);
// int width(BiTree T);
// int path(BiTree T,int a,int b);
// int findpath(BiTree T,int key);
// BiTree LowestCommonAncestor(BiTree T, int e1, int e2);

// BiTree T=NULL;

// int main()
// {
//     T=(BiTree)malloc(sizeof(BiTNode));
//     T->data=1;
//     T->lchild=NULL;
//     T->rchild=NULL;
//     int n;
//     scanf("%d",&n);
//     for(int i=0;i<n-1;i++)
//     {
//         int father,son;
//         scanf("%d%d",&father,&son);
//         insert(father,son);
//     }
//     int key1,key2;
//     scanf("%d%d",&key1,&key2);
//     printf("%d\n",depth(T));
//     printf("%d\n",width(T));
//     printf("%d",path(T,key1,key2));
//     // printf("%d\n",findpath(T,key1));
//     // printf("%d\n",findpath(T,key2));
//     return 0;
// }

// void insert(int f,int s)
// {
//     BiTree p=find(T,f);
//     BiTree q=(BiTree)malloc(sizeof(BiTNode));
//     q->data=s;
//     q->lchild=NULL;
//     q->rchild=NULL;
//     if(p->lchild==NULL)
//         p->lchild=q;
//     else 
//         p->rchild=q;
// }

// BiTree find(BiTree T,int key)
// {
//     if (T == NULL) // 空树
//         return NULL;
//     if (T->data == key) // 找到结点
//         return T;
//     BiTree p = find(T->lchild, key); // 在左子树中查找
//     if (p != NULL)
//         return p;
//     p = find(T->rchild, key); // 在右子树中查找
//     return p;
// }

// // void PreOrderTraverse(BiTree T, void (*visit)(BiTree))
// // {
// //     if (T)
// //     {
// //         visit(T);
// //         PreOrderTraverse(T->lchild, visit);
// //         PreOrderTraverse(T->rchild, visit);
// //     }
// // }

// // void visit(BiTree T)
// // {
// //     printf("%d ", T->data); // 访问结点
// // }

// int depth(BiTree T)
// {
//     if (T == NULL) // 空树
//         return 0;
//     int ldepth = depth(T->lchild);            // 左子树的深度
//     int rdepth = depth(T->rchild);            // 右子树的深度
//     return (ldepth > rdepth ? ldepth : rdepth) + 1; // max(ldepth,rdepth)+1
// }

// int width(BiTree T)
// {
//     int maxWidth = 0;  // 最大宽度
//     int currentWidth = 0;  // 当前层的宽度
//     // 创建一个队列用于层次遍历
//     BiTree queue[1000];  // 假设最多1000个节点
//     int front = 0, rear = 0;
//     // 将根节点入队
//     queue[rear++] = T;
//     while (front != rear) {
//         // 当前层的节点数
//         currentWidth = rear - front;
//         if (currentWidth > maxWidth)
//             maxWidth = currentWidth;
//         // 处理当前层的所有节点
//         for (int i = 0; i < currentWidth; i++) {
//             BiTree node = queue[front++];  // 出队
//             // 将左右孩子入队
//             if (node->lchild)
//                 queue[rear++] = node->lchild;
//             if (node->rchild)
//                 queue[rear++] = node->rchild;
//         }
//     }
//     return maxWidth;
// }

// int path(BiTree T,int a,int b)
// {
//     BiTree p=LowestCommonAncestor(T,a,b);
//     return (findpath(T,a)*2+findpath(T,b)-findpath(T,p->data));
// }

// int findpath(BiTree T, int key)
// {
//     if (T == NULL)
//         return -1;
    
//     if (T->data == key)
//         return 0; 
    
//     int leftPath = findpath(T->lchild, key);
//     if (leftPath != -1)
//         return leftPath + 1;
    
//     int rightPath = findpath(T->rchild, key);
//     if (rightPath != -1)
//         return rightPath + 1;
    
//     return -1;
// }

// BiTree LowestCommonAncestor(BiTree T, int e1, int e2)
// {
//     if (T == NULL) // 空树
//         return NULL;
//     if (T->data == e1 || T->data == e2) // 找到结点
//         return T;
//     BiTree left = LowestCommonAncestor(T->lchild, e1, e2);  // 递归左子树
//     BiTree right = LowestCommonAncestor(T->rchild, e1, e2); // 递归右子树
//     if (left != NULL && right != NULL)                      // 左右子树都找到
//         return T;
//     else if (left != NULL) // 左子树找到
//         return left;
//     else if (right != NULL) // 右子树找到
//         return right;
//     return NULL;
// }






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 101

// 数据结构定义
typedef struct Node {
    int id;
    struct Node* next;
} Node;

// 全局变量声明
Node* adj[MAX_N];  // 邻接表
int level[MAX_N] = {0};  // 每层节点数量
int visited[MAX_N] = {0};  // 访问标记
int depth[MAX_N] = {0};  // 每个节点的深度
int parent[MAX_N];  // 记录每个节点的父节点

// 函数声明
void add_edge(int u, int v);
void bfs(int start);
int find_lca(int u, int v);

int main() {
    int n, x, y;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    scanf("%d %d", &x, &y);

    // Step 1: BFS from root (node 1)
    bfs(1);

    // Calculate tree depth
    int max_depth = 0;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > max_depth) {
            max_depth = depth[i];
        }
    }
    printf("%d\n", max_depth);

    // Calculate tree width
    int max_width = 0;
    for (int i = 1; i <= max_depth; i++) {
        if (level[i] > max_width) {
            max_width = level[i];
        }
    }
    printf("%d\n", max_width);

    // Step 2: Calculate distance between x and y
    int lca = find_lca(x, y);
    int distance = (depth[x] *2 + depth[y] - 3 * depth[lca]);
    printf("%d\n", distance);

    return 0;
}

// 函数实现

// 添加边
void add_edge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->id = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// 广度优先搜索
void bfs(int start) {
    int queue[MAX_N], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    depth[start] = 1;
    parent[start] = 0;

    while (front < rear) {
        int u = queue[front++];
        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->id;
            if (!visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
                depth[v] = depth[u] + 1;
                level[depth[v]]++;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }
}

// 查找最近公共祖先
int find_lca(int u, int v) {
    while (u != v) {
        if (depth[u] > depth[v]) {
            u = parent[u];
        } else {
            v = parent[v];
        }
    }
    return u;
}

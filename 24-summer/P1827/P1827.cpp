#include <stdio.h>
#include <string.h>

char result[27];
int cnt=0;

void buildPostorder(char* inorder, char* preorder, int inStart, int inEnd, int preStart, int preEnd) {
    if (inStart > inEnd) {
        return;
    }

    // 先序遍历的第一个节点是当前子树的根节点
    char root = preorder[preStart];
    result[cnt++]=root;

    // 在中序遍历中找到根节点的位置
    int rootIndex = inStart;
    while (inorder[rootIndex] != root && rootIndex <= inEnd) {
        rootIndex++;
    }

    int leftSubtreeSize = rootIndex - inStart;

    // 递归构造右子树的hou序遍历
    buildPostorder(inorder, preorder, rootIndex + 1, inEnd, preStart + leftSubtreeSize+1, preEnd);
    // 递归构造左子树的hou序遍历
    buildPostorder(inorder, preorder, inStart, rootIndex - 1, preStart+1, preStart + leftSubtreeSize);

    // // 递归构造右子树的hou序遍历
    // buildPostorder(inorder, preorder, rootIndex + 1, inEnd, preStart + leftSubtreeSize+1, preEnd);
}

int main() {
    char inorder[27], preorder[27];

    // 读入中序遍历和后序遍历字符串
    scanf("%s", inorder);
    scanf("%s", preorder);

    int n = strlen(inorder);

    // 构造并输出hou序遍历
    buildPostorder(inorder, preorder, 0, n - 1, 0, n - 1);
    while(cnt>=0)
    {
        printf("%c",result[--cnt]);
    }
    printf("\n");

    return 0;
}
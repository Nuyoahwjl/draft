#include <stdio.h>
#include <string.h>

void buildPreorder(char* inorder, char* postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd) {
        return;
    }

    // 后序遍历的最后一个节点是当前子树的根节点
    char root = postorder[postEnd];
    printf("%c", root);  // 输出根节点

    // 在中序遍历中找到根节点的位置
    int rootIndex = inStart;
    while (inorder[rootIndex] != root && rootIndex <= inEnd) {
        rootIndex++;
    }

    int leftSubtreeSize = rootIndex - inStart;

    // 递归构造左子树的先序遍历
    buildPreorder(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSubtreeSize - 1);

    // 递归构造右子树的先序遍历
    buildPreorder(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);
}

int main() {
    char inorder[9], postorder[9];

    // 读入中序遍历和后序遍历字符串
    scanf("%s", inorder);
    scanf("%s", postorder);

    int n = strlen(inorder);

    // 构造并输出先序遍历
    buildPreorder(inorder, postorder, 0, n - 1, 0, n - 1);
    printf("\n");

    return 0;
}

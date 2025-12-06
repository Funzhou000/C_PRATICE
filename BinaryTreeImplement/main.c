#include <stdio.h>
#include <stdlib.h>

// 1. 定义结构体
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 2. 创建节点的函数
TreeNode *creatNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 3. 前序遍历函数 (Pre-order Traversal): Root -> Left -> Right
//  递归遍历
void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d -> ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    // --- 构建树 ---
    // 创建根节点 (Root)
    TreeNode *root = creatNode(1);
    root->left = creatNode(2);
    root->right = creatNode(3);
    root->left->left = creatNode(3);
    root->right->right = creatNode(3);

    // TreeNode *root = createNode(1);

    // // 创建子节点
    // root->left = createNode(2);
    // root->right = createNode(3);

    // // 创建孙子节点 (连接到 2 的下面)
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);

    /* 此时树的结构如下：
           1
         /   \
        2     3
       / \
      4   5
    */

    // --- 验证 ---
    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("NULL\n");

    // 注意：在实际工程中，程序结束前需要编写函数释放所有节点的内存 (free)

    return 0;
}
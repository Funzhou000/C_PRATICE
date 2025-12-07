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
    printf("%d", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void in_orderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    in_orderTraversal(root->left);
    printf("%d", root->data);
    in_orderTraversal(root->right);
}
void post_orderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    post_orderTraversal(root->left);

    post_orderTraversal(root->right);
    printf("%d ->", root->data);
}
// void preorderTraversal(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     printf("%d -> ", root->data);
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
// }
// void postorderTraversal(TreeNode *root)
// {
//     if (root == NULL)
//         return;

//     postorderTraversal(root->left);  // 1. 先去左边
//     postorderTraversal(root->right); // 2.再去右边
//     printf("%d -> ", root->data);    // 3. 最后访问自己
// }
// void inorderTraversal(TreeNode *root)
// {
//     if (root == NULL)
//         return;

//     inorderTraversal(root->left);  // 1. 先去左边
//     printf("%d -> ", root->data);  // 2. 回来访问中间
//     inorderTraversal(root->right); // 3. 最后去右边
// }

int main()
{
    // --- 构建树 ---
    // 创建根节点 (Root)
    TreeNode *root = creatNode(5);
    root->left = creatNode(3);
    root->right = creatNode(4);
    root->left->left = creatNode(1);
    root->left->right = creatNode(2);

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
    printf("In-order Traversal: ");
    post_orderTraversal(root);
    printf("NULL\n");

    // 注意：在实际工程中，程序结束前需要编写函数释放所有节点的内存 (free)

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
ElemType Maximum = 100;
// Define stack link node structure
typedef struct StackLink
{
    ElemType data;
    struct StackLink *next;
} StackLink;
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;
StackNode *initStack()
{
    StackNode *stack = (StackNode *)malloc(sizeof(StackNode) * Maximum);
    stack->next = NULL;
    return stack;
}
// StackNode *createNode(ElemType e)
// {
//     StackNode *node = (StackNode *)malloc(sizeof(StackNode));
//     node->data = e;
//     node->next = NULL;
//     return node;
// }
int main()
{
    printf("This is stack.c file.\n");
    StackNode *stack = initStack(); // create stack with a dummy head node

    return 0;
}
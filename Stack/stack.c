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
StackLink *initStack()
{
    StackLink *stack = (StackLink *)malloc(sizeof(StackLink));
    stack->next = 0;
    stack->next = NULL;
    return stack;
}
int push(StackLink *stack, ElemType e)
{
    StackLink *node = (StackLink *)malloc(sizeof(StackLink));
    node->data = e;
    node->next = stack->next;
    stack->next = node;
    return 1; // Success
}
int pop(StackLink *stack, ElemType *e)
{
    if (stack->next == NULL)
    {
        return 0; // Stack is empty
    }
    StackLink *temp = stack->next;
    *e = temp->data;
    stack->next = temp->next;
    free(temp);
    return 1; // Success
}
int getTop(StackLink *stack, ElemType *e)
{
    if (stack->next == NULL)
    {
        return 0; // Stack is empty
    }
    *e = stack->next->data;
    return 1; // Success
}
int main()
{
    printf("This is stack.c file.\n");
    // create stack with a dummy head node
    StackLink *stack = initStack();
    ElemType topElement;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    getTop(stack, &topElement);
    pop(stack, &topElement);
    getTop(stack, &topElement);
    printf("%d\n", topElement);
    return 0;
}
// typedef struct StackNode
// {
//     ElemType data;
//     struct StackNode *next;
// } StackNode, *LinkStack;
// StackNode *initStack()
// {
//     StackNode *stack = (StackNode *)malloc(sizeof(StackNode) * Maximum);
//     stack->next = NULL;
//     return stack;
// }
// StackNode *createNode(ElemType e)
// {
//     StackNode *node = (StackNode *)malloc(sizeof(StackNode));
//     node->data = e;
//     node->next = NULL;
//     return node;
// }

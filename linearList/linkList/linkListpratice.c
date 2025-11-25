#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode;
LNode *initList()
{
    LNode *L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}

int insertHead(LNode *L, ElemType e);
LNode *insertTail(LNode *tail, ElemType e);
void TraverseLinkList(LNode *L);
int cutInList(LNode *L, ElemType e, ElemType target);
void freeList(LNode *L);
int deleteNode(LNode *L, ElemType target);
int main()
{
    LNode *list = initList();
    insertHead(list, 10);
    insertTail(list, 20);
    cutInList(list, 15, 2);
    deleteNode(list, 2);
    TraverseLinkList(list);
    freeList(list);
    TraverseLinkList(list);
    printf("This is linkList pratice file.\n");
    return 0;
}
int insertHead(LNode *L, ElemType e)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L->next;
    L->next = s;
    return 1;
}
LNode *insertTail(LNode *L, ElemType e)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = e;
    p->next = NULL;
    LNode *tail = L;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = p;
    return p;
}
void TraverseLinkList(LNode *L)
{
    LNode *p = L->next; // 跳过头结点
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int cutInList(LNode *L, ElemType e, ElemType target)
{
    // 在插入的位置前插入
    LNode *p = L;
    for (int i = 1; i <= target - 1; i++)
    {
        p = p->next; // p是要插入位置的前一个节点
        if (p->next == NULL)
        {
            return 0;
        }
    }
    // 先把插入的节点创建好
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}
void freeList(LNode *L)
{
    LNode *p = L->next;
    LNode *q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}
int deleteNode(LNode *L, ElemType target)
{
    LNode *p = L;
    // 找到要删除节点的前驱（假设 target 为 1 表示第一个数据节点）
    for (int i = 1; i < target; i++)
    {
        if (p == NULL)
        {
            return 0;
        }
        p = p->next;
    }
    // 确保存在要删除的节点
    if (p == NULL || p->next == NULL)
    {
        return 0;
    }
    LNode *q = p->next; // 要删除的节点
    p->next = q->next;
    free(q);
    return 1;
}
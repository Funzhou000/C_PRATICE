#include <stdio.h>
#include <stdlib.h> // 需要引入 stdlib.h 使用 malloc

typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prev;
    struct DNode *next;
} DNode, *DLinkList; // 定义 DLinkList 为指向 DNode 的指针

// 初始化函数
int InitDLinkList(DLinkList *L)
{
    *L = (DNode *)malloc(sizeof(DNode)); // 分配头节点
    if (*L == NULL)
        return 0;      // 内存分配失败
    (*L)->prev = NULL; // 头节点的 prev 永远为 NULL
    (*L)->next = NULL; // 初始时 next 为 NULL
    return 1;
}
int insertHeadV2(DLinkList L, ElemType e)
{
    // 创建一个新节点
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    // 一定要先完成 new 节点的赋值在断开链子
    s->next = L->next;
    s->prev = L;
    // disconnect
    L->next = s;
    L->next->prev = s;
    return 1;
}

int insertHead(DLinkList L, ElemType e)
{
    // 开创一个新节点
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    // 把头节点，头的 next 节点存起来
    DNode *next = L->next;
    DNode *head = L;
    s->prev = head;
    s->next = next;
    head->next = s;
    if (next != NULL)
    {
        next->prev = s;
    }
    return 1;
}
int insertTail(DLinkList L, ElemType e)
{
    // find the tail node
    DNode *tail = L;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    // create new node
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = NULL;
    s->prev = tail;
    tail->next = s;
    return 1;
}
int insertPos(DLinkList L, ElemType e, int pos)
{
    // find the pos-1 node
    DNode *p = L;
    for (int i = 1; i <= pos - 1; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            return 0; // pos is out of range
        }
    }
    // create new node
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    s->prev = p;
    if (p->next != NULL)
    {
        p->next->prev = s;
    }
    p->next = s;
    return 1;
}
int deletePos(DLinkList L, int pos)
{
    // find the pos node
    DNode *p = L;
    for (int i = 1; i <= pos; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            return 0; // pos is out of range
        }
    }
    // disconnect the node
    p->prev->next = p->next;
    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }
    free(p);
    return 1;
}
int main()
{
    printf("This is doubleLinkeListPratice file.\n");

    DLinkList L;       // 声明一个头指针
    InitDLinkList(&L); // 初始化双向链表
    insertHead(L, 10);
    insertHead(L, 20);
    insertHead(L, 30);
    insertHeadV2(L, 10);
    insertHeadV2(L, 20);
    insertHeadV2(L, 30);
    // insertTail(L, 40);
    // insertTail(L, 50);
    // insertTail(L, 60);
    insertPos(L, 25, 3); // 在位置 3 插入元素 25
    // deletePos(L, 4);     // 删除位置 4 的元素

    // 遍历链表并打印元素
    DNode *p = L->next; // 从第一个数据节点开始遍历
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
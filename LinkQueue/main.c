#include <stdio.h>
#include <stdlib.h>

// 定义数据元素的类型
typedef int ElementType;

// 1. 定义节点结构体 (Node)
typedef struct QNode
{
    ElementType data;   // 数据域 (Data Field)
    struct QNode *next; // 指针域 (Pointer Field)
} QNode;

// 2. 定义队列结构体 (Queue Control Block)
typedef struct
{
    QNode *front; // 队头指针
    QNode *rear;  // 队尾指针
} LinkQueue;

// 3. 初始化队列 (Initialize Queue)
// 修改返回值类型为 LinkQueue*
LinkQueue *initQueue()
{
    // 只分配队列控制块的内存，不需要分配节点内存
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (queue == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // 初始状态，队头和队尾都为空
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

// 4. 入队 (Enqueue)
void enqueue(LinkQueue *Q, ElementType e)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = e;
    newNode->next = NULL;

    // 关键逻辑修改：处理空队列的情况
    if (Q->front == NULL)
    {
        // 如果队列为空，front 和 rear 都指向新节点
        Q->front = newNode;
        Q->rear = newNode;
    }
    else
    {
        // 如果队列不为空，链接到 rear 后面，并移动 rear
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

// 5. 遍历队列 (Traverse Queue)
void traverseQueue(LinkQueue *Q)
{
    // 这里建议判断一下 Q 是否存在
    if (Q == NULL)
        return;

    QNode *current = Q->front;
    printf("Queue elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void dequeue(LinkQueue *Q, ElementType *e)
{
    QNode *temp = Q->front;
    *e = temp->data;
    
}

int main()
{
    // 这里的类型现在匹配了
    LinkQueue *queue = initQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    traverseQueue(queue);

    // 实际项目中记得释放内存 (Free Memory)，这里省略
    return 0;
}
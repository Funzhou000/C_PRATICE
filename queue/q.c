#include <stdio.h>
#define MAXSIZE 100
// initialize queue
typedef int ElemType;
typedef struct queue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} Queue;
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}
ElemType dequeue(Queue *Q)
{
    if (Q->front == Q->rear)
    {
        printf("queue is emty");
        return 0;
    }
    ElemType e = Q->data[Q->front];
    Q->front++;
    return e;
}
int move(Queue *Q)
{
    if (Q->front == 0)
    {
        return 0; // front 已经在最前面了
    }
    for (int i = Q->front; i < Q->rear; i++)
    {
        Q->data[i - Q->front] = Q->data[i]; // Qfront is offset 偏移量 位置减去偏移量自然就能回到最初位置
    }
    Q->rear -= Q->front; // 得到有多少个元素，刚好就是新 queue 的 rear 的新位置
    Q->front = 0;
    return 1;
}
ElemType equeue(Queue *Q, ElemType e)
{
    if (Q->rear >= MAXSIZE)
    {
        // rear 已经到最后索引，进行前移，前移失败，说明已经满了
        if (!move(Q))
        {
            return 0; // 队列满了
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;
}

int main()
{
    Queue q;
    initQueue(&q);
    printf("equeue %d ", equeue(&q, 10));
    printf("equeue %d ", equeue(&q, 2));
    printf("equeue %d ", equeue(&q, 3));
    printf("equeue %d ", equeue(&q, 5));
    printf("equeue %d ", equeue(&q, 6));
    printf("dequeue %d ", dequeue(&q));
    printf("This is queue.c file.\n");
    return 0;
}
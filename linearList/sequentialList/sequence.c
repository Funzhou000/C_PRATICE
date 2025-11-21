#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
typedef int ElemType;
typedef struct initial
{
    ElemType data[Maxsize];
    int length;
} SeqList;
void initalizeList(SeqList *L)
{
    L->length = 0;
}
int tailAppend(SeqList *L, ElemType e)
{
    if (L->length >= Maxsize)
    {
        printf("sequence full ");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}
void TraverseSequenceList(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}
void SequenceListCutin(SeqList *L, int pos, ElemType e)
{
    if (pos <= L->length)
    { // pos is real address
        for (int i = L->length - 1; i >= pos - 1; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
}
int deleteElement(SeqList *L, int pos, ElemType *e)
{
    // 用指针带出被删除的值
    if (pos < 1 || pos > L->length) // 位置无效
    {
        printf("delete position invalid\n");
        return 0;
    }

    *e = L->data[pos - 1]; // 保存被删除的值

    for (int i = pos; i < L->length; i++)
    {
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return 1;
}
int searchElement(SeqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
int main()
{
    SeqList l;
    ElemType *e;
    // 直接初始化 *e 会给你一个随机的存了别的数据的空间因此
    e = (ElemType *)malloc(sizeof(ElemType));
    initalizeList(&l);
    printf("initalize successfully sequence length is %d\n", l.length);
    tailAppend(&l, 88);
    tailAppend(&l, 88);
    tailAppend(&l, 88);
    tailAppend(&l, 88);
    SequenceListCutin(&l, 2, 77);
    printf("append successfully sequence last figure  is %d\n", l.data[l.length - 1]);
    printf("append successfully sequence length is %d\n", l.length);

    TraverseSequenceList(&l);
    deleteElement(&l, 2, e);
    printf("%d\n", l.data[1]);
    printf("%d", searchElement(&l, 77));
}
// void traverseList(SeqList *L){
//     for(int i = 0;L->length;i++){
//         printf("%d",L->data);
//     }
// }
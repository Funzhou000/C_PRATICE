#include <stdio.h>
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

int main()
{
    SeqList l;
    initalizeList(&l);
    printf("initalize successfully sequence length is %d\n", l.length);
    tailAppend(&l, 88);
    tailAppend(&l, 88);
    tailAppend(&l, 88);
    tailAppend(&l, 88);

    printf("append successfully sequence last figure  is %d\n", l.data[l.length - 1]);
    printf("append successfully sequence length is %d\n", l.length);
    TraverseSequenceList(&l);
}
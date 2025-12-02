#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 定义栈的最大容量
#define MAX_STACK_SIZE 100

/**
 * 栈结构体定义
 * data: 用于存储栈元素的数组
 * top: 栈顶指针，指向当前栈顶元素的索引，初始为-1
 */
typedef struct
{
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

/**
 * 初始化栈
 * @param s 指向栈的指针
 */
void initStack(Stack *s)
{
    s->top = -1;
}

/**
 * 判断栈是否为空
 * @param s 指向栈的指针
 * @return 1 表示空，0 表示非空
 */
int isEmpty(Stack *s)
{
    return s->top == -1;
}

/**
 * 判断栈是否已满
 * @param s 指向栈的指针
 * @return 1 表示满，0 表示未满
 */
int isFull(Stack *s)
{
    return s->top == MAX_STACK_SIZE - 1;
}

/**
 * 入栈操作
 * @param s 指向栈的指针
 * @param value 要入栈的值
 */
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("栈溢出！无法入栈 %d\n", value);
        exit(1);
    }
    s->data[++(s->top)] = value;
}

/**
 * 出栈操作
 * @param s 指向栈的指针
 * @return 出栈的元素值
 */
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("栈为空！无法出栈\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

/**
 * 计算后缀表达式的值
 * @param expression 后缀表达式字符串 (例如 "53+82-*")
 * @return 计算结果
 */
int evaluatePostfix(char *expression)
{
    Stack stack;
    initStack(&stack);

    int i = 0;
    // 遍历表达式中的每个字符
    while (expression[i] != '\0')
    {
        char ch = expression[i];

        // 如果是数字，将其转换为整数并入栈
        // 注意：这里简单处理，假设都是个位数。如果是多位数需要额外处理空格分隔。
        if (isdigit(ch))
        {
            push(&stack, ch - '0'); // 将字符转换为整数
        }
        // 如果是运算符，从栈中弹出两个操作数进行计算
        else
        {
            int val2 = pop(&stack); // 第二个操作数（栈顶）
            int val1 = pop(&stack); // 第一个操作数（次栈顶）

            switch (ch)
            {
            case '+':
                push(&stack, val1 + val2);
                break;
            case '-':
                push(&stack, val1 - val2);
                break;
            case '*':
                push(&stack, val1 * val2);
                break;
            case '/':
                if (val2 == 0)
                {
                    printf("错误：除数不能为0\n");
                    exit(1);
                }
                push(&stack, val1 / val2);
                break;
            default:
                printf("未知运算符: %c\n", ch);
                exit(1);
            }
        }
        i++;
    }

    // 最后栈中剩下的元素就是表达式的结果
    return pop(&stack);
}

int main()
{
    // 示例后缀表达式: (5 + 3) * (8 - 2) -> 5 3 + 8 2 - *
    char expression[] = "53+82-*";

    printf("后缀表达式: %s\n", expression);

    int result = evaluatePostfix(expression);

    printf("计算结果: %d\n", result);

    // 另一个例子: 4 * 5 + 6 -> 4 5 * 6 +
    char expression2[] = "45*6+";
    printf("\n后缀表达式: %s\n", expression2);
    printf("计算结果: %d\n", evaluatePostfix(expression2));

    return 0;
}
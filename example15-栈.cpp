#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK; //PSTACK 等价于struct Stack *

void init(PSTACK);      //初始化, 造出一个空栈
void push(PSTACK, int); //压栈
void forEach(PSTACK);   //遍历

int main(void)
{
    STACK stack;
    init(&stack); //初始化, 造出一个空栈

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    //输出:3 2 1
    forEach(&stack); //遍历

    return 0;
}

void init(PSTACK pStack)
{
    pStack->pTop = (PNODE)malloc(sizeof(NODE));
    //这里可以加一个malloc分配内存失败的判断.

    pStack->pTop->data = NULL; //清空数据域
    pStack->pBottom = pStack->pTop;
}

void push(PSTACK pStack, int value)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = value;
    pNew->pNext = pStack->pTop;

    pStack->pTop = pNew;
}

//遍历
void forEach(PSTACK pStack)
{
    PNODE pNew = pStack->pTop;
    while (pNew != pStack->pBottom)
    {
        printf("%d ", pNew->data);
        pNew = pNew->pNext;
    }
    printf("\n");
}
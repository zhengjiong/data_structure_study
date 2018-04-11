#include <stdio.h>

typedef struct Node
{
    int data;           //数据域
    struct Node *pNext; //指针域

} NODE, *PNODE; //NODE 等价于 struct Node, PNODE 等价于 struct Node *

int main(void)
{
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;           //数据域
    struct Node *pNext; //指针域

} NODE, *PNODE; //NODE 等价于 struct Node, PNODE 等价于 struct Node *

PNODE createLinkedList();       //创建一个非循环单链表
void traverseList(PNODE pHead); //遍历
bool isEmpty(PNODE pHead);
int length(PNODE pHead);                                 //链表长度
bool insert(PNODE pHead, int position, int value);       //第二个参数是位置, 第三个参数是要插入的值
bool deleteValue(PNODE pHead, int position, int *value); //删除一个值, 第三个参数是用来返回删除的值
void sortAsc(PNODE pHead);                               //排序(升序)

int main(void)
{
    //创建一个非循环单链表,并将该链表的头结点的地址赋给pHead
    PNODE pHead = createLinkedList();

    //遍历链表
    traverseList(pHead);

    if (isEmpty(pHead))
    {
        printf("为空");
    }
    else
    {
        printf("不为空");
    }
    printf("数量=%d\n", length(pHead));
    return 0;
}

//创建一个非循环单链表
PNODE createLinkedList()
{
    int len = 10; //用来存放有效节点的个数
    int val;      //用来临时存放用户输入的节点的值

    //分配一块存储NODE的内存并返回内存地址
    //分配了一个不存放有效数据的头结点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));

    if (NULL == pHead)
    {
        printf("分配失败, 程序终止!\n");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->pNext = NULL;

    for (int i = 0; i < len; i++)
    {
        PNODE pTemp = (PNODE)malloc(sizeof(NODE));
        if (NULL == pTemp)
        {
            printf("分配失败, 程序终止!\n");
            exit(-1);
        }
        pTemp->data = i; //让节点中的数据为从0开始到len
        pTemp->pNext = NULL;
        pTail->pNext = pTemp;
        pTail = pTemp;
    }

    return pHead;
}

//遍历链表
void traverseList(PNODE pHead)
{
    //这里的pNext是首节点, 就是头结点的下一个结点
    PNODE pNext = pHead->pNext;

    while (NULL != pNext)
    {
        printf("%d\n", pNext->data);

        pNext = pNext->pNext;
    }

    printf("\n");
}

bool isEmpty(PNODE pHead)
{
    if (NULL == pHead->pNext)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int length(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int i = 0;
    while (p != NULL)
    {
        i++;
        p = p->pNext;
    }
    return i;
}
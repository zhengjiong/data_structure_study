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
        printf("为空\n");
    }
    else
    {
        printf("不为空\n");
    }
    printf("数量=%d\n", length(pHead));

    //在第三个位置插入一个99
    insert(pHead, 3, 99);
    int deleteVal;
    if(deleteValue(pHead, 1, &deleteVal)){
        printf("删除成功, 删除的值为%d\n", deleteVal);
    }else{
        printf("删除失败");
    }

    //升序排练
    sortAsc(pHead);
    //遍历
    traverseList(pHead);

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

//冒泡排序, 升序排列
void sortAsc(PNODE pHead)
{
    PNODE p, q;
    int i, j;
    int len = length(pHead);

    for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
    {
        for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
        {
            if (p->data > q->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

//第二个参数是位置, 第三个参数是要插入的值
//position的值从1开始
bool insert(PNODE pHead, int position, int value)
{
    int i = 0;
    PNODE p = pHead;

    while (NULL != p && i < position - 1)
    {
        p = p->pNext;
        ++i;
    }

    if (i > position - 1 || NULL == p)
    {
        return false;
    }
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("动态分配内存失败\n");
        exit(-1);
    }

    pNew->data = value;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return true;
}

bool deleteValue(PNODE pHead, int position, int *value)
{
    int i = 0;
    PNODE p = pHead;

    while (NULL != p->pNext && i < position - 1)
    {
        p = p->pNext;
        ++i;
    }

    if (i > position - 1 || NULL == p->pNext)
    {
        return false;
    }

    PNODE q = p->pNext;
    *value = q->data;
    //value = &(p->data);

    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;

    return true;
}
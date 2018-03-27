#include <stdio.h>
#include <stdlib.h>

struct Arr
{
    int *pBase; //存储的是数组第一个元素的地址
    int len;    //数组所能容纳的最大元素的个数
    int cnt;    //当前数组有效元素的个数
};

void initArr(struct Arr *pArr, int size);
bool isEmpty(struct Arr *pArr);
void showArr(struct Arr *pArr);
bool isFull(struct Arr *pArr);
bool append(struct Arr *pArr, int value);               //追加数据
bool insert(struct Arr *pArr, int position, int value); //插入一条数据
bool deleteArr(struct Arr *pArr, int position, int *deleteValue);

int main(void)
{
    struct Arr arr;
    initArr(&arr, 6);
    append(&arr, 1);
    append(&arr, 2);
    append(&arr, 3);
    append(&arr, 4);
    showArr(&arr);
    insert(&arr, 2, 9);
    showArr(&arr);
    return 0;
}
void initArr(struct Arr *pArr, int size)
{
    pArr->pBase = (int *)malloc(sizeof(int) * size);
    if (NULL == pArr->pBase)
    {
        printf("动态内存分配失败\n");
        exit(-1); //终止整个程序
    }
    else
    {
        pArr->len = size;
        pArr->cnt = 0;
    }
}

bool isEmpty(struct Arr *pArr)
{
    if (pArr->cnt == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void showArr(struct Arr *pArr)
{
    if (isEmpty(pArr))
    {
        printf("数组为空\n");
        return;
    }
    else
    {
        for (int i = 0; i < pArr->cnt; ++i)
        {
            printf("%d ", pArr->pBase[i]);
        }
        printf("\n");
    }
}

bool isFull(struct Arr *pArr)
{
    if (pArr->cnt == pArr->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool append(struct Arr *pArr, int value)
{
    if (isFull(pArr))
    {
        printf("数组已经满了,添加失败");
        return false;
    }
    pArr->pBase[pArr->cnt] = value;
    (pArr->cnt)++;
    return true;
}

bool insert(struct Arr *pArr, int position, int value)
{
    if (isFull(pArr))
    {
        printf("数组已经满了,添加失败");
        return false;
    }
    if (position < 1 || position > pArr->cnt)
    {
        printf("添加失败");
        return false;
    }
    for (int i = pArr->cnt; i >= position; i--)
    {
        pArr->pBase[i] = pArr->pBase[i - 1];
    }
    pArr->pBase[position - 1] = value;
    (pArr->cnt)++;
    return true;
}

bool deleteArr(struct Arr *pArr, int position, int *deleteValue)
{
    if (isEmpty(pArr))
    {
        printf("删除失败");
        return false;
    }

    if (position < 1 || position >= pArr->cnt)
    {
        printf("删除失败");
        return false;
    }
}
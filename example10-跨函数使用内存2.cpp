#include <stdio.h>
#include <stdlib.h>

//前置声明
void fun(int **q);

int main()
{
    int *p;

    //输出:0x7fff65196036, 是一个垃圾值(干地址)
    printf("%p\n", p);  

    fun(&p);

    //输出:0x7fca4b404c00, malloc动态分配的地址
    printf("%p\n", p);

    //因为使用了malloc分配的内存, 所以必须手动释放p的内存,不然会导致内存溢出
    free(p);
}

void fun(int **q)
{
    *q = (int *)malloc(sizeof(int));
}
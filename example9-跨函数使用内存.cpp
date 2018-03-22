#include <stdio.h>
#include <stdlib.h>

//这里必须要加前置声明
void f(int **q);

int main(void)
{
    int *p;

    f(&p);

    printf("2-%p\n", p);
}


/*
跨函数使用内存只能通过malloc动态分配内存,下面这样写f方法执行完成后,i
的地址会被释放,p指向的是一个垃圾值.
*/
void f(int **q )
{
    int i = 3;
    *q = &i;  
    printf("1-%p\n", *q);
}
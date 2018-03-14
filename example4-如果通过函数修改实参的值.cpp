#include <stdio.h>


void f(int **p)
{
    //这里*p代表上面参数p的值也就是main方法中的p
    //把参数p的值修改为0xFFFFFFFF
    *p = (int *)0xFFFFFFFF;
}

int main()
{
    int i = 9;
    int *p = &i; //int *p; p = &i;

    printf("%p\n", p);

    //p是int *类型的, 要传递p的地址那f方法参数的类型就应该是int **,代表指针的指针
    f(&p);

    printf("%p\n", p);
}
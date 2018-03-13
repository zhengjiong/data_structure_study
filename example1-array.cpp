#include <stdio.h>

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};

    //等价
    //a[3] == *(3 + a);

    //等价, 偏移地址
    //3[a] == *(3 + a);

    printf("%d", a[3]);

    printf("\n\n");

    printf("%d\n", 3 [a]);

    printf("\n");

    printf("%p\n", a); //a是a[0]的内存地址,等价&a[0]

    printf("\n");

    printf("%p\n", &a[0]);

    printf("\n");

    printf("%d\n", *a); //*a等价于a[0]

    printf("\n");

    printf("%d\n", *(a + 1)); //等价于a[1]

    printf("");

    //printf("%d", *a[0]); error

    /**
     * 下面输出的内存地址是连续的,一个内存地址占8个字节,c语言中int占4个字节所以是84,88,8c
     * 0x7fff5da69a84
     * 0x7fff5da69a88
     * 0x7fff5da69a8c
     * 
     * 如果a所指向的元素占4个字节,那a+1就是内存中再后面4个字节
     */
    printf("%p %p\n", a + 1, &a[1]); //输出a[1]的地址,等价于&a[1],也等价于a + 1
    printf("%p %p\n", a + 2, &a[2]); //输出a[2]的地址,等价于&a[2],也等价于a + 2
    printf("%p %p\n", a + 3, &a[3]); //输出a[3]的地址,等价于&a[3],也等价于a + 3

    printf("%d\n", *a + 3); //*a+3等价于a[0]+3
}
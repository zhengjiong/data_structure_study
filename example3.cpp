
#include <stdio.h>

int main(void)
{
    double *p;
    double x = 66.6;

    /*
     *  x占8个字节 1个字节是8位, 1个字节一个地址,
     *  p存放的是x的首地址
    */
    p = &x;

    double arr[3] = {1.1, 2.2, 3.3};
    double *q;

    q = &arr[0];
    //%p实际就是16进制输出
    //输出:0x7fff5beada80
    printf("%p\n", q);

    q = &arr[1];

    /**
     * 输出:0x7fff5beada88,
     * 因为一个double占用8个字节,就是8个内存地址, q记录的是存储的首地址,所以相差8个字节
     */
    printf("%p\n", q);

    return 0;
}
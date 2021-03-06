#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};

    int len;
    printf("请输入你需要分配的数组的长度: len = ");
    //sacnf()中的变量必须使用地址
    scanf("%d", &len);          //输入1

    int size = sizeof(int);           
    printf("int所占直接是%d\n", size); //输出4

    /*
        len输入5个话,malloc(sizeof(int) * len)总共会分配20个字节(4*5)

        malloc函数只返回第一个字节的地址,无论一个变量占几个字节, 该变量的地址都是以
        第一个字节的地址来表示, 所以malloc返回的地址是没有实际意义的,我们叫做无意义地址又叫
        干地址,所以要加强制类型转换来告诉编译器该地址代表什么变量(比如int *)就代表转换为
        int类型的变量, 这样pArr[0]或者*pArr就代表数组中第一个变量.


        加上(int *)强制转换后, pArr就可以代表前4个字节的地址,pArr+1代表后面4个字节的地址
    */
    int *pArr = (int *)malloc(sizeof(int) * len);   //pArr就等价于a

    *pArr = 1;          //等价于pArr[0] = 1
    *(pArr + 1) = 2;    //等价于pArr[1] = 2
    pArr[2] = 3;
    pArr[3] = 4;
    pArr[4] = 5;

    printf("开始输入");
    //使用for重新赋值
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &pArr[i]);
    }
    printf("输出:\n");
    //使用for输出
    for (int j = 0; j < len; j++)
    {
        printf("%d\n", pArr[j]);
    }

    free(pArr); //把pArr所代表的动态分配的20个字节的内存释放.

    return 0;
}

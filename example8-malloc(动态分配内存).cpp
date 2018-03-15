#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};

    int len;
    printf("请输入你需要分配的数组的长度: len = ");
    //sacnf()中的变量必须使用地址
    scanf("%d", &len);

    int size = sizeof(int);            //sizeof返回int所占的字节数
    printf("int所占直接是%d\n", size); //输出4,

    /*
        len输入5个话,malloc(sizeof(int) * len)总共会分配20个字节,
        加上(int *)强制转换后, pArr就可以代表前4个字节的地址,pArr+1代表后面4个字节的地址
    */
    int *pArr = (int *)malloc(sizeof(int) * len);

    *pArr = 1; //也可以用pArr[0] = 1
    *(pArr + 1) = 2;
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

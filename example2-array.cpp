#include <stdio.h>

void showArray(int *p, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", p[i]);
    }
}

int main(void)
{

    int a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]); //等价于*(a + i)
    }

    showArray(a, 2);
}
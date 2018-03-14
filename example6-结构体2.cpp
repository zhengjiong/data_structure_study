#include <stdio.h>

struct Student
{
    int sid;        //占4个字节
    char name[200]; //占200个字节
    int age;        //占4个字节
};

int main(void)
{
    struct Student st1 = {1000, "zhangsan", 20};
    //st1.sid = 99;   //第一种方式

    struct Student *pst1 = &st1;

    //给st1中的sid赋值的第二种方式,
    //等价于pst1->sid = 98;,也等价于st1.sid = 98;
    (*pst1).sid = 98;

    printf("%d \n", st1.sid); //99

    //第三种方式
    //等价于(*pst1).sid = 99;,也等价于st1.sid = 99;
    pst1->sid = 99;

    printf("%d \n", st1.sid); //98

    return 0;
}
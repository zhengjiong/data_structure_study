#include <stdio.h>

typedef int ZHANGSAN; //为int再多取一个名字, ZHANGSAN等价于int

//给结构体Student也取一个名字, 叫ST;
typedef struct Student
{
    int sid;
    char name[100];
    char sex;
} ST;

int main(void)
{
    struct Student st;
    struct Student * ps = &st;

    ZHANGSAN i = 10;
    printf("%d\n", i); //输出10

    ST st2;     //等价于struct Student st2;
    ST * pst2;  //等价于struct Student * st2;

    st2.sid = 100;
    printf("%d\n", st2.sid);    //输出:100

    return 0;
}
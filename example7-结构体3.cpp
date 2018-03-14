
#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[200];
    int age;
};

void f(struct Student *pst)
{
    //下面两种给sid赋值的写法效果一样
    pst->sid = 2;
    (*pst).sid = 2;

    strcpy(pst->name, "zhengjiong");

    pst->age = 32;
}

//这种方式,耗内存 耗时间 不推荐, 用传指针的方式来传值效率最高(方法g2)
void g(struct Student stu)
{
    printf("%d %s %d \n", stu.sid, stu.name, stu.age);
}

//比g方法好很多
void g2(struct Student *stu)
{
    printf("%d %s %d \n", stu->sid, stu->name, stu->age);
}

int main(void)
{
    struct Student stu1;    //已经为stu1分配好了内存, 只不过是一个垃圾值

    f(&stu1);
    g(stu1);
    g2(&stu1);
    return 0;
}

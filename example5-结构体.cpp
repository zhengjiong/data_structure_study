#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[20];
    int age;
}; //分号不能省

int main(void)
{
    struct Student st1 = {1, "zhangsan", 20};
    printf("%d %s %d\n", st1.sid, st1.name, st1.age);

    st1.sid = 2;
    //st.name = "lisi";   //error
    //给结构体中的字符串f赋值需要用strcpy方法, 上面要引入 string.h
    strcpy(st1.name, "lisi");
    st1.age = 22;

    printf("%d %s %d\n", st1.sid, st1.name, st1.age);
}
#include <stdio.h>


//给结构体Student * 指针取一个名字, 叫PST;
typedef struct Student
{
    int sid;
    char name[100];
    char sex;
} * PST, ST;    //PST 等价于struct Student * , ST 等价于 struct Student

int main(void)
{
    struct Student st;


    struct Student * pst1 = &st;

    //PST pst2 等价于 struct Student * pst2
    PST pst2 = &st;

    pst2->sid = 9;

    printf("%d\n", pst2->sid);  //输出: 100

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Person *createPerson();
void showPerson(struct Person *person);

struct Person
{
    int id;
    int age;
};

int main(void)
{
    struct Person * person;  //指针变量在64位电脑上是占用8个字节,32位系统是占用4个字节
    int size = sizeof(person); //输出8
    
    printf("%d\n", size);

    person = createPerson();

    showPerson(person);

    free(person);
}

struct Person *createPerson()
{
    //动态分配一个person大小的的内存赋值给p, p指向第一个地址
    struct Person *p = (struct Person *)malloc(sizeof(struct Person));
    p->id = 9;
    p->age = 30;
    return p;
}

void showPerson(struct Person *person)
{
    printf("id=%d ,age=%d\n", person->id, person->age);
}

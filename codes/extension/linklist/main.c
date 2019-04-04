#include <stdio.h>
#include <string.h>
#include "linklist.h"

typedef struct Person{
    LinkNode node;
    char name[64];
    int age;
}Person;

void MyPrint(LinkNode* data) {
    Person* p = (Person*)data;
    printf("name:%s, age:%d\n", p->name, p->age);
}

int MyCompare(LinkNode* data1, LinkNode* data2) {
    Person* p1 = (Person*)data1;
    Person* p2 = (Person*)data2;
    return (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age);

}


int main()
{
    LinkList* list = Init_LinkList();

    // generate some data;
    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "Liam");
    p1.age = 22;
    strcpy(p2.name, "Lizzy");
    p2.age = 21;
    strcpy(p3.name, "SB_yu_hao");
    p3.age = 2;
    strcpy(p4.name, "Jobs");
    p4.age = 156;
    strcpy(p5.name, "Bill Gates");
    p5.age = 175;

    // insert the data
    printf("Inserting the data...\n");
    Insert_LinkList(list, 0, (LinkNode*)&p1);
    Insert_LinkList(list, 0, (LinkNode*)&p2);
    Insert_LinkList(list, 0, (LinkNode*)&p3);
    Insert_LinkList(list, 0, (LinkNode*)&p4);
    Insert_LinkList(list, 0, (LinkNode*)&p5);

    // print the data
    Print_LinkList(list, MyPrint);

    printf("---------------------------------------\n");

    printf("Removing the element at index 2...\n");
    Remove_LinkList(list, 2);
    Print_LinkList(list, MyPrint);

    Person tmp;
    strcpy(tmp.name, "Jobs");
    tmp.age = 156;

    printf("---------------------------------------\n");
    printf("Finding the Jobs...\n");
    int pos = Find_LinkList(list, (LinkNode*)&tmp, MyCompare);
    printf("The position is:%d\n", pos);

    // free the memory of the data
    Free_LinkList(list);


    
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"


typedef struct Teacher{
    LinkNode node;
    int age;
    int salary;
}Teacher;

typedef struct Student{
    LinkNode node;
    char girlfriend[64];
    int face_score;
}Student;

int MyCompare(LinkNode* data1, LinkNode* data2) {
    Teacher* p1 = (Teacher*)data1;
    Teacher* p2 = (Teacher*)data2;
    return (p1->age == p2->age && p1->salary == p2->salary);
}

int main()
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    // generate some data
    Teacher t1, t2;
    Student s1, s2, s3;
    t1.age = 87;
    t1.salary = 9000;
    t2.age = 45;
    t2.salary = 34000;
    strcpy(s1.girlfriend, "Tang Yan");
    s1.face_score = 100;
    strcpy(s2.girlfriend, "Lizzy");
    s2.face_score = 2;
    strcpy(s3.girlfriend, "Taylor Swift");
    s3.face_score = 98;

    // insert
    printf("Inserting the data...\n");
    Insert_LinkList(list, 0, (LinkNode*)&t1);
    Insert_LinkList(list, 0, (LinkNode*)&t2);
    Insert_LinkList(list, 0, (LinkNode*)&s1);
    Insert_LinkList(list, 0, (LinkNode*)&s2);
    Insert_LinkList(list, 0, (LinkNode*)&s3);

    // If we want to print the data, we can define some "flags" to identify data types
    // In fact, we need not to print them at the most cases
    
    printf("--------------------\n");
    printf("Removing a data...\n");
    Remove_LinkList(list, 2);

    printf("--------------------\n");
    printf("Finding a data...\n");
    Teacher temp;
    temp.age = 87;
    temp.salary = 9000;
    int pos = Find_LinkList(list, (LinkNode*)&temp, MyCompare);
    printf("The position is: %d\n", pos);


    return 0;
}


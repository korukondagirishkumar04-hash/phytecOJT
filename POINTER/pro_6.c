//  Program to read and print student details using structure pointer, demonstrate example of structure with pointer.

#include <stdio.h>

struct student
{
    int roll;
    char name[50];
};

int main()
{
    struct student s1;
    struct student *p;

    p = &s1;

    printf("Enter your name: ");
    scanf("%s",p->name);

    printf("Enter your roll: ");
    scanf("%d", &p->roll);

    printf("Roll: %d\n", p->roll);
    printf("Name: %s\n", p->name);

    
}
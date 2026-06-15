//Program to Demonstrate Nested Structure

#include<stdio.h>
struct year{
    int day;
    int year;
    int month;
};
struct student{
    int age;
    char name[88];
    struct year Dob;
};
int main()
{
    struct student e;
    printf("enter your age:");
    scanf("%d",&e.age);
    printf("enter your name:");
    scanf("%s",e.name);
    printf("enter your dob(dd,mm,yyyy):");
    scanf("%d%d%d",&e.Dob.day,&e.Dob.month,&e.Dob.year);
    
    printf("details of students:");
    printf("age:%d\n",e.age);
    printf("name:%s\n",e.name);
    printf("Dob:%d%d%d\n",e.Dob.day,e.Dob.month,e.Dob.year);
    return 0;
    
}
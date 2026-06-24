//Program to Create, Declare and Initialize Structure


#include<stdio.h>
struct students{
    int roll;
    char name[30];
    float marks;
};
int main()
{
    struct students s1={47,"girish",90};
    
    printf("roll:%d\n",s1.roll);
    printf("name of student:%s\n",s1.name);
    printf("marks:%.1f\n",s1.marks);
    return 0;
}
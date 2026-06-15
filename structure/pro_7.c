//Program to Read and Print Employee Details Using Structure

#include<stdio.h>
struct employe{
    int id;
    char name[46];
    float salary;
};
int main()
{
struct employe s;

printf("enter the student id:");
scanf("%d",&s.id);

printf("enter the student name:");
scanf("%s",s.name);

printf("enter the student salary:");
scanf("%f",&s.salary);

printf("employee details:\n");
printf("id:%d\n",s.id);
printf("name:%s\n",s.name);
printf("id:%f\n",s.salary);
return 0;
}
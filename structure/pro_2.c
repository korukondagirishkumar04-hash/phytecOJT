#include<stdio.h>
struct Employee
{
	int id;
	char name[40];
	float salary;
};
int main()
{
	struct Employee e;
	printf("Enter ID :");
	scanf("%d", &e.id);
	printf("Enter Name :");
	scanf("%s", e.name);
	printf("Enter Salary :");
	scanf("%f", &e.salary);
	printf("\n---Employee Details---\n");
	printf("ID : %d\n",e.id);
	printf("Name : %s\n",e.name);
	printf("Salary: %f\n",e.salary);
	return 0;
}

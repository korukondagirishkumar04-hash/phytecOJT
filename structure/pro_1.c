#include<stdio.h>
struct Student
{
	int rollno;
	char name[30];
	float percentage;
};
int main()
{
	struct Student s1={101,"Sowjanya",83};
	printf("Roll:%d\n",s1.rollno);
	printf("Name:%s\n",s1.name);
	printf("Percent:%.2f\n",s1.percentage);
	return 0;
}

/* program to check wheather the person is adult or minor using if else*/
#include<stdio.h>
int main()
{
	int age;
	printf("enter age");
	scanf("%d",&age);
	if(age>=18)
	{
		printf("adult");
	}
	else{
		printf("minor");
	}
}

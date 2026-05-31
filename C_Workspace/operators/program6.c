#include<stdio.h>
int main()
{
	int num1,num2;
	char operator;
	printf("Enter first number:");
	scanf("%d",&num1);
        printf("Enter an operator(+,-,*,/):");
        scanf("%c",&operator);
	printf("Enter second number:");
        scanf("%d",&num2);
	if(operator=='+')
		printf("Result=%d",num1+num2);
	else if(operator=='-')
		printf("Result=%d",num1-num2);
	else if (operator=='*')
		printf("Result=%d",num1*num2);
	else if(operator=='/'&&num2!=0)
		printf("Result=%d",num1/num2);
	else if(operator=='/'&& num2==0)
		printf("Division by zero is not  allowed");
	else
		printf("Invalid operator");
 	return 0;
}



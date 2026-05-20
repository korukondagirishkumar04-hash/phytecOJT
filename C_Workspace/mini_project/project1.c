#include<stdio.h>
int main()
{
	int choice;
	float num1,num2,result;
	while(1)
	{
		printf("--\n Simple Calculator---\n");
		printf("1.Addition\n");
		printf("2.Subtraction\n");
		printf("3.Multiplication\n");
		printf("4.Division\n");
		printf("5.Exit\n");
		printf("Enter your choice");
		scanf("%d",&choice);
		if(choice==5)
		{
			printf("Calculator is closed");
		break;
		}
		printf("Enter two numbers");
		scanf("%e%e",&num1,&num2);
		switch(choice)
		{
			case 1:
				result=num1+num2;
					printf("Addittion of two numbers is %f\n",result);
				break;
			case 2:
				result=num1-num2;
				printf("Subtraction of two numbers is %f\n",result);
				break;
			case 3:
				result=num1*num2;
				printf("Multiplication of two numbers is %f\n",result);
				break;
			case 4:
				if(num2!=0)
					printf("Divison of two numbers is %f\n",num1/num2);
				else
					printf("Division by zero is not possible\n");
				break;
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}


	


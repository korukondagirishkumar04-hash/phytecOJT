#include<stdio.h>
int main()
{
	int num1,num2;
	char op;
	printf("Enter two numbers");
	scanf("%d%d",&num1,&num2);
	printf("Enter operator (+,-,*,/,%%): ");
	scanf(" %c", &op);
	switch(op)
	{
		case'+':
			printf("result is %d",num1+num2);
			break;
		case'-':
                        printf("result is %d",num1-num2);
                        break;
		case'*':
                        printf("result is %d",num1*num2);
                        break;
		case'/':
			if(num2!=0)
                        printf("result is %d",num1/num2);
			else
				printf("The number is not divisible by 0");
                        break;
		case'%':
                        printf("result is %d",num1%num2);
                        break;
		default:
                        printf("invalid opearator");
			return 0;
	}
}






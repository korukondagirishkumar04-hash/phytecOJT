//Integer division vs float division
#include<stdio.h>
int main()
{
	int a=20,b=10;
	int int_result;
	float float_res1,float_res2;
	//Integer Division
	int_result=a/b;
	//Float Division
	float_res1=(float)a/b;
	//Float Division using float variable
	float x=10.0,y=3.0;
	float_res2=x/y;
	printf("Integer Division is %d\n",int_result);
	printf("Float Division is %2f\n",float_res1);
	printf("Float Division is %2f\n",float_res2);
	return 0;
}

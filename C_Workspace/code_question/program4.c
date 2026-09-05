//Print range of float and double using float.h
#include<stdio.h>
#include<float.h>
int main()
{
	printf("Minimum float value is %e\n",FLT_MIN);
	printf("Maximum float value is  %e\n",FLT_MAX);
	printf("Minimum double value is %e\n",DBL_MIN);
	printf("Maximum double value is %e\n",DBL_MAX);
	return 0;
}

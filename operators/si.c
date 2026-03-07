#include<stdio.h>
int main()
{
	int p,t,r;
	float si;
	printf("enter the values:p,r,t");
	scanf("p=%d,r=%d, t=%d ",&p,&r,&t);
	si=(p*t*r)/100;
	printf("si=%f",si);
	return 0;
}

#include<stdio.h>
int main()
{
	float p,t,r,si;
       printf("enter the principal");
       scanf("%f\n",&p);
       printf("enter the time");
       scanf("%f\n",&t);
       printf("enter the rate");
       scanf("%f\n",&r);
       si=(p*t*r)/100;
       printf("si:%f\n",si);
       return 0;
}

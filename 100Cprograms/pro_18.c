#include <stdio.h> 
int main() 
{ 
float p,t,r,si;
printf("enter the principal rate:");
scanf("%f",&p);
printf("enter the time:");
scanf("%f",&t);
printf("enter the rate:");
scanf("%f",&r);

si=(p*t*r)/100;
printf("simple intrest:%.2f\n",si);
}
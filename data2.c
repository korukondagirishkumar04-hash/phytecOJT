#include<stdio.h>
#include<float.h>
int main()
{
float a=1.234543;
	double b=2.345654;
printf("maximum range of float:%f\n",FLT_MAX);
printf("minimum range of float:%f\n",FLT_MIN);
printf("maximum range of double:%lf\n",DBL_MAX);
printf("minimum range of double:%lf\n",DBL_MIN);
printf("float a:%.5f\n",a);
printf("double b:%.6lf\n",b);
return 0;
}

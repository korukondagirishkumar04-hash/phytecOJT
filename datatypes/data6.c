#include<stdio.h>
#include<float.h>
int main()
{
    float a=3.454;
    double b=2.987;
    printf("size of float:%zu\n",sizeof(float));
    printf("size of double:%zu\n",sizeof(double));
    printf("precision of float:%d digits\n",FLT_DIG);
    printf("precision of double:%d digits\n",DBL_DIG);
    printf("float a:%f\n",a);
    printf("double b:%lf\n",b);
    return 0;
}

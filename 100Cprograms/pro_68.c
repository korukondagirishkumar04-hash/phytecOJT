#include<stdio.h>
int prime(int num)
{
    int i;
    if(num<=1)
    {
        return 0;
    }
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
return 1;
}
int main()
{
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    
    if(prime(n))
    {
        printf("prime number:");
    }
    else
    {
        printf("not a prime number:");
    }
   

}
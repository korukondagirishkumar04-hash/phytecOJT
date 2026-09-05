//C program to calculate Sum, Product of all elements.


#include<stdio.h>
int main()
{
    int arr[100],n;
    int sum=0,product=1;
    printf("array size:");
    scanf("%d",&n);
    
    printf("enter array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    for( int i=0;i<n;i++)
    {
        sum+=arr[i];
        product*=arr[i];
    }
    
    printf("sum:%d\n",sum);
    printf("product:%d\n",product);
}
// Write a program to find the sum of array elements using pointers


#include<stdio.h>
int main()
{
int arr[50],n,sum;
int *p;

printf("enter the array:");
scanf("%d",&n);

printf("enter the number:");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

p=arr;

for(int i=0;i<n;i++){
    sum=sum+*(p);
}
printf("%d",sum);
return 0;
}

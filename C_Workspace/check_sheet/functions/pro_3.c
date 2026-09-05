//3) C program to find Sum of all Array Elements by passing array as an argument using User Define Functions.

#include<stdio.h>
int arraysum(int arr[40],int num)
{
    int i,sum=0;
   for(i=0;i<num;i++)
   {
       sum+=arr[i];
   }
   return sum;
   
    
}


int main()
{
   int arr[100],i,num;
   
   printf("enter the size:");
   scanf("%d",&num);
   printf("enter the elements:");
   for(i=0;i<num;i++)
   {
       scanf("%d",&arr[i]);
   }
   printf("array elements:%d",arraysum(arr,num));
}
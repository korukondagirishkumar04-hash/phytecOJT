//C program to swap adjacent elements of a one dimensional array

#include<stdio.h>
int main()
{
    int arr[50],n,i,temp;
    printf("array size:");
    scanf("%d",&n);
    
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n-1;i+=2)
    {
        temp=arr[i];
        arr[i]=arr[1+i];
        arr[1+i]=temp;
        
    }
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
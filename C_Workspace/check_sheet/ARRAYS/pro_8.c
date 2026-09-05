//C program to sort array elements in ascending order.

#include<stdio.h>
int main()
{
    int arr[50],n,temp;
    printf("array size:");
    scanf("%d",&n);
    
    printf("enter the elements:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("ascending order:");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    
}
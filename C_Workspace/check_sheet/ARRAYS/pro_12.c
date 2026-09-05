//C program to sort an one dimensional array in ascending order.


#include<stdio.h>
int main()
{
    int arr[50],n,i,temp;
    printf("enter size:");
    scanf("%d",&n);
    
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++ )
        {
            if(arr[i]<arr[j])
            {
        
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        }
    }
    }
    printf("ascending:");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    
    
}
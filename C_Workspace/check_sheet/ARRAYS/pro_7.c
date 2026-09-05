//C program to find a number from array elements.

#include<stdio.h>
int main()
{
    int arr[100],n,key,flag=0,i;
    printf("enter array size:");
    scanf("%d",&n);
    
    printf("enter the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("enter element to found:");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            flag=1;
            break;
            
        }
    }
    if(flag)
    
        printf("element is found");
    
    else
    
        printf("element not found");
    
    
}

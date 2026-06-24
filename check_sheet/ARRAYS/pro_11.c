// C program to find occurrence of an element in one dimensional array.


#include<stdio.h>
int main()
{
    int arr[50],n,i,key,count=0;
    printf("array size:");
    scanf("%d",&n);
    
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("key element");
    scanf("%d",&key);
    
    
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        count++;
        
    }
    printf("occurance:%d",count);
}
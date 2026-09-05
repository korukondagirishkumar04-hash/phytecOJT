// C program to delete given element from one dimensional array.

#include<stdio.h>
int main()
{
    int arr[50],i,n,pos;
    printf("enter the size:");
    scanf("%d",&n);
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("enter the position:");
    scanf("%d",&pos);
    
    for(i=pos-1;i<n-1;i++)
    {
        arr[i]=arr[i+1];
        n--;
    }
    printf("array after delete");
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
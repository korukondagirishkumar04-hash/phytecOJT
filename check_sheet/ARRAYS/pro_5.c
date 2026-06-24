//C program to merge Two One Dimensional Arrays elements.


#include<stdio.h>
int main()
{
    int arr1[50],n,arr2[23];
    printf("enter array size:");
    scanf("%d",&n);
    
    printf("enter array 1:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    
    
    for(int i=0;i<n;i++)
    {
        arr2[i]=arr1[i];
    }
     
   printf("merge:");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr2[i]);
    }
    
}
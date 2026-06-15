//C program to replace all EVEN elements by 0 and Odd by 1 in One Dimensional Array.


#include<stdio.h>
int main()
{
    int arr[100],n;
    printf("array size:");
    scanf("%d",&n);
    printf("array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    
    for(int i=0;i<n;i++)
    {
       if(arr[i]%2==0)
       {
           arr[i]=0;
       }
       else
       {
           arr[i]=1;
       }
        
    }
    printf("modified num:");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
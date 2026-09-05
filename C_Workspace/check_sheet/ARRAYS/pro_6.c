// C program to Add and Subtract of Two One Dimensional Array elements.

#include<stdio.h>
int main()
{
    int arr[50],n;
    int add=0,sub=0;
    printf("array size:");
    scanf("%d",&n);
    printf("arrays elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        add+=arr[i];
       
    }
    sub=arr[0];
    for(int i=0;i<n;i++)
    {
      sub-=arr[i];
       
    }
    
    printf("add:%d\n",add);
    printf("sub:%d",sub);
    return 0;
}
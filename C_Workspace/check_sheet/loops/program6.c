//print even numbers from 1 to n
#include<stdio.h>
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);

    printf("Even numbers: ");
    for(int i=1; i<=n; i++)
    {
        if(i%2==0)
        {
            printf("%d ",i);
        }
    }
    printf("\nOdd numbers: ");
    for(int i=1; i<=n; i++)
    {
        if(i%2!=0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
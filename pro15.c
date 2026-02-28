#include<stdio.h>
int main()
{
	int n,i;
	printf("enter the values");
	scanf("%d",&n);
	if(n<=1){
		printf("not a primenumber");
                      return 0;
		
	}
	for(i=2;i<n;i++)
	{
		if(n%i==0){
			printf("not a primenumber");
			return 0;
		}
	}
	printf("prime number");
	return 0;
}

//season of a month using switch
#include<stdio.h>
int main()
{
	int month;
	printf("Enter a month number");
	scanf("%d",&month);
	switch(month)
	{
		case 12:
		case 1:
			printf("Winter Season");
			break;
		case 2:
		case 3:
			printf("Spring Season");
			break;
		case 4:
		case 5:
		case 6:
			printf("Summer Season");
			break;
		case  7:
		case 8:
		case 9:
			printf("Rainy Season");
			break;
		case 10:
		case 11:
			printf("Autum Season");
			break;
		default:
			printf("Invalid Month");
	}	
	return 0;
}

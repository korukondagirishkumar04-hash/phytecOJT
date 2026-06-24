#include<stdio.h>
enum Menu 
{
	Idli=1,
	Dosa,
	Vada,
	Poori,
	Upma,
	Bonda,
        Parota,
	EXIT
};
int main()
{
	int choice,quantity;
	float total = 0;
	while(1)
	{
		printf("\n----FAST FOOD CENTER----\n");
		printf("1.Idli  -30\n");
		printf("2.Dosa  -30\n");
	        printf("3.Vada  -30\n");
	        printf("4.Poori  -40\n");
		printf("5.Upma  -25\n");
		printf("6.Bonda  -30\n");
		printf("7.Parota -40\n");
		printf("8.Exit\n ");

		printf("Enter your Choice: ");
		scanf("%d", &choice);

		if(choice == EXIT)
		{
			break;
		}
		printf("Enter quantity: ");
		scanf("%d", &quantity);

		switch(choice)
				{
					case Idli:
						total +=30 * quantity;
						break;
					 case Dosa:
                                                total +=30 * quantity;
                                                break;
				         case Vada:
                                                total +=30 * quantity;
                                                break;
				         case Poori:
                                                total +=40 * quantity;
                                                break;
				         case Upma:
                                                total +=25 * quantity;
                                                break;
				         case Bonda:
                                                total +=30 * quantity;
                                                break;
				          case Parota:
                                                total +=40 * quantity;
                                                break;
					  default:
						printf("Invalid choice\n");
				}


	}

	printf("\nTotal Bill=%f\n",total);
	printf("Thank You! Visit Again \n");
	return 0;
}

	
	

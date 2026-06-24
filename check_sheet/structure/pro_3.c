#include<stdio.h>
struct Book{
	int isbn;
	char title[50];
	float price;

};
int main(){
	struct Book library[3];
	for(int i=0;i<3;i++)
	{
		printf("\nEnter details of book %d:\n",i+1);
		printf("ISBN: ");
		scanf("%d",&library[i].isbn);
		printf("Title: ");
		scanf("%s\n",library[i].title);
		printf("Price: ");
		scanf("%f",&library[i].price);
	}
	printf("\n---Library Books---\n");
	for(int i=0;i<3;i++){
		printf("%d.%30s %.2f\n",library[i].isbn,library[i].title,library[i].price);
	}
	return 0;
}

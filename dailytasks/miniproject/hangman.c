#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
int main()
{
	char fruits[16][30]={"apple","mango","guava","kiwi","custard apple","grapes","cherry","blue berry","apricot","peach","pomegranate","pine apple","avacado","star fruit","banana","straw berry"};
	char word[30],display[30],guess;
	int i,len,chances=6,correct=0;
	srand(time(0));
	int index=rand()%16;
		for(i=0;i<len;i++)
	{
		if(word[i]==' ')
			display[i]=' ';
		else
			display[i]='_';
	}
	display[len]='\0';
	printf("HANGMAN GAME\n");
	printf("Guess the fruit name\n");
	while(chances>0 && correct<len)
	{
		printf("\nWord:%s",display);
		printf("\nChances left:%d",chances);
		printf("\n Enter a letter:");
		scanf("%c",&guess);
		guess=tolower(guess);
		int found=0;
		for(i=0;i<len;i++)
		{
			if(word[i]==guess&&display[i]=='_')
			{
				display[i]=guess;
				correct++;
				found=1;
			}
		}
		if(found)
			printf("Correct\n");
		else
		{
			chances--;
			printf("Wrong!\n");
		}
	}
	if(correct==len)
		printf("\n You WIN!Word is %s\n",word);
	else
		printf("\n YOU LOSE! Word is %s\n",word);
	return 0;
}

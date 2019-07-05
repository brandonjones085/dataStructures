
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char toUpperCase(char ch)
{
	ch = ch - 32; 

	return ch; 
} 

char toLowerCase(char ch)
{
	ch = ch + 32; 
	return ch; 
}

int stringLength(char s[])
{
	int count = 0; 
	int i; 
	for( i = 0; s[i] != '\0'; i++)
	{
		count += 1; 
	}
	return count; 
}

void camelCase(char *word)
{
	int count = stringLength(word);

	int index = 0; 

	int i; 
	for(i = 0; i < count; i++)
	{
		if(i == 0 && (word[i] >= 'A' && word[i] <= 'Z'))
		{
			word[i] = toLowerCase(word[i]);
		}

		if(word[i] == '_' && word[i+1]>= 'a' && word[i+1] <= 'z' )
		{
			word[i + 1] = toUpperCase(word[i + 1]);
		}
		else if(word[i]=='_' && word[i+1]>= 'A'  && word[i+1] <= 'Z' ) 

		{
			word[i+1] = word[i+1];
		}
		else
		{
			word[index++] = word[i];
		}
	}
	word[index] = '\0';
}

int main()
{
	char word[50];

	printf("Please enter a word: ");
	scanf("%s", word);

	camelCase(word);
 

	printf("Transformed word %s\n", word);	

	return 0; 
}

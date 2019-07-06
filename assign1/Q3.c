# /* CS261- Assignment 1 - Q.3*/
/* Name: Brandon Jones
 * Date: 6/28/2019
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



char toUpperCase(char ch) {
	/*Convert ch to upper case, assuming it is in lower case currently*/
	ch = ch - 32;

	return ch;
}


char toLowerCase(char ch) {
	/*Convert ch to lower case, assuming it is in upper case currently*/
	ch = ch + 32;

	return ch;
}


int stringLength(char s[]) {
	int count = 0;
	/*Return the length of the string*/

	int i; 
	for (i = 0; s[i] != '\0'; i++)
	{
		count += 1;
	}
	return count;

}

//Description: removes spaces
void removeSpaces(char word[])
{
	
	int count = stringLength(word);
	
	int i; 
	for (i = 0; i < count; i++)
	{
		if (word[i] == ' ')
		{
			word[i] = '_'; 
		}
	}


};

//Description: used to check the leading values for underscores
void checkForLeadingUnderscore(char word[])
{
	int count = stringLength(word);
	

	int i; 
	for (i = 0; i < count; i++)
	{
		if (word[0] == '_')
		{
			if (word[1] >= 'A' && word[1] <= 'Z')
			{
				word[0] = toLowerCase(word[1]);
			}
			else
			{
				word[0] = word[1];
			}
			
		}
	}
	

}

//Description: used to remove double underscores from the string
void checkForDoubleUnderscore(char word[])
{
	int count = stringLength(word);

	int index = 0;

	int i;
	for (i = 0; i < count; i++)
	{


		if (word[i] == '_' && word[i + 1] == '_' )
		{
			word[i] = word[i + 2];

		}

		else
		{
			word[index++] = word[i];
		}

	}
	word[index] = '\0';

}

//Description: Used to check for special characters and remove them
void checkForLetters(char word[])
{

	int count = stringLength(word);

	int index = 0;

	int i;
	for (i = 0; i < count; i++)
	{

		if ((word[i] >= 'A' && word[i] <= 'Z') ||( word[i] >= 'a' && word[i] <= 'z'))
		{
			
			
			word[index++] = word[i];
		}
		else if( word[i] != '_')
		{
			
			word[i] = word[i];
		}
	}
	word[index] = '\0';

}


//Description: used to make the first letter lower case. It's called last and used to double
//check the first index is lowercase
void index0Lower(char word[])
{
	
		if ( word[0] >= 'A' && word[0] <= 'Z')
		{
			word[0] = toLowerCase(word[0]);
		}
	
}

//Description: used to make a whole word lowercase
void convertWordToLower(char word[])
{
	int count = stringLength(word);
	int i;
	for (i = 0; i < count; i++)
	{
		
		if (word[i] >= 'A' && word[i] <= 'Z' && word[i] != '_' )
		{
			word[i] = toLowerCase(word[i]);
		}

	}
	
}

//Description: checks for letters, checks for spaces. Returns 1 if the string
// only contains letters and underscores
int validateLetters(char word[])
{
	int count = stringLength(word);

	int i; 
	for (i = 0; i < count; i++)
	{
		if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] == ' ') || (word[i] == '_'))
		{
			return 1; 
		}
		else
		{
			
			return 0; 
			
		}

		
	}
	return 0; 
}



//Description: used to check if the sting is all lowercase letters
int validateLowercase(char word[])
{
	int count = stringLength(word);

	int i;
	for (i = 0; i < count; i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z' )
		{
			return 0;
		}
		else
		{

			return 1;

		}


	}
return 0; 

}

//description: Used to validate the string doesn't have three consecutive underscores  input
int validateUnderscores(char word[])
{
	int count = stringLength(word);

	int i;
	for (i = 0; i < count; i++)
	{
		if (word[i] == '_' && word[i+1] == '_' && word[i + 2] == '_')
		{
			return 0;
		}
		
		else
		{

			return 1;

		}


	}
return 0; 
}

//Description: tests the input for a single underscore
int validateSingleUnderscore(char word[])
{
	int count = stringLength(word);

	int i;
	for (i = 0; i < count; i++)
	{
		if (count == 2 && word[0] == '_' )
		{
			return 0;
		}

		else
		{

			return 1;

		}


	}

	return 0; 
}


//Source: https://www.geeksforgeeks.org/remove-all-occurences-of-a-character-in-a-sting
void camelCase(char* word) {

	
	/*Convert to camelCase*/
	int count = stringLength(word);

	int index = 0;

	
	
	removeSpaces(word); 

	checkForDoubleUnderscore(word);
	convertWordToLower(word); 

	int i; 
	for (i = 0; i < count; i++)
	{
	
		if (i == 0 && (word[i] >= 'A' && word[i] <= 'Z'))
		{
			word[i] = toLowerCase(word[i]);
		}


		if (word[i] == '_' && word[i + 1] >= 'a' && word[i+1] <= 'z')
		{
			word[i + 1] = toUpperCase(word[i + 1]);

		}
		else if (word[i] == '_' && word[i + 1] >= 'A' && word[i + 1] <= 'Z')
		{
			word[i + 1] = word[i + 1]; 
		}
		else
		{
			word[index++] = word[i];
		}

	}
	word[index] = '\0';



	checkForLetters(word);
	checkForLeadingUnderscore(word);
	index0Lower(word);


}


//Source: https://stackoverflow.com/questions/22065675/get-text-from-user-input-using-c
int main() {

	char word[50];
	

	/*Read the string from the keyboard*/
	printf("Please enter a word: ");
	
	fgets(word, 50, stdin);
	


	while (validateLetters(word) == 0 || validateLowercase(word) == 0 || validateUnderscores(word) == 0 || validateSingleUnderscore(word) == 0)
	{
		printf("Invalid input! Try again: ");
		fgets(word, 50, stdin);
	}

	/*Call camelCase*/
	camelCase(word);


	/*Print the new string*/
	printf("Transformed word %s\n\n", word);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int foo(int *a, int *b, int c)
{
	int temp = *a; 
	*a = *b; 
	*b = temp;

	c -= 1; 

	return c; 
}



int main()
{
	int x = rand() % 10; 
	int y = rand() % 10; 
	int z = rand() % 10; 


	printf("The Value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The vlaue of z is %d\n ", z);


	int fooValue = foo(&x, &y, z); 

	printf("Swapped\n\n");
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The value of z is %d\n", z);


	printf("The value of foo is %d\n", fooValue);

	return 0; 


}

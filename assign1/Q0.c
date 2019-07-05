/* CS261 - Assignment 1 - Q.0 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int *iptr)
{
	printf("The value of iptr %d\n", *iptr);
	printf("The address of iptr %p\n", iptr);

	*iptr += 5;

	printf("The address of iptr %p\n", iptr);


}

void fooB(int *jptr)
{
	printf("The value of iptr %d\n", *jptr);
	printf("The address of iptr %p\n", jptr);

	*jptr -= 1; 

	printf("The address of iptr %p\n", jptr); 
} 

int main()
{
	int x = rand() % 10 + 0; 

	printf("The value of x is %d\n", x);
	printf("The address of x is %p\n ", &x );

	fooA(&x);

	printf("The value of x is %d\n", x);

	fooB(&x);

	printf("The value of x is %d\n", x);

	return 0; 
}

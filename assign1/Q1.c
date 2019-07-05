/* CS261- Assignment 1 - Q.1*/
/* Name: Brandon Jones	
 * Date: 6/27/2019
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student
{
    int id;
    int score;
};

struct student *allocate()
{
    /*Allocate memory for ten students*/
    struct student *ptr = malloc(10 * sizeof(struct student));

    /*Return the pointer*/
    return ptr;
}

//Source: https://stackoverflow.com/questions/42321370/fisher-yates-shuffling-algorithm-in-c
void generate(struct student *students)
{
    /*Generate random and unique IDs and random scores for ten students,
IDs being between 1 and 10, scores between 0 and 100*/

    int randArray[10];
	
    int i; 
    for ( i = 0; i < 10; i++)
    {
        randArray[i] = i;
    }
    
    
    for ( i = 9; i > 0; i--)
    {
        int j = rand() % (i + 1);

        int temp = randArray[i];
        randArray[i] = randArray[j];
        randArray[j] = temp;
    }
     
    for (i = 0; i < 10; i++)
    {
        int randScore = rand() % 100 + 0;

        students[i].id = randArray[i] + 1;
        students[i].score = randScore;
    }
}

void output(struct student *students)
{
    /*Output information about the ten students in the format:
			 ID1 Score1
			 ID2 score2
			 ID3 score3
			 ...
			 ID10 score10*/
    int i; 

    for ( i = 0; i < 10; i++)
    {

        printf("ID %d Score %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student *students)
{
    /*Compute and print the minimum, maximum and average scores of the
ten students*/
    int min = 100;
    int max = 0;
    double avg = 0;
   
    int i; 
    for ( i = 0; i < 10; i++)
    {
        if (students[i].score < min)
        {
            min = students[i].score;
        }
        if (students[i].score > max)
        {
            max = students[i].score;
        }

        avg += students[i].score;
    }

    avg = avg / 10;

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Average: %f\n", avg);
}

void deallocate(struct student *stud)
{
    /*Deallocate memory from stud*/
    if (stud != 0)
    {
        free(stud);
    }
}

int main()
{
    struct student *stud = NULL;

    /*Call allocate*/
    stud = allocate();

    /*Call generate*/
    generate(stud);

    /*Call output*/
    output(stud);

    /*Call summary*/
    summary(stud);

    /*Call deallocate*/
    deallocate(stud);

    return 0;
}

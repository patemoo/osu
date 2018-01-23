/* CS261- Assignment 1 - Q.4*/
/* Name: Patrick Moore
 * Date: Jan 22, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

int compareFunction(const void *a, const void *b)
{
    struct student *x = (struct student *)a;
    struct student *y = (struct student *)b;
    return ( x->score - y->score );
}

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     qsort(students, n, sizeof(struct student), compareFunction);       
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 6;
    
    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(n * sizeof(struct student));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    // create the id and score for the fist student.
    students[0].id = rand() % 101;
    students[0].score = rand() % 51 + 50;

    // for each new student compare the new random number to the ids of the previous students.
    for (int i=1; i<n; i++)
    {
        int repeat = 1;
        int num;
        while (repeat)
        {
            repeat = 0;
            num = rand() % 101;
            for (int j=0; j<i; j++)
            {
                if (students[j].id == num)
                {
                    repeat = 1;
                }
            }
        }
        students[i].id = num;

        students[i].score = rand() % 51 + 50;
    }
    
    /*Print the contents of the array of n students.*/
    for (int i=0; i<n; i++)
    {
        printf("student %d: id: %d score: %d\n", i+1, students[i].id, students[i].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    printf("\n");
    for (int i=0; i<n; i++)
    {
        printf("student %d: id: %d score: %d\n", i+1, students[i].id, students[i].score);
    }
    
    return 0;
}

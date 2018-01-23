/* CS261- Assignment 1 - Q.1*/
/* Name: Patrick Moore
 * Date: Jan. 19, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
    /*Allocate memory for ten students*/
    struct student *p = malloc(10 * sizeof(struct student));
     
    /*return the pointer*/
    return p;
}

void generate(struct student* students){
    /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    // srand(time(0));

    for (int i=0; i<10; i++)
    {
        students[i].id = rand() % 10 + 1;
        students[i].score = rand() % 101;
    }
     
}

void output(struct student* students){
    /*Output information about the ten students in the format:
            ID1 Score1
            ID2 score2
            ID3 score3
            ...
            ID10 score10*/
    for (int i=0; i<10; i++)
    {
        printf("ID%d Score%d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = students[0].score;
    int max = students[0].score;
    int avg = students[0].score;

    for (int i=1; i<10; i++)
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

    avg /= 10;

    printf("min: %d\n", min);
    printf("max: %d\n", max);
    printf("average: %d\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
     stud = 0;
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}

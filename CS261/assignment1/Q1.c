/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     
     /*return the pointer*/
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    
    /*call generate*/
    
    /*call output*/
    
    /*call summary*/
    
    /*call deallocate*/

    return 0;
}

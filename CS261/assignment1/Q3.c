/* CS261- Assignment 1 - Q.3*/
/* Name: Patrick Moore
 * Date: Jan. 20, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int compareFunction(const void *a, const void *b)
{
    return ( *(int*)a - *(int*)b );
}


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
     qsort(number, n, sizeof(int), compareFunction);    
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
    for (int i=0; i<n; i++)
    {
        array[i] = rand() % 101;
    }
    
    /*Print the contents of the array.*/
    for (int i=0; i<n; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    
    /*Print the contents of the array.*/
    for (int i=0; i<n; i++)
    {
        printf("%d\n", array[i]);
    } 
    
    return 0;
}

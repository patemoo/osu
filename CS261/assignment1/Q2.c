/* CS261- Assignment 1 - Q.2*/
/* Name: Patrick Moore
 * Date: Jan. 19, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    
    /*Set b to half its original value*/
    *b /= 2;
    
    /*Assign a+b to c*/
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    
    /*Print the values of x, y and z*/
    printf("x: %d\ny: %d\nz: %d\n\n", x, y, z);
    
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    /*Print the value returned by foo*/
    printf("foo returns: %d\n\n", foo(&x, &y, z));
    
    /*Print the values of x, y and z again*/
    printf("x: %d\ny: %d\nz: %d\n\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
    /**
     * Yes, the return value is differnet. Because the c param is passed by value 
     * z is not affected by the statements inside of foo().
     * */
    return 0;
}
    
    

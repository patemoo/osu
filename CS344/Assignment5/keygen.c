#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Get character
 * Takes value between 0 and 27
 * Return space character if value equals 27
 * For all other values, return capital ASCII character 
 * starting with 'A' which is ASCII 65
 */
char getCharacter(int value)
{
    char result;
    
    switch (value)
    {
        case 26:
            // The value for a ASCII space character is 32.
            result = 32;
            break;
        default:
            // Add value to 65 to get correct ASCII character.
            result = value + 65;
    }

    return result;
}

/**
 * Get value
 * Takes a capital ASCII letter character
 * Return 26 if argument equals space character value
 * For all other capital letter characters, reaturn the corresponding value
 * after subtracting 65 to result with a zero indexed value
 */
int getValue(char character)
{
    int result;

    switch ((int)character)
    {
        case 32:
            result = 26;
            break;
        default:
            result = (int)character - 65;
    }

    return result;
}

/**
 * keygen.c
 * This program creates a key file of specified length.
 * the characters in the file generated will be any of the
 * 27 allowed characters, generated using the standard
 * Unix randomization methods.
 */
int main(int argc, char* argv[])
{
    int i, keyLength;
    time_t t;

    // Intializes random number generator
    srand((unsigned) time(&t));

    keyLength = atoi(argv[1]);

    // Print as many random numbers as determined by
    // the keyLength command line argument
    for (i = 0 ; i < keyLength ; i++) {
        printf("%c", getCharacter(rand() % 27));
    }
    printf("\n");

    return 0;
}
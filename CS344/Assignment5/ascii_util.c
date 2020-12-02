#include "ascii_util.h"

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
 * 
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
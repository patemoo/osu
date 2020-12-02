/* ascii_util.h */
#ifndef ASCII_UTIL_H
#define ASCII_UTIL_H

/**
 * Get character
 * Takes value between 0 and 26
 * Return space character if value equals 26
 * For all other values, return capital ASCII character 
 * starting with 'A' which is ASCII 65
 */
char getCharacter(int value);

/**
 * Get value
 * Takes a capital ASCII letter character
 * Return 26 if argument equals space character value
 * For all other capital letter characters, reaturn the corresponding value
 * after subtracting 65 to result with a zero indexed value
 */
int getValue(char character);

#endif /* ASCII_UTIL_H */
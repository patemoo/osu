#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    char* word = nextWord(file);

    while (word != 0)
    {

        hashMapPut(map, word, sizeof(word));

        word = nextWord(file);
    }
}

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int levenshtein(char *s1, char *s2) {
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len+1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x-1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return(column[s1len]);
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);

        // Implement the spell checker code here..

        if(hashMapContainsKey(map, inputBuffer))
        {
            printf("\n ** word spelled correctly ** \n\n");
        }
        else 
        {
            HashLink* one = malloc(sizeof(HashLink));
            HashLink* two = malloc(sizeof(HashLink));
            HashLink* three = malloc(sizeof(HashLink));
            HashLink* four = malloc(sizeof(HashLink));
            HashLink* five = malloc(sizeof(HashLink));
            one->value = two->value = three->value = four->value = five->value = 20;

            for (int i=0; i<map->capacity; i++)
            {
                HashLink* link = map->table[i];
                while (link != 0)
                {   
                    int value = levenshtein(inputBuffer, link->key);
                    link->value = value;

                    if (value < one->value)
                    {
                        one->value = value;
                        one->key = link->key;
                    }
                    else if (value < two->value)
                    {
                        two->value = value;
                        two->key = link->key;
                    }
                    else if (value < three->value)
                    {
                        three->value = value;
                        three->key = link->key;
                    }
                    else if (value < four->value)
                    {
                        four->value = value;
                        four->key = link->key;
                    }
                    else if (value < five->value)
                    {
                        five->value = value;
                        five->key = link->key;
                    }

                    link = link->next;
                }
            }

            printf("did you mean?\n %s,\n %s,\n %s,\n %s,\n %s\n", one->key, two->key, three->key, four->key, five->key);
        }
        
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
    }
    
    hashMapDelete(map);
    return 0;
}
/* CS261- Assignment 1 - Q.5*/
/* Name: Patrick Moore
 * Date: Jan 22, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    return ch-'A'+'a';
}

void sticky(char* word){
    /*Convert to sticky caps*/
    for (int i=0; i<20; i++)
    {
        if (word[i] == '\0')
        {
            return;
        }
        
        if (i % 2 == 0)
        {
            if (word[i] > 93)
            {
                word[i] = toUpperCase(word[i]);
            }
        }
        else 
        {
            if (word[i] < 93)
            {
                word[i] = toLowerCase(word[i]);
            }
        }
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char *word = malloc(20 * sizeof(char));

    scanf("%s\n", word);
    
    /*Call sticky*/
    sticky(word);
    
    /*Print the new word*/
    printf("%s\n", word);
    
    return 0;
}

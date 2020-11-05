#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInput.h"

/**
 * Get user input
 */
struct UserInput*  getUserInput()
{
	// Take user input as an array of strings.
	char userInput[MAX_INPUT_ARG_CHARS];
      	fgets(userInput, MAX_INPUT_ARG_CHARS, stdin);

  	return  processUserInput(userInput);  
}

/**
 * Process user input
 */
struct UserInput* processUserInput(char* userInput)
{
	struct UserInput* newInput = malloc(sizeof(struct UserInput));
	newInput->runInBackground = false;

	char delim[2] = " ";
	char* token;

	// Store first input arg in command prop
	token = strtok(userInput, delim);

	newInput->command = token;
	newInput->argvLength = 0;

	while (token != NULL)
	{
		if (strcmp(token, "<") == 0)
		{
			newInput->inputFile = strtok(NULL, delim);
		}
		else if (strcmp(token, ">") == 0)
		{
			newInput->outputFile = strtok(NULL, delim);
		}
		else if (strcmp(token, "&\n") == 0)
		{
			newInput->runInBackground = true;	
		}
		else 
		{
			newInput->argv[newInput->argvLength] = token;
			newInput->argvLength += 1;	
		}
		token = strtok(NULL, delim);
	}

	return newInput;
}

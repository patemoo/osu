/* userInput.h */
#ifndef USER_INPUT_H
#define USER_INPUT_H

#define MAX_INPUT_ARGS 512
#define MAX_INPUT_ARG_CHARS 2048


typedef struct UserInput UserInput;

/**
 * UserInput stores relevant user input values.
 */
struct UserInput
{
	char* command;
	char* argv[MAX_INPUT_ARGS];
	int argvLength;
	char* inputFile;
	char* outputFile;
	bool runInBackground;	
};

/**
 * Get user input
 */
struct UserInput* getUserInput();

/**
 * Process user input
 * return: struct UserInput
 */
struct UserInput* processUserInput(char *str);

#endif /* USER_INPUT_H */

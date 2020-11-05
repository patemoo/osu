#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "userInput.h"

/**
 * SIGINT handler
 */
void handle_SIGINT(int signo)
{
	char message[23];
	sprintf(message, "terminated by signal %d\n", signo);
	write(STDOUT_FILENO, message, 23);
}

/**
 * SIGTSTP handler
 */
void handle_SIGTSTP(int signo)
{
	char* enterMessage = "Entering foreground-only mode (& is now ignored)";
    write(STDOUT_FILENO, enterMessage, 50);

	char* exitMessage = "Exiting foreground-only mode";
    write(STDOUT_FILENO, exitMessage, 30);
}

int main()
{
	// Initialize program vars
	int childStatus = 0;
	int saved_stdout;
	int saved_stdin;

	// Signal code:
	// Initialize SIGINT_action struct
	struct sigaction SIGINT_action = {0};
	// Add handler
	SIGINT_action.sa_handler = handle_SIGINT;
	// Block other signals
	sigfillset(&SIGINT_action.sa_mask);
	sigaction(SIGINT, &SIGINT_action, NULL);

	// Initialize SIGTSTP_action struct
	struct sigaction SIGTSTP_action = {0};
	// Add handler
	SIGTSTP_action.sa_handler = handle_SIGTSTP;
    // Block signals
    // sigfillset(&SIGTSTP_action.sa_mask);
	sigaction(SIGTSTP, &SIGTSTP_action, NULL);

	// Create bool used to exit shell.
	bool exitShell = false;
	
	// Run shell prompt loop.
	while (!exitShell)
	{
		
		// Print shell prompt
		printf(": ");
		fflush(stdout);

		// Get user input.
		// Store user input command values in a struct
		// so each value can be easily accessed.
		struct UserInput* inputObj;
		inputObj = getUserInput();
		
		// Remove new line char from arugments
		// this will help when using these values later.
		int lastArgIndex = inputObj->argvLength - 1;
		char* lastArg = inputObj->argv[lastArgIndex];
		lastArg[strcspn(lastArg, "\n")] = 0;

		// Expand code
		for (int i = 1; i < inputObj->argvLength; i++)
		{
			// if (strcspn(inputObj->argv[i]))
		}

		// Create a command var to comapre against.
		char* command = inputObj->command;
	
		// Handle built-in commands
		// exit
		if (strcmp(command, "exit") == 0)
		{
			// todo: kill any other processes.
			exitShell = true;
		}	

		// cd
		else if (strcmp(command, "cd") == 0)
		{

			if (!inputObj->argv[1])
			{
				// todo: change to HOME dir.
				chdir(getenv("HOME"));
			}
			else
			{
				// todo: change to arg[1] dir.
				chdir(inputObj->argv[1]);
			}
		}

		// status
		else if (strcmp(command, "status") == 0)
		{
			printf("exit value %d\n", childStatus);			
		}

		// blank
		else if (strcmp(command, "") == 0 || strcmp(command, "\n") == 0)
		{
			// do nothing..
		}

		// comment
		else if (strstr(command, "#") != NULL)
		{
			// do nothing..
		}

		// Handle all other commands
		else 
		{
		bool fileError = false;
				
			if (inputObj->runInBackground)
			{
				if (!inputObj->inputFile)
				{
					inputObj->inputFile = "./dev/null";
				}
				if (!inputObj->outputFile)
				{
					inputObj->outputFile = "./dev/null";
				}
			}

			// Handle input file
			if (inputObj->inputFile)
			{
				saved_stdin = dup(0);	
	
				// create var
				char* inputFilePath = inputObj->inputFile;
				// remove new line
				inputFilePath[strcspn(inputFilePath, "\n")] = 0;

				// open input file
				int inputFile = open(inputFilePath, O_RDONLY);
				if (inputFile == -1)
				{
					printf("cannot open %s for input\n", inputFilePath);
					fflush(stdout);
					childStatus = 1;
					fileError = true;
				}

				if (!fileError)
				{
				int result = dup2(inputFile, 0);
				if (result == -1)
				{
					perror("input dup2()");
					childStatus = 1;
				}
				}
			}

			// Handle output file
			if (inputObj->outputFile)
			{
				saved_stdout = dup(1);

				// create var
                                char* outputFilePath = inputObj->outputFile;
                                // remove new line
                                outputFilePath[strcspn(outputFilePath, "\n")] = 0;

				// open output file
				int outputFile = open(outputFilePath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (outputFile == -1) 
                                { 
                                        perror("No such file??");
                                        childStatus = 1;
					fileError = true;
                                }

				if (!fileError)
				{
                                int result = dup2(outputFile, 1);
                                if (result == -1)
                                { 
                                        perror("input dup2()");
                                        childStatus = 1;
                                }
				}				
			}

			if (!fileError)
			{
				// Fork a new process to run external command.			
				pid_t spawnPid = fork();

				switch(spawnPid)
				{
					case -1:
						// error
						perror("fork()\n");
						exit(1);
						break;
					case 0:
						// update signal before exec
						SIGINT_action.sa_handler = SIG_IGN;
						SIGTSTP_action.sa_handler = SIG_IGN;

						// In the child process
						execvp(command, inputObj->argv);		
						
						perror(command);
						exit(2);
						break;
					default:
						// In the parent process
							
						if (inputObj->runInBackground)
						{
							// run in the background.
							printf("background pid is %d\n", spawnPid);
							fflush(stdout);
						}
						else
						{
							spawnPid = waitpid(spawnPid, &childStatus, 0);
							
							// restore stdout
							dup2(saved_stdout, 1);
							dup2(saved_stdin, 0);
						}
						break;
				}

			}
		}

		// todo: check for background processes.

		// restore stdout
        dup2(saved_stdout, 1);
        dup2(saved_stdin, 0);
	}
	
	return 0;
}

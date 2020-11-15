#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * Struct to hold thread buffers props.
 */
struct bufferProps
{
    char* characters;
    ssize_t length;
};

// Define process buffer.
struct bufferProps* processBuffer;

/**
 * InputThread
 * Takes a line of characters from standard input.
 * Stores line characters and length in the inputBuffer.
 */
struct bufferProps* inputThread()
{
    struct bufferProps* inputBuffer = malloc(sizeof(struct bufferProps));
    inputBuffer->characters = NULL;
    inputBuffer->length = 0;
    size_t bufferLength = 0;

    // Get new line from standard input.
    inputBuffer->length = getline(&inputBuffer->characters, &bufferLength, stdin);

    return inputBuffer;
}

/**
 * Line Separator
 * Replaces a new line character with a space.
 */
struct bufferProps* lineSeparatorThread(struct bufferProps* inputBuffer)
{
    char* space = " ";

    inputBuffer->characters[strcspn(inputBuffer->characters, "\n")] = *space;

    if (strcmp(inputBuffer->characters, "STOP ") == 0)
    {
        processBuffer->characters = "STOP";
        processBuffer->length = 5;
    }
    else if (processBuffer->length > 0)
    {
        strcat(processBuffer->characters, inputBuffer->characters);
        processBuffer->length += inputBuffer->length;
    }
    else
    {
        processBuffer->characters = inputBuffer->characters;
        processBuffer->length = inputBuffer->length;
    }

    inputBuffer->characters = NULL;

    return processBuffer;
}

/**
 * Plus signs
 * Replaces '++' with '^'
 */
struct bufferProps* plusSignsThread(struct bufferProps* processBuffer)
{
    struct bufferProps* outputBuffer = malloc(sizeof(struct bufferProps));
    outputBuffer->characters = malloc(81 * sizeof(char));
    outputBuffer->length = 0;

    int processIndex = 0;
    bool skip = false;

    while (outputBuffer->length < 80)
    {
        int outputIndex = outputBuffer->length;
        // Skip if ...
        if (skip)
        {
            processIndex++;
            skip = false;
        }
        // Else if ++
        else if (processBuffer->characters[processIndex] == '+' && processBuffer->characters[processIndex + 1] == '+')
        {
            outputBuffer->characters[outputIndex] = '^';
            outputBuffer->length++;
            processIndex++;
            skip = true;
        }
        // Else add
        else
        {
            outputBuffer->characters[outputIndex] = processBuffer->characters[processIndex];
            outputBuffer->length++;
            processIndex++;
        }
    }

    processBuffer->characters = &processBuffer->characters[processIndex];
    processBuffer->length -= processIndex++;

    return outputBuffer;
}

/**
 * Output
 * Prints processed data as a line of 80 characters.
 */
void outputThread(struct bufferProps* outputBuffer)
{
    printf("%s\n", outputBuffer->characters);
}

/**
 * Line processor
 * 
 */
int main()
{
    processBuffer = malloc(sizeof(struct bufferProps));

    // bool to end loop
    // todo: change var name.
    bool endLoop = false;

    while (!endLoop)
    {
        struct bufferProps* inputBuffer = inputThread();

        processBuffer = lineSeparatorThread(inputBuffer);

        if (strcmp(processBuffer->characters, "STOP") == 0)
        {
            endLoop = true;
        }
        else 
        {
            while(processBuffer->length > 80)
            {
                struct bufferProps* outputBuffer = plusSignsThread(processBuffer);

                outputThread(outputBuffer);
            }
        }
    }

    return 0;
}
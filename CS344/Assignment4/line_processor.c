#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_COUNT 50

/**
 * Struct to store input line props
 */
struct lineProps
{
    char* characters;
    ssize_t length;
};

// Define input buffer.
struct lineProps* inputBuffer[MAX_LINE_COUNT];
int inputBufferLength = 0;
int inputSetIndex = 0;
int inputGetIndex = 0;
// Initialize mutex for input buffer.
pthread_mutex_t inputMutex = PTHREAD_MUTEX_INITIALIZER;
// Initialize conditional variable for input buffer.
pthread_cond_t inputFull = PTHREAD_COND_INITIALIZER;

// Define process buffer.
struct lineProps* processBuffer[MAX_LINE_COUNT];
int processBufferLength = 0;
int processSetIndex = 0;
int processGetIndex = 0;
// Initialize mutex for process buffer.
pthread_mutex_t processMutex = PTHREAD_MUTEX_INITIALIZER;
// Initialize conditional variable for process buffer.
pthread_cond_t processFull = PTHREAD_COND_INITIALIZER;

// Define output buffer.
struct lineProps* outputBuffer[MAX_LINE_COUNT];
int outputBufferLength = 0;
int outputSetIndex = 0;
int outputGetIndex = 0;
// Initialize mutex for output buffer.
pthread_mutex_t outputMutex = PTHREAD_MUTEX_INITIALIZER;
// Initialize conditional variable for output buffer.
pthread_cond_t outputFull = PTHREAD_COND_INITIALIZER;

/**
 * Set input buffer.
 */
void setInputBuffer(struct lineProps* props)
{
    // lock mutex
    pthread_mutex_lock(&inputMutex);
    // set input buffer
    inputBuffer[inputSetIndex] = props;
    inputSetIndex += 1;
    inputBufferLength++;
    // signal buffer is full
    pthread_cond_signal(&inputFull);
    // unlock mutex
    pthread_mutex_unlock(&inputMutex);
}

/**
 * Get input buffer
 */
struct lineProps* getInputBuffer()
{
    // lock mutex before checking buffer
    pthread_mutex_lock(&inputMutex);
    while (inputBufferLength == 0)
        // Buffer is empty, wait.
        pthread_cond_wait(&inputFull, &inputMutex);

    struct lineProps* line = inputBuffer[inputGetIndex];
    inputGetIndex += 1;
    inputBufferLength--;
    // unlock mutex
    pthread_mutex_unlock(&inputMutex);

    return line;
}

/**
 * Set process buffer.
 */
void setProcessBuffer(struct lineProps* props)
{
    // lock mutex
    pthread_mutex_lock(&processMutex);
    // set process buffer
    processBuffer[processSetIndex] = props;
    processSetIndex += 1;
    processBufferLength++;
    // signal buffer is full
    pthread_cond_signal(&processFull);
    // unlock mutex
    pthread_mutex_unlock(&processMutex);
}

/**
 * Get process buffer
 */
struct lineProps* getProcessBuffer()
{
    // lock mutex before checking buffer
    pthread_mutex_lock(&processMutex);
    while (processBufferLength == 0)
        // Buffer is empty. wait.
        pthread_cond_wait(&processFull, &processMutex);

    struct lineProps* line = processBuffer[processGetIndex];
    processGetIndex += 1;
    processBufferLength--;
    // unlock mutex
    pthread_mutex_unlock(&processMutex);

    return line;
}

/**
 * Set output buffer.
 */
void setOutputBuffer(struct lineProps* props)
{
    // lock mutex
    pthread_mutex_lock(&outputMutex);
    // set output buffer
    outputBuffer[outputSetIndex] = props;
    outputSetIndex += 1;
    outputBufferLength++;
    // signal buffer is full
    pthread_cond_signal(&outputFull);
    // unlock mutex
    pthread_mutex_unlock(&outputMutex);
}

/**
 * Get output buffer
 */
struct lineProps* getOutputBuffer()
{
    // lock mutex before checking buffer
    pthread_mutex_lock(&outputMutex);
    while (outputBufferLength == 0)
        // Buffer is empty, wait.
        pthread_cond_wait(&outputFull, &outputMutex);

    struct lineProps* line = outputBuffer[outputGetIndex];
    outputGetIndex += 1;
    outputBufferLength--;
    pthread_mutex_unlock(&outputMutex);

    return line;
}

// bool to stop input
bool stopInput = false;

/**
 * InputThread
 * Takes a line of characters from standard input.
 * Stores line characters and length in the inputBuffer.
 */
void* inputThread()
{
    bool stopThread = false;

    while (!stopThread)
    {

        struct lineProps* inputProps = malloc(sizeof(struct lineProps));
        inputProps->characters = NULL;
        inputProps->length = 0;
        size_t bufferLength = 0;

        // Get new line from standard input.
        inputProps->length = getline(&inputProps->characters, &bufferLength, stdin);

        if (strcmp(inputProps->characters, "STOP\n") == 0)
        {
            stopThread = true;
        }

        setInputBuffer(inputProps);
    }

    return NULL;
}

/**
 * Line Separator
 * Replaces a new line character with a space.
 */
void* lineSeparatorThread()
{
    bool stopThread = false;
    const char* space = " ";

    while (!stopThread)
    {
        struct lineProps* line = getInputBuffer();
        line->characters[strcspn(line->characters, "\n")] = *space;

        if (strcmp(line->characters, "STOP ") == 0)
        {
            stopThread = true;
        }

        setProcessBuffer(line);
    }

    return NULL;
}

/**
 * Plus signs
 * Replaces '++' with '^'
 */
void* plusSignsThread()
{
    bool stopThread = false;
    char* line = malloc(1000 * sizeof(char));
    ssize_t lineLength = 0;

    while (!stopThread)
    {
        while (lineLength <= 80 && !stopThread)
        {
            struct lineProps* processProps = getProcessBuffer();

            if (strcmp(processProps->characters, "STOP ") == 0)
            {
                stopThread = true;
                setOutputBuffer(processProps);
            }
            
            strcat(line, processProps->characters);
            lineLength += processProps->length;
        }

        if (lineLength >= 80 && !stopThread)
        {
            struct lineProps* outputProps = malloc(sizeof(struct lineProps));
            outputProps->characters = malloc(81 * sizeof(char));
            outputProps->length = 0;

            int processIndex = 0;
            bool skip = false;

            while (outputProps->length < 80 && !stopThread)
            {
                int outputIndex = outputProps->length;
                // Skip if ...
                if (skip)
                {
                    processIndex++;
                    skip = false;
                }
                // Else if ++
                else if (line[processIndex] == '+' && line[processIndex + 1] == '+')
                {
                    outputProps->characters[outputIndex] = '^';
                    outputProps->length++;
                    processIndex++;
                    skip = true;
                }
                // Else add
                else
                {
                    outputProps->characters[outputIndex] = line[processIndex];
                    outputProps->length++;
                    processIndex++;
                }
            }
            
            line = &line[processIndex];
            lineLength = lineLength - 80;
            
            setOutputBuffer(outputProps);
        }
    }

    return NULL;
}

/**
 * Output
 * Prints processed data as a line of 80 characters.
 */
void* outputThread()
{
    bool stopThread = false;

    while (!stopThread)
    {
        struct lineProps* outputProps = getOutputBuffer();
        
        if (strcmp(outputProps->characters, "STOP ") == 0)
        {
            stopThread = true;
        }
        else
        {
            printf("%s\n", outputProps->characters);
        }
    }

    return NULL;
}

/**
 * Line processor
 * 
 */
int main()
{   
    pthread_t input_t, separator_t, plus_sign_t, output_t;
    // Create threads
    pthread_create(&input_t, NULL, inputThread, NULL);
    pthread_create(&separator_t, NULL, lineSeparatorThread, NULL);
    pthread_create(&plus_sign_t, NULL, plusSignsThread, NULL);
    pthread_create(&output_t, NULL, outputThread, NULL);  
    // Wait for threads to terminate
    pthread_join(input_t, NULL);
    pthread_join(separator_t, NULL);
    pthread_join(plus_sign_t, NULL);
    pthread_join(output_t, NULL);

    return 0;
}
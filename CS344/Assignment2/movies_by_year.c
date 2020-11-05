#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h> 

/**
 * struct for movie info
 */
struct movie
{
    char* title;
    char* year;
    char* languages;
    char* rating;
    struct movie* next;
};

/**
 * Parse the current line which is comma delimited
 * and create a movie struct with the data in this line.
 */
struct movie* createMovie(char* currentLine)
{
    struct movie *currentMovie = malloc(sizeof(struct movie));

    // For use with strtok_r
    char* saveptr;

    // The first token is the title
    char* token = strtok_r(currentLine, ",", &saveptr);
    currentMovie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currentMovie->title, token);

    // The next token is the year
    token = strtok_r(NULL, ",", &saveptr);
    currentMovie->year = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currentMovie->year, token);

    // The next token is the language
    token = strtok_r(NULL, ",", &saveptr);
    currentMovie->languages = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currentMovie->languages, token);

    // The next token is the rating
    token = strtok_r(NULL, ",", &saveptr);
    currentMovie->rating = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currentMovie->rating, token);

    currentMovie->next = NULL;

    return currentMovie;
}

/**
 * Return a linked list of movies by parsing
 * data from each line of the specified file.
 */
struct movie* readMovieFile(char* filePath)
{
    FILE* movieFile = fopen(filePath, "r");

    char* currentLine = NULL;
    size_t length = 0;
    ssize_t nread;
    char* token;

    // The head of the linked list
    struct movie* head = NULL;
    // The tail of the linked list
    struct movie* tail = NULL;

    // Read the file line by line
    while ((nread = getline(&currentLine, &length, movieFile)) != -1)
    {
        // Get a new movie node corresponding to the current line
        struct movie* newNode = createMovie(currentLine);

        // Is this the first node in the linked list?
        if (head == NULL)
        {
            // This is the first node in the linked list
            // Set the head and the tail to this node
            head = newNode;
            tail = newNode;
        }
        else
        {
            // This is not the first node.
            // Add this node to the list and advance the tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    free(currentLine);
    fclose(movieFile);
    return head;
}

/**
 * struct movies by year
 */
struct moviesByYear
{
    int year;
    struct movie* movies;
    struct movie* moviesTail;
    struct moviesByYear* next;
};

/**
 * Create a struct for tracking movies by year
 */
struct moviesByYear* createMoviesByYear(int year, struct movie* movies)
{
    struct moviesByYear* aYear = malloc(sizeof(struct moviesByYear));

    struct movie* aMovie = malloc(sizeof(struct movie));

    aMovie->title = movies->title;
    aMovie->year = movies->year;
    aMovie->languages = movies->languages;
    aMovie->rating = movies->rating;
    aMovie->next = NULL;

    aYear->year = year;
    aYear->movies = aMovie;
    aYear->moviesTail = aMovie;
    aYear->next = NULL; 

    return aYear;
}

/**
 * Calc movies per year.
 */
struct moviesByYear* getMoviesByYear(struct movie* movies)
{
    struct moviesByYear* yearsHead = NULL;
    struct moviesByYear* yearsTail = NULL;

    while (movies != NULL)
    {
        if (atoi(movies->year))
        {
            int yearToCheck = atoi(movies->year);

            printf("%s %s\n",movies->year, movies->title);

            if (yearsHead == NULL)
            {
                // create first year and add first movie.
                struct moviesByYear* newYear = createMoviesByYear(yearToCheck, movies);

                yearsHead = newYear;
                yearsTail = newYear;
            }
            else
            {

                bool goToNextMovie = false;

                while (yearsTail != NULL && !goToNextMovie)
                {
                    int yearInList = yearsTail->year;

                    if (yearInList == yearToCheck)
                    {
                        // add movie to existing year
                        struct movie* aMovie = malloc(sizeof(struct movie));
                        aMovie->title = movies->title;
                        aMovie->year = movies->year;
                        aMovie->languages = movies->languages;
                        aMovie->rating = movies->rating;
                        aMovie->next = NULL;

                        yearsTail->moviesTail->next = aMovie;
                        yearsTail->moviesTail = aMovie;

                        goToNextMovie = true;
                    }
                    else if (!yearsTail->next)
                    {
                        // create new year.
                        yearsTail->next = createMoviesByYear(yearToCheck, movies);
                        goToNextMovie = true;
                    }
                    
                    yearsTail = yearsTail->next;
                }
            }
        }

        if (movies->next != NULL)
        {
            yearsTail = yearsHead;
        }

        movies = movies->next;
    }

    return yearsHead;
}


/**
 * Print processing file.
 */
void printProcessingFile(char* fileName)
{
    printf("Now processing the chosen file named %s\n", fileName);
}

/**
 * Print created directory
 */
void printCreatedDirectory(char* dirName)
{
    printf("Created directory with name %s\n", dirName);
}

/**
 * Process file.
 */
void processFile(char* filePath)
{
    printProcessingFile(filePath);

    // create directory name prefix
    char dirPath[FILENAME_MAX];
    strcpy(dirPath, "moorepat.movies.");

    //create random number string.
    char randStr[20];
    int randNum = rand() % 100000;
    sprintf(randStr, "%d", randNum);

    strcat(dirPath, randStr);

    // make directory.
    mkdir(dirPath, 0750);

    struct movie* movies = readMovieFile(filePath);

    struct moviesByYear* years = getMoviesByYear(movies);

    while (years != NULL)
    {
        char filePath[FILENAME_MAX];
        strcpy(filePath, "./moorepat.movies.");
        strcat(filePath, randStr);
        strcat(filePath, "/");
        strcat(filePath, years->movies->year);
        strcat(filePath, ".txt");
        int file_descriptor = open(filePath, O_CREAT, 0640);

        FILE* stream = fopen(filePath, "w");
        
        while (years->movies != NULL)
        {
            fprintf(stream, "%s\n", years->movies->title);
            years->movies = years->movies->next;
        }

        fclose(stream);

        years = years->next;
    }

    printCreatedDirectory(dirPath);
}

/**
 * Get largest file.
 */
char* getLargest()
{
    char* prefix = "movies_";
    char* fileExt = ".csv";
    char* largestName = "";
    off_t largestSize = 0;

    // Open dir
    DIR* currentDirectory = opendir(".");
    struct dirent *aDir;
    struct stat dirStat;
    off_t fileSize;

    // Go through all the entries
    while((aDir = readdir(currentDirectory)) != NULL){
        stat(aDir->d_name, &dirStat);

        if (strstr(aDir->d_name, prefix) != NULL && strstr(aDir->d_name, fileExt) != NULL )
        {
            if (dirStat.st_size > largestSize)
            {
                largestSize = dirStat.st_size;
                largestName = aDir->d_name;
            }
        }
    }

    return largestName;
}

/**
 * Get smallest file.
 */
char* getSmallest()
{
    char* prefix = "movies_";
    char* fileExt = ".csv";
    char* smallestName = "";
    off_t smallestSize = 2147483647;

    // Open dir
    DIR* currentDirectory = opendir(".");
    struct dirent *aDir;
    struct stat dirStat;
    off_t fileSize;

    // Go through all the entries
    while((aDir = readdir(currentDirectory)) != NULL){
        stat(aDir->d_name, &dirStat);

        if (strstr(aDir->d_name, prefix) != NULL && strstr(aDir->d_name, fileExt) != NULL )
        {
            if (dirStat.st_size < smallestSize)
            {
                smallestSize = dirStat.st_size;
                smallestName = aDir->d_name;
            }
        }
    }

    return smallestName;
}

/**
 * Process largest file.
 */
void processLargestFile()
{
    // calc largest file
    char* fileName = getLargest();

    // process file.
    processFile(fileName);
}

/**
 * Process smallest file.
 */
void processSmallestFile()
{
    // calc largest file
    char* fileName = getSmallest();

    // process file.
    processFile(fileName);
}

/**
 * Process file by name.
 */
int processFileByName()
{
    // get file name;
    
    printf("\nEnter the complete file name: ");
    
    char filePath[FILENAME_MAX];
    scanf("%s", filePath);

    FILE* movieFile = fopen(filePath, "r");

    if (movieFile)
    {
        // process file.
        processFile(filePath);
    }
    else
    {
        printf("\nThe file %s was not found. Try again.\n", filePath);
        return false;
    }

    return true;
}

/**
 * Print file menu options
 */
void printFileMenu()
{
    printf("\nWhich file do you want to process?\n");
    printf("Enter 1 to pick the largest file\n");
    printf("Enter 2 to pick the smallest file\n");
    printf("Enter 3 to specify the name of a file\n");
}

/**
 * Prompt user for file menu selection.
 * Returns: integer coresponding to the selected menu option.
 */
int getFileMenuSelection()
{
    int selection;
    printf("\nEnter a choice from 1 to 3: ");
    scanf("%d", &selection);

    return selection;
}

/**
 * File menu
 */
void fileMenu()
{
    bool exitMenu = false;
    while (!exitMenu)
    {
        // Print menu
        printFileMenu();

        // Get main menu selection
        int selection = getFileMenuSelection();

        exitMenu = true;

        // Run code per selection.
        switch (selection)
        {
            case 1:
                processLargestFile();
                break;
            case 2:
                processSmallestFile();
                break;
            case 3:
                exitMenu = processFileByName();
                break;
            default:
                printf("\nYou entered an incorrect choice. Try again.\n");
                exitMenu = false;
        }
    }
}

/**
 * Print main menu options
 */
void printMainMenu()
{
    printf("\n1. Select file to process\n");
    printf("2. Exit the program\n");
}

/**
 * Prompt user for main menu selection.
 * Returns: integer coresponding to the selected menu option.
 */
int getMainMenuSelection()
{
    int selection;
    printf("\nEnter a choice 1 or 2: ");
    scanf("%d", &selection);

    return selection;
}

/**
 * Main menu.
 */
void mainMenu()
{
    bool exitMenu = false;
    while (!exitMenu)
    {
        // Print menu
        printMainMenu();

        // Get main menu selection
        int selection = getMainMenuSelection();

        // Run code per selection.
        switch (selection)
        {
            case 1:
                fileMenu();
                break;
            case 2:
                exitMenu = true;
                break;
            default:
                printf("\nYou entered an incorrect choice. Try again.\n");
        }
    }
}

/**
 * Main program functionality.
 */
int main()
{
    time_t t;

    srand((unsigned) time(&t));

    mainMenu();

    return 0;
}
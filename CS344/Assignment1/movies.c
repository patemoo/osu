#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
struct movie* processFile(char* filePath)
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

int getMoviesLength(struct movie* movies)
{
    int length = 0;

    while (movies != NULL)
    {
        length += 1;
        movies = movies->next;
    }

    return length - 1;
}

/**
 * struct for highest rated movie in each year
 */
struct yearRating
{
    int year;
    struct movie* highestRatedMovie;
    struct yearRating* next;
};

/**
 * Create a struct for tracking a year's highest rating
 */
struct yearRating* createYearRating(int year, struct movie* movie)
{
    struct yearRating* yearRating = malloc(sizeof(struct yearRating));

    yearRating->year = year;
    yearRating->highestRatedMovie = movie;
    yearRating->next = NULL; 

    return yearRating;
}

/**
 * Prints options menu
 */
void printMenu()
{
    printf("\n1. Show movies released in the specified year\n");
    printf("2. Show highest rate movie for each year\n");
    printf("3. Show the title and year of release of all movies in a specific language\n");
    printf("4. Exit from the program\n");
}

/**
 * Prompts user for menu selection.
 * Returns: Int representing menu selection.
 */
int getMenuSelection()
{
    int selection;
    printf("\nEnter a choice from 1 to 4: ");
    scanf("%d", &selection);

    return selection;
}

/**
 * Prompts the user for a year. Prints a list of movies from that year.
 */
void showMoviesByYear(struct movie* movies)
{
    char year[5];
    printf("\nEnter the year for which you want to see movies: ");
    scanf("%s", year);

    bool noDataFound = true;

    while (movies != NULL)
    {
        if (strcmp(movies->year, year) == 0)
        {
            noDataFound = false;
            printf("%s\n", movies->title);
        }
        movies = movies->next;
    }

    if (noDataFound)
    {
        printf("\nNo data about movies released in the year %s\n", year);
    }
}

/**
 * Calc highest rated movie per year.
 */
struct yearRating* getYearRatings(struct movie* movies)
{
    struct yearRating* yearsHead = NULL;
    struct yearRating* yearsTail = NULL;

    while (movies != NULL)
    {
        if (atoi(movies->year))
        {
            
            int movieYear = atoi(movies->year);

            if (yearsHead == NULL)
            {
                struct yearRating* newYear = createYearRating(movieYear, movies);

                yearsHead = newYear;
                yearsTail = newYear;
            }

            bool goToNextMovie = false;

            while(yearsTail != NULL && !goToNextMovie)
            {
                int ratingYear = yearsTail->year;

                if (ratingYear)
                {
                    if (ratingYear == movieYear)
                    {

                        char* endptr;
                        if (strtod(yearsTail->highestRatedMovie->rating, &endptr) < strtod(movies->rating, &endptr))
                        {
                            yearsTail->highestRatedMovie = movies;
                        }
                        goToNextMovie = true;
                    }
                    else if (!yearsTail->next)
                    {
                        yearsTail->next = createYearRating(movieYear, movies);
                    }
                }

                yearsTail = yearsTail->next;
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
 * show movies by rating
 */
void showMoviesByRating(struct movie* movies)
{

    struct yearRating* years = getYearRatings(movies);

    char* endptr;

    while (years != NULL)
    {
        printf("%s %.2f %s\n", years->highestRatedMovie->year, strtof(years->highestRatedMovie->rating, &endptr), years->highestRatedMovie->title);
        years = years->next;
    }
}

/**
 * Prompts user for a language. Prints movies available in that language.
 */
void showMoviesByLanguage(struct movie* movies)
{
  
    printf("\nEnter the language for which you want to see movies: ");

    char language[12];
    scanf("%s", language);
   
    bool noDataFound = true;

    while (movies != NULL)
    {        
        if (strstr(movies->languages, language) != NULL)
        {
            noDataFound = false;
            printf("%s %s\n", movies->year, movies->title);
        }
        movies = movies->next;
    }

    if (noDataFound)
    {
        printf("\nNo data about movies released in %s\n", language);
    }
}

/**
 * Main program functionality.
 */
int main(int argc, char *argv[])
{
    // Process csv file
    struct movie *movies = processFile(argv[1]);

    // Get movie list length
    int moviesLength = getMoviesLength(movies);

    // Print file name and movie count
    printf("\nProcessed file %s and parsed data for %d movies \n\n", argv[1], moviesLength);

    bool exitProgram = false;
    while (!exitProgram)
    {
        // Print menu 
        printMenu();

        // Get menu selection
        int selection = getMenuSelection();

        // Run function for menu selection.
        switch (selection)
        {
            case 1: 
                showMoviesByYear(movies);
                break;
            case 2:
                showMoviesByRating(movies);
                break;
            case 3:
                showMoviesByLanguage(movies);
                break;
            case 4:
                exitProgram = true;
                break;
            default: 
                printf("\nYou entered an incorrect choice. Try again.\n");
        }

    }
    
    return 0;
}

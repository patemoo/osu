#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// The allowed number of processes to run at one time.
#define POOL_SIZE       5

// Declare a semaphone
sem_t* enc_sem;

// semaphone count
int sem_count = POOL_SIZE;

/**
 * Get character
 * Takes value between 0 and 27
 * Return space character if value equals 27
 * For all other values, return capital ASCII character 
 * starting with 'A' which is ASCII 65
 */
char getCharacter(int value)
{
    char result;
    
    switch (value)
    {
        case 26:
            // The value for a ASCII space character is 32.
            result = 32;
            break;
        default:
            // Add value to 65 to get correct ASCII character.
            result = value + 65;
    }

    return result;
}

/**
 * 
 */
int getValue(char character)
{
    int result;

    switch ((int)character)
    {
        case 32:
            result = 26;
            break;
        default:
            result = (int)character - 65;
    }

    return result;
}

char* run_encrypt(char* text, char* key)
{
    int length = strlen(text);
    char* result = malloc(sizeof(length * sizeof(char)));

    for (int i = 0; i < length; i++)
    {
        int textVal;
        int keyVal;
        int sum;
        int mod;

        textVal = getValue(text[i]);
        keyVal = getValue(key[i]);

        sum = textVal + keyVal;
        mod = sum % 27;

        // printf("text: %d %c %d key: %d %c %d mod: %d %c\n", text[i], text[i], textVal, key[i], key[i], keyVal, mod, getCharacter(mod));

        result[i] = getCharacter(mod);
    }

    return result;
}

// char* run_decrypt(char* cipher, char* key)
// {
//     int length = strlen(cipher);
//     char* result = malloc(sizeof(length * sizeof(char)));

//     for (int i = 0; i < length; i++)
//     {
//         int cipherVal;
//         int keyVal;
//         int sub;
//         int mod;

//         cipherVal = getValue(cipher[i]);
//         keyVal = getValue(key[i]);

//         sub = cipherVal - keyVal;
//         if (sub < 0)
//         {
//             sub += 27;
//         }
//         mod = sub % 27;

//         printf("cipher: %d %c %d key: %d %c %d mod: %d %c\n", cipher[i], cipher[i], cipherVal, key[i], key[i], keyVal, mod, getCharacter(mod));

//         result[i] = getCharacter(mod);
//     }

//     return result;
// }

// Error function used for reporting issues
void error(const char *msg) {
  perror(msg);
  exit(1);
} 

// Set up the address struct for the server socket
void setupAddressStruct(struct sockaddr_in* address, 
                        int portNumber){
 
  // Clear out the address struct
  memset((char*) address, '\0', sizeof(*address)); 

  // The address should be network capable
  address->sin_family = AF_INET;
  // Store the port number
  address->sin_port = htons(portNumber);
  // Allow a client at any address to connect to this server
  address->sin_addr.s_addr = INADDR_ANY;
}

int main(int argc, char *argv[]){
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t sizeOfClientInfo = sizeof(clientAddress);

    // Check usage & args
    if (argc < 2) { 
        fprintf(stderr,"USAGE: %s port\n", argv[0]); 
        exit(1);
    }

    // Initialize the semaphore to POOL_SIZE
    enc_sem = sem_open("enc_sem", 0, POOL_SIZE);
  
    // Create the socket that will listen for connections
    int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket < 0) {
        error("ERROR opening socket");
    }

    // Set up the address struct for the server socket
    setupAddressStruct(&serverAddress, atoi(argv[1]));

    // Associate the socket to the port
    if (bind(listenSocket, 
          (struct sockaddr *)&serverAddress, 
          sizeof(serverAddress)) < 0){
        error("ERROR on binding");
    }

    // Start listening for connetions. Allow up to 5 connections to queue up
    listen(listenSocket, 5);

    // Create pocesses for socket connections
    for (int i = 0; i < POOL_SIZE; i++)
    {
        //Fork a new process to handle socket connection
        pid_t connectionPid = fork();

        int childStatus;
        int connectionSocket, charsRead;
    
        char* textBuffer;
        char* keyBuffer;
        char* cipherBuffer;

        char buffer[140000];

        switch(connectionPid)
        {
            case -1:
                // error
                perror("fork()\n");
                exit(1);
                break;
            case 0:
                // child process

                // Accept a connection, blocking if one is not available until one connects
                while(1)
                {
                    // wait for available resource allocation:
                    sem_wait(enc_sem);
                    // printf("Connection: pid: %d got resource\n", getpid());

                    // Accept the connection request which creates a connection socket
                    connectionSocket = accept(listenSocket, 
                            (struct sockaddr *)&clientAddress, 
                            &sizeOfClientInfo); 
                    if (connectionSocket < 0){
                        error("ERROR on accept");
                    }

                    // printf("SERVER: Connected to client running at host %d port %d\n", 
                    //         ntohs(clientAddress.sin_addr.s_addr),
                    //         ntohs(clientAddress.sin_port));

                    // Get the message from the client and display it
                    memset(buffer, '\0', 140000);
                    // Read the client's message from the socket
                    charsRead = recv(connectionSocket, buffer, 140000, 0);
                    if (charsRead < 0){
                        error("ERROR reading from socket");
                    }
                    // printf("SERVER: chars read: %d\n", charsRead);

                    // For use with strtok_r
                    char* saveptr;

                    // The first token is the client type
                    char* token = strtok_r(buffer, ",", &saveptr);
                    if (strcmp(token, "enc") != 0)
                    {
                        error("wrong client");
                    }

                    textBuffer = strtok_r(NULL, ",", &saveptr);
                    // printf("SERVER: text from client: \"%s\"\n", textBuffer);

                    keyBuffer = strtok_r(NULL, ",", &saveptr);
                    // printf("SERVER: key from client: \"%s\"\n", keyBuffer);

                    // do encrypt work here:
                    cipherBuffer = run_encrypt(textBuffer, keyBuffer);


                    // char* decBuffer = run_decrypt(cipherBuffer, keyBuffer);

        

                    // Send a Success message back to the client
                    charsRead = send(connectionSocket, 
                                    cipherBuffer, 70000, 0); 
                    if (charsRead < 0){
                        error("ERROR writing to socket");
                    }

                    // Close the connection socket for this client
                    close(connectionSocket);

                    // Release resource allocation:
                    sem_post(enc_sem);
                    // printf("Connection: pid: %d giving up resource\n", getpid());
                }

                exit(0);
                break;
            default:
                // parent process

                break;
        }
    }

    // Close the listening socket
    close(listenSocket); 

    return 0;
}

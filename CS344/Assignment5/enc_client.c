#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>  // ssize_t
#include <sys/socket.h> // send(),recv()
#include <netdb.h>      // gethostbyname()

// Error function used for reporting issues
void error(const char *msg) { 
    perror(msg); 
    exit(1); 
}

// Set up the address struct
void setupAddressStruct(struct sockaddr_in* address, 
                        int portNumber, 
                        char* hostname){
 
  // Clear out the address struct
  memset((char*) address, '\0', sizeof(*address)); 

  // The address should be network capable
  address->sin_family = AF_INET;
  // Store the port number
  address->sin_port = htons(portNumber);

  // Get the DNS entry for this host name
  struct hostent* hostInfo = gethostbyname(hostname); 
  if (hostInfo == NULL) { 
    fprintf(stderr, "CLIENT: ERROR, no such host\n"); 
    exit(0); 
  }
  // Copy the first IP address from the DNS entry to sin_addr.s_addr
  memcpy((char*) &address->sin_addr.s_addr, 
        hostInfo->h_addr_list[0],
        hostInfo->h_length);
}

/**
 * Encrypt Client
 * 1. Read input from plaintext and key argument paths
 * 2. Check for valid key length
 * 3. Check for bad characters within plaintext input
 * 4. Create a socket and connect to the server specified in the command arugments.
 * 5. Print the message received from the server and exit the program.
 */
int main(int argc, char *argv[]) {
    int socketFD, portNumber, charsWritten, charsRead;
    struct sockaddr_in serverAddress;
    
    // Define characters that should not be allowed in the plaintext input.
    char* badCharacters = "!@#$%^&*()-+=_";

    // Define variables to hold the plaintext and key file paths.
    FILE* plaintext,* key;

    // Create buffers used to read plaintext and key input
    // and to send data over the socket to the server
    char textBuffer[70000];
    char keyBuffer[70000];
    char socketBuffer[140000];
  
    // Check usage & args
    if (argc < 4) { 
        fprintf(stderr,"USAGE: %s plaintext key port\n", argv[0]); 
        exit(0); 
    }

    // Open files
    plaintext = fopen(argv[1], "r");
    if (plaintext == NULL)
    {
        // Throw error if file does not open.
        error("Error: opening plaintext file path");
    }

    key = fopen(argv[2], "r");
    if (key == NULL)
    {
        // Throw error if file does not open.
        error("Error: opeing key file path");
    }

    // Clear out buffer arrays
    memset(textBuffer, '\0', sizeof(textBuffer));
    memset(keyBuffer, '\0', sizeof(keyBuffer));

    // Get file input
    fgets(textBuffer, sizeof(textBuffer), plaintext);
    fgets(keyBuffer, sizeof(keyBuffer), key);

    // Remove the trailing \n
    textBuffer[strcspn(textBuffer, "\n")] = '\0';
    keyBuffer[strcspn(keyBuffer, "\n")] = '\0';

    // Check value compared to key length
    if (strlen(textBuffer) > strlen(keyBuffer))
    {
        // Throw error if the key length is less than the plaintext length
        error("Error: key is too short.");
    }

    // Check for bad characters within the plaintext input
    // For each bad character loop through the characters of the plaintext
    // if a bad character is found throw an error.
    for (int i = 0; i < strlen(badCharacters); i++)
    {
        for (int j = 0; j < strlen(textBuffer); j++)
        {
            if (badCharacters[i] == textBuffer[j])
            {
                error("error: input contains bad characters");
            }
        }
    }

    // Construct the socketBuffer string:
    // Pass a comma separated string using the following pattern:
    // First token is the client type.
    // Second token is the plaintext input.
    // Third toekn is the key input.
    strcat(socketBuffer, "enc,");
    strcat(socketBuffer, textBuffer);
    strcat(socketBuffer, ",");
    strcat(socketBuffer, keyBuffer);

    // Create a socket
    socketFD = socket(AF_INET, SOCK_STREAM, 0); 
    if (socketFD < 0){
        error("CLIENT: ERROR opening socket");
    }

    // Set up the server address struct
    setupAddressStruct(&serverAddress, atoi(argv[3]), "localhost");

    // Connect to server
    if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        error("CLIENT: ERROR connecting");
    }

    // Send message to server
    // Write to the server
    charsWritten = send(socketFD, socketBuffer, sizeof(socketBuffer), 0); 
    if (charsWritten < 0){
        error("CLIENT: ERROR writing to socket");
    }
    if (charsWritten < strlen(socketBuffer)){
        printf("CLIENT: WARNING: Not all data written to socket!\n");
    }

    // Get return message from server
    // Clear out the buffer again for reuse
    memset(textBuffer, '\0', sizeof(textBuffer));
    // Read data from the socket, leaving \0 at end
    charsRead = recv(socketFD, textBuffer, sizeof(textBuffer) - 1, 0); 
    if (charsRead < 0){
        error("CLIENT: ERROR reading from socket");
    }
    printf("%s\n", textBuffer);

    // Close the socket
    close(socketFD); 

    // Close files
    fclose(plaintext);
    fclose(key);
    
    return 0;
}
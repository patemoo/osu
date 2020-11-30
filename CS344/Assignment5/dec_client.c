#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>  // ssize_t
#include <sys/socket.h> // send(),recv()
#include <netdb.h>      // gethostbyname()


// todo: update program comments
/**
* Client code
* 1. Create a socket and connect to the server specified in the command arugments.
* 2. Prompt the user for input and send that input as a message to the server.
* 3. Print the message received from the server and exit the program.
*/

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

int main(int argc, char *argv[]) {
    int socketFD, portNumber, charsWritten, charsRead;
    struct sockaddr_in serverAddress;

    FILE* ciphertext,* key;

    char cipherBuffer[70000];
    char keyBuffer[70000];
    char socketBuffer[140000];
  
    // Check usage & args
    if (argc < 4) { 
        fprintf(stderr,"USAGE: %s cipher key port\n", argv[0]); 
        exit(0); 
    }

    // Open files
    ciphertext = fopen(argv[1], "r");
    if (ciphertext == NULL)
    {
        // error
    }

    key = fopen(argv[2], "r");
    if (key == NULL)
    {
        // error
    }

    // Clear out buffer arrays
    memset(cipherBuffer, '\0', sizeof(cipherBuffer));
    memset(keyBuffer, '\0', sizeof(keyBuffer));

    // Get file input
    fgets(cipherBuffer, sizeof(cipherBuffer), ciphertext);
    fgets(keyBuffer, sizeof(keyBuffer), key);

    // Remove the trailing \n
    cipherBuffer[strcspn(cipherBuffer, "\n")] = '\0';
    keyBuffer[strcspn(keyBuffer, "\n")] = '\0';

    // check value and key length
    if (strlen(cipherBuffer) > strlen(keyBuffer))
    {
        error("Error: key is too short.");
    }

    // construct socketBuffer:
    strcat(socketBuffer, "dec,");
    strcat(socketBuffer, cipherBuffer);
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
    memset(cipherBuffer, '\0', sizeof(cipherBuffer));
    // Read data from the socket, leaving \0 at end
    charsRead = recv(socketFD, cipherBuffer, sizeof(cipherBuffer) - 1, 0); 
    if (charsRead < 0){
        error("CLIENT: ERROR reading from socket");
    }
    printf("%s\n", cipherBuffer);

    // Close the socket
    close(socketFD); 

    // Close files
    fclose(ciphertext);
    fclose(key);
    
    return 0;
}
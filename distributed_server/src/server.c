#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <gpio.h>


#include "server.h"
#include "state.h"
#include "control.h"

void *run_server(void *state) {
    int serverSocket;
    struct sockaddr_in serverAddr;
    unsigned short serverPort;
    
    serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 10);

    printf("Listening at %d...\n", PORT);

    while (1) {
        handle_request(serverSocket, (struct HouseState *)state);
    }
    close(serverSocket);
    return NULL;
}

void handle_request(int serverSocket, struct HouseState *state) {
    int clientSocket;
    struct sockaddr_in clientAddr;
    unsigned int clientLen;


    clientLen = sizeof(clientAddr);
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientLen);
    char buff[5];
    int receivedLen;

    receivedLen = recv(clientSocket, buff, 5, 0);


    while (receivedLen > 0) {
        const char *response = process_command(buff[0], state);
        if (response != NULL) {
            send(clientSocket, response, strlen(response), 0);
        }
        receivedLen = recv(clientSocket, buff, 4, 0);
        free((void *)response);
    }
    close(clientSocket);
}

void *send_message() {
    return NULL;
}
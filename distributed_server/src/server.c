#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


#include "server.h"
#include "state.h"

#include <json-c/json.h>
#include <json-c/json_types.h>

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
    printf("%d\n", clientSocket);
    char buff[16];
    int receivedLen;

    receivedLen = recv(clientSocket, buff, 16, 0);

    while (receivedLen > 0) {
        const char *json_state = send_state(state);
        printf("%s %lu\n", json_state, strlen(json_state));
        send(clientSocket, json_state, strlen(json_state), 0);
        printf("%s\n", buff);
        memset(buff, 0, 16);
        receivedLen = recv(clientSocket, buff, 16, 0);
    }
    close(clientSocket);
}
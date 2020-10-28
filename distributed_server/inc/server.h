#ifndef SERVER_H
#define SERVER_H

#include "state.h"
#define PORT 10103

#define TOGGLE_LAMP01 1
#define TOGGLE_LAMP02 2
#define TOGGLE_LAMP03 3
#define TOGGLE_LAMP04 4
#define SEND_STATE 20

void *run_server();
void handle_request(int serverSocket, struct HouseState *state);

#endif
#ifndef SERVER_H
#define SERVER_H

#include "state.h"
#define PORT 10103

void *run_server();
void handle_request(int serverSocket, struct HouseState *state);

#endif
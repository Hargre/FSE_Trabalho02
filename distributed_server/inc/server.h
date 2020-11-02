#ifndef SERVER_H
#define SERVER_H

#include "state.h"
#define PORT 10103
#define CENTRAL_SERVER_HOST "192.168.0.53"
#define CENTRAL_SERVER_PORT 10003

void *run_server();
void handle_request(int serverSocket, struct HouseState *state);
void *send_alarm();

#endif
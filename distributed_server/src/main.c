#include "gpio.h"
#include "server.h"
#include "state.h"
#include "control.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void cleanup() {
    close_gpio();
}

void handle_sigint(int signum) {
    cleanup();
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    pthread_t server_thread;

    setup_gpio();
    struct HouseState state = init_state();
    printf("%s\n", state_to_string(&state));

    pthread_create(&server_thread, NULL, run_server, (void *)&state);
    start_polling(&state);
    int a = pthread_join(server_thread, NULL);
    return 0;
}

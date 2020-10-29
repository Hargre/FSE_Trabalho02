#include "gpio.h"
#include "server.h"
#include "state.h"
#include <stdio.h>
#include <pthread.h>

int main() {
    pthread_t server_thread;

    setup_gpio();
    struct HouseState state = init_state();
    printf("%s\n", state_to_string(&state));

    pthread_create(&server_thread, NULL, run_server, (void *)&state);
    int a = pthread_join(server_thread, NULL);
    return 0;
}

#include "control.h"
#include "gpio.h"
#include "state.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int commands_table[7] = {NULL, LAMP01, LAMP02, LAMP03, LAMP04, AIR01, AIR02};

void process_command(int command) {
    if (command <= TOGGLE_COMMANDS) {
        toggle_device(commands_table[command]);
    } else if (command == SEND_STATE) {
        //
    }
}

void start_polling(struct HouseState *state) {
    pthread_t presence_polling;
    pthread_t open_sensors_polling;

    pthread_create(&presence_polling, NULL, poll_presence_sensors, (void *)state);
    pthread_create(&open_sensors_polling, NULL, poll_open_sensors, (void *)state);
}

void *poll_presence_sensors(void *state) {
    while (1) {
        get_presence_sensors_state((struct HouseState *)state);
        usleep(100000);
    }
    return NULL;
}

void *poll_open_sensors(void *state) {
    while (1) {
        get_open_sensors_state((struct HouseState *)state);
        usleep(100000);
    }
    return NULL;
}
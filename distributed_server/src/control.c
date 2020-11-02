#include "control.h"
#include "server.h"
#include "gpio.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int commands_table[7] = {(int)NULL, LAMP01, LAMP02, LAMP03, LAMP04, AIR01, AIR02};

char* process_command(int command, struct HouseState *state) {
    if (command <= TOGGLE_COMMANDS) {
        toggle_device(commands_table[command]);
        get_air_lamps_state(state);
    } else if (command == TEMP_CONTROL_ON) {
        set_device(AIR01);
        set_device(AIR02);
        get_air_lamps_state(state);
    } else if (command == TEMP_CONTROL_OFF) {
        unset_device(AIR01);
        unset_device(AIR02);
        get_air_lamps_state(state);
    } else if (command == SEND_STATE) {
        return state_to_string(state);
    }
    return NULL;
}

void start_polling(struct HouseState *state) {
    pthread_t presence_polling;
    pthread_t open_sensors_polling;
    pthread_t climate_readings_loop;

    climate_readings_flag = 0;
    signal(SIGALRM, climate_readings_trigger);
    pthread_mutex_init(&climate_readings_mutex, NULL);
    pthread_cond_init(&climate_readings_cond, NULL);

    pthread_create(&presence_polling, NULL, poll_presence_sensors, (void *)state);
    pthread_create(&open_sensors_polling, NULL, poll_open_sensors, (void *)state);
    pthread_create(&climate_readings_loop, NULL, climate_readings, (void *)state);

    alarm(1);
}

void *poll_presence_sensors(void *state) {
    while (1) {
        int alarm_trigger = get_presence_sensors_state((struct HouseState *)state);
        if (alarm_trigger) {
            pthread_t alarm_message;
            pthread_create(&alarm_message, NULL, send_alarm, NULL);
        }
        usleep(100000); 
    }
    return NULL;
}

void *poll_open_sensors(void *state) {
    while (1) {
        int alarm_trigger = get_open_sensors_state((struct HouseState *)state);
        if (alarm_trigger) {
            pthread_t alarm_message;
            pthread_create(&alarm_message, NULL, send_alarm, NULL);
        }
        usleep(100000);
    }
    return NULL;
}

void climate_readings_trigger(int sigalarm) {
    pthread_mutex_lock(&climate_readings_mutex);
    climate_readings_flag = 1;
    pthread_cond_signal(&climate_readings_cond);
    pthread_mutex_unlock(&climate_readings_mutex);
    alarm(1);
}

void *climate_readings(void *state) {
    while (1) {
        pthread_mutex_lock(&climate_readings_mutex);
        while (!climate_readings_flag) {
            pthread_cond_wait(&climate_readings_cond, &climate_readings_mutex);
        }
        pthread_mutex_unlock(&climate_readings_mutex);
        get_climate_state(state);

        pthread_mutex_lock(&climate_readings_mutex);
        climate_readings_flag = 0;
        pthread_mutex_unlock(&climate_readings_mutex);
    }
    return NULL;
}

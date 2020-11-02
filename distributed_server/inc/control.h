#ifndef CONTROL_H
#define CONTROL_H

#include <pthread.h>
#include "state.h"

#define TOGGLE_COMMANDS 6

#define TEMP_CONTROL_ON 10
#define TEMP_CONTROL_OFF 11
#define SEND_STATE 20

pthread_mutex_t climate_readings_mutex;
pthread_cond_t climate_readings_cond;
int climate_readings_flag;

const char *process_command(int command, struct HouseState *state);
void start_polling(struct HouseState *state);
void *poll_presence_sensors(void *state);
void *poll_open_sensors(void *state);
void climate_readings_trigger(int sigalarm);
void *climate_readings(void *state);

#endif
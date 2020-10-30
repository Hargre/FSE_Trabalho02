#ifndef CONTROL_H
#define CONTROL_H

#include "state.h"

#define TOGGLE_COMMANDS 6

#define TOGGLE_LAMP01 1
#define TOGGLE_LAMP02 2
#define TOGGLE_LAMP03 3
#define TOGGLE_LAMP04 4
#define SEND_STATE 20

const char *process_command(int command, struct HouseState *state);
void start_polling(struct HouseState *state);
void *poll_presence_sensors(void *state);
void *poll_open_sensors(void *state);

#endif
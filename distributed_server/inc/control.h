#ifndef CONTROL_H
#define CONTROL_H

#define TOGGLE_COMMANDS 6

#define TOGGLE_LAMP01 1
#define TOGGLE_LAMP02 2
#define TOGGLE_LAMP03 3
#define TOGGLE_LAMP04 4
#define SEND_STATE 20

void process_command(int command);

#endif
#include "control.h"
#include "gpio.h"
#include <stdlib.h>

int commands_table[7] = {NULL, LAMP01, LAMP02, LAMP03, LAMP04, AIR01, AIR02};

void process_command(int command) {
    if (command <= TOGGLE_COMMANDS) {
        toggle_device(commands_table[command]);
    }
}
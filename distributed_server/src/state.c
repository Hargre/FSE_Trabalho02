
#include "state.h"
#include "gpio.h"
#include "climate.h"
#include <stdlib.h>
#include <stdio.h>

struct HouseState init_state() {
    struct HouseState state;
    get_sensor_data(&(state.temperature), &(state.humidity));
    state.lamp01 = read_device(LAMP01);
    state.lamp02 = read_device(LAMP02);
    state.lamp03 = read_device(LAMP03);
    state.lamp04 = read_device(LAMP04);
    state.air01 = read_device(AIR01);
    state.air02 = read_device(AIR02);
    state.presence01 = read_device(PRESENCE01);
    state.presence02 = read_device(PRESENCE02);
    state.open01 = read_device(OPEN01);
    state.open02 = read_device(OPEN02);
    state.open03 = read_device(OPEN03);
    state.open04 = read_device(OPEN04);
    state.open05 = read_device(OPEN05);
    state.open06 = read_device(OPEN06);

    return state;
}

const char *state_to_string(struct HouseState *state) {

    char *message = malloc(68 * sizeof(char));
    sprintf(
        message,
        "%.2f, %.2f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
        state->temperature, state->humidity,
        state->lamp01, state->lamp02, state->lamp03, state->lamp04,
        state->air01, state->air02,
        state->presence01, state->presence02,
        state->open01, state->open02, state->open03, state->open04, state->open05, state->open06
    );

    return message;
}
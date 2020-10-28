
#include "state.h"
#include "gpio.h"
#include <stdlib.h>
#include <stdio.h>

struct HouseState init_state() {
    struct HouseState state;
    state.temperature = 23.0;
    state.humidity = 81.0;
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

const char *send_state(struct HouseState *state) {

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

    // json_object *state_json = json_object_new_object();
    // json_object *temp = json_object_new_double(state->temperature);
    // json_object *humidity = json_object_new_double(state->humidity);
    // json_object *lamp01 = json_object_new_int(state->lamp01);
    // json_object *lamp02 = json_object_new_int(state->lamp02);
    // json_object *lamp03 = json_object_new_int(state->lamp03);
    // json_object *lamp04 = json_object_new_int(state->lamp04);
    // json_object *presence01 = json_object_new_int(state->presence01);
    // json_object *presence02 = json_object_new_int(state->presence02);
    // json_object *open01 = json_object_new_int(state->open01);
    // json_object *open02 = json_object_new_int(state->open02);
    // json_object *open03 = json_object_new_int(state->open03);
    // json_object *open04 = json_object_new_int(state->open04);
    // json_object *open05 = json_object_new_int(state->open05);
    // json_object *open06 = json_object_new_int(state->open06);

    // json_object_object_add(state_json, "temperature", temp);
    // json_object_object_add(state_json, "humidity", humidity);
    // json_object_object_add(state_json, "lamp01", lamp01);
    // json_object_object_add(state_json, "lamp02", lamp02);
    // json_object_object_add(state_json, "lamp03", lamp03);
    // json_object_object_add(state_json, "lamp04", lamp04);
    // json_object_object_add(state_json, "presence01", presence01);
    // json_object_object_add(state_json, "presence02", presence02);
    // json_object_object_add(state_json, "open01", open01);
    // json_object_object_add(state_json, "open02", open02);
    // json_object_object_add(state_json, "open03", open03);
    // json_object_object_add(state_json, "open04", open04);
    // json_object_object_add(state_json, "open05", open05);
    // json_object_object_add(state_json, "open06", open06);

    return message;
}
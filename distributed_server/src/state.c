
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
    init_guarded_device_state(&(state.presence01), PRESENCE01);
    init_guarded_device_state(&(state.presence02), PRESENCE02);
    init_guarded_device_state(&(state.open01), OPEN01);
    init_guarded_device_state(&(state.open02), OPEN02);
    init_guarded_device_state(&(state.open03), OPEN03);
    init_guarded_device_state(&(state.open04), OPEN04);
    init_guarded_device_state(&(state.open05), OPEN05);
    init_guarded_device_state(&(state.open06), OPEN06);

    return state;
}


void get_air_lamps_state(struct HouseState *state) {
    state->lamp01 = read_device(LAMP01);
    state->lamp02 = read_device(LAMP02);
    state->lamp03 = read_device(LAMP03);
    state->lamp04 = read_device(LAMP04);
    state->air01 = read_device(AIR01);
    state->air02 = read_device(AIR02);
}

void get_climate_state(struct HouseState *state) {
    get_sensor_data(&(state->temperature), &(state->humidity));
}

void init_guarded_device_state(GuardedDevice *device, int device_flag) {
    device->alarm_activated = 0;
    device->state = read_device(device_flag);
}

int get_guarded_device_state(GuardedDevice *device, int device_flag) {
    device->state = read_device(device_flag);
    if (device->state && !device->alarm_activated) {
        device->alarm_activated = 1;
        return 1;
    } else if (!device->state && device->alarm_activated) {
        device->alarm_activated = 0;
    }
    return 0;
}

int get_presence_sensors_state(struct HouseState *state) {
    int trigger_alarm = 0;
    trigger_alarm = trigger_alarm || get_guarded_device_state(&(state->presence01), PRESENCE01);
    trigger_alarm = trigger_alarm || get_guarded_device_state(&(state->presence02), PRESENCE02);

    return trigger_alarm;
}

int get_open_sensors_state(struct HouseState *state) {
    int trigger_alarm = 0;
    trigger_alarm = trigger_alarm || get_guarded_device_state(&(state->open01), OPEN01);
    trigger_alarm = trigger_alarm || get_guarded_device_state(&(state->open02), OPEN02);
    trigger_alarm = trigger_alarm || get_guarded_device_state(&(state->open03), OPEN03);
    trigger_alarm = trigger_alarm || get_guarded_device_state(&(state->open04), OPEN04);
    trigger_alarm = trigger_alarm || get_guarded_device_state(&(state->open05), OPEN05);
    trigger_alarm = trigger_alarm || get_guarded_device_state(&(state->open06), OPEN06);

    return trigger_alarm;
}

char *state_to_string(struct HouseState *state) {

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
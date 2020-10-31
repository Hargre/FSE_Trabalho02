#ifndef STATE_H
#define STATE_H

struct HouseState {
    float temperature;
    float humidity;
    unsigned char lamp01;
    unsigned char lamp02;
    unsigned char lamp03;
    unsigned char lamp04;
    unsigned char air01;
    unsigned char air02;
    unsigned char presence01;
    unsigned char presence02;
    unsigned char open01;
    unsigned char open02;
    unsigned char open03;
    unsigned char open04;
    unsigned char open05;
    unsigned char open06;
};

struct HouseState init_state();

int get_presence_sensors_state(struct HouseState *state);
int get_open_sensors_state(struct HouseState *state);
void get_climate_state(struct HouseState *state);

const char *state_to_string(struct HouseState *state);

#endif
#ifndef STATE_H
#define STATE_H

typedef struct {
    unsigned char state;
    unsigned char alarm_activated;
} GuardedDevice;

struct HouseState {
    float temperature;
    float humidity;
    unsigned char lamp01;
    unsigned char lamp02;
    unsigned char lamp03;
    unsigned char lamp04;
    unsigned char air01;
    unsigned char air02;
    GuardedDevice presence01;
    GuardedDevice presence02;
    GuardedDevice open01;
    GuardedDevice open02;
    GuardedDevice open03;
    GuardedDevice open04;
    GuardedDevice open05;
    GuardedDevice open06;
};

struct HouseState init_state();

int get_presence_sensors_state(struct HouseState *state);
int get_open_sensors_state(struct HouseState *state);
void get_climate_state(struct HouseState *state);
void get_air_lamps_state(struct HouseState *state);
void init_guarded_device_state(GuardedDevice *device, int device_flag);
int get_guarded_device_state(GuardedDevice *device, int device_flag);

char *state_to_string(struct HouseState *state);

#endif
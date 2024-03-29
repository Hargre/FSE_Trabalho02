#include <stdio.h>
#include <bcm2835.h>

#include "gpio.h"


int out_devices[6] = {LAMP01, LAMP02, LAMP03, LAMP04, AIR01, AIR02};
int in_devices[8] = {PRESENCE01, PRESENCE02, OPEN01, OPEN02, OPEN03, OPEN04, OPEN05, OPEN06};

void init_in_devices() {
    for (int i = 0; i < 8; i++) {
        bcm2835_gpio_fsel(in_devices[i], BCM2835_GPIO_FSEL_INPT);
    }
}

void init_out_devices() {
    for (int i = 0; i < 6; i++) {
        bcm2835_gpio_fsel(out_devices[i], BCM2835_GPIO_FSEL_OUTP);
    }
}

void setup_gpio() {
    bcm2835_init();
    init_in_devices();
    init_out_devices();
}

void close_gpio() {
    for (int i = 0; i < 6; i++) {
        unset_device(out_devices[i]);
    }
    bcm2835_close();
}

int read_device(int device) {
    return bcm2835_gpio_lev(device);
}

void toggle_device(int device) {
    int current = read_device(device);
    bcm2835_gpio_write(device, !current);
}

void set_device(int device) {
    bcm2835_gpio_write(device, HIGH);
}

void unset_device(int device) {
    bcm2835_gpio_write(device, LOW);
}
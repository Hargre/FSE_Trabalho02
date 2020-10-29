#ifndef GPIOC_H
#define GPIOC_H

#define LAMP01 17
#define LAMP02 18
#define LAMP03 27
#define LAMP04 22
#define AIR01 23
#define AIR02 24
#define PRESENCE01 25
#define PRESENCE02 26
#define OPEN01 5
#define OPEN02 6
#define OPEN03 12
#define OPEN04 16
#define OPEN05 20
#define OPEN06 21

void init_in_devices();
void init_out_devices();
void setup_gpio();
int read_device(int device);
void toggle_device(int device);

#endif
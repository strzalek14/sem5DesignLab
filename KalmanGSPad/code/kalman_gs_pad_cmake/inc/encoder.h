#ifndef ENCODER_H
#define ENCODER_H
#include <stdint.h>

int encoder_init(void);

int16_t  encoder_take_delta(void);

uint16_t encoder_button_bits(void);

#endif
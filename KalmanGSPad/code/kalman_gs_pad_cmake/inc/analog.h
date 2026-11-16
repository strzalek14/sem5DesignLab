#ifndef ANALOG_H
#define ANALOG_H
#include <stdint.h>

typedef enum {
    AN_G1_X,    /* rank 1: GIMBAL_1_X, ADC1_IN0,  PA0 */
    AN_G1_Y,    /* rank 2: GIMBAL_1_Y, ADC1_IN1,  PA1 */
    AN_G2_X,    /* rank 3: GIMBAL_2_X, ADC1_IN6,  PB0 */
    AN_G2_Y,    /* rank 4: GIMBAL_2_Y, ADC1_IN7,  PB1 */
    AN_POT0,    /* rank 5: POT_0,      ADC1_IN8,  PC0 */
    AN_POT1,    /* rank 6: POT_1,      ADC1_IN9,  PC1 */
    AN_POT2,    /* rank 7: POT_2,      ADC1_IN10, PC2 */
    AN_COUNT    /* = 7 */
} analog_ch_t;

void analog_read_all(uint16_t raw[AN_COUNT]);
int analog_init(void);

#endif
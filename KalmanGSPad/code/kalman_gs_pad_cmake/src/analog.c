#include "analog.h"
#include "generated/hal/mx_adc1.h"
#include "stm32c5xx_hal_adc.h"



static volatile uint32_t adc_buffer[AN_COUNT];

int analog_init(void){

    hal_adc_handle_t *gnp_handle = mx_adc1_init();
    if (gnp_handle == NULL){
        return -1;
    }

    HAL_ADC_Calibrate(gnp_handle);
    HAL_ADC_Start(gnp_handle);
    
    HAL_ADC_REG_StartConv_DMA(gnp_handle, (void *)adc_buffer, sizeof(adc_buffer));

    HAL_Delay(2);

    return 0;
}

void analog_read_all(uint16_t raw[AN_COUNT]){
    
    static uint32_t filtered[AN_COUNT] = {0};
    static uint8_t initialized = 0;

    if (!initialized)
    {
        for (int i = 0; i < AN_COUNT; i++)
        {
            filtered[i] = (adc_buffer[i] & 0x0FFFU) << 4;
        }
        initialized = 1;
    }

    for (int i = 0; i < AN_COUNT; i++)
    {
        uint32_t sample = (adc_buffer[i] & 0x0FFFU);
        filtered[i] = ((filtered[i] * 15U) + (sample << 4)) >> 4;
        raw[i] = (uint16_t)(filtered[i] >> 4);
    }
}

#include "encoder.h"
#include "mx_tim1.h"

static hal_tim_handle_t *htim;

int encoder_init(void)
{
  htim = mx_tim1_init();     /* skip this line if mx_system_init() already calls mx_tim1_init() */
  if (htim == NULL) { return -1; }

  if (HAL_TIM_IC_StartChannel(htim, HAL_TIM_CHANNEL_1) != HAL_OK) { return -2; }
  if (HAL_TIM_IC_StartChannel(htim, HAL_TIM_CHANNEL_2) != HAL_OK) { return -3; }
  if (HAL_TIM_Start(htim) != HAL_OK)                              { return -4; }
  return 0;
}

static uint16_t read_counter(void)
{
  return (uint16_t)HAL_TIM_GetCounter(htim);
}
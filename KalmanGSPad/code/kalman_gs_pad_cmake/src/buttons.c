#include "buttons.h"
#include "mx_gpio_default.h"
#include "stm32c5xx_hal_gpio.h"

static uint16_t read_buttons_raw(void)
{
  uint16_t b = 0; //checks if a button is pushed, if it is, puts 1 in correct place in base 2
  if (HAL_GPIO_ReadPin(BUTTON_0_PORT, BUTTON_0_PIN) == HAL_GPIO_PIN_RESET) b |= 1u << 0;  /* button_0 */
  if (HAL_GPIO_ReadPin(BUTTON_1_PORT, BUTTON_1_PIN) == HAL_GPIO_PIN_RESET) b |= 1u << 1;  /* button_1 */
  if (HAL_GPIO_ReadPin(BUTTON_2_PORT, BUTTON_2_PIN) == HAL_GPIO_PIN_RESET) b |= 1u << 2;  /* button_2 */
  if (HAL_GPIO_ReadPin(BUTTON_3_PORT, BUTTON_3_PIN) == HAL_GPIO_PIN_RESET) b |= 1u << 3;  /* button_3 */
  if (HAL_GPIO_ReadPin(BUTTON_4_PORT, BUTTON_4_PIN)  == HAL_GPIO_PIN_RESET) b |= 1u << 4;  /* button_4 */
  if (HAL_GPIO_ReadPin(BUTTON_5_PORT, BUTTON_5_PIN)  == HAL_GPIO_PIN_RESET) b |= 1u << 5;  /* button_5 */
  if (HAL_GPIO_ReadPin(BUTTON_6_PORT, BUTTON_6_PIN)  == HAL_GPIO_PIN_RESET) b |= 1u << 6;  /* button_6 */
  if (HAL_GPIO_ReadPin(BUTTON_7_PORT, BUTTON_7_PIN)  == HAL_GPIO_PIN_RESET) b |= 1u << 7;  /* button_7 */
  if (HAL_GPIO_ReadPin(INC_BUTTON_PORT, INC_BUTTON_PORT) == HAL_GPIO_PIN_RESET) b |= 1u << 10;
  return b; //eg button 3 pushed (button 4 in joy.cpl) == 1000
}

uint16_t buttons_debounced(void)
{
  static uint16_t candidate, stable, count; //static remembers 

  uint16_t raw = read_buttons_raw();
  if (raw != candidate){ 
    candidate = raw; count = 0; 
  }else if(count < 3){ 
    count++; 
  }else{
    stable = candidate; 
  }

  return stable;
}
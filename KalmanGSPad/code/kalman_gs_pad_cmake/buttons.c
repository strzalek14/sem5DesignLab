#include "buttons.h"
#include "stm32_hal.h"

uint8_t read_buttons_raw(void)
{
  uint8_t b = 0; //checks if a button is pushed, if it is, puts 1 in correct place in base 2
  if (HAL_GPIO_ReadPin(HAL_GPIOB, HAL_GPIO_PIN_12) == HAL_GPIO_PIN_RESET) b |= 1u << 0;  /* button_0 */
  if (HAL_GPIO_ReadPin(HAL_GPIOB, HAL_GPIO_PIN_13) == HAL_GPIO_PIN_RESET) b |= 1u << 1;  /* button_1 */
  if (HAL_GPIO_ReadPin(HAL_GPIOB, HAL_GPIO_PIN_14) == HAL_GPIO_PIN_RESET) b |= 1u << 2;  /* button_2 */
  if (HAL_GPIO_ReadPin(HAL_GPIOB, HAL_GPIO_PIN_15) == HAL_GPIO_PIN_RESET) b |= 1u << 3;  /* button_3 */
  if (HAL_GPIO_ReadPin(HAL_GPIOC, HAL_GPIO_PIN_6)  == HAL_GPIO_PIN_RESET) b |= 1u << 4;  /* button_4 */
  if (HAL_GPIO_ReadPin(HAL_GPIOC, HAL_GPIO_PIN_7)  == HAL_GPIO_PIN_RESET) b |= 1u << 5;  /* button_5 */
  if (HAL_GPIO_ReadPin(HAL_GPIOC, HAL_GPIO_PIN_8)  == HAL_GPIO_PIN_RESET) b |= 1u << 6;  /* button_6 */
  if (HAL_GPIO_ReadPin(HAL_GPIOC, HAL_GPIO_PIN_9)  == HAL_GPIO_PIN_RESET) b |= 1u << 7;  /* button_7 */
  return b; //eg button 3 pushed (button 4 in joy.cpl) == 1000
}


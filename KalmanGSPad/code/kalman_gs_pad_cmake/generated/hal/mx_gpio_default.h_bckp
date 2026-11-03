/**
  ******************************************************************************
  * @file           : mx_gpio_default.h
  * @brief          : Header for mx_gpio_default.c file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the mx_stm32c5xx_hal_drivers_license.md file
  * in the same directory as the generated code.
  * If no mx_stm32c5xx_hal_drivers_license.md file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MX_GPIO_DEFAULT_H
#define MX_GPIO_DEFAULT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "stm32_hal.h"
#include "mx_def.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/******************************************************************************/
/* Exported defines for gpio_default in HAL layer                             */
/******************************************************************************/

/* Primary aliases for GPIO PA5 pin */
#define LED_PORT                                        HAL_GPIOA
#define LED_PIN                                         HAL_GPIO_PIN_5
#define LED_INIT_STATE                                  HAL_GPIO_PIN_RESET
#define LED_ACTIVE_STATE                                HAL_GPIO_PIN_SET
#define LED_INACTIVE_STATE                              HAL_GPIO_PIN_RESET

/* Primary aliases for GPIO PB4(NJTRST) pin */
#define INC_BUTTON_PORT                                 HAL_GPIOB
#define INC_BUTTON_PIN                                  HAL_GPIO_PIN_4

/* Primary aliases for GPIO PB12 pin */
#define BUTTON_0_PORT                                   HAL_GPIOB
#define BUTTON_0_PIN                                    HAL_GPIO_PIN_12

/* Primary aliases for GPIO PB13 pin */
#define BUTTON_1_PORT                                   HAL_GPIOB
#define BUTTON_1_PIN                                    HAL_GPIO_PIN_13

/* Primary aliases for GPIO PB14 pin */
#define BUTTON_2_PORT                                   HAL_GPIOB
#define BUTTON_2_PIN                                    HAL_GPIO_PIN_14

/* Primary aliases for GPIO PB15 pin */
#define BUTTON_3_PORT                                   HAL_GPIOB
#define BUTTON_3_PIN                                    HAL_GPIO_PIN_15

/* Primary aliases for GPIO PC6 pin */
#define BUTTON_4_PORT                                   HAL_GPIOC
#define BUTTON_4_PIN                                    HAL_GPIO_PIN_6

/* Primary aliases for GPIO PC7 pin */
#define BUTTON_5_PORT                                   HAL_GPIOC
#define BUTTON_5_PIN                                    HAL_GPIO_PIN_7

/* Primary aliases for GPIO PC8 pin */
#define BUTTON_6_PORT                                   HAL_GPIOC
#define BUTTON_6_PIN                                    HAL_GPIO_PIN_8

/* Primary aliases for GPIO PC9 pin */
#define BUTTON_7_PORT                                   HAL_GPIOC
#define BUTTON_7_PIN                                    HAL_GPIO_PIN_9

/* Exported macros -----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/******************************************************************************/
/* Exported functions for gpio_default in HAL layer                           */
/******************************************************************************/
/**
  * @brief mx_gpio_default init function
  * This function configures the hardware resources used in this example
  * @retval 0  GPIO group correctly initialized
  * @retval -1 Issue detected during GPIO group initialization
  */
system_status_t mx_gpio_default_init(void);

/**
  * @brief  De-initialize gpio_default instance.
  */
system_status_t mx_gpio_default_deinit(void);

/**
  * @brief  Get the EXTI10 object.
  * @retval Pointer on the EXTI10 Handle
  */
hal_exti_handle_t *mx_gpio_default_exti10_gethandle(void);

/******************************************************************************/
/*                           EXTI Line10 interrupt                            */
/******************************************************************************/
void EXTI10_IRQHandler(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MX_GPIO_DEFAULT_H */

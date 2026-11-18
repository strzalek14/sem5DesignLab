
/**
  ******************************************************************************
  * @file           : mx_adc1.h
  * @brief          : Header for mx_adc1.c file.
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
#ifndef MX_ADC1_H
#define MX_ADC1_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "stm32_hal.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Aliases of channels labels */
#define GIMBAL_1_X_CHANNEL HAL_ADC_CHANNEL_0
#define GIMBAL_1_Y_CHANNEL HAL_ADC_CHANNEL_1
#define GIMBAL_2_X_CHANNEL HAL_ADC_CHANNEL_6
#define GIMBAL_2_Y_CHANNEL HAL_ADC_CHANNEL_7
#define POT_0_CHANNEL HAL_ADC_CHANNEL_8
#define POT_1_CHANNEL HAL_ADC_CHANNEL_9
#define POT_2_CHANNEL HAL_ADC_CHANNEL_10

/** Primary aliases for ADC1_IN7 pin */
#define GIMBAL_2_Y_PORT                       HAL_GPIOA
#define GIMBAL_2_Y_PIN                        HAL_GPIO_PIN_7

/** Primary aliases for ADC1_IN6 pin */
#define GIMBAL_2_X_PORT                       HAL_GPIOA
#define GIMBAL_2_X_PIN                        HAL_GPIO_PIN_6

/** Primary aliases for ADC1_IN0 pin */
#define GIMBAL_1_X_PORT                       HAL_GPIOA
#define GIMBAL_1_X_PIN                        HAL_GPIO_PIN_0

/** Primary aliases for ADC1_IN1 pin */
#define GIMBAL_1_Y_PORT                       HAL_GPIOA
#define GIMBAL_1_Y_PIN                        HAL_GPIO_PIN_1

/** Primary aliases for ADC1_IN8 pin */
#define POT_0_PORT                            HAL_GPIOC
#define POT_0_PIN                             HAL_GPIO_PIN_0

/** Primary aliases for ADC1_IN9 pin */
#define POT_1_PORT                            HAL_GPIOC
#define POT_1_PIN                             HAL_GPIO_PIN_1

/** Primary aliases for ADC1_IN10 pin */
#define POT_2_PORT                            HAL_GPIOC
#define POT_2_PIN                             HAL_GPIO_PIN_2

/* Exported macros -----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/******************************************************************************/
/* Exported functions for ADC in HAL layer */
/******************************************************************************/
/**
  * @brief mx_adc1 init function
  * This function configures the hardware resources used in this example
  * @retval pointer to handle or NULL in case of failure
  */
hal_adc_handle_t *mx_adc1_init(void);

/**
  * @brief  De-initialize adc1 instance and return it.
  */
void mx_adc1_deinit(void);

/**
  * @brief  Get the ADC1 object.
  * @retval Pointer on the ADC1 Handle
  */
hal_adc_handle_t *mx_adc1_gethandle(void);

/******************************************************************************/
/*                      LPDMA1 channel0 global interrupt                      */
/******************************************************************************/
void LPDMA1_CH0_IRQHandler(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MX_ADC1_H */

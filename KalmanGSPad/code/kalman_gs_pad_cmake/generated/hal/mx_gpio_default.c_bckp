/**
  ******************************************************************************
  * @file           : mx_gpio_default.c
  * @brief          : gpio_default Peripheral initialization
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

/* Includes ------------------------------------------------------------------*/
#include "mx_gpio_default.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported variables by reference -------------------------------------------*/
static hal_exti_handle_t hEXTI10;

/******************************************************************************/
/* Exported functions for GPIO in HAL layer                                   */
/******************************************************************************/
system_status_t mx_gpio_default_init(void)
{
  hal_gpio_config_t  gpio_config;

  HAL_RCC_GPIOA_EnableClock();

  HAL_RCC_GPIOB_EnableClock();

  HAL_RCC_GPIOC_EnableClock();

  /*
    GPIO pin labels :
    PA5   ---------> LED
    */
  /* Configure PA5 GPIO pin in output mode */
  gpio_config.mode            = HAL_GPIO_MODE_OUTPUT;
  gpio_config.speed           = HAL_GPIO_SPEED_FREQ_LOW;
  gpio_config.pull            = HAL_GPIO_PULL_NO;
  gpio_config.output_type     = HAL_GPIO_OUTPUT_PUSHPULL;
  gpio_config.init_state      = LED_INIT_STATE;
  if (HAL_GPIO_Init(LED_PORT, LED_PIN, &gpio_config) != HAL_OK)
  {
    return SYSTEM_PERIPHERAL_ERROR;
  }

  /*
    GPIO pin labels :
    PB4   ---------> INC_BUTTON
    PB12  ---------> BUTTON_0
    PB13  ---------> BUTTON_1
    PB14  ---------> BUTTON_2
    PB15  ---------> BUTTON_3
    */
  /* Configure PB4, PB12, PB13, PB14, PB15 GPIO pins in input mode */
  gpio_config.mode            = HAL_GPIO_MODE_INPUT;
  gpio_config.pull            = HAL_GPIO_PULL_UP;
  if (HAL_GPIO_Init(HAL_GPIOB, INC_BUTTON_PIN | BUTTON_0_PIN | BUTTON_1_PIN | BUTTON_2_PIN | BUTTON_3_PIN, &gpio_config) != HAL_OK)
  {
    return SYSTEM_PERIPHERAL_ERROR;
  }

  /* Configure PB10 GPIO pin in input mode */
  gpio_config.mode            = HAL_GPIO_MODE_INPUT;
  gpio_config.pull            = HAL_GPIO_PULL_NO;
  if (HAL_GPIO_Init(HAL_GPIOB, HAL_GPIO_PIN_10, &gpio_config) != HAL_OK)
  {
    return SYSTEM_PERIPHERAL_ERROR;
  }

  hal_exti_config_t exti_config;

  /* Initialize the EXTI for line 10 */
  HAL_EXTI_Init(&hEXTI10, HAL_EXTI_LINE_10);

  /* Set the trigger as RISING for the GPIOB */
  exti_config.trigger   = HAL_EXTI_TRIGGER_RISING;
  exti_config.gpio_port = HAL_EXTI_GPIOB;
  HAL_EXTI_SetConfig(&hEXTI10, &exti_config);

  /* Set line 10 Interrupt priority */
  HAL_CORTEX_NVIC_SetPriority(EXTI10_IRQn, HAL_CORTEX_NVIC_PREEMP_PRIORITY_0, HAL_CORTEX_NVIC_SUB_PRIORITY_0);
  HAL_CORTEX_NVIC_EnableIRQ(EXTI10_IRQn);

  /*
    GPIO pin labels :
    PC6   ---------> BUTTON_4
    PC7   ---------> BUTTON_5
    PC8   ---------> BUTTON_6
    PC9   ---------> BUTTON_7
    */
  /* Configure PC6, PC7, PC8, PC9 GPIO pins in input mode */
  gpio_config.mode            = HAL_GPIO_MODE_INPUT;
  gpio_config.pull            = HAL_GPIO_PULL_UP;
  if (HAL_GPIO_Init(HAL_GPIOC, BUTTON_4_PIN | BUTTON_5_PIN | BUTTON_6_PIN | BUTTON_7_PIN, &gpio_config) != HAL_OK)
  {
    return SYSTEM_PERIPHERAL_ERROR;
  }

  return SYSTEM_OK;
}

system_status_t mx_gpio_default_deinit(void)
{
  /* De-initialize the EXTI for GPIOB line10 */
  HAL_EXTI_DeInit(&hEXTI10);

  /* set line 10 Interrupt priority */
  HAL_CORTEX_NVIC_DisableIRQ(EXTI10_IRQn);

  /* De-initialize pins of GPIOA port */
  HAL_GPIO_DeInit(LED_PORT, LED_PIN);

  /* De-initialize pins of GPIOB port */
  HAL_GPIO_DeInit(HAL_GPIOB, INC_BUTTON_PIN | HAL_GPIO_PIN_10 | BUTTON_0_PIN | BUTTON_1_PIN | BUTTON_2_PIN | BUTTON_3_PIN);

  /* De-initialize pins of GPIOC port */
  HAL_GPIO_DeInit(HAL_GPIOC, BUTTON_4_PIN | BUTTON_5_PIN | BUTTON_6_PIN | BUTTON_7_PIN);

  return SYSTEM_OK;
}

hal_exti_handle_t *mx_gpio_default_exti10_gethandle(void)
{
  return &hEXTI10;
}

/******************************************************************************/
/*                           EXTI Line10 interrupt                            */
/******************************************************************************/
void EXTI10_IRQHandler(void)
{
  HAL_EXTI_IRQHandler(&hEXTI10);
}

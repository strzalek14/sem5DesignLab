/**
  ******************************************************************************
  * file           : main.c
  * brief          : Main program body
  *                  main() calls the target system initialization, then calls the example entry point.
  ******************************************************************************
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* @user: configure the delay in milliseconds between 2 loop rounds */
#define EXAMPLE_LOOP_DELAY_MS 100U

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private functions prototype -----------------------------------------------*/

static void error_handler(void);

volatile int  g_fail = 0;
volatile UINT g_usbx_status = 0;

int main(void)
{
  if (mx_system_init() != SYSTEM_OK)                  { g_fail = 1; error_handler(); }

  hal_pcd_handle_t *pcd = mx_usb_drd_fs_device_init();
  if (pcd == NULL)                                    { g_fail = 2; error_handler(); }

  g_usbx_status = app_usbx_init();
  if (g_usbx_status != UX_SUCCESS)                    { g_fail = 3; error_handler(); }

  app_usbx_process();   /* first call runs ux_dcd_stm32_initialize() */

  if (HAL_PCD_GetState(pcd) != HAL_PCD_STATE_ACTIVE)  { g_fail = 4; error_handler(); }
  if (HAL_PCD_DeviceConnect(pcd) != HAL_OK)           { g_fail = 5; error_handler(); }

  gamepad_report_t last_report = {0};
  uint32_t next_tick = 0;
  uint32_t step = 0;

  while (1)
  {
    app_usbx_process();                     /* must keep running, so no HAL_Delay in this loop */

    if ((int32_t)(HAL_GetTick() - next_tick) >= 0)
    {
      next_tick = HAL_GetTick() + 5;
      step++;

      gamepad_report_t now = {0};

      now.report_id = 1;

      /* TEST PATTERN: delete once the real inputs exist */
      now.x       = (int8_t)((int32_t)(step % 255U) - 127);          /* sweeps -127..127 */
      now.rx      = (uint8_t)(((step / 20U) % 21U) * 5U);            /* steps 0..100     */
      now.buttons = (step & 0x40U) ? (1u << 4) : 0u;                 /* button 5 blinks  */

      /* REAL INPUTS, later:
      now.x       = (int8_t)gamepad_map(adc_axis0, 120, 3980, -127, 127);
      now.y       = (int8_t)-gamepad_map(adc_axis3, 120, 3980, -127, 127);
      now.z       = (int8_t)gamepad_map(adc_axis2, 120, 3980, -127, 127);
      now.rx      = (uint8_t)(gamepad_map(adc_wheels, 0, 4095, 0, 20) * 5);
      now.buttons = (sideways_pressed ? (1u << 4) : 0u) | (inplace_pressed ? (1u << 5) : 0u);
      */

      if (memcmp(&now, &last_report, sizeof(now)) != 0)
      {
        if (gamepad_send(&now) == UX_SUCCESS) { last_report = now; }
      }
    }
    
  }
}

static void error_handler(void)
{
  while (1)
  {
    HAL_GPIO_WritePin(HAL_GPIOA, HAL_GPIO_PIN_5, HAL_GPIO_PIN_SET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(HAL_GPIOA, HAL_GPIO_PIN_5, HAL_GPIO_PIN_RESET);
    HAL_Delay(2000);
  }
}

void HardFault_Handler(void)
{
  HAL_GPIO_WritePin(HAL_GPIOA, HAL_GPIO_PIN_5, HAL_GPIO_PIN_RESET);
  while (1);
}

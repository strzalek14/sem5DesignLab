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

uint16_t raw[AN_COUNT];

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
  
  analog_init();

 // encoder_init();
 // if (encoder_init() != 0)                             { g_fail = 6; error_handler(); }
 
  gamepad_report_t last_report = {0};
  uint32_t next_tick = 0;

  while (1)
  {
    app_usbx_process();                     /* must keep running, so no HAL_Delay in this loop */



  if ((int32_t)(HAL_GetTick() - next_tick) >= 0)
    {
      next_tick = HAL_GetTick() + 5; //hid report sent every 5 ms

      gamepad_report_t now = {0};

      now.report_id = 1;

      
      analog_read_all(raw);

      /* TEST PATTERN: delete once the real inputs exist */
      now.x      = (int8_t)gamepad_map(raw[AN_G1_X], 120, 3980, -127, 127);
      now.y      = (int8_t)gamepad_map(raw[AN_G1_Y], 120, 3980, -127, 127);
      now.z      = (int8_t)gamepad_map(raw[AN_G2_X], 120, 3980, -127, 127);
      now.rx     = (uint8_t)gamepad_map(raw[AN_G2_Y], 120, 3980, 0, 255);
      now.ry     = (uint8_t)gamepad_map(raw[AN_POT0], 0, 4095, 0, 255);
      now.rz     = (uint8_t)gamepad_map(raw[AN_POT1], 0, 4095, 0, 255);
      now.slider = (uint8_t)gamepad_map(raw[AN_POT2], 0, 4095, 0, 255);
      now.buttons = buttons_debounced(); //| encoder_button_bits();
                 

      volatile UINT g_send_status;   /* file scope */

      g_send_status = gamepad_send(&now);
      if (g_send_status == UX_SUCCESS) { last_report = now; }

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

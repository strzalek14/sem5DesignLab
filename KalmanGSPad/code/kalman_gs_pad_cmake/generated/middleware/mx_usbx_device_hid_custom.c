/**
  ******************************************************************************
  * @file    mx_usbx_device_hid_custom.c
  * @brief   USBX Device Custom HID applicative source file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025-2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the mx_usbx_license.md file
  * in the same directory as the generated code.
  * If no mx_usbx_license.md file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "mx_usbx_device_hid_custom.h"
#include "ux_api.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UX_SLAVE_CLASS_HID *g_hid_instance = UX_NULL;

UCHAR usbd_custom_hid_report_descriptor[] =
{
    0x05, 0x01,        // Usage Page (Generic Desktop)
    0x09, 0x05,        // Usage (Game Pad)
    0xA1, 0x01,        // Collection (Application)
    0x85, 0x01,        //   Report ID (1)
    0x09, 0x01,        //   Usage (Pointer)
    0xA1, 0x00,        //   Collection (Physical)
    0x09, 0x30,        //     Usage (X)
    0x09, 0x31,        //     Usage (Y)
    0x09, 0x32,        //     Usage (Z)
    0x15, 0x81,        //     Logical Minimum (-127)
    0x25, 0x7F,        //     Logical Maximum (127)
    0x75, 0x08,        //     Report Size (8)
    0x95, 0x03,        //     Report Count (3)
    0x81, 0x02,        //     Input (Data, Var, Abs)
    0x09, 0x33,        //     Usage (Rx)
    0x09, 0x34,        //     Usage (Ry)
    0x09, 0x35,        //     Usage (Rz)
    0x15, 0x00,        //     Logical Minimum (0)
    0x25, 0x7F,        //     Logical Maximum (127)
    0x75, 0x07,        //     Report Size (7)
    0x95, 0x03,        //     Report Count (3)
    0x81, 0x02,        //     Input (Data, Var, Abs)
    0xC0,              //   End Collection
    0x05, 0x09,        //   Usage Page (Button)
    0x19, 0x01,        //   Usage Minimum (Button 1)
    0x29, 0x08,        //   Usage Maximum (Button 8)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x08,        //   Report Count (8)
    0x81, 0x02,        //   Input (Data, Var, Abs)
    0x75, 0x03,        //   Report Size (3)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x03,        //   Input (Const, Var, Abs)   <- the 3 padding bits
    0xC0               // End Collection
};
/* Private function prototypes -----------------------------------------------*/

/**
  * @brief  usbd_custom_hid_activate
  *         This function is called when insertion of a Custom HID device.
  * @param  hid_instance: Pointer to the hid class instance.
  * @retval none
  */
VOID usbd_custom_hid_activate(VOID *hid_instance)
{
  g_hid_instance = (UX_SLAVE_CLASS_HID *)hid_instance;
  
}

/**
  * @brief  usbd_custom_hid_deactivate
  *         This function is called when extraction of a Custom HID device.
  * @param  hid_instance: Pointer to the hid class instance.
  * @retval none
  */
VOID usbd_custom_hid_deactivate(VOID *hid_instance)
{
  UX_PARAMETER_NOT_USED(hid_instance);
  g_hid_instance = UX_NULL;

}

/**
  * @brief  usbd_custom_hid_set_feature
  *         This function is invoked when the host sends a HID SET_REPORT
  *         to the application over Endpoint 0 (Set Feature).
  * @param  hid_instance: Pointer to the hid class instance.
  * @param  hid_event: Pointer to structure of the hid event.
  * @retval status
  */
UINT usbd_custom_hid_set_feature(struct UX_SLAVE_CLASS_HID_STRUCT *hid_instance,
                                 UX_SLAVE_CLASS_HID_EVENT *hid_event)
{
  UINT status = UX_SUCCESS;

  UX_PARAMETER_NOT_USED(hid_instance);
  UX_PARAMETER_NOT_USED(hid_event);

  return status;
}

/**
  * @brief  usbd_custom_hid_get_report
  *         This function is invoked when host is requesting event through
  *         control GET_REPORT request.
  * @param  hid_instance: Pointer to the hid class instance.
  * @param  hid_event: Pointer to structure of the hid event.
  * @retval status
  */
UINT usbd_custom_hid_get_report(struct UX_SLAVE_CLASS_HID_STRUCT *hid_instance,
                                UX_SLAVE_CLASS_HID_EVENT *hid_event)
{
  UINT status = UX_SUCCESS;

  UX_PARAMETER_NOT_USED(hid_instance);
  UX_PARAMETER_NOT_USED(hid_event);

  return status;
}

/**
  * @brief  usbd_custom_hid_set_report
  *         This function is invoked when a HID OUT event is received.
  * @param  hid_instance: Pointer to the hid class instance.
  * @retval none
  */
VOID usbd_custom_hid_set_report(struct UX_SLAVE_CLASS_HID_STRUCT *hid_instance)
{
  UX_PARAMETER_NOT_USED(hid_instance);

  return;
}

/**
  * @brief  usbd_custom_hid_EventMaxNumber
  *         This function to set receiver event max number parameter.
  * @param  none
  * @retval receiver event max number
  */
ULONG usbd_custom_hid_EventMaxNumber(VOID)
{
  ULONG max_number = 0U;

  return max_number;
}

/**
  * @brief  usbd_custom_hid_EventMaxLength
  *         This function to set receiver event max length parameter.
  * @param  none
  * @retval receiver event max length
  */
ULONG usbd_custom_hid_EventMaxLength(VOID)
{
  ULONG max_length = 0U;

  return max_length;
}
/**
  * @brief  usbd_custom_hid_report_address
  *         Return the device HID MOUSE Report Descriptor
  * @retval Pointer to HID Report Descriptor buffer
  */
UCHAR *usbd_custom_hid_report_address(VOID)
{
  return usbd_custom_hid_report_descriptor;
}

/**
  * @brief  usbd_custom_hid_report_length
  *         Return the device HID Report Descriptor
  * @retval Size of HID Report Descriptor buffer
  */
ULONG usbd_custom_hid_report_length(VOID)
{
  return sizeof(usbd_custom_hid_report_descriptor);
}

/**
  * @brief  usbd_custom_hid_report_id
  *         Return the device HID Report ID Support
  * @retval UX_FALSE / UX_TRUE
  */
ULONG usbd_custom_hid_report_id(VOID)
{
  return UX_FALSE;
}

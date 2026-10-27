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
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UX_SLAVE_CLASS_HID *g_hid_instance = UX_NULL;

UCHAR usbd_custom_hid_report_descriptor[] =
{
    0x05, 0x01,    // UsagePage(Generic Desktop[0x0001])
    0x09, 0x05,    // UsageId(Gamepad[0x0005])
    0xA1, 0x01,    // Collection(Application)
    0x85, 0x01,    //     ReportId(1)
    0x09, 0x01,    //     UsageId(Pointer[0x0001])
    0xA1, 0x00,    //     Collection(Physical)
    0x09, 0x30,    //         UsageId(X[0x0030])
    0x09, 0x31,    //         UsageId(Y[0x0031])
    0x09, 0x32,    //         UsageId(Z[0x0032])
    0x15, 0x81,    //         LogicalMinimum(-127)
    0x25, 0x7F,    //         LogicalMaximum(127)
    0x95, 0x03,    //         ReportCount(3)
    0x75, 0x08,    //         ReportSize(8)
    0x81, 0x02,    //         Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x09, 0x33,    //         UsageId(Rx[0x0033])
    0x09, 0x34,    //         UsageId(Ry[0x0034])
    0x09, 0x35,    //         UsageId(Rz[0x0035])
    0x15, 0x00,    //         LogicalMinimum(0)
    0x75, 0x07,    //         ReportSize(7)
    0x81, 0x02,    //         Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0xC0,          //     EndCollection()
    0x05, 0x09,    //     UsagePage(Button[0x0009])
    0x19, 0x01,    //     UsageIdMin(Button 1[0x0001])
    0x29, 0x05,    //     UsageIdMax(Button 5[0x0005])
    0x25, 0x01,    //     LogicalMaximum(1)
    0x95, 0x05,    //     ReportCount(5)
    0x75, 0x01,    //     ReportSize(1)
    0x81, 0x02,    //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x95, 0x01,    //     ReportCount(1)
    0x75, 0x06,    //     ReportSize(6)
    0x81, 0x03,    //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0xC0,          // EndCollection()
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

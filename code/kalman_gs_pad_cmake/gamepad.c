/* gamepad.c */
#include "gamepad.h"
#include "ux_device_class_hid.h"

extern UX_SLAVE_CLASS_HID *g_hid_instance;

/* Arduino map() + constrain() in one */
int32_t gamepad_map(int32_t v, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
  if (v < in_min) v = in_min;
  if (v > in_max) v = in_max;
  return (v - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

UINT gamepad_send(const gamepad_report_t *report)
{
  UX_SLAVE_CLASS_HID_EVENT ev = {0};

  if ((g_hid_instance == UX_NULL) ||
      (_ux_system_slave->ux_system_slave_device.ux_slave_device_state != UX_DEVICE_CONFIGURED))
  {
    return UX_ERROR;
  }

  ev.ux_device_class_hid_event_length = sizeof(gamepad_report_t);
  ux_utility_memory_copy(ev.ux_device_class_hid_event_buffer, (VOID *)report, sizeof(gamepad_report_t));
  return ux_device_class_hid_event_set(g_hid_instance, &ev);
}
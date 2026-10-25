/* gamepad.h */
#ifndef GAMEPAD_H
#define GAMEPAD_H
#include <stdint.h>
#include "mx_usbx_app.h"

typedef struct __attribute__((packed))
{
  int8_t   x, y, z;       /* -127..127 */
  uint8_t  rx, ry, rz;    /* 0..100    */
  uint16_t buttons;       /* bit 0 = button 1 ... bit 15 = button 16 */
} gamepad_report_t;

_Static_assert(sizeof(gamepad_report_t) == 8, "must match the descriptor");

int32_t gamepad_map(int32_t v, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
UINT    gamepad_send(const gamepad_report_t *report);
#endif
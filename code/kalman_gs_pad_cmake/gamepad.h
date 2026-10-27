/* gamepad.h */
#ifndef GAMEPAD_H
#define GAMEPAD_H
#include <stdint.h>
#include "mx_usbx_app.h"

typedef struct __attribute__((packed))
{
  uint8_t report_id;
  int8_t   x, y, z;       /* -127..127 */
  uint32_t rx      : 7;    /* 0..127 */
  uint32_t ry      : 7;    /* 0..127 */
  uint32_t rz      : 7;    /* 0..127 */
  uint32_t buttons : 5;    /* 5 przycisków (bity 0..4) */
  uint32_t padding : 6;    /* padding wyrównujący do pełnego bajtu */
} gamepad_report_t;

_Static_assert(sizeof(gamepad_report_t) == 8, "must match the descriptor");

int32_t gamepad_map(int32_t v, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
UINT    gamepad_send(const gamepad_report_t *report);
#endif
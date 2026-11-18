#include "encoder.h"
#include "mx_tim1.h"

#ifndef ENCODER_COUNTS_PER_CLICK
#define ENCODER_COUNTS_PER_CLICK  4   /* zmień na 2 lub 1 zależnie od trybu enkodera w TIM1 */
#endif

static hal_tim_handle_t *htim;
static uint16_t last_cnt  = 0;
static int16_t  enc_remainder = 0;

static uint16_t read_counter(void)
{
  return (uint16_t)HAL_TIM_GetCounter(htim);
}

int encoder_init(void)
{
  htim = mx_tim1_init();     /* pomiń tę linię, jeśli mx_system_init() wywołuje już mx_tim1_init() */
  if (htim == NULL) { return -1; }

  if (HAL_TIM_IC_StartChannel(htim, HAL_TIM_CHANNEL_1) != HAL_OK) { return -2; }
  if (HAL_TIM_IC_StartChannel(htim, HAL_TIM_CHANNEL_2) != HAL_OK) { return -3; }
  if (HAL_TIM_Start(htim) != HAL_OK)                              { return -4; }

  last_cnt  = read_counter();
  enc_remainder = 0;
  return 0;
}

int16_t encoder_take_delta(void)
{
  uint16_t now  = read_counter();
  int16_t  diff = (int16_t)(now - last_cnt);   /* bezpieczne przy zawinięciu 0 <-> 65535 */
  last_cnt = now;

  enc_remainder += diff;
  int16_t clicks = enc_remainder / ENCODER_COUNTS_PER_CLICK;
  enc_remainder      = enc_remainder % ENCODER_COUNTS_PER_CLICK;
  return clicks;
}

typedef struct { uint8_t pending; uint8_t phase; } pulse_t;
static pulse_t pulse_cw, pulse_ccw;

static void pulse_add(pulse_t *p, uint16_t n)
{
  uint16_t total = (uint16_t)p->pending + n;
  p->pending = (total > 20U) ? 20U : (uint8_t)total;      /* cap the backlog */
}

static uint8_t pulse_step(pulse_t *p)        /* 1 while the button should be down */
{
  if ((p->phase == 0) && (p->pending > 0)) { p->pending--; p->phase = 1; }
  uint8_t pressed = (p->phase >= 1) && (p->phase <= 3);
  if (p->phase != 0) { p->phase = (p->phase >= 6) ? 0 : (uint8_t)(p->phase + 1); }
  return pressed;
}

uint16_t encoder_button_bits(void)           /* call once per 5 ms tick */
{
  int16_t clicks = encoder_take_delta();
  if (clicks > 0)      { pulse_add(&pulse_cw,  (uint16_t)clicks); }
  else if (clicks < 0) { pulse_add(&pulse_ccw, (uint16_t)(-clicks)); }

  uint16_t bits = 0;
  if (pulse_step(&pulse_cw))  { bits |= 1u << 8; }
  if (pulse_step(&pulse_ccw)) { bits |= 1u << 9; }
  return bits;
}
/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    ht_led.c
 * @brief   LED Indicator code.
 *
 * @addtogroup GPIO
 * @{
 */

#include "ch.h"
#include "hal.h"

#include "ht_led.h"

void ht_led_Init(void){
    palSetPadMode(GPIOA,LED_TRUE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_FALSE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_ANSA,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_ANSB,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPad(GPIOA,LED_TRUE);
    palSetPad(GPIOA,LED_FALSE);
    palSetPad(GPIOA,LED_ANSA);
    palSetPad(GPIOB,LED_ANSB);
}
/** @} */

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

/**
 * @brief Amplification level status index
 */
uint8_t idx_ampl;

/**
 * @brief Frequency level status index
 */
uint8_t idx_freq;

/**
 * @brief Set all Amplification/Frequency indicator LEDs to off
 */
static void indicator_m_off(void){
    palClearPad(GPIOA,LED_AMPL);
    palClearPad(GPIOA,LED_FREQ);

    palSetPad(GPIOB,LED_M1);
    palSetPad(GPIOB,LED_M2);
    palSetPad(GPIOB,LED_M3);
    palSetPad(GPIOB,LED_M4);
    palSetPad(GPIOB,LED_M5);
}

/**
 * @brief Set Amplification/Frequency indicator LED
 * @details LED to set on at desired number
 */
static void indicator_m_on(uint8_t lednum){
    switch(lednum){
        case 1: palClearPad(GPIOB,LED_M1);break;
        case 2: palClearPad(GPIOB,LED_M2);break;
        case 3: palClearPad(GPIOB,LED_M3);break;
        case 4: palClearPad(GPIOB,LED_M4);break;
        case 5: palClearPad(GPIOB,LED_M5);break;
    }
}

static THD_WORKING_AREA(waIndicator, 128);
#define ThdFunc_Indicator THD_FUNCTION
/**
 * @brief Thread for Amplification/Frequency Level indicator
 * @details Working by switching between Ampl and Freq LED indicator in microsecond
 */
static ThdFunc_Indicator(thdIndicator, arg) {
  (void)arg;
  chRegSetThreadName("led indicator");

  indicator_m_off();

  while (true) {
      indicator_m_off();
      palSetPad(GPIOA,LED_FREQ);
      indicator_m_on(idx_freq);
      chThdSleepMicroseconds(100);

      indicator_m_off();
      palSetPad(GPIOA,LED_AMPL);
      indicator_m_on(idx_ampl);
      chThdSleepMicroseconds(100);
  }
}

void ht_led_Shift(void){
    idx_ampl++;
    if(idx_ampl==6){
        idx_ampl = 1;
        idx_freq++;

        if(idx_freq==6){
            idx_ampl = 1;
            idx_freq = 1;
        }
    }
}

void ht_led_Init(void){
    palSetPadMode(GPIOA,LED_TRUE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_FALSE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_ANSA,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_ANSB,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPad(GPIOA,LED_TRUE);
    palSetPad(GPIOA,LED_FALSE);
    palSetPad(GPIOA,LED_ANSA);
    palSetPad(GPIOB,LED_ANSB);

    palSetPadMode(GPIOA,LED_AMPL,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_FREQ,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPadMode(GPIOB,LED_M1,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M2,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M3,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M4,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M5,PAL_MODE_OUTPUT_PUSHPULL);

    indicator_m_off();

    chThdCreateStatic(waIndicator, sizeof(waIndicator),	NORMALPRIO, thdIndicator, NULL);
}
/** @} */

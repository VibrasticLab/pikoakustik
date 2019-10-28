/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    drv_led.c
 * @brief   Indicator LED Driver code.
 *
 * @addtogroup Interface
 * @{
 */

#include "ch.h"
#include "hal.h"

#include "drv_led.h"

extern uint8_t stt_BtnAns;

/**
 * @brief delay for system running indicator (in ms)
 */
uint16_t led_delay=50;

/**
 * @brief Amplification level status index
 */
static uint8_t idx_ampl;

/**
 * @brief Frequency level status index
 */
static uint8_t idx_freq;

static THD_WORKING_AREA(waLed, 128);
#define ThdFunc_LED THD_FUNCTION
/**
 * @brief Thread for System Running Indicator
 * @details Smallest Thread to check either system in Run or Freeze
 */
static ThdFunc_LED(thdLed, arg) {

  (void)arg;
  chRegSetThreadName("led1");
  while (true) {
    palTogglePad(GPIOA, 5);
    chThdSleepMilliseconds(led_delay);
  }
}

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
  chRegSetThreadName("indicator run");

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

      if(stt_BtnAns == 1){
          palClearPad(GPIOA,LED_ANSA);
          palSetPad(GPIOB,LED_ANSB);
      }
      else if(stt_BtnAns == 2){
          palSetPad(GPIOA,LED_ANSA);
          palClearPad(GPIOB,LED_ANSB);
      }
  }
}

static THD_WORKING_AREA(waTestLed, 256);
#define ThdFunc_TestLED THD_FUNCTION
/**
 * @brief Thread for Actual LED interface
 * @details Checking all LED and Button status flags each second
 */
static ThdFunc_TestLED(thdTestLed, arg) {

  (void)arg;
  chRegSetThreadName("test led");

  while (true) {
      led_shift();

      if(stt_BtnAns!=0){
          stt_BtnAns=0;
          palSetPad(GPIOA,LED_ANSA);
          palSetPad(GPIOB,LED_ANSB);
      }

      chThdSleepMilliseconds(1000);
  }
}

void led_shift(void){
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

void led_start(void){
    palSetPadMode(GPIOA,5,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOA,5);

    chThdCreateStatic(waLed, sizeof(waLed),	NORMALPRIO, thdLed, NULL);
}

void indicator_start(void){
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

    idx_freq = 1;
    chThdCreateStatic(waIndicator, sizeof(waIndicator),	NORMALPRIO, thdIndicator, NULL);
    chThdCreateStatic(waTestLed, sizeof(waTestLed),	NORMALPRIO, thdTestLed, NULL);
}
/** @} */

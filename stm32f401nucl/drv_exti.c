/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    drv_exti.c
 * @brief   GPIO Interrupt Driver code.
 *
 * @addtogroup Interface
 * @{
 */

#include "ch.h"
#include "hal.h"

#include "drv_led.h"
#include "drv_audio.h"
#include "drv_exti.h"

/**
 * @brief Sine Wave test play flag
 * @details Used by Wave play thread
 */
static uint8_t testWave = 0;

/**
 * @brief Button status flag
 * @details Used by Interface to determine last Answer Button
 */
uint8_t stt_BtnAns = 1;

static THD_WORKING_AREA(waTestWave, 1024);
#define ThdFunc_TestWave THD_FUNCTION
/**
 * @brief Thread for Test Wave
 * @details Thread for respoding audio test flag
 */
static ThdFunc_TestWave(thdTestWave, arg) {
  (void)arg;
  chRegSetThreadName("test wave");
  while (true) {
      if(testWave==1){
          audio_test(0,4);
          testWave=0;
      }
      chThdSleepMilliseconds(100);
  }
}

/**
 * @brief Play Test EXTI Callback
 * @details Enumerated and not called directly by any normal thread
 */
static void extTestWave(EXTDriver *extp, expchannel_t channel) {

  (void)extp;
  (void)channel;

  testWave=1;
}

/**
 * @brief Button Answer A EXTI Callback
 * @details Enumerated and not called directly by any normal thread
 */
static void extBtnAnsA(EXTDriver *extp, expchannel_t channel) {

  (void)extp;
  (void)channel;

  stt_BtnAns = 1;
}

/**
 * @brief Button Answer B EXTI Callback
 * @details Enumerated and not called directly by any normal thread
 */
static void extBtnAnsB(EXTDriver *extp, expchannel_t channel) {

  (void)extp;
  (void)channel;

  stt_BtnAns = 2;
}

/**
 * @brief External Interrupt Channel Config
 */
static const EXTConfig extcfg = {
  {
    {EXT_CH_MODE_RISING_EDGE | EXT_MODE_GPIOC, extBtnAnsB}, //PC0
    {EXT_CH_MODE_RISING_EDGE | EXT_MODE_GPIOC, extBtnAnsA}, //PC1
    {EXT_CH_MODE_DISABLED, NULL}, //2
    {EXT_CH_MODE_DISABLED, NULL}, //3
    {EXT_CH_MODE_DISABLED, NULL},//4
    {EXT_CH_MODE_DISABLED, NULL}, //5
    {EXT_CH_MODE_DISABLED, NULL}, //6
    {EXT_CH_MODE_DISABLED, NULL}, //7
    {EXT_CH_MODE_DISABLED, NULL}, //8
    {EXT_CH_MODE_DISABLED, NULL}, //9
    {EXT_CH_MODE_DISABLED, NULL}, //10
    {EXT_CH_MODE_DISABLED, NULL}, //11
    {EXT_CH_MODE_DISABLED, NULL}, //12
    {EXT_CH_MODE_RISING_EDGE | EXT_MODE_GPIOC, extTestWave}, //13
    {EXT_CH_MODE_DISABLED, NULL}, //14
    {EXT_CH_MODE_DISABLED, NULL}, //15
    {EXT_CH_MODE_DISABLED, NULL}, //16
    {EXT_CH_MODE_DISABLED, NULL}, //17
    {EXT_CH_MODE_DISABLED, NULL}, //18
    {EXT_CH_MODE_DISABLED, NULL}, //19
    {EXT_CH_MODE_DISABLED, NULL}, //20
    {EXT_CH_MODE_DISABLED, NULL}, //21
    {EXT_CH_MODE_DISABLED, NULL}  //22
  }
};

void exti_start(void){
    palSetPadMode(GPIOC,  0, PAL_MODE_INPUT_PULLUP);
    palSetPadMode(GPIOC,  1, PAL_MODE_INPUT_PULLUP);
    palSetPadMode(GPIOC, 13, PAL_MODE_INPUT_PULLUP);

    extStart(&EXTD1, &extcfg);
    extChannelEnable(&EXTD1,  0);
    extChannelEnable(&EXTD1,  1);
    extChannelEnable(&EXTD1, 13);

    chThdCreateStatic(waTestWave, sizeof(waTestWave),	NORMALPRIO, thdTestWave, NULL);
}
/** @} */

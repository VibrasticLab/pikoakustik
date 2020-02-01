/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    ht_exti.c
 * @brief   External Interrupt code.
 *
 * @addtogroup GPIO
 * @{
 */

#include "ch.h"
#include "hal.h"
#include "chprintf.h"

#include "ht_exti.h"
#include "ht_audio.h"
#include "ht_led.h"

/**
 * @brief Interrupt 13 callback flag
 */
static uint8_t ext13 = 0;

/**
 * @brief Amplitude modification each iteration
 */
static double ampl_mod = 1;

static THD_WORKING_AREA(waExtiCb, 512);
#define ThdFunc_ExtiCb THD_FUNCTION
/**
 * @brief Thread for Interrupt Callback
 * @details Reason: System freezed when call long process directly from Exti Callback
 */
static ThdFunc_ExtiCb(thdExtiCb, arg) {
  (void)arg;
  double ampl_act;
  uint16_t y_act;

  chRegSetThreadName("exti callback");
  while (true) {
      if(ext13==1){

          ampl_act = DEFAULT_ATTEN*ampl_mod*32767;
          if(ampl_act<=DEFAULT_AMPL_THD){ampl_mod = 0;}

          y_act = DEFAULT_ATTEN*ampl_mod*32767;
          chprintf((BaseSequentialStream *)&SD1,"Ampl: %5i\r\n",y_act);

          ht_audio_Tone(1,ampl_mod);
          ht_audio_Play(TEST_DURATION);

          ampl_mod = ampl_mod/2;
          ext13=0;
      }
      chThdSleepMicroseconds(100);
  }
}

/**
 * @brief Play Test EXTI Callback
 * @details Enumerated and not called directly by any normal thread
 * @details Only trigerring callback flag
 */
static void extTestWave(EXTDriver *extp, expchannel_t channel) {
    (void)extp;
    (void)channel;

    if(ext13==0)ext13=1;
}

/**
 * @brief External Interrupt Channel Config
 */
static const EXTConfig extcfg = {
  {
    {EXT_CH_MODE_DISABLED, NULL}, //0
    {EXT_CH_MODE_DISABLED, NULL}, //1
    {EXT_CH_MODE_DISABLED, NULL}, //2
    {EXT_CH_MODE_DISABLED, NULL}, //3
    {EXT_CH_MODE_DISABLED, NULL}, //4
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

void ht_exti_Init(void){
    palSetPadMode(GPIOC, 13, PAL_MODE_INPUT_PULLUP);

    extStart(&EXTD1, &extcfg);
    extChannelEnable(&EXTD1, 13);

    chThdCreateStatic(waExtiCb, sizeof(waExtiCb),	NORMALPRIO, thdExtiCb, NULL);
}


 /** @} */

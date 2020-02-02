/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    main.c
 * @brief   Main code.
 *
 * @addtogroup Main
 * @{
 */

#include "ch.h"
#include "hal.h"
#include "chprintf.h"

#include "ht_audio.h"
#include "ht_exti.h"
#include "ht_led.h"
#include "ht_console.h"
#include "ht_mmc.h"

uint16_t led_delay=100;

static THD_WORKING_AREA(waRunLed, 128);
#define ThdFunc_RunLED THD_FUNCTION
/**
 * @brief Thread for System Running Indicator
 * @details Smallest Thread to check either system in Run or Freeze
 */
static ThdFunc_RunLED(thdRunLed, arg) {
  (void)arg;
  chRegSetThreadName("run led");
  while (true) {
    palTogglePad(GPIOA, 1);
    chThdSleepMilliseconds(led_delay);
  }
}

int main(void){
    halInit();
    chSysInit();

    ht_audio_Init();
#if USE_STARTUP_TEST
    ht_audio_Tone(2,0.1);
    ht_audio_Play(TEST_DURATION);
#endif

    ht_exti_Init();
    ht_led_Init();
    ht_commUSB_Init();

    ht_mmc_Init();
    ht_mmc_Test();

    palSetPadMode(GPIOA,1,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOA,1);
    chThdCreateStatic(waRunLed, sizeof(waRunLed),	NORMALPRIO, thdRunLed, NULL);

    chprintf((BaseSequentialStream *)&SD1,"Initialization completed\r\n");
    while(1){
        ht_commUSB_ReInit();
        chThdSleepMicroseconds(100);
    }
}

/** @} */

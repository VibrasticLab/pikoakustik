/*
    Embedded Audiometri - Copyright (C) 2020 Achmadi

    github.com/mekatronik-achmadi/ or mekatronik-achmadi@gmail.com

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

#include "user_conf.h"

#include "ht_audio.h"
#include "ht_exti.h"
#include "ht_led.h"
#include "ht_console.h"
#include "ht_mmc.h"
#include "ht_metri.h"

extern uint8_t mode_status;
extern uint8_t mode_led;

/**
 * @brief status to control LED thread start
 */
static uint8_t stt_readyAll = FALSE;

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

#if USER_TEST_STATE
    if(mode_led==LED_FAIL){
        led_result_off();

        palClearPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(200);

        palSetPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(200);

        palClearPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(200);

        palSetPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(200);

 #if USER_LED_BUTTON
        led_result_off();
        led_resultYES();
        chThdSleepMilliseconds(200);

        led_result_off();
        led_resultNO();
        chThdSleepMilliseconds(200);
 #else
        chThdSleepMilliseconds(400);
 #endif
    }
    else if(mode_led==LED_READY){
        palTogglePad(GPIOA, LED_RUN);

 #if USER_LED_BUTTON
        led_result_off();
        led_resultYES();
        chThdSleepMilliseconds(200);

        led_result_off();
        led_resultNO();
        chThdSleepMilliseconds(200);
 #else
        chThdSleepMilliseconds(400);
 #endif
    }
#else
    if(mode_led==LED_FAIL){
        palClearPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(50);
        palSetPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(100);
        palClearPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(50);
        palSetPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(1500);
    }
    else if(mode_led==LED_READY){
        palTogglePad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(500);
    }
    else if(mode_led==LED_CFILE){
        palSetPad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(1);
    }
    else if(mode_led==LED_METRI){
        palTogglePad(GPIOA, LED_RUN);
        chThdSleepMilliseconds(50);
    }
#endif

  }
}

/**
 * @brief Main Function as start entry
 * @return Nothing
 */
int main(void){
    halInit();
    chSysInit();

    palSetPadMode(GPIOA,LED_RUN,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOA,LED_RUN);

#if USER_LED_BUTTON
    ht_led_Init();
    ht_led_Test();
    ht_exti_Init();
#endif

#if USER_MMC
   ht_mmc_Init();
   ht_mmc_initCheck();
#endif

#if USER_SERIAL
 ht_commUSB_Init();

 #if USER_IOT
   ht_commUART_Init();
 #endif
#endif

#if USER_AUDIO
    ht_audio_Init();
 #if USER_AUDIO_STARTUP
    ht_audio_TestBoth();
 #endif
#endif

#if USER_METRI
    ht_metri_Init();
#endif

    while(1){

#if USER_SERIAL
 ht_commUSB_shInit();

 #if USER_IOT
    ht_commUART_shInit();
 #endif
#endif
        if(stt_readyAll==FALSE){
            chThdSleepMilliseconds(500);
            chThdCreateStatic(waRunLed, sizeof(waRunLed),	NORMALPRIO, thdRunLed, NULL);
            ht_comm_Msg("All System Ready\r\n");
            stt_readyAll = TRUE;
        }

        chThdSleepMilliseconds(500);
    }
}
/** @} */

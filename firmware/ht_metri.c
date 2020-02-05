/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    ht_metri.c
 * @brief   Audiometri process code.
 *
 * @addtogroup Audiometri
 * @{
 */

#include <stdio.h>
#include <stdlib.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"

#include "ht_metri.h"
#include "ht_exti.h"
#include "ht_console.h"
#include "ht_led.h"

/* USB-CDC pointer object */
extern SerialUSBDriver SDU1;

uint8_t wait_input = 0;
uint8_t mode_status = STT_IDLE;

static THD_WORKING_AREA(waRunMetri, 128);
#define ThdFunc_RunMetri THD_FUNCTION
/**
 * @brief Thread for System Running Indicator
 * @details Smallest Thread to check either system in Run or Freeze
 */
static ThdFunc_RunMetri(thdRunMetri, arg) {
    (void)arg;

    uint8_t rndans;
    uint8_t rndnum;
    chRegSetThreadName("run led");
    srand(5);
    while (true) {
        if(mode_status==STT_STDBY){
            palTogglePad(GPIOA,LED_TRUE);
            palTogglePad(GPIOA,LED_FALSE);
            chThdSleepMilliseconds(500);
        }
        else if(mode_status==STT_METRI){
            rndnum = rand() % 100;
            rndans = rndnum % 2;
            if(rndans==0){
                led_answer_off();
                chThdSleepMilliseconds(500);
                led_answerA();
            }
            else if(rndans==1){
                led_answer_off();
                chThdSleepMilliseconds(500);
                led_answerB();
            }
            chThdSleepMilliseconds(1000);
        }
        chThdSleepMilliseconds(100);
    }
}

void ht_metri_Init(void){
    chThdCreateStatic(waRunMetri, sizeof(waRunMetri), NORMALPRIO, thdRunMetri, NULL);
}

/** @} */

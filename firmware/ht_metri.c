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

uint8_t mode_status = STT_IDLE;
uint8_t mode_step = STEP_ASK;
uint8_t numresp,numask;

static THD_WORKING_AREA(waRunMetri, 512);
#define ThdFunc_RunMetri THD_FUNCTION
/**
 * @brief Thread for System Running Indicator
 * @details Smallest Thread to check either system in Run or Freeze
 */
static ThdFunc_RunMetri(thdRunMetri, arg) {
    (void)arg;

    uint8_t rndnum;
    uint8_t rndask;
    srand(3);
    chRegSetThreadName("run led");

    while (true) {
        if(mode_status==STT_STDBY){
            palTogglePad(GPIOA,LED_TRUE);
            palTogglePad(GPIOA,LED_FALSE);
            chThdSleepMilliseconds(500);
        }
        else if(mode_status==STT_METRI){
            rndnum = rand() % 50;
            rndask = rndnum % 2;

            if(mode_step==STEP_ASK){
                chThdSleepMilliseconds(1000);

                if(rndask==0){
                    led_answerA();
                    numask = 1;
                }
                else if(rndask==1){
                    led_answerB();
                    numask = 2;
                }
                mode_step=STEP_WAIT;
                chprintf((BaseSequentialStream *)&SHELL_IFACE,"Question is %i\r\n",numask);
            }
            else if(mode_step==STEP_CHK){
                if(numresp==numask){
                    led_result_off();
                    led_resultYES();
                    chprintf((BaseSequentialStream *)&SHELL_IFACE,"Conclusion True\r\n");
                }
                else{
                    led_result_off();
                    led_resultNO();
                    chprintf((BaseSequentialStream *)&SHELL_IFACE,"Conclusion False\r\n");
                }

                numask = 0;
                numresp = 0;
                chThdSleepMilliseconds(1000);

                led_answer_off();
                led_result_off();
                mode_step=STEP_ASK;
            }
        }
        chThdSleepMilliseconds(100);
    }
}

void ht_metri_Init(void){
    chThdCreateStatic(waRunMetri, sizeof(waRunMetri), NORMALPRIO, thdRunMetri, NULL);
}

/** @} */

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
#include "ht_audio.h"
#include "ht_mmc.h"

extern uint8_t mode_led;

uint8_t mode_status = STT_IDLE;
uint8_t mode_step = STEP_ASK;
uint8_t numresp,numask;

static THD_WORKING_AREA(waRunMetri, 2048);
#define ThdFunc_RunMetri THD_FUNCTION
/**
 * @brief Thread for System Running Indicator
 * @details Smallest Thread to check either system in Run or Freeze
 */
static ThdFunc_RunMetri(thdRunMetri, arg) {
    (void)arg;

    uint8_t rndnum;
    uint8_t rndask;
    double ampl_test = FIRSTTEST_DB;
    char strbuff[IFACE_BUFF_SIZE];

    srand(3);
    chRegSetThreadName("run led");

    while (true) {
        if(mode_status==STT_STDBY){
            palTogglePad(GPIOA,LED_TRUE);
            palTogglePad(GPIOA,LED_FALSE);
            chThdSleepMilliseconds(500);
        }
        else if(mode_status==STT_CFILE){
            ht_mmcMetri_chkFile();
            mode_led=LED_METRI;
            mode_status=STT_METRI;
        }
        else if(mode_status==STT_METRI){
            rndnum = rand() % 50;
            rndask = rndnum % 2;

            if(mode_step==STEP_ASK){
                chThdSleepMilliseconds(1000);
                led_answer_off();

                led_answerA();
                if(rndask==0){
                    ht_audio_Tone(1.25,ampl_test);
                    ht_audio_Play(TEST_DURATION);
                    numask = 1;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();

                chThdSleepMilliseconds(TEST_SPEED_DELAY);

                led_answerB();
                if(rndask==1){
                    ht_audio_Tone(1.25,ampl_test);
                    ht_audio_Play(TEST_DURATION);
                    numask = 2;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();

                mode_step=STEP_WAIT;
                ht_comm_Buff(strbuff,sizeof(strbuff),"amplitude level: %5.4f\r\n",ampl_test);
                ht_comm_Msg(strbuff);
                ampl_test = ampl_test / 2;
            }
            else if(mode_step==STEP_CHK){
                if(numresp==numask){
                    led_result_off();
                    led_resultYES();
                    ht_comm_Msg("Answer is True\r\n");
                    ht_mmcMetri_lineResult(1.25,ampl_test,1);
                }
                else{
                    led_result_off();
                    led_resultNO();
                    ht_comm_Msg("Answer is False\r\n");
                    ht_mmcMetri_lineResult(1.25,ampl_test,0);
                }

                numask = 0;
                numresp = 0;
                chThdSleepMilliseconds(1000);

                led_answer_off();
                led_result_off();
                mode_step=STEP_ASK;

                if(ampl_test <= SMALLEST_DB){
                    ht_comm_Msg("Testing Finish\r\n");
                    mode_status = STT_IDLE;
                    ampl_test = FIRSTTEST_DB;
                    mode_led = LED_READY;
                }
            }
        }
        chThdSleepMilliseconds(100);
    }
}

void ht_metri_Init(void){
    chThdCreateStatic(waRunMetri, sizeof(waRunMetri), NORMALPRIO, thdRunMetri, NULL);
}

/** @} */

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

/**
 * @brief Device mode variable
 */
uint8_t mode_status = STT_IDLE;

/**
 * @brief Audiometri step variable
 */
uint8_t mode_step = STEP_ASK;

/**
 * @brief User response number
 */
uint8_t numresp;

/**
 * @brief User asking number
 */
uint8_t numask;

/* More action/statement need more allocated memory space */
static THD_WORKING_AREA(waRunMetri, 4096);
#define ThdFunc_RunMetri THD_FUNCTION

/**
 * @brief Thread for System Running Indicator
 * @details Smallest Thread to check either system in Run or Freeze
 */
static ThdFunc_RunMetri(thdRunMetri, arg) {
    (void)arg;

    uint8_t rndask;
    double ampl_test = FIRSTTEST_DB;
    double freq_test[] = {1,2,4,8,16,32};
    uint8_t freq_idx = 0;
    uint8_t freq_max = sizeof(freq_test)/sizeof(freq_test[0]);
    char strbuff[IFACE_BUFF_SIZE];

    srand(3);
    chRegSetThreadName("run led");

    while (true) {
        if(mode_status==STT_SETUP){
            chThdSleepMilliseconds(100);
            ht_comm_Msg("Entering Mode: Ready\r\n");
            mode_status = STT_READY;
        }
        else if(mode_status==STT_CFILE){
#if RECORD_TEST
            ht_mmcMetri_chkFile();
#endif
            ht_comm_Msg("Entering Mode: Audiometri\r\n");
            mode_led=LED_METRI;
            mode_status=STT_METRI;
        }
        else if(mode_status==STT_METRI){
            rndask = ht_metri_RndOpt();

            if(mode_step==STEP_ASK){
                chThdSleepMilliseconds(1000);
                led_answer_off();

                led_answerA();
                if(rndask == OPT_ASK_A){
                    ht_audio_Tone(freq_test[freq_idx],ampl_test);
                    ht_audio_Play(TEST_DURATION);
                    numask = 1;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();

                chThdSleepMilliseconds(TEST_SPEED_DELAY);

                led_answerB();
                if(rndask == OPT_ASK_B){
                    ht_audio_Tone(freq_test[freq_idx],ampl_test);
                    ht_audio_Play(TEST_DURATION);
                    numask = 2;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();

                mode_step=STEP_WAIT;
                ht_comm_Buff(strbuff,sizeof(strbuff),"freq,ampl: %5.2f, %5.4f\r\n",freq_test[freq_idx],ampl_test);
                ht_comm_Msg(strbuff);
            }
            else if(mode_step==STEP_CHK){
                if(numresp==numask){
                    led_result_off();
                    led_resultYES();
                    ht_comm_Msg("Answer is True\r\n");
#if RECORD_TEST
                    ht_mmcMetri_lineResult(freq_test[freq_idx],ampl_test,1);
#endif
                }
                else{
                    led_result_off();
                    led_resultNO();
                    ht_comm_Msg("Answer is False\r\n");
#if RECORD_TEST
                    ht_mmcMetri_lineResult(freq_test[freq_idx],ampl_test,0);
#endif

                }

                numask = 0;
                numresp = 0;
                chThdSleepMilliseconds(1000);

                led_answer_off();
                led_result_off();
                mode_step=STEP_ASK;

                ampl_test = ampl_test / 2;

                if(ampl_test <= SMALLEST_DB){
                    freq_idx++;

                    if(freq_idx == freq_max){
#if RECORD_TEST
                        ht_mmcMetri_endResult();
#endif
                        ht_comm_Msg("Testing Finish\r\n");
                        mode_status = STT_IDLE;
                        ampl_test = FIRSTTEST_DB;
                        mode_led = LED_READY;
                    }
                    else{
                        ampl_test = FIRSTTEST_DB;
                        ht_comm_Msg("Ampliying next Frequency\r\n");
                    }
                }
            }
        }
        chThdSleepMilliseconds(100);
    }
}

uint8_t ht_metri_RndOpt(void){
    uint8_t rndnum, rndnumask;

    rndnum = rand() % 50;
    rndnumask = rndnum % 2;

    return rndnumask;
}

void ht_metri_Init(void){
    chThdCreateStatic(waRunMetri, sizeof(waRunMetri), NORMALPRIO, thdRunMetri, NULL);
}

/** @} */

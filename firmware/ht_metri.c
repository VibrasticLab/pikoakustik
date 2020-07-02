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

#include "user_conf.h"

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

/**
 * @brief Counter for test in each frequency
 * @details Should be not exceed 50 as it will exhausting
 */
uint8_t test_count = 0;

/**
 * @brief Counter for right answer
 * @details Should be not exceed 72% of test_count
 * @details Which is maximum at 36 (72% of 50)
 */
uint8_t test_right = 0;

/**
 * @brief Global flag for last answer status
 * @details Either False:0 or True:1
 */
uint8_t test_answer;

/**
 * @brief Global flag for convinient limit status
 * @details If reached should be True:0
 */
uint8_t test_conv = 0;

/**
 * @brief Last recorded random number
 */
static uint8_t last_rnd;

/**
 * @brief calibrated array ratio for frequency
 * @details Last Calibrated: 1.25 = 500 Hz
 * @details Requirement: 250,500,1000,2000,4000,8000
 */
#if USER_METRI_1FREQ
static double freq_test[] = {1.25};
#else
static double freq_test[] = {0.625,1.25,2.5,5,10,20};
#endif

/**
 * @brief Amplification ratio
 */
static double ampl_test = FIRSTTEST_DB;

/**
 * @brief Frequency array ID
 */
static uint8_t freq_idx = 0;

/**
 * @brief Audio Play function
 * @details Played in Metri routine
 */
static void ht_metri_AudioPlay(void){
    ht_audio_Tone(freq_test[freq_idx],ampl_test);
    ht_audio_Play(TEST_DURATION,OUT_LEFT);
}

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
#if USER_METRI_CONVLV
    double conv_level;
#endif

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

#if defined(USER_METRI_RECORD) && defined(USER_MMC)
            ht_mmcMetri_chkFile();
#endif
            ht_comm_Msg("Entering Mode: Audiometri\r\n");
            ht_comm_Msg("------------\r\n");
            mode_led=LED_METRI;
            mode_status=STT_METRI;
            srand((unsigned long)chVTGetSystemTime());
        }

        else if(mode_status==STT_METRI){
            if(mode_step==STEP_ASK){
                rndask = ht_metri_RndOpt();
#if USER_TEST_RNG
                ht_comm_Buff(strbuff,sizeof(strbuff),"rng: %4i\r\n", rndask);
                ht_comm_Msg(strbuff);
                chThdSleepMilliseconds(1000);
#else
                chThdSleepMilliseconds(1000);
                led_answer_off();

                /*************************************/
                led_answerA();
                if(rndask == OPT_ASK_A){
                    ht_metri_AudioPlay();
                    numask = BTN_ANS_A;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();
                /*************************************/

                chThdSleepMilliseconds(TEST_SPEED_DELAY);

                /*************************************/
                led_answerB();
                if(rndask == OPT_ASK_B){
                    ht_metri_AudioPlay();
                    numask = BTN_ANS_B;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();
                /*************************************/

                chThdSleepMilliseconds(TEST_SPEED_DELAY);

                /*************************************/
                led_answerC();
                if(rndask == OPT_ASK_C){
                    ht_metri_AudioPlay();
                    numask = BTN_ANS_C;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();
                /*************************************/

                mode_step=STEP_WAIT;
                test_count++;
                ht_comm_Buff(strbuff,sizeof(strbuff),"freq,ampl: %5.2f, %5.4f\r\n",freq_test[freq_idx],ampl_test);
                ht_comm_Msg(strbuff);
#endif
            }

            else if(mode_step==STEP_CHK){
                if(numresp==numask){
                    led_result_off();
                    led_resultYES();
                    test_answer = 1;
                    test_right++;
                    ht_comm_Msg("Answer is True\r\n");

#if defined(USER_METRI_RECORD) && defined(USER_MMC)
                    ht_mmcMetri_lineResult(freq_test[freq_idx],ampl_test,1);
#endif
                }
                else{
                    led_result_off();
                    led_resultNO();
                    test_answer = 0;
                    ht_comm_Msg("Answer is False\r\n");

#if defined(USER_METRI_RECORD) && defined(USER_MMC)
                    ht_mmcMetri_lineResult(freq_test[freq_idx],ampl_test,0);
#endif
                }

                numask = 0;
                numresp = 0;
                chThdSleepMilliseconds(1000);

                led_answer_off();
                led_result_off();
                mode_step=STEP_ASK;

                // TODO: redefined on amplitude scaling method
                if(test_answer==1){
                    ampl_test = ampl_test / 2;
                }
                else{
                    ampl_test = ampl_test * 2;
                }

#if USER_METRI_CONVLV
                conv_level = test_right*100/test_count;
                if(conv_level>=72){
                    test_conv = 1;
                }
                else{
                    test_conv = 0;
                }
#else
                test_conv = 0;
#endif

                if(ampl_test <= SMALLEST_DB || test_conv == 1){
                    freq_idx++;
                    ampl_test = FIRSTTEST_DB;
                    test_conv = 0;
                    test_right = 0;
                    test_count = 0;

                    if(freq_idx == freq_max){

#if defined(USER_METRI_RECORD) && defined(USER_MMC)
                        ht_mmcMetri_endResult();
#endif
                        ht_comm_Msg("Testing Finish\r\n");
                        mode_status = STT_IDLE;
                        mode_led = LED_READY;
                    }
                    else{
                        ht_comm_Msg("Continue next Frequency\r\n");
                    }
                }
            }
        }
        chThdSleepMilliseconds(100);
    }
}

uint8_t ht_metri_RndOpt(void){
    uint8_t rndnum, rndnumask;

    rndnum = rand() % 36;
    while(rndnum==last_rnd){rndnum = rand() % 36;}
    last_rnd = rndnum;

    if(rndnum==0||rndnum==3||rndnum==6||rndnum==9||rndnum==12||rndnum==15||rndnum==18||rndnum==21||rndnum==24||rndnum==27||rndnum==30||rndnum==33){
        rndnumask = OPT_ASK_A;
        ht_comm_Msg("Option A\r\n");
    }
    else if(rndnum==1||rndnum==4||rndnum==7||rndnum==10||rndnum==13||rndnum==16||rndnum==19||rndnum==22||rndnum==25||rndnum==28||rndnum==31||rndnum==34){
        rndnumask = OPT_ASK_B;
        ht_comm_Msg("Option B\r\n");
    }
    else if(rndnum==2||rndnum==5||rndnum==8||rndnum==11||rndnum==14||rndnum==17||rndnum==20||rndnum==23||rndnum==26||rndnum==29||rndnum==32||rndnum==35){
        rndnumask = OPT_ASK_C;
        ht_comm_Msg("Option C\r\n");
    }
    else{
        rndnumask = OPT_ASK_A;
    }

#if USER_TEST_RNG
    return rndnum;
#else
    return rndnumask;
#endif
}

void ht_metri_Init(void){
#if !defined(USER_TEST_STATE)
    chThdCreateStatic(waRunMetri, sizeof(waRunMetri), NORMALPRIO, thdRunMetri, NULL);
#endif
}

/** @} */

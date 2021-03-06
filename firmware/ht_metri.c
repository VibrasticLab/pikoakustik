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
 * @brief Global flag for last answer status
 * @details Either False:0 or True:1
 */
uint8_t test_answer;

/**
 * @brief Channel status variable
 */
static uint8_t channel_stt=OUT_LEFT;

/**
 * @brief Variable indicate amplitude scale going down
 */
static uint8_t curr_goDown = 1;

/**
 * @brief Varable indicate amplitude previously going down
 */
static uint8_t prev_goDown = 1;

/**
 * @brief Variable counting how much amplitude going up after down
 */
static uint8_t upAfterDown = 0;

/**
 * @brief calibrated array ratio for frequency
 * @details Last Calibrated: 1.25 = 500 Hz
 * @details Requirement: 250,500,1000,2000,4000,8000
 */
#if USER_METRI_ALLFREQ
 #if USER_METRI_16KHZ
static double freq_test[] = {0.625, 1.25, 2.5, 5, 10, 20, 40};
 #else
static double freq_test[] = {0.625, 1.25, 2.5, 5, 10, 20};
 #endif
#else
 static double freq_test[] = {1.25, 2.5, 5};
#endif

/**
 * @brief Amplification ratio
 */
static double ampl_test = FIRSTTEST_DB;

/**
 * @brief Amplification number status
 */
static uint8_t ampl_num = 9;

/**
 * @brief Frequency array ID
 */
static uint8_t freq_idx = 0;

/**
 * @brief Array to record of result
 */
static uint8_t res_arr[TEST_MAX_COUNT];

/**
 * @brief Resetting Result record
 */
static void ht_metri_ResultReset(void){
    uint8_t i;

    for(i=0;i<TEST_MAX_COUNT;i++){
        res_arr[i] = 9;
    }
}

/**
 * @brief Audio Play function
 * @details Played in Metri routine
 */
static void ht_metri_AudioPlay(uint8_t lr_stt){
    ht_audio_Tone(freq_test[freq_idx],ampl_test);

    if(lr_stt==OUT_LEFT)ht_audio_LeftCh();
    else if(lr_stt==OUT_RIGHT) ht_audio_RightCh();

    ht_audio_Play(TEST_DURATION);
    ht_audio_DisableCh();
}

/* More action/statement need more allocated memory space */
static THD_WORKING_AREA(waRunMetri, 2048);
#define ThdFunc_RunMetri THD_FUNCTION

/**
 * @brief Thread for Audiometri process
 * @details Main thread that run Audiometri process
 */
static ThdFunc_RunMetri(thdRunMetri, arg) {
    (void)arg;

    uint8_t rndask;

    uint8_t freq_max = sizeof(freq_test)/sizeof(freq_test[0]);
    char strbuff[IFACE_BUFF_SIZE];

    chRegSetThreadName("audiometri");

    while (true) {
        if(mode_status==STT_SETUP){
            chThdSleepMilliseconds(100);
            ht_comm_Msg("Entering Mode: Ready\r\n");
            mode_status = STT_READY;
        }

        else if(mode_status==STT_CFILE){

            ht_metri_ResultReset();
#if defined(USER_METRI_RECORD) && defined(USER_MMC)
            ht_mmcMetri_chkFile();
            ht_mmcMetri_jsonChStart(channel_stt);
#endif

            ht_comm_Msg("Entering Mode: Audiometri\r\n");
            ht_comm_Msg("------------\r\n");
            mode_led=LED_METRI;
            mode_status=STT_METRI;
        }

        else if(mode_status==STT_METRI){
            if(mode_step==STEP_ASK){
                rndask = ht_metri_RndOpt();

                chThdSleepMilliseconds(2*TEST_SPEED_DELAY);
                led_answer_off();

                /*************************************/
                led_answerA();
                if(rndask == OPT_ASK_A){
                    ht_metri_AudioPlay(channel_stt);
                    numask = BTN_ANS_A;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();
                /*************************************/

                chThdSleepMilliseconds(TEST_SPEED_DELAY);

                /*************************************/
                led_answerB();
                if(rndask == OPT_ASK_B){
                    ht_metri_AudioPlay(channel_stt);
                    numask = BTN_ANS_B;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();
                /*************************************/

                chThdSleepMilliseconds(TEST_SPEED_DELAY);

                /*************************************/
                led_answerC();
                if(rndask == OPT_ASK_C){
                    ht_metri_AudioPlay(channel_stt);
                    numask = BTN_ANS_C;
                }
                chThdSleepMilliseconds(TEST_SPEED_DELAY);
                led_answer_off();
                /*************************************/

                mode_step=STEP_WAIT;
                ht_comm_Buff(strbuff,sizeof(strbuff),"freq,ampl: %6.3f, %i\r\n",freq_test[freq_idx],ampl_num);
                ht_comm_Msg(strbuff);
            }

            else if(mode_step==STEP_CHK){
                if(numresp==numask){
                    led_result_off();
                    led_resultYES();
                    test_answer = 1;
                    ht_comm_Msg("Answer is True\r\n");
                }
                else{
                    led_result_off();
                    led_resultNO();
                    test_answer = 0;
                    ht_comm_Msg("Answer is False\r\n");
                }

                numask = 0;
                numresp = 0;
                chThdSleepMilliseconds(500);

                led_answer_off();
                led_result_off();
                mode_step=STEP_ASK;

                // TODO: redefined on amplitude scaling method
                res_arr[test_count] = ampl_num;
                test_count++;

                if(test_answer==1){
                    if(ampl_num>0){
                        ampl_test = ampl_test / 2;
                        ampl_num--;
                        curr_goDown = 1;
                    }
                }
                else{
                    if(ampl_num<9){
                        ampl_test = ampl_test * 2;
                        ampl_num++;
                        curr_goDown = 0;
                    }
                }

                /** Some blind statistic here */
                if((prev_goDown==1)&&(curr_goDown==0)){
                    upAfterDown++;
                }
                else if((prev_goDown==1)&&(curr_goDown==1)){
                    if(upAfterDown > (TEST_FALSE_COUNT-2))upAfterDown--;
                }
                prev_goDown = curr_goDown;
                /** end of some stupidity */

                if(ampl_test <= SMALLEST_DB || test_count==TEST_MAX_COUNT || ampl_num==0 || upAfterDown==TEST_FALSE_COUNT){

                    if(curr_goDown==1){ampl_num++;}

                    ht_comm_Buff(strbuff,sizeof(strbuff),"Last Amplitude Scale=%i\r\n",ampl_num);
                    ht_comm_Msg(strbuff);
                    ht_comm_Msg("A Frequency Finish\r\n");

#if defined(USER_METRI_RECORD) && defined(USER_MMC)
                    ht_mmcMetri_hearingResult(freq_test[freq_idx],freq_idx,ampl_num);
                    ht_mmcMetri_hearingRecord(res_arr,test_count,ampl_num);
#endif

                    freq_idx++;
                    ampl_test = FIRSTTEST_DB;
                    ampl_num = 9;
                    test_count = 0;
                    upAfterDown = 0;
                    ht_metri_ResultReset();

                    if(freq_idx != freq_max){
                        ht_comm_Msg("Continue next Frequency\r\n");
                        ht_mmcMetri_jsonComma();
                    }
                    else{
                        if(channel_stt!=OUT_RIGHT){
                            channel_stt = OUT_RIGHT;
                            freq_idx = 0;
                            ht_comm_Msg("Continue next Channel\r\n");

#if defined(USER_METRI_RECORD) && defined(USER_MMC)
                            ht_mmcMetri_jsonChClose();
                            ht_mmcMetri_jsonChStart(channel_stt);
#endif
                        }
                        else{
#if defined(USER_METRI_RECORD) && defined(USER_MMC)
                            ht_mmcMetri_jsonChClose();
                            ht_mmcMetri_endResult();
#endif
                            ht_comm_Msg("Testing Finish\r\n");
                            freq_idx = 0;
                            mode_status = STT_IDLE;
                            mode_led = LED_READY;
                            channel_stt = OUT_LEFT;
                        }
                    }
                }
            }
        }
        chThdSleepMilliseconds(100);
    }
}

uint8_t ht_metri_RndOpt(void){
    char strbuff[IFACE_BUFF_SIZE];
    uint8_t rndnum=0, rndnumask=0;

    //is this pseudorandom really works?
    srand((unsigned long)chVTGetSystemTime());

#if USER_METRI_LONGRNG
    uint8_t last_rnd;

    rndnum = rand() % 36;
    while(rndnum==last_rnd){rndnum = rand() % 36;}
    last_rnd = rndnum;

    if(rndnum==0||rndnum==5||rndnum==7||rndnum==11||rndnum==13||rndnum==17||rndnum==20||rndnum==21||rndnum==25||rndnum==29||rndnum==31||rndnum==35){
        rndnumask = OPT_ASK_A;
        ht_comm_Msg("Option A ");
    }
    else if(rndnum==1||rndnum==3||rndnum==8||rndnum==9||rndnum==14||rndnum==15||rndnum==18||rndnum==22||rndnum==26||rndnum==27||rndnum==32||rndnum==33){
        rndnumask = OPT_ASK_B;
        ht_comm_Msg("Option B ");
    }
    else if(rndnum==2||rndnum==4||rndnum==6||rndnum==10||rndnum==12||rndnum==16||rndnum==19||rndnum==23||rndnum==24||rndnum==28||rndnum==30||rndnum==34){
        rndnumask = OPT_ASK_C;
        ht_comm_Msg("Option C ");
    }
#else
    rndnum = rand() % 3;
    if(rndnum==0){rndnumask = OPT_ASK_A;ht_comm_Msg("Option A ");}
    if(rndnum==1){rndnumask = OPT_ASK_B;ht_comm_Msg("Option B ");}
    if(rndnum==2){rndnumask = OPT_ASK_C;ht_comm_Msg("Option C ");}
#endif

    ht_comm_Buff(strbuff,sizeof(strbuff),"(%1i)\r\n", rndnum);
    ht_comm_Msg(strbuff);

    return rndnumask;
}

void ht_metri_Init(void){
    chThdCreateStatic(waRunMetri, sizeof(waRunMetri), NORMALPRIO, thdRunMetri, NULL);
}

/** @} */

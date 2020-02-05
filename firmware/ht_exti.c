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
#include "ht_metri.h"
#include "ht_console.h"

/* USB-CDC pointer object */
extern SerialUSBDriver SDU1;

extern uint8_t mode_status;
extern uint8_t mode_led;

uint8_t mode_btnA, mode_btnB;

/**
 * @brief Button answer A callback
 * @details Enumerated and not called directly by any normal thread
 */
static void extiAnsA(EXTDriver *extp, expchannel_t channel) {
    (void)extp;
    (void)channel;

    if(mode_status==STT_IDLE){
        led_answer_off();
        led_answerA();
        mode_btnA=1;

        if(mode_btnB==1){
            chprintf((BaseSequentialStream *)&SHELL_IFACE,"Entering Mode: Standby\r\n");
            mode_status=STT_STDBY;
            mode_btnA=0;
            mode_btnB=0;
            led_answer_off();
            led_result_off();
            led_resultYES();
        }
    }
    else if(mode_status==STT_STDBY){
        chprintf((BaseSequentialStream *)&SHELL_IFACE,"Entering Mode: Audiometri\r\n");
        mode_status=STT_METRI;
        mode_led=LED_METRI;
        led_answer_off();
        led_result_off();
    }
}

/**
 * @brief Button answer B callback
 * @details Enumerated and not called directly by any normal thread
 */
static void extiAnsB(EXTDriver *extp, expchannel_t channel) {
    (void)extp;
    (void)channel;

    if(mode_status==STT_IDLE){
        led_answer_off();
        led_answerB();
        mode_btnB=1;

        if(mode_btnA==1){
            chprintf((BaseSequentialStream *)&SHELL_IFACE,"Entering Mode: Standby\r\n");
            mode_status=STT_STDBY;
            mode_btnA=0;
            mode_btnB=0;
            led_answer_off();
            led_result_off();
            led_resultYES();
        }
    }
    else if(mode_status==STT_STDBY){
        chprintf((BaseSequentialStream *)&SHELL_IFACE,"Entering Mode: Audiometri\r\n");
        mode_status=STT_METRI;
        mode_led=LED_METRI;
        led_answer_off();
        led_result_off();
    }
}

/**
 * @brief External Interrupt Channel Config
 */
static const EXTConfig extcfg = {
  {
    {EXT_CH_MODE_RISING_EDGE | EXT_MODE_GPIOC, extiAnsA}, //0
    {EXT_CH_MODE_RISING_EDGE | EXT_MODE_GPIOC, extiAnsB}, //1
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
    {EXT_CH_MODE_DISABLED, NULL}, //13
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
    palSetPadMode(GPIOC, BTN_ANS_A, PAL_MODE_INPUT_PULLUP);
    palSetPadMode(GPIOC, BTN_ANS_B, PAL_MODE_INPUT_PULLUP);

    extStart(&EXTD1, &extcfg);
    extChannelEnable(&EXTD1, BTN_ANS_A);
    extChannelEnable(&EXTD1, BTN_ANS_B);

    mode_btnA=0;
    mode_btnB=0;
}


 /** @} */

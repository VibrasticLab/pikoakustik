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
 * @file    ht_led.c
 * @brief   LED Indicator code.
 *
 * @addtogroup GPIO
 * @{
 */

#include "ch.h"
#include "hal.h"

#include "ht_led.h"

/**
 * @brief LED Mode global variable
 */
uint8_t mode_led=LED_FAIL;

void led_answer_off(void){
    palSetPad(GPIOA,LED_ANSA);
    palSetPad(GPIOB,LED_ANSB);
    palSetPad(GPIOB,LED_ANSC);
}

void led_result_off(void){
    palSetPad(GPIOA,LED_TRUE);
    palSetPad(GPIOA,LED_FALSE);
}

void ht_led_Init(void){
    palSetPadMode(GPIOA,LED_TRUE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_FALSE,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPadMode(GPIOA,LED_ANSA,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_ANSB,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_ANSC,PAL_MODE_OUTPUT_PUSHPULL);

    led_answer_off();
    led_result_off();
}
/** @} */

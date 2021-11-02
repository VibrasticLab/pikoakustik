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
 * @file    ht_led.h
 * @brief   LED Indicator header.
 *
 * @addtogroup GPIO
 * @{
 */

#ifndef HT_LED_H
#define HT_LED_H

/**
 * @brief LED Mode when MMC failed
 */
#define LED_FAIL    0

/**
 * @brief LED Mode when device Idle and Ready
 */
#define LED_READY   1

/**
 * @brief LED Mode when Checking File Save
 */
#define LED_CFILE   2

/**
 * @brief LED Mode when Audiometri start
 */
#define LED_METRI   3

/**
 * @brief LED Mode when Virtual test
 */
#define LED_VIRT    4

/* LED MACRO */
#define LED_RUN     1 //PA.1
#define LED_TRUE    2 //PA.2
#define LED_FALSE   3 //PA.3
#define LED_ANSA    4 //PA.4
#define LED_ANSB    0 //PB.0
#define LED_ANSC    1 //PB.1

/* LED Answer ON */
#define led_answerA() palClearPad(GPIOA,LED_ANSA)
#define led_answerB() palClearPad(GPIOB,LED_ANSB)
#define led_answerC() palClearPad(GPIOB,LED_ANSC)

/* LED Result ON  */
#define led_resultYES() palClearPad(GPIOA,LED_TRUE)
#define led_resultNO() palClearPad(GPIOA,LED_FALSE)

/**
 * @brief LED Test delay in milliseconds
 */
#define LED_TEST    500

/**
 * @brief Turn LED answer off
 */
void led_answer_off(void);

/**
 * @brief Turn LED result off
 */
void led_result_off(void);

/**
 * @brief LED indicator initialization
 */
void ht_led_Init(void);

/**
 * @brief LED indicator test function
 */
void ht_led_Test(void);

#endif // HT_LED_H
/** @} */

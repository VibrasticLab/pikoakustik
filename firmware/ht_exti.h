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
 * @file    ht_exti.h
 * @brief   External Interrupt header.
 *
 * @addtogroup GPIO
 * @{
 */

#ifndef HT_EXTI_H
#define HT_EXTI_H

/**
 * @brief Button answer A on port C0
 */
#define BTN_ANS_A 1

/**
 * @brief Button answer B on port C1
 */
#define BTN_ANS_B 2

/**
 * @brief Button answer C on port C2
 */
#define BTN_ANS_C 3

/**
 * @brief External Interrupt Initialization
 * @details Never put or calling any delay or chThdSleep() on EXTI callback
 * @details By doing so would cause the entire system frozen
 */
void ht_exti_Init(void);

#endif // HT_EXTI_H
/** @} */

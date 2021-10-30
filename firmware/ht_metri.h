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
 * @file    ht_metri.h
 * @brief   Audiometri process header.
 *
 * @addtogroup Audiometri
 * @{
 */

#ifndef HT_METRI_H
#define HT_METRI_H

#define STT_IDLE    0
#define STT_SETUP   1
#define STT_READY   2
#define STT_STDBY   3
#define STT_CFILE   4
#define STT_METRI   5
#define STT_VIRT    6

#define STEP_ASK    0
#define STEP_WAIT   1
#define STEP_CHK    2

#define OPT_ASK_A   0
#define OPT_ASK_B   1
#define OPT_ASK_C   2

/**
 * @brief Delay each event on metri loop
 */
#define TEST_SPEED_DELAY 500

/**
 * @brief Maximum number for each frequency test
 */
#define TEST_MAX_COUNT   24

/**
 * @brief Maximum number of false counter
 */
#define TEST_FALSE_COUNT 5

/**
 * @brief Function Random Initialization
 */
void ht_metri_RndInit(void);

/**
 * @brief Function Random Number Generation
 * @return uint32_t random number
 */
uint32_t ht_metri_RndGen(void);

/**
 * @brief Random number to choose answer position
 * @return Answer number position
 */
uint8_t ht_metri_RndOpt(void);

/**
 * @brief Audiometri process Initialization
 */
void ht_metri_Init(void);

#endif // HT_METRI_H
/** @} */

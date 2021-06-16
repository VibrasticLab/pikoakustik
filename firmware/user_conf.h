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
 * @file    user_conf.h
 * @brief   Global User config header.
 *
 * @addtogroup Main
 * @{
 */
#ifndef USER_CONF_H
#define USER_CONF_H

#define USER_BAUD           9600    /* Default Baudrate */

#define USER_TEST_STATE     FALSE   /* Whether run as test or metri mode */
 #define USER_TEST_RNG      FALSE   /* Whether run test for RNG */

#define USER_SERIAL         TRUE   /* Whether enable serial interface or not */
 #define USER_SERCONSOLE    FALSE   /* Whether user serial echo and prompt */
 #define USER_USB_DESC      TRUE   /* Whether use custom USB description or not */
 #define USER_SER_SCALE     TRUE   /* Whether use tone test out in scale or not */

#define USER_MMC            TRUE   /* Whether use memory card or not */
 #define USER_MMC_DBG       FALSE  /* Whether show MMC debug or not */
 #define USER_MMC_JSON      TRUE   /* Whether use JSON format or not */
 #define USER_MMC_AMPSC     TRUE   /* Whether use JSON in Amplification Scale or not */

#define USER_IOT            FALSE   /* Whether use UART for IOT module or not */

#define USER_AUDIO          TRUE   /* Whether use Audio module or not */
 #define USER_AUDIO_STARTUP TRUE   /* Whether use Audio test at startup */

#define USER_LED_BUTTON     TRUE   /* Whether use LED and Button modules */

#define USER_METRI          TRUE   /* Whether use Audiometri routine or not */
 #define USER_METRI_RECORD  TRUE   /* Whether record Audiometri session */
 #define USER_METRI_2EARS   TRUE   /* Whether Audiometri in Left only or also Right */
 #define USER_METRI_ALLFREQ FALSE   /* Whether Audiometri in all frequency or selection */
 #define USER_METRI_16KHZ   FALSE   /* Whether Audiometri use 16kHz or not */

#endif // USER_CONF_H
/** @} */

/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

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

#define USER_TEST_STATE     TRUE
 #define USER_TEST_RNG      FALSE

#define USER_SERIAL         TRUE
 #define USER_SERMSG_USB    TRUE

#define USER_MMC            TRUE

#define USER_IOT            TRUE
 #define USER_IOTSEND_ONLY  TRUE

#define USER_AUDIO          TRUE
 #define USER_AUDIO_STARTUP TRUE

#define USER_LED_BUTTON     TRUE

#define USER_METRI          FALSE
 #define USER_METRI_RECORD  TRUE
 #define USER_METRI_CONVLV  FALSE
 #define USER_METRI_1FREQ   TRUE

#endif // USER_CONF_H
/** @} */

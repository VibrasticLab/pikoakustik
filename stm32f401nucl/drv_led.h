/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    drv_led.h
 * @brief   Indicator LED Driver header.
 *
 * @addtogroup Interface
 * @{
 */

#ifndef DRV_LED_H
#define DRV_LED_H

#define LED_TRUE     0 //PA.0
#define LED_FALSE    1 //PA.1
#define LED_ANSA     4 //PA.4
#define LED_ANSB     0 //PB.0

#define LED_AMPL    2 //PA.2
#define LED_FREQ    3 //PA.3

#define LED_M1       3 //PB.3
#define LED_M2       5 //PB.5
#define LED_M3       4 //PB.4
#define LED_M4      13 //PB.13
#define LED_M5      14 //PB.14

/**
 * @brief Shift Ampli/Freq status index
 */
void led_shift(void);

/**
 * @brief System Running indicator initialization
 */
void led_start(void);

/**
 * @brief Amplification/Frequency Level indicator initialization
 */
void indicator_start(void);

#endif // DRV_LED_H
/** @} */

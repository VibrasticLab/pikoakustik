/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

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

#define LED_TRUE    2 //PA.0
#define LED_FALSE   3 //PA.1
#define LED_ANSA    4 //PA.4
#define LED_ANSB    0 //PB.0

/**
 * @brief LED indicator initialization
 */
void ht_led_Init(void);

#endif // HT_LED_H
/** @} */

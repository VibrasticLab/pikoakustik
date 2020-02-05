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

#define LED_FAIL    0
#define LED_READY   1
#define LED_METRI   2

#define LED_TRUE    2 //PA.2
#define LED_FALSE   3 //PA.3
#define LED_ANSA    4 //PA.4
#define LED_ANSB    0 //PB.0

/* LED Answer ON (Inversed) */
#define led_answerB() palClearPad(GPIOA,LED_ANSA)
#define led_answerA() palClearPad(GPIOB,LED_ANSB)

/* LED Result ON  */
#define led_resultYES() palClearPad(GPIOA,LED_TRUE)
#define led_resultNO() palClearPad(GPIOA,LED_FALSE)

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

#endif // HT_LED_H
/** @} */

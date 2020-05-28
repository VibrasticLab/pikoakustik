/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

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
 * @brief Button answer A on port C1
 */
#define BTN_ANS_A 1

/**
 * @brief Button answer B on port C0
 */
#define BTN_ANS_B 0

/**
 * @brief Button answer C on port C2
 */
#define BTN_ANS_C 2

/**
 * @brief External Interrupt Initialization
 * @details Never put or calling any delay or chThdSleep() on EXTI callback
 * @details By doing so would cause the entire system frozen
 */
void ht_exti_Init(void);

#endif // HT_EXTI_H
/** @} */

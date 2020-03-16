/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

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

#define STEP_ASK    0
#define STEP_WAIT   1
#define STEP_CHK    2

#define OPT_ASK_A   0
#define OPT_ASK_B   1
#define OPT_ASK_C   2

#define TEST_SPEED_DELAY 200

/**
 * Whether use 2 or 3 force choice
 */
#define USE_3FC 1

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

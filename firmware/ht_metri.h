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
#define STT_STDBY   1
#define STT_METRI   2

#define STEP_ASK    0
#define STEP_WAIT   1
#define STEP_CHK    2

void ht_metri_Init(void);

#endif // HT_METRI_H
/** @} */
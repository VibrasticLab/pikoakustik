/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    ht_audio.h
 * @brief   Audio Generator header.
 *
 * @addtogroup Audio
 * @{
 */

#ifndef HT_AUDIO_H
#define HT_AUDIO_H

/**
 * @brief I2S protocol buffer size
 */
#define SAMPLING_RATE 44100

/**
 * @brief I2S protocol buffer size
 */
#define I2S_BUFF_SIZE   256

/**
 * @brief Initiate Audio driver via I2S
 */
void ht_audio_Init(void);

/**
 * @brief Generate sine wave with only zero
 */
void ht_audio_Zero(void);

/**
 * @brief Generate sine wave from array table
 */
void ht_audio_Table(void);

/**
 * @brief Generate sine wave sample array
 * @param[in] Sine wave sample frequency
 * @param[in] Sine wave sample amplitude
 */
void ht_audio_Sine(double freq,uint16_t ampl);

/**
 * @brief Play Audio via I2S
 * @details Play I2S Transmit buffer in loop
 * @param[in] Duration to play in seconds
 */
void ht_audio_Play(uint8_t duration);

/**
 * @brief Test Audio driver as configured
 * @details 0: Zero Mode
 *          1: Table Mode
 *          2: Sine Mode
 */
void ht_audio_Test(uint8_t mode);

#endif // HT_AUDIO_H
/** @} */

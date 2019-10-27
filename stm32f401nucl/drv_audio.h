/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    drv_audio.h
 * @brief   Audio Driver header.
 *
 * @addtogroup Audio
 * @{
 */

#ifndef DRV_AUDIO_H
#define DRV_AUDIO_H

/**
 * @brief  Channel Number
 * @details 1: Mono
 *          2: Left-Right
 */
#define NUM_CHANNELS    1

/**
 * @brief  Initial Sample Array size
 */
#define NUM_SAMPLES     512

/**
 * @brief  Total Initial Buffer Array size
 * @details Multiply of Channel and Sample size
 */
#define I2S_BUF_SIZE    NUM_SAMPLES*NUM_CHANNELS

/**
 * @brief Actual Wave Play Call
 * @details Sends Array to ble played through I2S protocol
 */
void wave_test(void);

/**
 * @brief Actual Audio Peripheral Starting Call
 * @details Configure STM32 GPIO to I2S protocol
 */
void audio_start(void);

/**
 * @brief Actual Audio Test
 * @details Sine Wave generated and played at desired frequency and amplitude
 */
void audio_test(uint8_t n_freq, uint8_t n_ampl);

#endif // DRV_AUDIO_H
/** @} */

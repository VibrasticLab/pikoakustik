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
 * @brief Default Attenuation
 */
#define DEFAULT_ATTEN 0.01

/**
 * @brief Default Minimum threshold of 16-bit amplitude
 */
#define DEFAULT_AMPL_THD 1

/**
 * @brief I2S protocol buffer size
 * @details If I2S-SPI and MMC-SPI use same DMA stream, set to 512.
 *          Please check DMA stream ID on both SPI peripherals.
 */
#define I2S_BUFF_SIZE   512

/**
 * @brief Size of Half Buffer
 */
#define I2S_HALF_SIZE   ((I2S_BUFF_SIZE/2)-1)

/**
 * @brief Total buffer size
 * @details Just fill it below 44100
 */
#define TOTAL_BUFF_SIZE I2S_BUFF_SIZE*16

/**
 * @brief Wheter use Left/Right or Mono array
 */
#define USE_STEREO_ARRAY TRUE

/**
 * @brief Tone Test at startup
 */
#define USE_STARTUP_TEST FALSE

/**
 * @brief Global Duration for Testing
 */
#define TEST_DURATION   2

/**
 * @brief Initiate Audio driver via I2S
 */
void ht_audio_Init(void);

/**
 * @brief Generate sine wave with only zero
 */
void ht_audio_Zero(void);

/**
 * @brief Generate sine wave tone from halving formula with Frequency and Amplitude
 * @details This function intended to be actual implementaion of sample preparation
 * @param[in] Sine wave sample frequency in linear scaling from 400Hz (0.25,0.5,1,2,4,8,16,32) -> 500Hz=1.25
 * @param[in] Sine wave sample amplitude in linear scaling from 100dB (1 ~ 0.0001 or use ht_audio_Zero())
 */
void ht_audio_Tone(double freq, double ampl);

/**
 * @brief Play Audio via I2S
 * @details Play I2S Transmit buffer in loop
 * @param[in] Duration to play in seconds
 */
void ht_audio_Play(uint8_t duration);

#endif // HT_AUDIO_H
/** @} */
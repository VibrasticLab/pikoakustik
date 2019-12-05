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
 * @brief Use Archived Audio Features
 */
#define AUDIO_TEST_DEV  0

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

#if AUDIO_TEST_DEV
/**
 * @brief Use SineWave table or not
 */
#define USE_SINE_TABLE  0

/**
 * @brief I2S table buffer size
 * @details If I2S-SPI and MMC-SPI use same DMA stream, set to 512.
 *          Please check DMA stream ID on both SPI peripherals.
 */
#define I2S_TABLE_SIZE   256

/**
 * @brief Default Amplitude divided by 1000
 * @details Possible value (signed 16bit) are 32.767
 * @details Recommended value 32.767
 */
#define DEFAULT_AMPLI 32.767

/**
 * @brief I2S protocol buffer size
 */
#define SAMPLING_RATE 44100

#if USE_SINE_TABLE
/**
 * @brief Generate sine wave from array table
 */
void ht_audio_Table(void);

/**
 * @brief Generate sine waveform from array table
 */
void ht_audio_Wave(void);

/**
 * @brief Generate sine wave from halving formula
 */
void ht_audio_Half(void);
#endif

/**
 * @brief Generate sine wave sample array
 * @param[in] Sine wave sample frequency
 * @param[in] Sine wave sample amplitude (0.1-50)
 * @details WARNING: Dont set Amplitude to maximum (1000)!!!
 *          Your ear would damaged eventually.
 *          Except using speaker (not earphone).
 */
void ht_audio_Sine(double freq, double ampl);
#endif

#endif // HT_AUDIO_H
/** @} */

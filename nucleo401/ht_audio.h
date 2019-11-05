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
 * @brief Use SineWave table or not
 */
#define USE_SINE_TABLE  1

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

/**
 * @brief I2S protocol buffer size
 * @details If I2S-SPI and MMC-SPI use same DMA stream, set to 512.
 *          Please check DMA stream ID on both SPI peripherals.
 */
#if USE_SINE_TABLE
#define I2S_BUFF_SIZE   256
#else
#define I2S_BUFF_SIZE   512
#endif

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

#if USE_SINE_TABLE
/**
 * @brief Generate sine wave from array table
 */
void ht_audio_Table(void);

/**
 * @brief Generate sine waveform from array table
 */
void ht_audio_Wave(void);
#endif

/**
 * @brief Generate sine wave from halving formula
 */
void ht_audio_Half(void);

/**
 * @brief Generate sine wave tone from halving formula with Frequency and Amplitude
 * @details This function intended to be actual implementaion of sample preparation
 * @param[in] Sine wave sample frequency
 * @param[in] Sine wave sample amplitude
 */
void ht_audio_Tone(double freq, double ampl);

/**
 * @brief Generate sine wave sample array
 * @param[in] Sine wave sample frequency
 * @param[in] Sine wave sample amplitude (0.1-50)
 * @details WARNING: Dont set Amplitude to maximum (1000)!!!
 *          Your ear would damaged eventually.
 *          Except using speaker (not earphone).
 */
void ht_audio_Sine(double freq, double ampl);

/**
 * @brief Play Audio via I2S
 * @details Play I2S Transmit buffer in loop
 * @param[in] Duration to play in seconds
 */
void ht_audio_Play(uint8_t duration);

#endif // HT_AUDIO_H
/** @} */

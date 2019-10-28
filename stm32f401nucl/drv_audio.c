/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    drv_audio.c
 * @brief   Audio Driver code.
 *
 * @addtogroup Audio
 * @{
 */

#include <math.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"

#include "../driver.h"
#include "drv_audio.h"

/**
 * @brief Global Sine Wave Sample Buffer
 */
uint16_t sine_sample[I2S_BUF_SIZE];

/**
 * @brief Global Wave Play Duration value
 */
uint8_t play_duration;

/**
 * @brief Global Amplitude Available Array
 */
int ampl_arr[5] = {8000,6000,4000,2000,1000};

/**
 * @brief Global Frequency Available Array
 */
double freq_arr[5] = {8000,6000,4000,2000,1000};

/**
 * @brief Global Audio I2S structure
 * @details NUM_SAMPLES typesize should be buffer size and size_t are big enough on gcc
 */
I2SConfig i2scfg = {
  sine_sample,
  NULL,
  NUM_SAMPLES,
  NULL,
  0,
  16
};

void wave_test(void){
    i2sStart(&I2SD2, &i2scfg);
    i2sStartExchange(&I2SD2);

    chThdSleepMilliseconds(play_duration * 200);

    i2sStopExchange(&I2SD2);
    i2sStop(&I2SD2);
}

void audio_start(void){
    palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(5));
    palSetPadMode(GPIOB, 10, PAL_MODE_ALTERNATE(5));
    palSetPadMode(GPIOC, 3 , PAL_MODE_ALTERNATE(5));
}

void audio_test(uint8_t n_freq, uint8_t n_ampl){
    int v_ampl = ampl_arr[n_ampl];
    double v_freq = freq_arr[n_freq];

    chprintf((BaseSequentialStream *)&SD1,"Audio Test (Uncalibrated)\r\n");
    chprintf((BaseSequentialStream *)&SD1,"Freq: %4i and Ampli: %4i\r\n",(int)v_freq,v_ampl);

    sample_prep(v_freq,
                5,
                v_ampl);
    wave_test();
}
/** @} */

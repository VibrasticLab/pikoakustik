/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    driver.h
 * @brief   Global Driver Call header.
 *
 * @addtogroup Global
 * @{
 */

#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief Global Sampling Rate Value
 */
#define SAMPLING_RATE 44100

/**
 * @brief Global Call for System Initialization
 */
void system_init(void);

/**
 * @brief Global Call for Audio Initialization
 */
void driver_init(void);

/**
 * @brief Find Length of one cycle wave
 * @param[in] FR Desired frequency (Hz)
 * @param[in] DUR Desired duration wave-play (s)
 * @param[in] AMP Desired amplitude (bit)
 * @return Array Length
 */
void sample_prep(
        double FR,
        double DUR,
        int AMP);

/**
 * @brief Global Call for Sine Wave Play
 * @details This called one time at start-up.
 */
void play_wave(void);

/**
 * @brief Global Call for Main Loop
 */
void system_loop(void);

#endif
/** @} */

/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    ht_audio.c
 * @brief   Audio Generator code.
 *
 * @addtogroup Audio
 * @{
 */

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "ch.h"
#include "hal.h"

#include "ht_audio.h"

/**
 * @brief Sine Table for Test
 */
static uint16_t squared_table[I2S_BUFF_SIZE] = {
   0x0000, 0x0324, 0x0647, 0x096a, 0x0c8b, 0x0fab, 0x12c8, 0x15e2,
   0x18f8, 0x1c0b, 0x1f19, 0x2223, 0x2528, 0x2826, 0x2b1f, 0x2e11,
   0x30fb, 0x33de, 0x36ba, 0x398c, 0x3c56, 0x3f17, 0x41ce, 0x447a,
   0x471c, 0x49b4, 0x4c3f, 0x4ebf, 0x5133, 0x539b, 0x55f5, 0x5842,
   0x5a82, 0x5cb4, 0x5ed7, 0x60ec, 0x62f2, 0x64e8, 0x66cf, 0x68a6,
   0x6a6d, 0x6c24, 0x6dca, 0x6f5f, 0x70e2, 0x7255, 0x73b5, 0x7504,
   0x7641, 0x776c, 0x7884, 0x798a, 0x7a7d, 0x7b5d, 0x7c29, 0x7ce3,
   0x7d8a, 0x7e1d, 0x7e9d, 0x7f09, 0x7f62, 0x7fa7, 0x7fd8, 0x7ff6,
   0x7fff, 0x7ff6, 0x7fd8, 0x7fa7, 0x7f62, 0x7f09, 0x7e9d, 0x7e1d,
   0x7d8a, 0x7ce3, 0x7c29, 0x7b5d, 0x7a7d, 0x798a, 0x7884, 0x776c,
   0x7641, 0x7504, 0x73b5, 0x7255, 0x70e2, 0x6f5f, 0x6dca, 0x6c24,
   0x6a6d, 0x68a6, 0x66cf, 0x64e8, 0x62f2, 0x60ec, 0x5ed7, 0x5cb4,
   0x5a82, 0x5842, 0x55f5, 0x539b, 0x5133, 0x4ebf, 0x4c3f, 0x49b4,
   0x471c, 0x447a, 0x41ce, 0x3f17, 0x3c56, 0x398c, 0x36ba, 0x33de,
   0x30fb, 0x2e11, 0x2b1f, 0x2826, 0x2528, 0x2223, 0x1f19, 0x1c0b,
   0x18f8, 0x15e2, 0x12c8, 0x0fab, 0x0c8b, 0x096a, 0x0647, 0x0324,
   0x0000, 0xfcdc, 0xf9b9, 0xf696, 0xf375, 0xf055, 0xed38, 0xea1e,
   0xe708, 0xe3f5, 0xe0e7, 0xdddd, 0xdad8, 0xd7da, 0xd4e1, 0xd1ef,
   0xcf05, 0xcc22, 0xc946, 0xc674, 0xc3aa, 0xc0e9, 0xbe32, 0xbb86,
   0xb8e4, 0xb64c, 0xb3c1, 0xb141, 0xaecd, 0xac65, 0xaa0b, 0xa7be,
   0xa57e, 0xa34c, 0xa129, 0x9f14, 0x9d0e, 0x9b18, 0x9931, 0x975a,
   0x9593, 0x93dc, 0x9236, 0x90a1, 0x8f1e, 0x8dab, 0x8c4b, 0x8afc,
   0x89bf, 0x8894, 0x877c, 0x8676, 0x8583, 0x84a3, 0x83d7, 0x831d,
   0x8276, 0x81e3, 0x8163, 0x80f7, 0x809e, 0x8059, 0x8028, 0x800a,
   0x8000, 0x800a, 0x8028, 0x8059, 0x809e, 0x80f7, 0x8163, 0x81e3,
   0x8276, 0x831d, 0x83d7, 0x84a3, 0x8583, 0x8676, 0x877c, 0x8894,
   0x89bf, 0x8afc, 0x8c4b, 0x8dab, 0x8f1e, 0x90a1, 0x9236, 0x93dc,
   0x9593, 0x975a, 0x9931, 0x9b18, 0x9d0e, 0x9f14, 0xa129, 0xa34c,
   0xa57e, 0xa7be, 0xaa0b, 0xac65, 0xaecd, 0xb141, 0xb3c1, 0xb64c,
   0xb8e4, 0xbb86, 0xbe32, 0xc0e9, 0xc3aa, 0xc674, 0xc946, 0xcc22,
   0xcf05, 0xd1ef, 0xd4e1, 0xd7da, 0xdad8, 0xdddd, 0xe0e7, 0xe3f5,
   0xe708, 0xea1e, 0xed38, 0xf055, 0xf375, 0xf696, 0xf9b9, 0xfcdc,
};

/**
 * @brief I2S Transmit buffer
 */
static uint16_t i2s_tx_buf[I2S_BUFF_SIZE];

/**
 * @brief I2S Protocol config struct
 */
static const I2SConfig i2scfg = {
  i2s_tx_buf,
  NULL,
  I2S_BUFF_SIZE,
  NULL,
  0,
  16
};

void ht_audio_Init(void){
    palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(5));
    palSetPadMode(GPIOB, 10, PAL_MODE_ALTERNATE(5));
    palSetPadMode(GPIOC, 3 , PAL_MODE_ALTERNATE(5));
    i2sStart(&I2SD2, &i2scfg);
}

void ht_audio_Zero(void){
    uint16_t i;
    for(i=0;i<I2S_BUFF_SIZE;i++){
        i2s_tx_buf[i] = 0x0000;
    }
}

void ht_audio_Table(void){
    uint16_t i;
    for(i=0;i<I2S_BUFF_SIZE;i++){
        i2s_tx_buf[i] = squared_table[i];
    }
}

void ht_audio_Half(void){
    uint16_t half_size = (I2S_BUFF_SIZE/2)-1;
    uint16_t i;

    for(i=0;i<half_size+1;i++){
        i2s_tx_buf[i]           = (uint16_t)   32767*sin(M_PI*((double)i/(double)half_size));
        i2s_tx_buf[half_size+i] = (uint16_t)32767*(2-sin(M_PI*((double)i/(double)half_size)));
    }
}

void ht_audio_Sine(double freq, uint16_t ampl){
    uint16_t i;
    for(i=0;i<I2S_BUFF_SIZE;i++){
        i2s_tx_buf[i] = ampl*(DEFAULT_AMPLI*sin((double) freq*i*2*M_PI/I2S_BUFF_SIZE));
    }
}

void ht_audio_Test(uint8_t mode){
    switch(mode){
        case ZERO_MODE: ht_audio_Zero(); break;
        case TABLE_MODE: ht_audio_Table(); break;
        case HALF_MODE: ht_audio_Half(); break;
        case SINE_MODE: ht_audio_Sine(1,1000); break;
    }

    ht_audio_Play(1);
}

void ht_audio_Play(uint8_t duration){
    i2sStartExchange(&I2SD2);
    chThdSleepMilliseconds(duration*1000);
    i2sStopExchange(&I2SD2);
}
/** @} */

/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    driver.c
 * @brief   Global Driver Call code.
 *
 * @addtogroup Global
 * @{
 */

#include "ch.h"
#include "hal.h"

#include "chprintf.h"

#include "drv_exti.h"
#include "drv_audio.h"
#include "drv_led.h"
#include "drv_mmc.h"
#include "drv_serial.h"

#include "../driver.h"

extern uint16_t sine_sample[I2S_BUFF_SIZE];
extern uint8_t play_duration;
extern I2SConfig i2scfg;

/**
 * @brief Constant to Add for signal compensation
 */

static const double waveConst = 0;

#if I2S_ADJ_SIZE
/**
 * @brief Find Length of one cycle wave
 * @param[in] FR Desired frequency
 * @param[in] AMP Desired amplitude
 * @return Array Length
 */
static uint16_t onewavelen(double FR,int AMP){
    double x,y;

    uint8_t neg_a = 0,neg_b = 0;
    uint8_t phase = 0;
    uint8_t stop = 0;
    uint16_t sample;

    uint16_t i = 1;

    while(stop==0){
        x = (double) i / (double) SAMPLING_RATE;
        y = sin(2.0 * 3.14159 * FR * x) + waveConst;
        sample = (uint16_t) AMP * 0.2 * y;

        i++;

        if(sample == 2000){ phase++;}
        else if(sample > 2000){ neg_b = 0;	}
        else if(sample < 2000){ neg_b = 1;	}

        if(neg_b != neg_a){
            phase=phase+1;
            if(phase==2){ ;stop=1;	}
            neg_a = neg_b;
        }
        else if(neg_b == neg_a){ neg_a = neg_b; }

        if(i==I2S_BUFF_SIZE){ stop=1; }
    };

    return i;
}
#endif

void system_init(void){
	halInit();
	chSysInit();  

    mmc_start();
    mmc_test();

    shell_start();

    indicator_start();
    led_start();
    exti_start();

    chprintf((BaseSequentialStream *)&SD1,"SYSTEM BOOT COMPLETE\n");
}

void driver_init(void){
    audio_start();
}

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP) //Amplitudo
{
    double x, y;
	uint16_t sample;

#if I2S_ADJ_SIZE
    uint16_t waveone,wavenum,wavelen;

    waveone = onewavelen(FR,AMP);
    wavenum = (uint16_t) I2S_BUFF_SIZE/waveone;
    wavelen = wavenum * waveone;
#endif

	uint16_t i = 1;
	sine_sample[0] = AMP * 0.2;

	play_duration = DUR;

    for(i=1;i<I2S_BUFF_SIZE;i++){
        x = (double) i / (double) SAMPLING_RATE;
        y = sin(2.0 * 3.14159 * FR * x) + waveConst;

#if ZERO_TEST
        sample = (uint16_t) 0;
#else
        sample = (uint16_t) AMP * 0.2 * ;
#endif

        sine_sample[i] = sample;
	};

#if I2S_ADJ_SIZE
    i2scfg.size = wavelen;
#endif
}

void play_wave(void){
    wave_test();
}

void system_loop(void){
    shell_term();
	chThdSleepMilliseconds(100);
}
/** @} */

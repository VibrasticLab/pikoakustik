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

extern uint16_t sine_sample[I2S_BUF_SIZE];
extern uint8_t play_duration;
extern I2SConfig i2scfg;

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
        y = sin(2.0 * 3.14159 * FR * x) + 1;
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

        if(i==NUM_SAMPLES){	stop=1;	}
    };

    return i;
}

void system_init(void){
	halInit();
	chSysInit();  

    exti_start();
    indicator_start();

    shell_start();

    mmc_start();
    mmc_test();

    led_start();

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
	double x,y;

    uint16_t waveone,wavenum,wavelen;
	uint16_t sample;

    waveone = onewavelen(FR,AMP);
    wavenum = (uint16_t) NUM_SAMPLES/waveone;
    wavelen = NUM_CHANNELS * wavenum * waveone;

	uint16_t i = 1;
	sine_sample[0] = AMP * 0.2;

	play_duration = DUR;

    for(i=1;i<I2S_BUF_SIZE;i++){
		x = (double) i / (double) SAMPLING_RATE;
		y = sin(2.0 * 3.14159 * FR * x) + 1;
        sample = (uint16_t) AMP * 0.2 * y;

		sine_sample[i] = sample;
        if(NUM_CHANNELS==2){ sine_sample[i+1] = sample; }
	};

    i2scfg.size = wavelen;
}

void play_wave(void){
    wave_test();
}

void system_loop(void){
    shell_term();
	chThdSleepMilliseconds(100);
}
/** @} */

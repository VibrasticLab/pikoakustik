#include <math.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"

#include "../driver.h"
#include "drv_audio.h"

uint16_t sine_sample[I2S_BUF_SIZE];
uint8_t play_duration;

I2SConfig i2scfg = {
  sine_sample,
  NULL,
  NUM_SAMPLES, // should be buffer size and size_t are big enough on gcc
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

void audio_test(uint8_t n_ampl, uint8_t n_freq){
    int v_ampl=0;
    double v_freq=0;

    switch(n_freq){
        case 0: v_freq = 8000;break;
        case 1: v_freq = 6000;break;
        case 2: v_freq = 4000;break;
        case 3: v_freq = 2000;break;
        case 4: v_freq = 1000;break;
    }

    switch(n_ampl){
        case 0: v_ampl = 8000;break;
        case 1: v_ampl = 6000;break;
        case 2: v_ampl = 4000;break;
        case 3: v_ampl = 2000;break;
        case 4: v_ampl = 1000;break;
    }

    chprintf((BaseSequentialStream *)&SD1,"Audio Test (Uncalibrated)\n");
    chprintf((BaseSequentialStream *)&SD1,"Freq: %4i and Ampli: %4i\n",(int)v_freq,v_ampl);

    sample_prep(v_freq,1,v_ampl);
}

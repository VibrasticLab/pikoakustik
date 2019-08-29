#include <math.h>

#include "ch.h"
#include "hal.h"

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

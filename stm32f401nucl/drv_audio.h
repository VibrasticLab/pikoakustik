#ifndef DRV_AUDIO_H
#define DRV_AUDIO_H

#define NUM_CHANNELS    1
#define NUM_SAMPLES     512
#define I2S_BUF_SIZE    NUM_SAMPLES*NUM_CHANNELS

void wave_test(void);
void audio_start(void);

#endif // DRV_AUDIO_H

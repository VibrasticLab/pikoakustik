#include <alsa/asoundlib.h>

#include "../driver.h"

#define NUM_CHANNELS    1
#define NUM_SAMPLES     1024
#define I2S_BUF_SIZE    NUM_SAMPLES*NUM_CHANNELS

uint16_t sine_sample[I2S_BUF_SIZE];
uint16_t wavelen;

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
   //do nothing on this
}

void driver_init(void){
  //do nothing on this
}

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP) //Amplitudo
{
	(void) DUR;
  	double x,y;

    uint16_t waveone,wavenum;
	uint16_t sample;

    waveone = onewavelen(FR,AMP);
    wavenum = (uint16_t) NUM_SAMPLES/waveone;
    wavelen = NUM_CHANNELS * wavenum * waveone;

	uint16_t i = 1;
	sine_sample[0] = AMP * 0.2;

	for(i=1;i<I2S_BUF_SIZE;i++){
		x = (double) i / (double) SAMPLING_RATE;
		y = sin(2.0 * 3.14159 * FR * x) + 1;
        sample = (uint16_t) AMP * 0.2 * y;

		sine_sample[i] = sample;
        if(NUM_CHANNELS==2){ sine_sample[i+1] = sample; }
	};
}

void play_wave(void){
	for(uint16_t i=0;i<wavelen;i++){ printf("%4i,",sine_sample[i]); }
}

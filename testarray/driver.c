#include <alsa/asoundlib.h>

#include "../driver.h"

#define NUM_SAMPLES     SAMPLING_RATE

uint16_t sine[NUM_SAMPLES];
uint16_t onesample;

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

	uint8_t neg_a,neg_b;
	uint8_t phase = 0;
	uint8_t stop = 0;
	uint16_t sample;

	uint16_t i = 1;
	sine[0] = 2000;

	while(stop==0){
		x = (double) i / (double) SAMPLING_RATE;
		y = sin(2.0 * 3.14159 * FR * x) + 1;
		sample = 2000 * y;

		sine[i] = sample;

		i++;

		if(sample == 2000){ phase++;}
		else if(sample > 2000){ neg_b = 0;	}
		else if(sample < 2000){ neg_b = 1;	}

		if(neg_b != neg_a){
			phase=phase+1;
			if(phase==2){ onesample = i;stop=1;	}
			neg_a = neg_b;
		}
		else if(neg_b == neg_a){ neg_a = neg_b; }

		if(i==NUM_SAMPLES){	stop=1;	}
	};
}

void play_wave(void){
	//only print sine wave
	for(uint16_t i=0;i<onesample;i++){	printf("%4i, ",sine[i]); }
}

#include <alsa/asoundlib.h>

#include "../driver.h"

#define NUM_SAMPLES     SAMPLING_RATE
#undef DEBUG_PRINT

uint16_t sine[NUM_SAMPLES];
uint16_t sample;
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
	uint16_t i = 1;

	sine[0] = 0;

	while(stop==0){
		x = (double) i / (double) SAMPLING_RATE;
		y = sin(2.0 * 3.14159 * FR * x) + 1;
		sample = 2000 * y;

		sine[i] = sample;
#ifdef DEBUG_PRINT
		printf("%4i ",sample);
#endif
		i++;

		if(sample == 2000){ phase++;}
		else if(sample > 2000){ neg_b = 0;	}
		else if(sample < 2000){ neg_b = 1;	}

		if(neg_b != neg_a){
#ifdef DEBUG_PRINT
			printf("negA %i negB %i ",neg_a,neg_b);
			printf("changes detected\n");
#endif
			phase=phase+1;
			if(phase==2){
				onesample = i;
				stop=1;
			}
			neg_a = neg_b;
		}
		else if(neg_b == neg_a){
#ifdef DEBUG_PRINT
			printf("negA %i negB %i\n",neg_a,neg_b);
#endif
			neg_a = neg_b;
		}

		if(i==NUM_SAMPLES){
			stop=1;
#ifdef DEBUG_PRINT
			printf("Max array reached\n");
#endif
		}
	};
#ifdef DEBUG_PRINT
	printf("phase %i stop %i\n",phase,stop);
#endif
}

void play_wave(void){
#ifndef DEBUG_PRINT
	for(uint16_t i=0,i<onesample;i++){
		printf("%4i ",sine[i]);
	}
#endif
}

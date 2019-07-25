#include <alsa/asoundlib.h>

#include "../driver.h"

#define NUM_SAMPLES     SAMPLING_RATE

uint16_t sine[NUM_SAMPLES];

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

	uint8_t phiphase = 0;
	uint8_t phistop = 0;
	uint16_t i = 1;

	sine[0] = 0;

	do{
		x = (double) i / (double) SAMPLING_RATE;
		y = sin(2.0 * 3.14159 * FR * x);
		printf("%5.4f\n",y);
		i++;

		if((y < 0.01) && (y > -0.01)){
			phiphase++;
			if(phiphase==2){
				phistop=1;
			}
		}
	}while(phistop==0);
}

void play_wave(void){
  // do nothing
}

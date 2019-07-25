#include "ch.h"
#include "hal.h"

#include "../driver.h"

#define NUM_CHANNELS    2
#define NUM_SAMPLES     512
#define I2S_BUF_SIZE    NUM_SAMPLES*NUM_CHANNELS

static uint16_t sine_sample[I2S_BUF_SIZE];
static uint8_t play_duration;

static void i2scallback(I2SDriver *i2sp, size_t offset, size_t n);

I2SConfig i2scfg = {
  sine_sample,
  NULL,
  NUM_SAMPLES, // should be buffer size and size_t are big enough on gcc
  i2scallback,
  0,
  16
};

static void i2scallback(I2SDriver *i2sp, size_t offset, size_t n) {
  (void)i2sp;
  (void)offset;
  (void)n;

  palSetPad(GPIOG,13);
}

static THD_WORKING_AREA(waLed1, 128);
static THD_FUNCTION(thdLed1, arg) {

  (void)arg;
  chRegSetThreadName("led1");
  while (true) {
    palClearPad(GPIOG, 14);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOG, 14);
    chThdSleepMilliseconds(500);
  }
}

static void led_start(void){
    palSetPadMode(GPIOG,14,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOG,13,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOG,13);

    chThdCreateStatic(waLed1, sizeof(waLed1),	NORMALPRIO, thdLed1, NULL);
}

void system_init(void){
	halInit();
	chSysInit();

	led_start();
}

void driver_init(void){
    palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(5));
    palSetPadMode(GPIOB, 10, PAL_MODE_ALTERNATE(5));
    palSetPadMode(GPIOC, 3 , PAL_MODE_ALTERNATE(5));
}

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP) //Amplitudo
{
	double x,y;

	uint8_t neg_a,neg_b;
	uint8_t phase = 0;
	uint8_t stop = 0;
	uint16_t sample;

	uint16_t i = 1;
	sine_sample[0] = AMP * 0.2;

	play_duration = DUR;

	while(stop==0){
		x = (double) i / (double) SAMPLING_RATE;
		y = sin(2.0 * 3.14159 * FR * x) + 1;
		sample = AMP * 0.2 * y;

		sine_sample[i] = sample;
		if(NUM_CHANNELS==2){	sine_sample[i+1] = sample; }

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

	//buffer size
	i2scfg.size = 10*i;
}

void play_wave(void){
	i2sStart(&I2SD2, &i2scfg);
	i2sStartExchange(&I2SD2);

	chThdSleepMilliseconds(play_duration * 100);

	i2sStopExchange(&I2SD2);
	i2sStop(&I2SD2);

	palClearPad(GPIOG,13);
}

void system_loop(void){
	chThdSleepMilliseconds(100);
}

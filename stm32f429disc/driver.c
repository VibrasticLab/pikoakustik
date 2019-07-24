#include "ch.h"
#include "hal.h"

#include "../driver.h"

#define NUM_CHANNELS    2
#define NUM_SAMPLES     SAMPLING_RATE
#define I2S_BUF_SIZE    NUM_SAMPLES*NUM_CHANNELS

static uint16_t sine_sample[I2S_BUF_SIZE];
static uint8_t play_duration;

static void i2scallback(I2SDriver *i2sp, size_t offset, size_t n);

I2SConfig i2scfg = {
  sine_sample,
  NULL,
  256, // should be buffer size
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

	play_duration = DUR;

	for (int i = 0; i < NUM_CHANNELS * NUM_SAMPLES; i+=NUM_CHANNELS){
		x = (double) i / (double) SAMPLING_RATE;
		y = sin(2.0 * 3.14159 * FR * x);
		sine_sample[i] = AMP * 0.3 * y; // 3000 as max 4096 and 10000 as scaling =>> 3000/10000
		sine_sample[i+1] = sine_sample[i];
	}
}

void play_wave(void){
	i2sStart(&I2SD2, &i2scfg);
	i2sStartExchange(&I2SD2);

	chThdSleepMilliseconds(play_duration * 500);

	i2sStopExchange(&I2SD2);
	i2sStop(&I2SD2);

	palClearPad(GPIOG,13);
}

void system_loop(void){
	chThdSleepMilliseconds(100);
}

#include "ch.h"
#include "hal.h"

#include "../driver.h"

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

void driver_init(int SMPR){}

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP) //Amplitudo
{}

void play_wave(void){}

void system_loop(void){
	chThdSleepMilliseconds(100);
}
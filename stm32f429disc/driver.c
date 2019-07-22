#include "ch.h"
#include "hal.h"

#include "../driver.h"

#define I2S_BUF_SIZE 256
static uint16_t i2s_tx_buf[I2S_BUF_SIZE];

static void i2scallback(I2SDriver *i2sp, size_t offset, size_t n);

I2SConfig i2scfg = {
  i2s_tx_buf,
  NULL,
  I2S_BUF_SIZE,
  i2scallback,
  0,
  16
};

static void i2scallback(I2SDriver *i2sp, size_t offset, size_t n) {
  (void)i2sp;
  (void)offset;
  (void)n;

  palTogglePad(GPIOG,13);
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

void driver_init(int SMPR){
	palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(5));
    palSetPadMode(GPIOB, 10, PAL_MODE_ALTERNATE(5));
    palSetPadMode(GPIOC, 3 , PAL_MODE_ALTERNATE(5));
}

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP) //Amplitudo
{}

void play_wave(void){}

void system_loop(void){
	chThdSleepMilliseconds(100);
}

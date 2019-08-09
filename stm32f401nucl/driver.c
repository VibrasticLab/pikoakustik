#include "ch.h"
#include "hal.h"

#include "../driver.h"

//================================================================================

#define NUM_CHANNELS    2
#define NUM_SAMPLES     512
#define I2S_BUF_SIZE    NUM_SAMPLES*NUM_CHANNELS

static uint16_t sine_sample[I2S_BUF_SIZE];
static uint8_t play_duration;

static I2SConfig i2scfg = {
  sine_sample,
  NULL,
  NUM_SAMPLES, // should be buffer size and size_t are big enough on gcc
  NULL,
  0,
  16
};

//================================================================================

static THD_WORKING_AREA(waLed1, 128);
static THD_FUNCTION(thdLed1, arg) {

  (void)arg;
  chRegSetThreadName("led1");
  while (true) {
    palClearPad(GPIOA, 5);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOA, 5);
    chThdSleepMilliseconds(500);
  }
}

static void led_start(void){
    palSetPadMode(GPIOA,5,PAL_MODE_OUTPUT_PUSHPULL);
    chThdCreateStatic(waLed1, sizeof(waLed1),	NORMALPRIO, thdLed1, NULL);
}

//================================================================================

static u_int8_t testWave=0;

static THD_WORKING_AREA(waTestWave, 128);
static THD_FUNCTION(thdTestWave, arg) {

  (void)arg;
  chRegSetThreadName("test wave");
  while (true) {
      if(testWave==1){
          play_wave();
          testWave=0;
      }
      chThdSleepMilliseconds(100);
  }
}

static void extTestWave(EXTDriver *extp, expchannel_t channel) {

  (void)extp;
  (void)channel;

  testWave=1;
}

static const EXTConfig extcfg = {
  {
    {EXT_CH_MODE_DISABLED, NULL}, //0	  
    {EXT_CH_MODE_DISABLED, NULL}, //1
    {EXT_CH_MODE_DISABLED, NULL}, //2
    {EXT_CH_MODE_DISABLED, NULL}, //3
    {EXT_CH_MODE_DISABLED, NULL}, //4
    {EXT_CH_MODE_DISABLED, NULL}, //5 
    {EXT_CH_MODE_DISABLED, NULL}, //6 
    {EXT_CH_MODE_DISABLED, NULL}, //7
    {EXT_CH_MODE_DISABLED, NULL}, //8
    {EXT_CH_MODE_DISABLED, NULL}, //9
    {EXT_CH_MODE_DISABLED, NULL}, //10
    {EXT_CH_MODE_DISABLED, NULL}, //11 
    {EXT_CH_MODE_DISABLED, NULL}, //12 
    {EXT_CH_MODE_RISING_EDGE | EXT_MODE_GPIOC, extTestWave}, //13 
    {EXT_CH_MODE_DISABLED, NULL}, //14 
    {EXT_CH_MODE_DISABLED, NULL}, //15 
    {EXT_CH_MODE_DISABLED, NULL}, //16 
    {EXT_CH_MODE_DISABLED, NULL}, //17 
    {EXT_CH_MODE_DISABLED, NULL}, //18 
    {EXT_CH_MODE_DISABLED, NULL}, //19 
    {EXT_CH_MODE_DISABLED, NULL}, //20 
    {EXT_CH_MODE_DISABLED, NULL}, //21
    {EXT_CH_MODE_DISABLED, NULL}  //22
  }
};

static void exti_start(void){
    palSetPadMode(GPIOC, 13, PAL_MODE_INPUT_PULLUP);
    extStart(&EXTD1, &extcfg);
    extChannelEnable(&EXTD1, 13);
    chThdCreateStatic(waTestWave, sizeof(waTestWave),	NORMALPRIO, thdTestWave, NULL);
}

//================================================================================

#define LED_TRUE    0 //PA.0
#define LED_FALSE   1 //PA.1
#define LED_ANSA    4 //PA.4
#define LED_ANSB    0 //PB.0

#define LED_AMPL    2 //PA.2
#define LED_FREQ    3 //PA.3

#define LED_M1      3 //PB.3
#define LED_M2      5 //PB.5
#define LED_M3      4 //PB.4
#define LED_M4      13 //PB.13
#define LED_M5      14 //PB.14

static void indicator_m_off(void){
    palClearPad(GPIOA,LED_AMPL);
    palClearPad(GPIOA,LED_FREQ);

    palSetPad(GPIOB,LED_M1);
    palSetPad(GPIOB,LED_M2);
    palSetPad(GPIOB,LED_M3);
    palSetPad(GPIOB,LED_M4);
    palSetPad(GPIOB,LED_M5);
}

static void indicator_m_on(u_int8_t lednum){
    switch(lednum){
        case 1: palClearPad(GPIOB,LED_M1);break;
        case 2: palClearPad(GPIOB,LED_M2);break;
        case 3: palClearPad(GPIOB,LED_M3);break;
        case 4: palClearPad(GPIOB,LED_M4);break;
        case 5: palClearPad(GPIOB,LED_M5);break;
    }
}

static THD_WORKING_AREA(waIndicator, 128);
static THD_FUNCTION(thdIndicator, arg) {

  (void)arg;
  chRegSetThreadName("indicator run");

  indicator_m_off();

  while (true) {
      palSetPad(GPIOA,LED_AMPL);
      indicator_m_on(1);
      chThdSleepMilliseconds(100);
  }
}

static THD_WORKING_AREA(waTestLed, 128);
static THD_FUNCTION(thdTestLed, arg) {

  (void)arg;
  chRegSetThreadName("test led");

  palSetPad(GPIOA,LED_TRUE);
  palClearPad(GPIOA,LED_FALSE);
  palClearPad(GPIOA,LED_ANSA);
  palSetPad(GPIOB,LED_ANSB);

  while (true) {
      palTogglePad(GPIOA,LED_TRUE);
      palTogglePad(GPIOA,LED_FALSE);
      palTogglePad(GPIOA,LED_ANSA);
      palTogglePad(GPIOB,LED_ANSB);

      chThdSleepMilliseconds(500);
  }
}

static void indicator_start(void){
    palSetPadMode(GPIOA,LED_TRUE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_FALSE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_ANSA,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_ANSB,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPadMode(GPIOA,LED_AMPL,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_FREQ,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPadMode(GPIOB,LED_M1,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M2,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M3,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M4,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M5,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPad(GPIOA,LED_AMPL);
    indicator_m_on(1);

    //chThdCreateStatic(waIndicator, sizeof(waIndicator),	NORMALPRIO, thdIndicator, NULL);
    chThdCreateStatic(waTestLed, sizeof(waTestLed),	NORMALPRIO, thdTestLed, NULL);
}

//================================================================================

// ============================= Platform Calling ===================

void system_init(void){
	halInit();
	chSysInit();

    exti_start();
    indicator_start();
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

	uint8_t neg_a = 0,neg_b = 0;
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
}

void system_loop(void){
	chThdSleepMilliseconds(100);
}
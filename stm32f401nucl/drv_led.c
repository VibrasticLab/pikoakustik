#include "ch.h"
#include "hal.h"

#include "drv_led.h"

uint16_t led_delay=50;
static uint8_t idx_ampl,idx_freq;

uint8_t stt_LedAns = 1;
uint8_t stt_BtnAns = 0;

static THD_WORKING_AREA(waLed1, 128);
static THD_FUNCTION(thdLed1, arg) {

  (void)arg;
  chRegSetThreadName("led1");
  while (true) {
    palTogglePad(GPIOA, 5);
    chThdSleepMilliseconds(led_delay);
  }
}

static void indicator_m_off(void){
    palClearPad(GPIOA,LED_AMPL);
    palClearPad(GPIOA,LED_FREQ);

    palSetPad(GPIOB,LED_M1);
    palSetPad(GPIOB,LED_M2);
    palSetPad(GPIOB,LED_M3);
    palSetPad(GPIOB,LED_M4);
    palSetPad(GPIOB,LED_M5);
}

static void indicator_m_on(uint8_t lednum){
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
      indicator_m_off();
      palSetPad(GPIOA,LED_FREQ);
      indicator_m_on(idx_freq);
      chThdSleepMicroseconds(100);

      indicator_m_off();
      palSetPad(GPIOA,LED_AMPL);
      indicator_m_on(idx_ampl);
      chThdSleepMicroseconds(100);

      if(stt_BtnAns != 0){
          if(stt_BtnAns == stt_LedAns){ palClearPad(GPIOA,LED_TRUE); }
          else{ palClearPad(GPIOA,LED_FALSE); }
      }
  }
}

static THD_WORKING_AREA(waTestLed, 256);
static THD_FUNCTION(thdTestLed, arg) {

  (void)arg;
  chRegSetThreadName("test led");

  while (true) {
      led_test();

      if(stt_BtnAns == 0){
          if(stt_LedAns == 1){
              palClearPad(GPIOA,LED_ANSA);
              palSetPad(GPIOB,LED_ANSB);
              stt_LedAns = 2;
          }
          else{
              palSetPad(GPIOA,LED_ANSA);
              palClearPad(GPIOB,LED_ANSB);
              stt_LedAns = 1;
          }
      }
      else{
          stt_BtnAns = 0;
          palSetPad(GPIOA,LED_TRUE);
          palSetPad(GPIOA,LED_FALSE);
      }

      chThdSleepMilliseconds(1000);
  }
}

void led_test(void){
    idx_ampl++;
    if(idx_ampl==6){
        idx_ampl = 1;
        idx_freq++;

        if(idx_freq==6){
            idx_ampl = 1;
            idx_freq = 1;
        }
    }
}

void led_start(void){
    palSetPadMode(GPIOA,5,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOA,5);

    chThdCreateStatic(waLed1, sizeof(waLed1),	NORMALPRIO, thdLed1, NULL);
}

void indicator_start(void){
    palSetPadMode(GPIOA,LED_TRUE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_FALSE,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_ANSA,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_ANSB,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPad(GPIOA,LED_TRUE);
    palSetPad(GPIOA,LED_FALSE);
    palSetPad(GPIOA,LED_ANSA);
    palSetPad(GPIOB,LED_ANSB);

    palSetPadMode(GPIOA,LED_AMPL,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,LED_FREQ,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPadMode(GPIOB,LED_M1,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M2,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M3,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M4,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LED_M5,PAL_MODE_OUTPUT_PUSHPULL);

    idx_freq = 1;

    chThdCreateStatic(waIndicator, sizeof(waIndicator),	NORMALPRIO, thdIndicator, NULL);
    chThdCreateStatic(waTestLed, sizeof(waTestLed),	NORMALPRIO, thdTestLed, NULL);
}


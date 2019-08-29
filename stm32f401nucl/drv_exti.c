#include "ch.h"
#include "hal.h"

#include "drv_audio.h"
#include "drv_exti.h"

static uint8_t testWave=0;

static THD_WORKING_AREA(waTestWave, 1024);
static THD_FUNCTION(thdTestWave, arg) {

  (void)arg;
  chRegSetThreadName("test wave");
  while (true) {
      if(testWave==1){
          wave_test();
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

void exti_start(void){
    palSetPadMode(GPIOC, 13, PAL_MODE_INPUT_PULLUP);
    extStart(&EXTD1, &extcfg);
    extChannelEnable(&EXTD1, 13);
    chThdCreateStatic(waTestWave, sizeof(waTestWave),	NORMALPRIO, thdTestWave, NULL);
}

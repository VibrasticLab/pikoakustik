#include <stdlib.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#include "drv_serial.h"
#include "drv_audio.h"

extern int ampl_arr[5];
extern double freq_arr[5];


static thread_t *shelltp = NULL;

//===============================================================================

static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {

  if (argc != 2) {
    chprintf(chp, "Usage: test <frequency> <amplitudo>\r\n");
    return;
  }

  audio_test(atoi(argv[0]),atoi(argv[1]));
}

static void cmd_list(BaseSequentialStream *chp, int argc, char *argv[]) {

  (void) argv;
  if (argc > 0) {
    chprintf(chp, "Usage: list \r\n");
    return;
  }

  chprintf(chp, "list available wave level\r\n");
  chprintf(chp, "Frequency  Amplitudo\r\n");
  chprintf(chp, "--------------------\r\n");
  for(uint8_t i=0;i<5;i++){
      chprintf(chp, "  %4i      %4i\r\n",(int)freq_arr[i],ampl_arr[i]);
  }
  chprintf(chp, "--------------------\r\n");

}

//===============================================================================

static const ShellCommand commands[] = {
    {"list", cmd_list},
    {"test", cmd_test},
    {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
  (BaseSequentialStream *)&SD1,
  commands
};

//===============================================================================

void shell_start(void){
    palSetPadMode(GPIOA, 9,PAL_MODE_ALTERNATE(7) | PAL_STM32_OSPEED_HIGHEST); //TX
    palSetPadMode(GPIOA,10,PAL_MODE_ALTERNATE(7) | PAL_STM32_OSPEED_HIGHEST); //RX
    sdStart(&SD1,NULL);
    shellInit();
}

void shell_term(void){
    if (!shelltp) {
        shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);
    }
    else {
      if (chThdTerminatedX(shelltp)) {
        chThdRelease(shelltp);
        shelltp = NULL;
      }
    }
}

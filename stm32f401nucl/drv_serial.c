/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    drv_serial.c
 * @brief   Serial Console code.
 *
 * @addtogroup Console
 * @{
 */

#include <stdlib.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#include "drv_serial.h"
#include "drv_audio.h"

extern int ampl_arr[5];
extern double freq_arr[5];

/**
 * @brief Shell Console pointer
 */
static thread_t *shelltp = NULL;

/**
 * @brief Test command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {

  if (argc != 2) {
    chprintf(chp, "Usage: test <frequency> <amplitudo>\r\n");
    return;
  }

  audio_test(atoi(argv[0]),atoi(argv[1]));
}

/**
 * @brief List Availabel Ampli/freq Level callback
 * @details Enumerated and not called directly by any normal thread
 */
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

/**
 * @brief Shell command and it's callback enumeration
 * @details Extending from internal shell's callback
 */
static const ShellCommand commands[] = {
    {"list", cmd_list},
    {"test", cmd_test},
    {NULL, NULL}
};

/**
 * @brief Shell Driver Config
 * @details Serial Interface using UART0 (SD1)
 */
static const ShellConfig shell_cfg1 = {
  (BaseSequentialStream *)&SD1,
  commands
};

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
/** @} */

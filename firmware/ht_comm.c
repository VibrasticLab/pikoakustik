/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    ht_comm.c
 * @brief   Shell Commands code.
 *
 * @addtogroup Console
 * @{
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"

#include "ht_console.h"
#include "ht_audio.h"
#include "ht_mmc.h"

/**
 * @brief Shell Console pointer
 */
static thread_t *shelltp = NULL;

/**
 * @brief Test command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: test\r\n");return;}

    chprintf(chp,"Serial Console at %d & buffer size %d bit\r\n",SERIAL_DEFAULT_BITRATE,SERIAL_BUFFERS_SIZE);
}

/**
 * @brief Audio Zero command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_zero(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: zero\r\n");return;}

    chprintf(chp,"Test Audio: Sine Zero\r\n");
    ht_audio_Tone(1,0);
    ht_audio_Play(TEST_DURATION);
    chprintf(chp,"Finished\r\n");
}

/**
 * @brief Audio Maximum command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_max(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: max\r\n");return;}

    chprintf(chp,"Test Audio: Sine Max\r\n");

    chprintf(chp,"--------------------------\r\n");
    chprintf(chp,"DONT PLAY MAX ON HEADPHONE !!!\r\n");
    chprintf(chp,"OR YOUR EAR WILL DAMAGED !!!\r\n");
    chprintf(chp,"--------------------------\r\n");

    chprintf(chp,"Play Max in 3s !!!\r\n");
    chThdSleepMilliseconds(3000);

    ht_audio_Tone(1.25,1);
    ht_audio_Play(TEST_DURATION);
    chprintf(chp,"Finished\r\n");
}

/**
 * @brief Audio Minimum command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_min(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: min\r\n");return;}

    chprintf(chp,"Test Audio: Sine Min\r\n");
    ht_audio_Tone(1.25,0.0001);
    ht_audio_Play(TEST_DURATION);
    chprintf(chp,"Finished\r\n");
}

/**
 * @brief Audio Play Halving-Formula with Frequency and Amplitude command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_tone(BaseSequentialStream *chp, int argc, char *argv[]) {
    if(argc == 0){
        (void) argv;

        chprintf(chp,"Coba Audio: Tone\r\n");
        ht_audio_Tone(1.25,0.01);
        ht_audio_Play(TEST_DURATION);
        chprintf(chp,"Finished\r\n");
    }
    else if (argc == 2) {
        double vfreq = atof(argv[0]);
        double vampl = atof(argv[1]);

        chprintf(chp,"Coba Tone: Freq:%3.1f Ampl:%3.1f\r\n",vfreq,vampl);
        ht_audio_Tone(vfreq,vampl);
        ht_audio_Play(TEST_DURATION);
        chprintf(chp,"Finished\r\n");
    }
    else if (argc == 3) {
        double vfreq = atof(argv[0]);
        double vampl = atof(argv[1]);
        u_int8_t vdurr = atoi(argv[2]);

        chprintf(chp,"Test Audio: Freq:%3.1f Ampl:%3.1f Durr:%1i\r\n",vfreq,vampl,vdurr);
        ht_audio_Tone(vfreq,vampl);
        ht_audio_Play(vdurr);
        chprintf(chp,"Finished\r\n");
    }
    else{chprintf(chp,"usage: tone | tone <freq> <ampl>\r\n");}
}

static void cmd_lsfile(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: ls\r\n");return;}

    ht_mmc_lsFiles();
}

static void cmd_catfile(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: cat\r\n");return;}

    ht_mmc_catFiles();
}

/**
 * @brief Shell command and it's callback enumeration
 * @details Extending from internal shell's callback
 */
static const ShellCommand commands[] = {
    {"test",cmd_test},
    {"zero",cmd_zero},
    {"tone",cmd_tone},
    {"max",cmd_max},
    {"min",cmd_min},
    {"ls",cmd_lsfile},
    {"cat",cmd_catfile},
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

void ht_comm_Init(void){
    palSetPadMode(GPIOA, 9,PAL_MODE_ALTERNATE(7) | PAL_STM32_OSPEED_HIGHEST); //TX
    palSetPadMode(GPIOA,10,PAL_MODE_ALTERNATE(7) | PAL_STM32_OSPEED_HIGHEST); //RX
    sdStart(&SD1,NULL);

    shellInit();
}

void ht_comm_ReInit(void){
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
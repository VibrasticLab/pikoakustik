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

#include "user_conf.h"
#include "ht_console.h"
#include "ht_audio.h"
#include "ht_mmc.h"

/* USB-CDC pointer object */
extern SerialUSBDriver SDU1;
extern const USBConfig usbcfg;
extern const SerialUSBConfig serusbcfg;

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
    ht_audio_Tone(1.25,0);
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
        ht_audio_Tone(1,2*SMALLEST_DB);
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

/**
 * @brief List available files on MMC and get saves last number
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_lsfile(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: ls\r\n");return;}

    ht_mmc_lsFiles();
}

/**
 * @brief CAT content file on given number suffix
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_catfile(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    uint8_t fnum;

    if(argc==0 || argc>1){chprintf(chp,"usage: cat file_number\r\n");return;}
    fnum = atoi(argv[0]);
    ht_mmc_catFiles(fnum);
}

/**
 * @brief MMC Write Test command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_mmcwrt(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: mmc\r\n");return;}

    ht_mmc_Test();
    chprintf(chp,"MMC R/W Test Finished\r\n\r\n");
}

/**
 * @brief MMC CAT Test command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_mmcat(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: mmcat\r\n");return;}

    ht_mmc_catTest();
    chprintf(chp,"MMC R/W Content look Finished\r\n\r\n");
}

/**
 * @brief MMC Check Test command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_mmchk(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: mmc\r\n");return;}

    ht_mmc_Check();
    chprintf(chp,"MMC R/W Check Finished\r\n\r\n");
}

/**
 * @brief Shell command and it's callback enumeration
 * @details Extending from internal shell's callback
 */
static const ShellCommand commands[] = {
    {"test",cmd_test},
#if USER_AUDIO
    {"zero",cmd_zero},
    {"tone",cmd_tone},
    {"max",cmd_max},
    {"min",cmd_min},
#endif
#if USER_MMC
    {"ls",cmd_lsfile},
    {"cat",cmd_catfile},
    {"mmcwr",cmd_mmcwrt},
    {"mmcat",cmd_mmcat},
    {"mmchk",cmd_mmchk},
#endif
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

/**
 * @brief Shell Driver Config
 * @details Serial Interface using USB1 (SDU1)
 */
static const ShellConfig usbshell_cfg1 = {
  (BaseSequentialStream *)&SDU1,
  commands
};

void ht_comm_Init(void){
    palSetPadMode(GPIOA, 9,PAL_MODE_ALTERNATE(7) | PAL_STM32_OSPEED_HIGHEST); //TX
    palSetPadMode(GPIOA,10,PAL_MODE_ALTERNATE(7) | PAL_STM32_OSPEED_HIGHEST); //RX
    sdStart(&SD1,NULL);

    shellInit();
}

void ht_commUSB_Init(void){
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(500);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

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

void ht_commUSB_ReInit(void){
    if (!shelltp && (SDU1.config->usbp->state == USB_ACTIVE)) {
        shelltp = shellCreate(&usbshell_cfg1, SHELL_WA_SIZE, NORMALPRIO);
    }
    else {
        if (chThdTerminatedX(shelltp)) {
            chThdRelease(shelltp);
            shelltp = NULL;
        }
    }
}

void ht_comm_Msg(char *string){
#if USER_SERIAL_USB
    if(SDU1.config->usbp->state == USB_ACTIVE){
        chprintf((BaseSequentialStream *)&SDU1,string);
    }
#else
    chprintf((BaseSequentialStream *)&SD1,string);
#endif
}

/** @} */

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

/* File related*/
extern uint8_t lastnum;

/*******************************************
 * Serial Command Callback
 *******************************************/

/**
 * @brief Test command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
    uint8_t lrc;

    chprintf(chp,"Serial Console at %d & buffer size %d bit\r\n",SERIAL_DEFAULT_BITRATE,SERIAL_BUFFERS_SIZE);
    chprintf(chp,"Playing Audio Test\r\n");

    if(argc==0){
#if USER_AUDIO
    chprintf(chp,"Test on both Channel\r\n");
    ht_audio_TestBoth();
#else
    chprintf(chp,"Audio features disabled\r\n");
#endif
    }
    else if(argc == 1){
#if USER_AUDIO
        lrc = atoi(argv[0]);
        ht_audio_Tone(1.25,1);

        if(lrc==OUT_LEFT){
            ht_audio_LeftCh();
            chprintf(chp,"Test on Left Channel\r\n");
            ht_audio_Play(TEST_DURATION);
            chThdSleepMilliseconds(200);
            ht_audio_Play(TEST_DURATION);
        }
        else if(lrc==OUT_RIGHT){
            ht_audio_RightCh();
            chprintf(chp,"Test on Right Channel\r\n");
            ht_audio_Play(TEST_DURATION);
            chThdSleepMilliseconds(200);
            ht_audio_Play(TEST_DURATION);
        }
        else{
            chprintf(chp,"Channel option incorrect \r\n");
        }
        ht_audio_DisableCh();
#else
        chprintf(chp,"Audio features disabled\r\n");
#endif
    }
    else{
        chprintf(chp,"usage: test [0|1] \r\n");
        chprintf(chp,"0 -> Left Channel \r\n");
        chprintf(chp,"1 -> Righ Channel \r\n");
        return;
    }
}

/*******************************************/

/**
 * @brief Audio Zero command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_zero(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: zero\r\n");return;}

    chprintf(chp,"Test Audio: Sine Zero\r\n");
    ht_audio_Tone(1,0);
    ht_audio_LeftCh();
    ht_audio_Play(TEST_DURATION);
    ht_audio_DisableCh();
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
    ht_audio_LeftCh();
    ht_audio_Play(TEST_DURATION);
    ht_audio_DisableCh();
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
    ht_audio_LeftCh();
    ht_audio_Play(TEST_DURATION);
    ht_audio_DisableCh();
    chprintf(chp,"Finished\r\n");
}

/**
 * @brief Audio Play with Frequency, Amplitude, Duration command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_tone(BaseSequentialStream *chp, int argc, char *argv[]) {

    if(argc == 0){
        (void) argv;

        chprintf(chp,"Coba Audio: Tone\r\n");
        ht_audio_Tone(1,1);
        ht_audio_LeftCh();
        ht_audio_Play(TEST_DURATION);
        chprintf(chp,"Finished\r\n");
    }
    else if (argc == 2) {
        double vfreq = atof(argv[0]);
        double vampl = atof(argv[1]);

        chprintf(chp,"Coba Tone: Freq:%5.3f Ampl:%5.3f\r\n",vfreq,vampl);
        ht_audio_Tone(vfreq,vampl);
        ht_audio_LeftCh();
        ht_audio_Play(TEST_DURATION);
        chprintf(chp,"Finished\r\n");
    }
    else if (argc == 3) {
        double vfreq = atof(argv[0]);
        double vampl = atof(argv[1]);
        u_int8_t vdurr = atoi(argv[2]);

        chprintf(chp,"Test Audio: Freq:%3.1f Ampl:%3.1f Durr:%1i\r\n",vfreq,vampl,vdurr);
        ht_audio_Tone(vfreq,vampl);
        ht_audio_TestLeft();
        ht_audio_Play(vdurr);
        chprintf(chp,"Finished\r\n");
    }
    else{chprintf(chp,"usage: tone | tone <freq> <ampl>\r\n");}

    ht_audio_DisableCh();
}

/**
 * @brief Audio Play at a frequency and down from highest to lowest amplitude
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_sing(BaseSequentialStream *chp, int argc, char *argv[]) {
    double vampl = 1;
    uint16_t sing_durr = 500;

    if(argc != 1){chprintf(chp,"usage: sing <freq>\r\n");return;}
    double vfreq = atof(argv[0]);

    ht_audio_RightCh();
    while(1){
        chprintf(chp,"Coba Tone: Freq:%5.3f Ampl:%5.3f\r\n",vfreq,vampl);
        ht_audio_Tone(vfreq,vampl);
        ht_audio_Play(sing_durr);
        chThdSleepMilliseconds(500);

        vampl = vampl/2;
        if(vampl<SMALLEST_DB){
            chprintf(chp,"Finished\r\n");
            break;
        }
    }
    ht_audio_DisableCh();
}

/**
 * @brief Test enable the DAC
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_dacon(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;

    if(argc != 0){chprintf(chp,"usage: dacon\r\n");return;}

    palSetPad(AUDIO_IO,AUDIO_L);
    palSetPad(AUDIO_IO,AUDIO_R);
}

/**
 * @brief Test disable the DAC
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_dacoff(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;

    if(argc != 0){chprintf(chp,"usage: dacon\r\n");return;}

    palClearPad(AUDIO_IO,AUDIO_L);
    palClearPad(AUDIO_IO,AUDIO_R);
}

/*******************************************/

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

    ht_mmc_initCheck();
    chprintf(chp,"MMC Checking Finished\r\n\r\n");
}

/*******************************************/

/**
 * @brief IoT Subscribe Test command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_iotsub(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: sub\r\n");return;}

    ht_comm_IoT("sub\r\n");
    chprintf(chp,"IoT subscribe hello/world Finished\r\n\r\n");
}

/**
 * @brief IoT Publish Test command callback
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_iotpub(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: pub\r\n");return;}

    ht_comm_IoT("pub\r\n");
    chprintf(chp,"IoT publish hello/world Finished\r\n\r\n");
}

/**
 * @brief IoT Publish last saved
 * @details Enumerated and not called directly by any normal thread
 */
static void cmd_iotsend(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void) argv;
    if(argc != 0){chprintf(chp,"usage: send\r\n");return;}

    ht_mmc_lsFiles();
    ht_mmc_sendFiles(lastnum);
    ht_comm_IoT("send\r\n");
}

/*******************************************/

/**
 * @brief Shell command and it's callback enumeration
 * @details Extending from internal shell's callback
 */
static const ShellCommand commands[] = {
    {"test",cmd_test},
#if USER_AUDIO
    {"zero",cmd_zero},
    {"tone",cmd_tone},
    {"sing",cmd_sing},
    {"max",cmd_max},
    {"min",cmd_min},
    {"dacon",cmd_dacon},
    {"dacoff",cmd_dacoff},
#endif
#if USER_MMC
    {"ls",cmd_lsfile},
    {"cat",cmd_catfile},
    {"mmcwr",cmd_mmcwrt},
    {"mmcat",cmd_mmcat},
    {"mmchk",cmd_mmchk},
#endif
#if USER_IOT
    {"sub",cmd_iotsub},
    {"pub",cmd_iotpub},
    {"send",cmd_iotsend},
#endif
    {NULL, NULL}
};

/*******************************************
 * Serial Peripheral Setup
 *******************************************/

/**
 * @brief UART Shell Console pointer
 */
static thread_t *shelltp_uart = NULL;

/**
 * @brief USB Shell Console pointer
 */
static thread_t *shelltp_usb = NULL;

/**
 * @brief Shell Driver Config
 * @details Serial Interface using UART0 (SD1)
 */
static const ShellConfig shell_uart_cfg = {
  (BaseSequentialStream *)&SD1,
  commands
};

/**
 * @brief Shell Driver Config
 * @details Serial Interface using USB1 (SDU1)
 */
static const ShellConfig shell_usb_cfg = {
  (BaseSequentialStream *)&SDU1,
  commands
};

void ht_commUART_Init(void){
    palSetPadMode(GPIOA, 9,PAL_MODE_ALTERNATE(7) | PAL_STM32_OSPEED_HIGHEST); //TX
    palSetPadMode(GPIOA,10,PAL_MODE_ALTERNATE(7) | PAL_STM32_OSPEED_HIGHEST); //RX
    sdStart(&SD1,NULL);

    shellInit();
}

void ht_commUSB_Init(void){
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    usbDisconnectBus(serusbcfg.usbp);
    usbStop(serusbcfg.usbp);
    chThdSleepMilliseconds(500);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    shellInit();
}

void ht_commUART_shInit(void){
    if (!shelltp_uart) {
        shelltp_uart = shellCreate(&shell_uart_cfg, SHELL_WA_SIZE, NORMALPRIO);
    }
    else {
        if (chThdTerminatedX(shelltp_uart)) {
            chThdRelease(shelltp_uart);
            shelltp_uart = NULL;
        }
    }
}

void ht_commUSB_shInit(void){
    if (!shelltp_usb && (SDU1.config->usbp->state == USB_ACTIVE)) {
        shelltp_usb = shellCreate(&shell_usb_cfg, SHELL_WA_SIZE, NORMALPRIO);
    }
    else {
        if (chThdTerminatedX(shelltp_usb)) {
            chThdRelease(shelltp_usb);
            shelltp_usb = NULL;
        }
    }
}

void ht_comm_Msg(char *string){
#if USER_SERMSG_USB
    if(SDU1.config->usbp->state == USB_ACTIVE){
        chprintf((BaseSequentialStream *)&SDU1,string);
    }
#else
    chprintf((BaseSequentialStream *)&SD1,string);
#endif
}

void ht_comm_IoT(char *string){
    chprintf((BaseSequentialStream *)&SD1,string);
}

/** @} */

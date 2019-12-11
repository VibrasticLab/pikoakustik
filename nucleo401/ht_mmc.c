/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    ht_mmc.c
 * @brief   MMC-SPI FAT-FS code.
 *
 * @addtogroup Storage
 * @{
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "ff.h"

#include "ht_mmc.h"

extern uint16_t led_delay;

/**
 * @brief Global MMC Driver Pointer
 */
MMCDriver MMCD1;

/**
 * @brief FatFS ready status flag
 */
static bool filesystem_ready=true;

/**
 * @brief MMC SPI Peripheral status flag
 */
static uint8_t mmc_spi_status_flag=MMC_SPI_OK;

/**
 * @brief SPI High-Clock NSS config
 */
static SPIConfig hs_spicfg = {NULL, GPIOA, 15, 0};

/**
 * @brief SPI Low-Clock NSS config
 */
static SPIConfig ls_spicfg = {NULL, GPIOA, 15, SPI_CR1_BR_2 | SPI_CR1_BR_1};

/**
 * @brief MMC config struct
 */
static MMCConfig mmccfg = {&SPID3, &ls_spicfg, &hs_spicfg};

#if USE_MMC_CHK
/**
 * @brief Checking readiness FatFS
 * @details Must calling before mounting actual media MMC
 * @details Checking both Peripheral and Filesystem status
 */
static void mmc_check(void){
    FATFS FatFs;
    FRESULT err;

#if USE_MMC_FREE
    uint32_t clusters;
    FATFS *fsp;
#endif

    mmc_spi_status_flag=MMC_SPI_OK;
    filesystem_ready=false;

    if(mmcConnect(&MMCD1)) { filesystem_ready = true; }
    else{
        err = f_mount(&FatFs, "", 0);
        if(err == FR_OK){ filesystem_ready = true; }
    }

    if(!filesystem_ready){ mmc_spi_status_flag=MMC_SPI_FAIL;return; }

#if USE_MMC_FREE
    mmc_spi_status_flag=MMC_SPI_ERROR;
    err = f_getfree("/", &clusters, &fsp);
    if(err == FR_OK){ mmc_spi_status_flag=MMC_SPI_OK; led_delay=500; }
#endif

    f_mount(0, "", 0);

    chThdSleepMilliseconds(100);
}
#endif

void ht_mmc_Test(void){
    char buffer[36];

    FATFS FatFs;
    FIL *Fil;
    UINT bw;

    Fil = (FIL*)malloc(sizeof(FIL));

#if USE_MMC_CHK
    mmc_check();
#endif

    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        chsnprintf(buffer,sizeof(buffer),"Test\n\r");

        f_mount(&FatFs, "", 0);

        f_open(Fil, "/TEST.TXT", FA_WRITE | FA_READ | FA_OPEN_ALWAYS);
        f_lseek(Fil, f_size(Fil));
        f_write(Fil, buffer, strlen(buffer), &bw);
        f_close(Fil);

        f_mount(0, "", 0);
    }
    free(Fil);
}

void ht_mmc_Init(void){
    palSetPadMode(GPIOC, 12, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //MOSI
    palSetPadMode(GPIOC, 11, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //MISO
    palSetPadMode(GPIOC, 10, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //SCK
    palSetPadMode(GPIOA, 15, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST); //NSS
    palSetPad(GPIOA, 15);

    mmcObjectInit(&MMCD1);
    mmcStart(&MMCD1, &mmccfg);
    chThdSleepMilliseconds(100);

    palSetPadMode(GPIOA,5,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOA,5);
}

static FRESULT scanFile(char *path){
    FRESULT err;
    DIR Dir;
    FILINFO Fno;
#if USE_SCAN_DIR
    UINT num;
#endif

    err = f_opendir(&Dir,path);
    if(err==FR_OK){
        while(1){
            err=f_readdir(&Dir,&Fno);
            if(err!=FR_OK || Fno.fname[0]==0)break;

            if(Fno.fattrib & AM_DIR){
#if USE_SCAN_DIR
                num = strlen(path);
                chsnprintf(&path[num],sizeof(&path[num]),"/%s",Fno.fname);
                err = scanFile(path);
                if(err!=FR_OK)break;
                path[num]=0;

            }
            else{
                chprintf((BaseSequentialStream *)&SD1,"%s%s\r\n",path,Fno.fname);
#else
            }
            else{
                chprintf((BaseSequentialStream *)&SD1,"%s\r\n",Fno.fname);
#endif
            }
        }
        f_closedir(&Dir);
    }
    return err;
}

void ht_mmc_lsFiles(void){
    FATFS FatFs;
    FRESULT err;
    char buff[256];

#if USE_MMC_CHK
    mmc_check();
#endif

    chprintf((BaseSequentialStream *)&SD1,"\r\nFiles on MMC\r\n");
    chprintf((BaseSequentialStream *)&SD1,"------------\r\n");
    err = f_mount(&FatFs,"",0);
    if(err==FR_OK){
        strcpy(buff,"/");
        err = scanFile(buff);
        if(err==FR_OK){
            chprintf((BaseSequentialStream *)&SD1,"------------\r\n\r\n");
        }
    }
    f_mount(0, "", 0);
}

void ht_mmc_catFiles(void){
    char buffer[64];
    FATFS FatFs;
    FIL *Fil;
    UINT br;
    FRESULT err;

    Fil = (FIL*)malloc(sizeof(FIL));

#if USE_MMC_CHK
    mmc_check();
#endif

    chprintf((BaseSequentialStream *)&SD1,"Content:\r\n");

    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        f_mount(&FatFs, "", 0);

        err=f_open(Fil, "/TEST.TXT", FA_OPEN_EXISTING |FA_READ);
        if(err==FR_OK){
            f_read(Fil,buffer,sizeof(buffer),&br);
            f_close(Fil);
            chprintf((BaseSequentialStream *)&SD1,"%s\r\n",buffer);
        }
        else{
            chprintf((BaseSequentialStream *)&SD1,"Open Error:%d\r\n",err);
        }

        f_mount(0, "", 0);
    }
    free(Fil);
}
/** @} */

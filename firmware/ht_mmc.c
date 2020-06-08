﻿/*
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

#include "user_conf.h"
#include "ht_mmc.h"
#include "ht_led.h"
#include "ht_metri.h"
#include "ht_console.h"

/* Blink indicator mode */
extern uint8_t mode_led;
extern uint8_t mode_status;

/**
 * @brief Global MMC Driver Pointer
 */
MMCDriver MMCD1;

/**
 * @brief Save file last number variable
 */
static uint8_t lastnum=0;

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

static void string_parse(char *strIn, char *strOut, uint8_t pos, char sep){
    char strInput[90];
    char strSplit[3][30];
    uint8_t i,j,cnt;

    strcpy(strInput,strIn);
    j=0; cnt=0;
    for(i=0;i<=strlen(strInput);i++){
        if(strInput[i]==' ' || strInput[i]=='\0' || strInput[i]==sep){
            strSplit[cnt][j]='\0';
            cnt++;
            j=0;
        }
        else {
            strSplit[cnt][j]=strInput[i];
            j++;
        }
    }

    strcpy(strOut,strSplit[pos]);
}

static uint8_t get_fnum(char *strIn){
    char buffer[64];
    char filenum[16];
    uint8_t numOut;

    string_parse(strIn,buffer,1,'_');
    string_parse(buffer,filenum,0,'.');
    numOut = atoi(filenum);

    return numOut;
}

static FRESULT scanFile(char *path, uint8_t *lastfnum, uint8_t stt_print){
    char strbuff[IFACE_BUFF_SIZE];
    FRESULT err;
    DIR Dir;
    FILINFO Fno;
    uint8_t fnum;

#if USE_SCAN_DIR
    UINT num;
#endif

    *lastfnum=0;
    err = f_opendir(&Dir,path);
    if(err==FR_OK){
        ht_comm_Msg("------------\r\n");
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
                fnum = get_fnum(Fno.fname);
                if(*lastfnum<=fnum)*lastfnum=fnum;

                if(stt_print==1){
                    ht_comm_Buff(strbuff,sizeof(strbuff),"%s%s\r\n",path,Fno.fname);
                    ht_comm_Msg(strbuff);
                }
#else
            }
            else{
                fnum = get_fnum(Fno.fname);
                if(*lastfnum<=fnum)*lastfnum=fnum;

                if(stt_print==1){
                    ht_comm_Buff(strbuff,sizeof(strbuff),"%s\r\n",Fno.fname);
                    ht_comm_Msg(strbuff);
                }
#endif
            }
        }
        f_closedir(&Dir);
    }
    return err;
}

/**
 * @brief Checking readiness FatFS
 * @details Must calling before mounting actual media MMC
 * @details Checking both Peripheral and Filesystem status
 * @param[in] uint8_t Status to change LED mode or not
 */
static FRESULT mmc_check(void){
    FATFS FatFs;
    FRESULT err;

    uint32_t clusters;
    FATFS *fsp;

    mmc_spi_status_flag=MMC_SPI_OK;
    filesystem_ready=false;
    err = FR_OK;

    if(mmcConnect(&MMCD1)){
        filesystem_ready = true;
        f_mount(&FatFs, "", 0);
    }
    else{
        err = f_mount(&FatFs, "", 0);
        if(err == FR_OK){
            filesystem_ready = true;
        }
        else{
            if(mode_led!=LED_METRI)mode_led=LED_FAIL;
            return err;
        }
    }

    if(!filesystem_ready){
        mmc_spi_status_flag=MMC_SPI_FAIL;
        if(mode_led!=LED_METRI)mode_led=LED_FAIL;
        return err;
    }

    mmc_spi_status_flag=MMC_SPI_ERROR;
    err = f_getfree("", &clusters, &fsp);
    if(err == FR_OK){
        mmc_spi_status_flag=MMC_SPI_OK;
        if(mode_led!=LED_METRI)mode_led=LED_READY;
    }
    else{
        if(mode_led!=LED_METRI)mode_led=LED_FAIL;
        return err;
    }

    f_mount(0, "", 0);

    return err;
}

void ht_mmc_initCheck(void){
    FATFS FatFs;
    FRESULT err;
    char strbuff[IFACE_BUFF_SIZE];

    uint32_t clusters;
    FATFS *fsp;

    mmc_spi_status_flag=MMC_SPI_OK;
    filesystem_ready=false;

    if(mmcConnect(&MMCD1)){
        filesystem_ready = true;
        err = f_mount(&FatFs, "", 0);
        if(err == FR_OK){
            ht_comm_Msg("MMC connected and mounted\r\n");
        }
        else{
            ht_comm_Buff(strbuff,sizeof(strbuff),"MMC connected but not mounted with error = %i\r\n",err);
            ht_comm_Msg(strbuff);
            if(mode_led!=LED_METRI)mode_led=LED_FAIL;
            return;
        }
    }
    else{
        err = f_mount(&FatFs, "", 0);
        if(err == FR_OK){
            ht_comm_Msg("MMC mount forcefully\r\n");
            filesystem_ready = true;
        }
        else{
            ht_comm_Buff(strbuff,sizeof(strbuff),"MMC mount error = %i\r\n",err);
            ht_comm_Msg(strbuff);
            if(mode_led!=LED_METRI)mode_led=LED_FAIL;
            return;
        }
    }

    if(!filesystem_ready){
        ht_comm_Msg("MMC filesystem Not Ready\r\n");
        mmc_spi_status_flag=MMC_SPI_FAIL;
        if(mode_led!=LED_METRI)mode_led=LED_FAIL;
        return;
    }
    else{
        ht_comm_Msg("MMC filesystem Ready\r\n");
    }

    mmc_spi_status_flag=MMC_SPI_ERROR;
    err = f_getfree("", &clusters, &fsp);
    if(err == FR_OK){
        ht_comm_Msg("MMC checking OK\r\n");
        mmc_spi_status_flag=MMC_SPI_OK;
        if(mode_led!=LED_METRI)mode_led=LED_READY;
    }
    else{
        ht_comm_Buff(strbuff,sizeof(strbuff),"MMC getfree error = %i\r\n",err);
        ht_comm_Msg(strbuff);
        if(mode_led!=LED_METRI)mode_led=LED_FAIL;
        return;
    }

    f_mount(0, "", 0);
}

void ht_mmc_Test(void){
    char buffer[FILE_BUFF_SIZE];
    char strbuff[IFACE_BUFF_SIZE];

    FATFS FatFs;
    FIL *Fil;
    UINT bw;
    FRESULT err;

    Fil = (FIL*)malloc(sizeof(FIL));

    err = mmc_check();
    if(err!=FR_OK){
        ht_comm_Buff(strbuff,sizeof(strbuff),"MMC Error code = %i\r\n",err);
        ht_comm_Msg(strbuff);
        return;
    }

    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        ht_comm_Buff(buffer,sizeof(buffer),"Test\n");

        f_mount(&FatFs, "", 0);

        err = f_open(Fil, "/TEST.TXT", FA_WRITE | FA_READ | FA_OPEN_ALWAYS);
        if(err==FR_OK){
            f_lseek(Fil, f_size(Fil));
            f_write(Fil, buffer, strlen(buffer), &bw);
            f_close(Fil);
            ht_comm_Msg("MMC R/W Test Success\r\n");
            mode_led=LED_READY;
        }
        else{
            ht_comm_Buff(strbuff,sizeof(strbuff),"MMC Error code = %i\r\n",err);
            ht_comm_Msg(strbuff);
            mode_led=LED_FAIL;
        }

        f_mount(0, "", 0);
    }
    free(Fil);
}

void ht_mmc_catTest(void){
    uint16_t line_num=0;
    char buffer[FILE_BUFF_SIZE];
    char strbuff[IFACE_BUFF_SIZE];
    char fname[LINE_BUFF_SIZE];
    FATFS FatFs;
    FIL *Fil;
    FRESULT err;

    Fil = (FIL*)malloc(sizeof(FIL));

    err = mmc_check();
    if(err!=FR_OK){
        ht_comm_Buff(strbuff,sizeof(strbuff),"MMC Error code = %i\r\n",err);
        ht_comm_Msg(strbuff);
        return;
    }

    ht_comm_Msg("\r\nFiles Content\r\n");
    ht_comm_Msg("------------\r\n");

    strcpy(buffer,"");
    ht_comm_Buff(fname,sizeof(fname),"/TEST.TXT");
    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        f_mount(&FatFs, "", 0);

        err=f_open(Fil, fname, FA_OPEN_EXISTING |FA_READ);
        if(err==FR_OK){
#if USE_READ_LINE
            char line[LINE_BUFF_SIZE];
            TCHAR *eof;
            while(1){
                line_num++;
                strcpy(line,"");
                eof=f_readline(line,sizeof(line),Fil);
                if(eof[0]==0)break;

    #if CAT_BY_LINE
                ht_comm_Buff(strbuff,sizeof(strbuff),"%3i %s\r",line_num,line);
                ht_comm_Msg(strbuff);
    #else
                ht_comm_Buff(buffer,sizeof(buffer),"%s%s\r",buffer,line);
    #endif
            }
#else
            UINT br;
            f_read(Fil,buffer,sizeof(buffer),&br);
#endif
            f_close(Fil);

#if !(CAT_BY_LINE)
            ht_comm_Buff(strbuff,sizeof(strbuff),"%s\r\n",buffer);
            ht_comm_Msg(strbuff);
            ht_comm_Msg("All line printed at once\r\n\r\n");
#endif
            ht_comm_Msg("------------\r\n\r\n");
        }
        else{
            ht_comm_Buff(strbuff,sizeof(strbuff),"Open Error:%d\r\n",err);
            ht_comm_Msg(strbuff);
        }

        f_mount(0, "", 0);
    }
    free(Fil);
}

void ht_mmc_lsFiles(void){
    char strbuff[IFACE_BUFF_SIZE];
    FATFS FatFs;
    FIL *Fil;
    FRESULT err;
    char buff[FILE_BUFF_SIZE];
    char buffer[FILE_BUFF_SIZE];
    char fname[LINE_BUFF_SIZE];

    Fil = (FIL*)malloc(sizeof(FIL));

    if(mmc_check()!=FR_OK){return;}

    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        ht_comm_Buff(buffer,sizeof(buffer),"START\n");

        err = f_mount(&FatFs,"",0);
        if(err==FR_OK){
            ht_comm_Msg("\r\nFiles on MMC\r\n");
            strcpy(buff,"/");
            err = scanFile(buff,&lastnum,1);
            if(err==FR_OK){
                ht_comm_Msg("------------\r\n");
                ht_comm_Buff(strbuff,sizeof(strbuff),"Last Num: %i\r\n",lastnum);
                ht_comm_Msg(strbuff);
                ht_comm_Buff(strbuff,sizeof(strbuff),"Last File: TEST_%i.TXT\r\n",lastnum);
                ht_comm_Msg(strbuff);

                if(lastnum < 255){
                    ht_comm_Buff(fname,sizeof(fname),"/TEST_%i.TXT",lastnum);

                    err = f_open(Fil, fname, FA_READ | FA_OPEN_EXISTING);
                    if(err==FR_OK){
                        f_close(Fil);
                        ht_comm_Buff(strbuff,sizeof(strbuff),"File %s exist\r\n",fname);
                        ht_comm_Msg(strbuff);                      
                    }
                    else if(err==FR_NO_FILE){
                        ht_comm_Buff(strbuff,sizeof(strbuff),"File %s not exist\r\n",fname);
                        ht_comm_Msg(strbuff);                        
                    }
                    else{
                        ht_comm_Buff(strbuff,sizeof(strbuff),"File %s error code = %i\r\n",fname,err);
                        ht_comm_Msg(strbuff);
                    }
                }
                else{
                    ht_comm_Msg("Maximum saves number, please back-up and clear before continue\r\n");
                }
                ht_comm_Msg("------------\r\n\r\n");
            }
        }
        f_mount(0, "", 0);
    }
    free(Fil);
}

void ht_mmc_catFiles(uint8_t fnum){
    uint16_t line_num=0;
    char buffer[FILE_BUFF_SIZE];
    char strbuff[IFACE_BUFF_SIZE];
    char fname[LINE_BUFF_SIZE];
    FATFS FatFs;
    FIL *Fil;
    FRESULT err;

    Fil = (FIL*)malloc(sizeof(FIL));

    ht_comm_Msg("\r\nFiles Content\r\n");
    ht_comm_Msg("------------\r\n");
    strcpy(buffer,"");

    if(mmc_check()!=FR_OK){return;}

    ht_comm_Buff(fname,sizeof(fname),"/TEST_%i.TXT",fnum);
    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        f_mount(&FatFs, "", 0);

        err=f_open(Fil, fname, FA_OPEN_EXISTING |FA_READ);
        if(err==FR_OK){
#if USE_READ_LINE
            char line[LINE_BUFF_SIZE];
            TCHAR *eof;
            while(1){
                line_num++;
                strcpy(line,"");
                eof=f_readline(line,sizeof(line),Fil);
                if(eof[0]==0)break;

    #if CAT_BY_LINE
                ht_comm_Buff(strbuff,sizeof(strbuff),"%3i %s\r",line_num,line);
                ht_comm_Msg(strbuff);
    #else
                ht_comm_Buff(buffer,sizeof(buffer),"%s%s\r",buffer,line);
    #endif
            }
#else
            UINT br;
            f_read(Fil,buffer,sizeof(buffer),&br);
#endif
            f_close(Fil);

#if !(CAT_BY_LINE)
            ht_comm_Buff(strbuff,sizeof(strbuff),"%s\r\n",buffer);
            ht_comm_Msg(strbuff);
            ht_comm_Msg("All line printed at once\r\n\r\n");
#endif
            ht_comm_Msg("------------\r\n\r\n");
        }
        else{
            ht_comm_Buff(strbuff,sizeof(strbuff),"Open Error:%d\r\n",err);
            ht_comm_Msg(strbuff);
        }

        f_mount(0, "", 0);
    }
    free(Fil);
}

void ht_mmcMetri_chkFile(void){
    char strbuff[IFACE_BUFF_SIZE];
    FATFS FatFs;
    FIL *Fil_last;
    FIL *Fil_new;
    FRESULT err;
    UINT bw;
    char buff[FILE_BUFF_SIZE];
    char buffer[FILE_BUFF_SIZE];
    char fname[LINE_BUFF_SIZE];

    Fil_last = (FIL*)malloc(sizeof(FIL));
    Fil_new = (FIL*)malloc(sizeof(FIL));

    if(mmc_check()!=FR_OK){return;}

    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        ht_comm_Buff(buffer,sizeof(buffer),"START\n");

        err = f_mount(&FatFs,"",0);
        if(err==FR_OK){
            strcpy(buff,"/");
            err = scanFile(buff,&lastnum,0);

            if(lastnum < 255){
                ht_comm_Buff(fname,sizeof(fname),"/TEST_%i.TXT",lastnum);

                err = f_open(Fil_last, fname, FA_READ | FA_OPEN_EXISTING);
                if(err==FR_OK){
                    f_close(Fil_last);
                    ht_comm_Buff(strbuff,sizeof(strbuff),"File %s exist\r\n",fname);
                    ht_comm_Msg(strbuff);

                    lastnum++;
                    ht_comm_Msg("File name incremented\r\n");
                    ht_comm_Buff(fname,sizeof(fname),"/TEST_%i.TXT",lastnum);

                    err = f_open(Fil_new, fname, FA_WRITE | FA_READ | FA_OPEN_ALWAYS);
                    if(err==FR_OK){
                        f_lseek(Fil_new, f_size(Fil_new));
                        f_write(Fil_new, buffer, strlen(buffer), &bw);
                        f_close(Fil_new);
                    }
                }
                else if(err==FR_NO_FILE){
                    ht_comm_Buff(strbuff,sizeof(strbuff),"File %s not exist\r\n",fname);
                    ht_comm_Msg(strbuff);

                    ht_comm_Msg("File name created now\r\n");
                    ht_comm_Buff(fname,sizeof(fname),"/TEST_%i.TXT",lastnum);

                    err = f_open(Fil_new, fname, FA_WRITE | FA_READ | FA_OPEN_ALWAYS);
                    if(err==FR_OK){
                        f_lseek(Fil_new, f_size(Fil_new));
                        f_write(Fil_new, buffer, strlen(buffer), &bw);
                        f_close(Fil_new);
                    }
                }
                else{
                    ht_comm_Buff(strbuff,sizeof(strbuff),"File %s error code = %i\r\n",fname,err);
                    ht_comm_Msg(strbuff);
                    mode_status = STT_IDLE;
                    mode_led = LED_READY;
                }
            }
            else{
                mode_status = STT_IDLE;
                mode_led = LED_READY;
                ht_comm_Msg("Maximum saves number, please back-up and clear before continue\r\n");
            }
        }
    }
    free(Fil_last);
    free(Fil_new);
}

void ht_mmcMetri_lineResult(double freq, double ample, uint8_t result){
    char buffer[FILE_BUFF_SIZE];
    char fname[LINE_BUFF_SIZE];
    FATFS FatFs;
    FIL *Fil;
    UINT bw;
    FRESULT err;

    Fil = (FIL*)malloc(sizeof(FIL));

    if(mmc_check()!=FR_OK){return;}

    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        if(result==0){ht_comm_Buff(buffer,sizeof(buffer),"%5.2f, %5.4f, FALSE\n",freq,ample);}
        else if(result==1){ht_comm_Buff(buffer,sizeof(buffer),"%5.2f, %5.4f, TRUE\n",freq,ample);}

        if(lastnum < 255){
            f_mount(&FatFs, "", 0);

            ht_comm_Buff(fname,sizeof(fname),"/TEST_%i.TXT",lastnum);
            err = f_open(Fil, fname, FA_WRITE | FA_READ | FA_OPEN_ALWAYS);
            if(err==FR_OK){
                f_lseek(Fil, f_size(Fil));
                f_write(Fil, buffer, strlen(buffer), &bw);
                f_close(Fil);
            }

            f_mount(0, "", 0);
        }
        else{
            mode_status = STT_IDLE;
            mode_led = LED_READY;
            ht_comm_Msg("Maximum saves number, please back-up and clear before continue\r\n");
        }
    }
    free(Fil);
}

void ht_mmcMetri_endResult(void){
    char buffer[FILE_BUFF_SIZE];
    char fname[LINE_BUFF_SIZE];
    FATFS FatFs;
    FIL *Fil;
    UINT bw;
    FRESULT err;

    Fil = (FIL*)malloc(sizeof(FIL));

    if(mmc_check()!=FR_OK){return;}

    if( (filesystem_ready==true) && (mmc_spi_status_flag==MMC_SPI_OK) ){
        ht_comm_Buff(buffer,sizeof(buffer),"END\n");

        if(lastnum < 255){
            f_mount(&FatFs, "", 0);

            ht_comm_Buff(fname,sizeof(fname),"/TEST_%i.TXT",lastnum);
            err = f_open(Fil, fname, FA_WRITE | FA_READ | FA_OPEN_ALWAYS);
            if(err==FR_OK){
                f_lseek(Fil, f_size(Fil));
                f_write(Fil, buffer, strlen(buffer), &bw);
                f_close(Fil);
            }

            f_mount(0, "", 0);
        }
        else{
            mode_status = STT_IDLE;
            mode_led = LED_READY;
            ht_comm_Msg("Maximum saves number, please back-up and clear before continue\r\n");
        }
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

    chThdSleepMilliseconds(1000);
}
/** @} */

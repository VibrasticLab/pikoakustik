/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    ht_mmc.h
 * @brief   MMC-SPI FAT-FS header.
 *
 * @addtogroup Storage
 * @{
 */

#ifndef HT_MMC_H
#define HT_MMC_H

#include <stdlib.h>
#include <string.h>

#define MMC_SPI_OK      0
#define MMC_SPI_FAIL    1
#define MMC_SPI_ERROR   2

/**
 * @brief File buffer maximal size
 * @details More than 256 cause all system freeze
 */
#define STR_BUFF_SIZE 128

/**
 * @brief Define whether scan directory recursively or files only
 * @details Highly recommended to disable it as still buggy
 */
#define USE_SCAN_DIR FALSE

/**
 * @brief File Buffer length variable
 */
#define FILE_BUFF_LEN 4096

/**
 * @brief rename to match name f_write()
 */
#define f_readline    f_gets

/**
 * @brief Test Write and Read Simple text in Append mode
 */
void ht_mmc_Test(void);

/**
 * @brief Test CAT on Simple text
 */
void ht_mmc_catTest(void);

/**
 * @brief Check MMC readyness
 */
void ht_mmc_initCheck(void);

/**
 * @brief Initialize MMC-SPI peripherals
 */
void ht_mmc_Init(void);

/**
 * @brief List files on directory
 */
void ht_mmc_lsFiles(void);

/**
 * @brief Read a file on directory and print
 * @param[in] uint8_t Last number of Save file
 */
void ht_mmc_catFiles(uint8_t fnum);

/**
 * @brief Read a file on directory and send to IoT
 * @param[in] uint8_t Last number of Save file
 */
void ht_mmc_sendFiles(uint8_t fnum);

/**
 * @brief Check save file existence before audiometri
 * @details If last number file already exist, create new in incremented last number
 * @details Otherwise, use current last number
 * @details Save START on save files
 */
void ht_mmcMetri_chkFile(void);

/**
 * @brief Save each line for every result
 * @param[in] double Frequency scaling
 * @param[in] double Amplitude scaling
 * @param[in] uint8  Channel Left (0) or Right (1)
 * @param[in] double Result True of False
 */
void ht_mmcMetri_lineResult(double freq, double ample, uint8_t lr_ch, uint8_t result);

/**
 * @brief Save word END on save files
 */
void ht_mmcMetri_endResult(void);

#endif // HT_MMC_H
/** @} */

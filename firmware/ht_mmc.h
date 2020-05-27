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
#define FILE_BUFF_SIZE 256

/**
 * @brief Maximal buffer size for each line
 */
#define LINE_BUFF_SIZE 16

/**
 * @brief Print cat() line by line
 * @details Recommended to use this option
 */
#define CAT_BY_LINE   TRUE

/**
 * @brief rename to match name f_write()
 */
#define f_readline      f_gets

/**
 * @brief Define whether scan directory recursively or files only
 * @details Highly recommended to disable it as still buggy
 */
#define USE_SCAN_DIR FALSE

/**
 * @brief Read a file as line by line
 * @details If enabled, _USE_STRFUNC must 1
 * @details Highly recommended to enable it
 */
#define USE_READ_LINE TRUE

/**
 * @brief Whether record test on MMC or not (for debugging)
 */
#define RECORD_TEST TRUE

/**
 * @brief Test Write and Read Simple text in Append mode
 */
void ht_mmc_Test(void);

/**
 * @brief Check MMC readyness
 */
void ht_mmc_Check(void);

/**
 * @brief Initialize MMC-SPI peripherals
 */
void ht_mmc_Init(void);

/**
 * @brief List files on directory
 */
void ht_mmc_lsFiles(void);

/**
 * @brief Read a file on directory
 * @param[in] uint8_t Last number of Save file
 */
void ht_mmc_catFiles(uint8_t fnum);

/**
 * @brief Check save file existence before audiometri
 * @details If last number file already exist, create new in incremented last number
 * @details Otherwise, use current last number
 */
void ht_mmcMetri_chkFile(void);

/**
 * @brief Save each line for every result
 * @param[in] double Frequency scaling
 * @param[in] double Amplitude scaling
 * @param[in] double Result True of False
 */
void ht_mmcMetri_lineResult(double freq, double ample, uint8_t result);

/**
 * @brief Save word END on save files
 */
void ht_mmcMetri_endResult(void);

#endif // HT_MMC_H
/** @} */

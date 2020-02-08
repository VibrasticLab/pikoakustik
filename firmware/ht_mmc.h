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
 * @brief Define whether use checking routine or not
 * @details Highly recommended to enabled it
 */
#define USE_MMC_CHK TRUE

/**
 * @brief Define whether use R/W Test routine or MMC readyness
 */
#define USE_MMC_RWCHK FALSE

/**
 * @brief Define whether use free-space check routine or not
 * @details If enabled, _FS_MINIMIZE must 0
 * @details Highly recommended to enable it
 */
#define USE_MMC_FREE TRUE

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
 */
void ht_mmc_catFiles(uint8_t fnum);

/**
 * @brief Check save file existence before audiometri
 * @details If last number file already exist, create new in incremented
 * @details Otherwise, use current last number
 */
void ht_mmcMetri_chkFile(void);

void ht_mmcMetri_lineResult(double freq, double ample, uint8_t result);

#endif // HT_MMC_H
/** @} */

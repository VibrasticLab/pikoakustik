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
 * @brief rename to match name f_write()
 */
#define f_readline      f_gets

/**
 * @brief Define whether use checking routine or not
 * @details Highly recommended to enabled it
 */
#define USE_MMC_CHK 1

/**
 * @brief Define whether use free-space check routine or not
 * @details Highly recommended to disable it
 */
#define USE_MMC_FREE 0

/**
 * @brief Define whether scan directory recursively or files only
 * @details Highly recommended to disable it as still buggy
 */
#define USE_SCAN_DIR 0

/**
 * @brief Read a file as line by line
 * @details If enabled, _USE_STRFUNC must 1
 * @details Highly recommended to enable it
 */
#define USE_READ_LINE 1

/**
 * @brief Test Write and Read Simple text in Append mode
 */
void ht_mmc_Test(void);

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
void ht_mmc_catFiles(void);

#endif // HT_MMC_H
/** @} */
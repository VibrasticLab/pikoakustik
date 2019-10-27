/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    drv_mmc.h
 * @brief   MMC-SPI Storage header.
 *
 * @addtogroup Storage
 * @{
 */

#ifndef DRV_MMC_H
#define DRV_MMC_H

#define MMC_SPI_OK 0
#define MMC_SPI_FAIL 1
#define MMC_SPI_ERROR 2

/**
 * @brief Define whether use checking routine or not
 * @details Highly recommended to enabled it
 */
#define USE_MMC_CHK 1

/**
 * @brief Test Write and Read Simple text in Append mode
 */
void mmc_test(void);

/**
 * @brief Initialize MMC-SPI peripherals
 */
void mmc_start(void);

#endif // DRV_MMC_H
/** @} */

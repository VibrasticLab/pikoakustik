/*
    Embedded Audiometri - Copyright (C) 2020 Achmadi

    github.com/mekatronik-achmadi/ or mekatronik-achmadi@gmail.com

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
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
 * @brief File Buffer length variable
 */
#define FILE_BUFF_LEN 4096

/**
 * @brief Maximum Last Number to be saved
 */
#define FILE_MAX_NUM  500

/**
 * @brief rename to match name f_write()
 */
#define f_readline    f_gets

/**
 * @brief For easy remember, chsnprintf() also defined as ht_mmc_Buff()
 */
#define ht_mmc_Buff chsnprintf

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
 * @brief List number files on directory
 */
void ht_mmc_lsNumFiles(void);

/**
 * @brief Delete All Files on media
 */
void ht_mmc_delAllFiles(void);

/**
 * @brief Read a file on directory and print
 * @param[in] uint16_t Last number of Save file
 */
void ht_mmc_catFiles(uint16_t fnum);

/**
 * @brief Check save file existence before audiometri
 * @details If last number file already exist, create new in incremented last number
 * @details Otherwise, use current last number
 * @details Save START on save files
 */
void ht_mmcMetri_chkFile(void);

/**
 * @brief Put JSON open bracket on save files
 * @param[in] uint8_t Channel number
 */
void ht_mmcMetri_jsonChStart(uint8_t lr_ch);

/**
 * @brief Put JSON close bracket on save files
 */
void ht_mmcMetri_jsonChClose(void);

/**
 * @brief Put JSON comma separator on save files
 */
void ht_mmcMetri_jsonComma(void);

/**
 * @brief Save last amplification scale for every frequency test
 * @param[in] double Frequency ratio
 * @param[in] uint8_t Frequency index number
 * @param[in] uint8_t Amplitude scaling number
 */
void ht_mmcMetri_hearingResult(double freq, uint8_t freqidx, uint8_t ample);

/**
 * @brief Save word END on save files
 */
void ht_mmcMetri_endResult(void);

#endif // HT_MMC_H
/** @} */

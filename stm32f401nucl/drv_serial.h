/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    drv_serial.h
 * @brief   Serial Console header.
 *
 * @addtogroup Console
 * @{
 */

#ifndef DRV_SERIAL_H
#define DRV_SERIAL_H

/**
 * @brief Shell thread working area size
 * @details Set to bigger size if necessary
 */
#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(1024)

/**
 * @brief Start Shell and UART peripheral
 * @details Serial Interface using UART0 (SD1)
 */
void shell_start(void);

/**
 * @brief Re-Initialize Shell Thread
 * @details This routine should be called on main thread with some delays
 */
void shell_term(void);

#endif // DRV_SERIAL_H
/** @} */

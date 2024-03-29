/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Wira S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    user_config.h
 * @brief   User Configuration header.
 *
 * @addtogroup Config
 * @{
 */

#ifndef _USER_CONF_
#define _USER_CONF_

/**
 * @brief Choose as Station or not (Access Point)
 * @details Currently failed connect to broker if using AP Mode
 */
#define USED_AS_STATION TRUE

/**
 * @brief Default UART BaudRate
 */
#define SERIALBAUD 9600

/**
 * @brief Wahyu Anggoro gak ada kerjaan
 */
#define TEST_MQTT_WAHYU FALSE

/**
 * @brief Enable subscribe routines
 */
#define SUBSCRIBE_CMD   FALSE

/**
 * @brief Stop receive same topic
 */
#define SUB_SAME_TOPIC  FALSE

/**
 * @brief Whether UART Send NACK command or not
 */
#define UART_SEND_NACK  FALSE

#endif

/** @} */

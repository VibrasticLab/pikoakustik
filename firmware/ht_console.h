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
 * @file    ht_console.h
 * @brief   Console Shell header.
 *
 * @addtogroup Console
 * @{
 */

#ifndef HT_CONSOLE_H
#define HT_CONSOLE_H

#include "user_conf.h"

#if USER_SERCONSOLE
 #define SHELL_ECHO     TRUE
 #define SHELL_PROMPT   TRUE
#else
 #define SHELL_ECHO     FALSE
 #define SHELL_PROMPT   FALSE
#endif

/**
 * @brief Size off buffer for chsnprintf() on interface
 */
#define IFACE_BUFF_SIZE 128

/**
 * @brief Shell thread working area size
 * @details Set to bigger size if necessary
 */
#define SHELL_WA_SIZE THD_WORKING_AREA_SIZE(2048)

/**
 * @brief   Shell maximum input line length.
 */
#if !defined(SHELL_MAX_LINE_LENGTH) || defined(__DOXYGEN__)
#define SHELL_MAX_LINE_LENGTH       64
#endif

/**
 * @brief   Shell maximum arguments per command.
 */
#if !defined(SHELL_MAX_ARGUMENTS) || defined(__DOXYGEN__)
#define SHELL_MAX_ARGUMENTS         4
#endif

/**
 * @brief   Command handler function type.
 */
typedef void (*shellcmd_t)(BaseSequentialStream *chp, int argc, char *argv[]);

/**
 * @brief   Custom command entry type.
 */
typedef struct {
  const char            *sc_name;           /**< @brief Command name.       */
  shellcmd_t            sc_function;        /**< @brief Command function.   */
} ShellCommand;

/**
 * @brief   Shell descriptor type.
 */
typedef struct {
  BaseSequentialStream  *sc_channel;        /**< @brief I/O channel associated
                                                 to the shell.              */
  const ShellCommand    *sc_commands;       /**< @brief Shell extra commands
                                                 table.                     */
} ShellConfig;

#if !defined(__DOXYGEN__)
extern event_source_t shell_terminated;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void shellInit(void);
  void shellExit(msg_t msg);
#if CH_CFG_USE_HEAP && CH_CFG_USE_DYNAMIC
  thread_t *shellCreate(const ShellConfig *scp, size_t size, tprio_t prio);
#endif
  thread_t *shellCreateStatic(const ShellConfig *scp, void *wsp,
                              size_t size, tprio_t prio);
  bool shellGetLine(BaseSequentialStream *chp, char *line, unsigned size);
#ifdef __cplusplus
}
#endif

/**
 * @brief For easy remember, chsnprintf() defined as ht_comm_BUff()
 */
#define ht_comm_Buff chsnprintf

/**
 * @brief Start Shell and UART peripheral
 * @details Serial Interface using UART0 (SD1)
 */
void ht_commUART_Init(void);

/**
 * @brief Start Shell and USB peripheral
 * @details Serial Interface using USB0 (SDU1)
 */
void ht_commUSB_Init(void);

/**
 * @brief Re-Initialize Shell Thread
 * @details This routine should be called on main thread with some delays
 */
void ht_commUART_shInit(void);

/**
 * @brief Re-Initialize Shell Thread
 * @details This routine should be called on main thread with some delays
 */
void ht_commUSB_shInit(void);

/**
 * @brief Common message function
 * @param[in] String Message to chprintf() on chosen interface.
 */
void ht_comm_Msg(char *string);

/**
 * @brief Send Message to ESP8266 function
 * @param[in] String Message to serial interface to ESP8266.
 */
void ht_comm_IoT(char *string);

#endif // HT_CONSOLE_H
/** @} */

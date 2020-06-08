/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

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

/**
 * @brief Size off buffer for chsnprintf() on interface
 */
#define IFACE_BUFF_SIZE 128

/**
 * @brief Enables Echo on Shell Console
 */
#define SHELL_ECHO FALSE

/**
 * @brief Enables Prompt on Shell Console
 */
#define SHELL_PROMPT FALSE

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

#endif // HT_CONSOLE_H
/** @} */

/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    stubs.c
 * @brief   Some stubs for compatibility.
 *
 * @addtogroup Main
 * @{
 */

#include <sys/types.h>
#include <stdlib.h>

pid_t _getpid(void){
	return 0;
}

void _exit(int status){
	(void)status;
	
	while(1);
}

int _kill(int pid, int sig){
	(void)pid;
	(void)sig;
	
	return -1;
}

int _open_r(void *reent, const char *file, int flags, int mode){
	(void)reent;
	(void)file;
	(void)flags;
	(void)mode;
	
	return -1;
}

void *__dso_handle = NULL;

/** @} */

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

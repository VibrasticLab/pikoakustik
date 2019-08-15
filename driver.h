#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define SAMPLING_RATE 44100

void system_init(void);

void driver_init(void);

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP); //Amplitudo

void play_wave(void);

void system_loop(void);

#endif


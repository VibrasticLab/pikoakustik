#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <alsa/asoundlib.h>

void system_init(void);

void driver_init(
	int SMPR); // Sampling Rate

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP); //Amplitudo

void play_wave(void);

#endif


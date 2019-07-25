#include <alsa/asoundlib.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>

#include "../driver.h"

snd_pcm_t * handle; // A reference to the sound card
snd_pcm_hw_params_t * params; // Information about hardware params
snd_pcm_uframes_t frames = 4; // The size of the period

int sampling_rate; //global Sampling Rate

WINDOW * mainwin;

void system_init(void){
	if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}

	mvaddstr(13, 33, "Hello, world!");
    refresh();
    sleep(3);

	delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}

void driver_init(void){
  //do nothing
}

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP) //Amplitudo
{
  (void) FR;
  (void) DUR;
  (void) AMP;
  //do nothing
}

void play_wave(void){
  //do nothing
}

#include "driver.h"

double frequency = 500.0;
int durasi = 1;
int amplitudo = 10000;

int main(void){
	system_init();
	driver_init();
	sample_prep(frequency,durasi,amplitudo);
	play_wave();

	while(1){ system_loop(); }
	return 0;
}


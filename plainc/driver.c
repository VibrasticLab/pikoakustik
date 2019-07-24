#include <alsa/asoundlib.h>

#include "../driver.h"

snd_pcm_t * handle; // A reference to the sound card
snd_pcm_hw_params_t * params; // Information about hardware params
snd_pcm_uframes_t frames = 4; // The size of the period

int sampling_rate; //global Sampling Rate

void system_init(void){
   //do nothing on plain C
}

void driver_init(void){
  int dir = 0;
  int rc;

  // Here we open a reference to the sound card
  rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
  if(rc < 0){
    fprintf(stderr,"unable to open defualt device: %s\n", snd_strerror(rc));
    exit(1);
  }

  // Now we allocate memory for the parameters structure on the stack
  snd_pcm_hw_params_alloca(&params);

  // Next, we're going to set all the parameters for the sound card

  // This sets up the soundcard with some default parameters and we'll
  // customize it a bit afterwards
  snd_pcm_hw_params_any(handle, params);

  // Set the samples for each channel to be interleaved
  snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);

  // This says our samples represented as signed, 16 bit integers in
  // little endian format
  snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);

  // We use 2 channels (left audio and right audio)
  snd_pcm_hw_params_set_channels(handle, params, 2);

  // Here we set our sampling rate.
  sampling_rate = SAMPLING_RATE;
  snd_pcm_hw_params_set_rate_near(handle, params, &sampling_rate, &dir);

  // This sets the period size
  snd_pcm_hw_params_set_period_size_near(handle, params, &frames, &dir);

  // Finally, the parameters get written to the sound card
  rc = snd_pcm_hw_params(handle, params);
  if(rc < 0){
    fprintf(stderr, "unable to set the hw params: %s\n",snd_strerror(rc));
    exit(1);
  }

}

void sample_prep(
	double FR, // Frequency (Hz)
	double DUR, //Duration (s)
	int AMP) //Amplitudo
{
  char *buffer;
  double x, y;
  unsigned int sample;
  int i, j;

  // This allocates memory to hold our samples
  buffer = (char *) malloc(frames * 4);

  j = 0;
  for (i=0;i< DUR * sampling_rate; i++){

    // Create a sample and convert it back to an integer
    x = (double) i / (double) sampling_rate;
    y = sin(2.0 * 3.14159 * FR * x);
    sample = AMP * y;
    printf("%d,",sample);

    // Store the sample in our buffer using Little Endian format
    buffer[0 + 4*j] = sample & 0xff;
    buffer[1 + 4*j] = (sample & 0xff00) >> 8;
    buffer[2 + 4*j] = sample & 0xff;
    buffer[3 + 4*j] = (sample & 0xff00) >> 8;

    if(j++ == frames){
      j = snd_pcm_writei(handle, buffer, frames);

      // Check for under runs
      if (j < 0){ snd_pcm_prepare(handle); }
      j = 0;
    }
  }

}

void play_wave(void){
  // Play all remaining samples before exitting
  snd_pcm_drain(handle);

  // Close the sound card handle
  snd_pcm_close(handle);
}

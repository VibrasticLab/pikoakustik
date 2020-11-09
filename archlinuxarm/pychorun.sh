#!/bin/bash

pactl set-default-sink alsa_output.platform-bcm2835_audio.stereo-fallback.2
pactl set-sink-volume @DEFAULT_SINK@ 100%

pychoacoustics

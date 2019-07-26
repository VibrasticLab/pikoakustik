This platform is for STM32F429ZI Discovery board.

Software Requirement:
- arm-none-eabi GCC toolchain
- GNU/Make
- ChibiOS/RT version 3.x
- stlink or stm32flash

on Arch Linux, install using command:
~~~
sudo pacman -S arm-none-eabi-gcc arm-none-eabi-newlib stlink
~~~

Hardware Requirement:
- STM32F401RE Discovery board.
- Audio DAC using I2S interface (e.g MAX98357A)
- Micro SDCard
- Led Indicator
- Push Button

Connection:
- Audio DAC
~~~
STM32	MAX98
----	----
GND		GND
VDD		Vin
VDD		SD (Shutdown)
PC3		Din (Data)
PB10	BCLK
PB12	LRC
~~~
- MicroSDCard
STM32	SDCard
----	----
GND		VSS
VDD		VDD
VDD		DAT2 (10k pullup)
PA4		NSS/DAT3/CD
PA7		MOSI
PA5		CLK
PA6		MISO/DAT0 (10k pullup)
VDD		DAT1 (10k pullup)
~~~

For the record, there's range on:
- Frequency: from 500 to 10000 (not calibrated in Hz)
- Amplitudo: from 10 to 10000 (not calibrated in dB)

To build, just run on top repos directory:
~~~
./build.sh stm32f401nucl
~~~

If no error on compiling, connect board to usb then run:
~~~
sudo st-flash write build/stm32f401nucl/build/pikotes.bin 0x8000000
~~~

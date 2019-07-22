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
- STM32F429ZI Discovery board.
- Audio DAC using I2S interface (e.g MAX98357A)
Connection:
~~~
STM32	MAX98
----	----
GND		GND
3V		Vin
3V		SD (Shutdown)
PC3		Din (Data)
PB10	BCLK
PB12	LRC
~~~

To build, just run on top repos directory:
~~~
./build.sh stm32f429disc
~~~

If no error on compiling, connect board to usb then run:
~~~
sudo st-flash write build/stm32f429disc/build/pikotes.bin 0x8000000
~~~

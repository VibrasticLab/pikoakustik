## Short Description

This work are originally from [here](https://github.com/sam81/pychoacoustics) that reworked and simplified.
Instead of Python, we use C in hope to be more cross-platform.
Detailed build instruction available on each platforms.

Currently supported platform:

- Plain C
- STM32F429ZI (Discovery)
- STM32F401RE (Nucleo)

And planned platform:

- NCurses
- C on GTK+
- STM32F103C8 (BluePill)

To list all currently supported platform run on terminal:
```
./build.sh
```

----

## Platforms and Todo List:

#### Plain C (Abandoned)

- [x] Create Simple Sine Array
- [x] Feed to Audio

#### Test Arry (Abandoned)

- [x] Create Simple Sine Array

#### Test MMC (Abandoned)

- [x] FatFs on SDCard/MMC
	- [x] Simple Write/Append
	- [x] Simple Read
	
#### STM32429ZI Discovery (Abandoned)

- [x] Run-LED Indicator
- [x] Create Simple Sine Array
- [x] Simple Feed Audio (I2S)
- [x] Play test wave in duration





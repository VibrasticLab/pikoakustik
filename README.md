This is audiometri tool project (still in heavy development).
Main chip are STM32F401RE and Audio-DAC MAX98357A.

### Implemented Features:

##### User Interaction:

- [X] LED Run Mode Indicator
	+ [x] Measurement Mode: Blink fast
	+ [x] Idle Mode: Blink slower
	+ [x] No Media Mode: Blink every 2s
- [X] LED TRUE/FALSE
- [X] LED Play Choices
- [X] Button Choices
	+ [x] 3 Button Choices
	+ [x] 3 Choices Random Generator
	+ [x] 3 Choice Answer Placement

###### Data Communication:

- [X] Serial Data
	+ [x] ACM USB-CDC Protocol
	+ [x] Basic Serial commands
	+ [ ] Media handling commands
	+ [ ] Audiometri control commands

- [x] Media Storage
	+ [x] MMC Connector Slot
	+ [x] MMC readyness checking
	+ [x] FATFS as FAT32 handler
	+ [x] Via SPI protocol
	+ [ ] Via SDIO protocol

- [x] IoT Exchanges
	+ [x] ESP-12E slot on PCB
	+ [ ] WiFi handling
	+ [ ] TCP Data exchange
	+ [ ] MQTT Protocol
	+ [ ] Standard Data Format
	+ [ ] Data Identification
	+ [ ] Database Server

###### Audiometri:

- [x] Tone Generator
	+ [x] Generic I2S Protocol
	+ [x] Pure Single Tone
	+ [ ] Calibrated Frequency array
	+ [ ] Calibrated SPL range
	+ [ ] Calibrated SPL scaling

- [x] Hearing Test
	+ [x] User Test Flow
	+ [ ] Convinient Level at 75%
	+ [ ] Random starting SPL
	+ [ ] Up/Down SPL scaling

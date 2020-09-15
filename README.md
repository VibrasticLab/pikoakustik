This is audiometri tool project (still in heavy development).
Main chip are STM32F401RE and Audio-DAC MAX98357A.

### Implemented Features:

##### User Interaction:

- [X] LED Run Mode Indicator
	- [x] Measurement Mode: Blink fast
	- [x] Idle Mode: Blink slow
	- [x] No Media Mode: Blink fast every 2s
- [X] LED TRUE/FALSE
- [X] LED Play/MMC
- [x] LED 3 Choices
- [X] Button Choices
	- [x] 3 Button Choices
	- [x] 3 Choices Random Generator
	- [x] 3 Choice Answer Placement
- [x] Button Reset
- [ ] User-Friendlyness Interface Test (**September 2020**)
- [ ] Build New PCB as Latest Revision  (**October 2020**)

###### Packaging

- [x] Acrilic Protector
- [ ] Box Design
	- [ ] Print 3D (**September 2020**)
	- [ ] Plastic Molding
- [ ] Battery
	- [x] Regulator TP4056
	- [x] LiPo Battery
	- [x] Main Power Button
	- [ ] Charge/Discharge Test (**September 2020**)

###### Data Communication:

- [X] Serial Data
	- [x] ACM USB-CDC Protocol
	- [x] Basic Serial commands
	- [x] Media handling commands
	- [x] Audiometri control commands
	- [x] MQTT Data control commands
	- [ ] HTTP Data control commands (**September 2020**)

- [x] Media Storage
	- [x] MMC Connector Slot
	- [x] MMC readyness checking
	- [x] FATFS as FAT32 handler
	- [x] Via SPI protocol
	- [ ] Via SDIO protocol

- [x] IoT Exchanges
	- [x] ESP-12E slot on PCB
	- [x] ESP-12E power jumper
	- [x] WiFi handling
	- [ ] Access Point handling
	- [ ] Wifi/AP button switch
	- [x] MQTT Protocol
	- [ ] HTTP Data exchange (**September 2020**)
	- [ ] Standard Data Format (**September 2020**)

###### Audiometri:

- [x] Tone Generator
	- [x] Generic I2S Protocol
	- [x] Pure Single Tone
	- [x] Calibrated Frequency array
	- [x] Pop-Click Suppression
	- [ ] Calibrated SPL range
	- [ ] Calibrated SPL scaling
	- [ ] Left/Right Isolation (**September 2020**) 
	
- [ ] Microphone Input (**September 2020**)
	- [ ] Environment Noise Capture (**September 2020**)
	- [ ] Environment Noise Compensation

- [x] Hearing Test
	- [x] User Test Flow
	- [ ] Convinient Level Test (**September 2020**)
	- [ ] Random starting SPL
	- [x] Up/Down SPL scaling
	
- [ ] Mass Production
	- [ ] PCB Electronic (**October 2020**)
		- [ ] Seeed Studio
		- [ ] DigiKey
	- [ ] Packaging

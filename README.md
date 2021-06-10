This is audiometri tool project (still in heavy development).
Main chip are STM32F401RE and Audio-DAC MAX98357A.

### Implemented Features:

#### User Interaction:

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
- [x] User-Friendlyness Interface Test
- [x] Build New PCB as Latest Revision

#### Packaging

- [x] Acrilic Protector
- [ ] Box Design
	- [x] Print 3D
	- [ ] Plastic Molding
	- [ ] Brosur Promo with Good Packaging
- [ ] Battery
	- [x] Regulator TP4056
	- [x] LiPo Battery
	- [x] Main Power Button
	- [ ] Charge/Discharge Test
	- [ ] Battery Manager
	- [ ] No Cap except Run Elco

#### Data Communication:

- [ ] Serial Data
	- [x] ACM USB-CDC Protocol
	- [x] Basic Serial commands
	- [x] Media handling commands
	- [x] Audiometri control commands
	- [x] MQTT Data control commands
	- [ ] HTTP Data control commands

- [x] Media Storage
	- [x] MMC Connector Slot
	- [x] MMC readyness checking
	- [x] FATFS as FAT32 handler
	- [x] Via SPI protocol

- [ ] IoT Exchanges
	- [x] ESP-12E slot on PCB
	- [x] ESP-12E power jumper
	- [x] WiFi handling
	- [x] Access Point handling
	- [ ] Wifi/AP switch command
	- [x] MQTT Protocol
	- [ ] HTTP Data exchange
	- [ ] MQTT Data JSON/Format
	- [ ] HTTP Data JSON/Format

#### Audiometri:

- [ ] Tone Generator
	- [x] Generic I2S Protocol
	- [x] Pure Single Tone
	- [x] Calibrated Frequency array
	- [x] Pop-Click Suppression
	- [x] Calibrated SPL range
	- [x] Calibrated SPL scaling
	- [ ] Left/Right Isolation

- [ ] Microphone Input
	- [ ] Environment Noise Capture
	- [ ] Environment Noise Compensation

- [ ] Hearing Test
	- [x] User Test Flow
	- [ ] **Convinient Level Test**
	- [ ] Random starting SPL
	- [x] Up/Down SPL scaling
	- [ ] Lowest Tone still too loud
	- [ ] Suffle Block
		- [ ] 1 Block is 1 Freq in 1 Channel
		- [ ] Left/Right suffle

- [ ] Mass Production
	- [ ] PCB Electronic
		- [ ] Seeed Studio
		- [ ] DigiKey
	- [ ] Packaging

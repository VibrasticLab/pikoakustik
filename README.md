This is audiometri tool project (still in heavy development).
Main chip are STM32F401RE and Audio-DAC MAX98357A.

---

### Short Description:

- [x] Fungsional

Mengukur Ambang Pendengaran secara mandiri tanpa perlu bantuan dokter spesialis dan tanpa datang ke klinik.

- [x] Portabel

Dapat digunakan dimana saja dan kapan saja. Baterai mudah diisi ulang.

- [x] Terstandar

Telah terkalibrasi standar Audiometri dan teruji pada ruang *un-echoic*.

- [x] Ramah Pengguna

Antar Muka hanya berupa Tombol dan Lampu LED tanpa pengaturan tambahan dan bisa langsung digunakan.

- [x] Terintergrasi

Terhubung dengan penyimpanan *dedicated server* sehingga dapat diakses dokter spesialis secara jarak jauh jika diperlukan.

---

### Marking Rules:
- [ ] Unfinished
- [x] Finished but Open to Improve
- [x] ~~Finished~~
- [ ] ~~Unused but Noted~~

---

### Implemented Features:

#### User Interaction:

- [X] ~~LED Run Mode Indicator~~
	- [x] ~~Measurement Mode: Blink fast~~
	- [x] ~~Idle Mode: Blink slow~~
	- [x] ~~No Media Mode: Blink fast every 2s~~
- [X] ~~LED TRUE/FALSE~~
- [X] ~~LED Play/MMC~~
- [x] ~~LED 3 Choices~~
- [X] ~~Button Choices~~
	- [x] ~~3 Button Choices~~
	- [x] 3 Choices Random Generator
	- [x] ~~3 Choice Answer Placement~~
- [x] ~~Button Reset~~
- [x] ~~User-Friendlyness Interface Test~~
- [ ] LCD Non-Input Interface
	- [ ] LCD SPI ILI9xxx series

---

#### Packaging

- [x] ~~Acrilic Protector~~
- [ ] Box Design
	- [x] Print 3D
	- [ ] Plastic Molding
	- [ ] Brosur Promo with Good Packaging
- [ ] Battery
	- [x] Regulator TP4056
	- [x] ~~LiPo Battery~~
	- [x] ~~Main Power Button~~
	- [ ] Charge/Discharge Test
	- [ ] Battery Manager
	- [x] No Cap except Run Elco

---

#### Data Communication:

- [ ] Serial Data
	- [x] ~~ACM USB-CDC Protocol~~
	- [x] ~~Basic Serial commands~~
	- [x] ~~Media handling commands~~
	- [x] ~~Audiometri control commands~~
	- [ ] HTTP Data control commands

- [x] ~~Media Storage~~
	- [x] ~~MMC Connector Slot~~
	- [x] ~~MMC readyness checking~~
	- [x] ~~FATFS as FAT32 handler~~
	- [x] ~~Via SPI protocol~~

- [ ] IoT Exchanges
	- [x] ESP-12E slot on PCB
	- [x] ESP-12E power jumper
	- [x] WiFi handling
	- [x] Access Point handling
	- [ ] Wifi/AP switch command
	- [ ] HTTP Data exchange
	- [ ] HTTP Data JSON/Format

---

#### Audiometri:

- [ ] Tone Generator
	- [x] ~~Generic I2S Protocol~~
	- [x] ~~Pure Single Tone~~
	- [x] Calibrated Frequency array
	- [x] Pop-Click Suppression
	- [x] Calibrated SPL range
	- [x] Calibrated SPL scaling
	- [x] Left/Right Isolation
	- [ ] Number Headphones
		- [ ] Embedded Tone Model
		- [ ] External Tone Model

- [ ] Hearing Test
	- [x] User Test Flow
	- [ ] **Convinient Level Test**
	- [ ] Random starting SPL
	- [x] Up/Down SPL scaling
	- [ ] Lowest Tone still too loud
	- [ ] Suffle Block
		- [ ] 1 Block is 1 Freq in 1 Channel
		- [ ] Left/Right suffle

- [ ] Microphone Input
	- [ ] Environment Noise Capture
	- [ ] Environment Noise Compensation

- [ ] Mass Production
	- [ ] PCB Electronic
		- [ ] Seeed Studio
		- [ ] ~~DigiKey~~
		- [ ] Xirca
		- [ ] Gerai-Cerdas
		- [ ] ~~Maxtron~~
	- [ ] Packaging





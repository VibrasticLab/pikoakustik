## Audiometri STM32 (RISPRO)

### Sirkuit Terpadu (DTLST)
- [ ] Simpaki sudah dipahami
- [x] Blueprint PCB siap

---------------------------------------------------------

### Paten

#### Layak Paten
- Serial Commands:
	- Audio Speaker Test. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_comm.c#L58-L105)
	- Audio Tone Test. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_comm.c#L243-L323)
- Usage:
	- Start Up Sequence Button
	- Three-Force Choice Input method
- Filesystem:
	- MMC Readyness Indicator

---------------------------------------------------------

#### Common Design, Ambigu, atau Kurang Layak
- Audio methods:
	- Konstanta Persamaan Tone. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L78-L109)
	- Algoritma Tone Generation. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L111-L124)
	- L/R Control. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L131-L139)
- Serial Commands:
	- Audio Zero. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_comm.c#L113-L134)
	- Audio Max. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L140-L161)
	- MMC List. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L402-L407)
	- MMC Show Files. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L413-L420)
	- MMC Show Contents. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L413-L420)
	- MMC Check MMC. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L450-L456)
	- IoT MQTT Subscribe. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L464-L570)
	- IoT MQTT Publish. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L476-L482)
	- IoT HTTP JSON Send. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L488-L495)
	- IoT MQTT Send Log. [Source](https://github.com/VibrasticLab/pikoakustik/blob/stm32f401re_3pin/firmware/ht_audio.c#L501-L512)
- Filesystem:
	- MMC Saving
	- String Parser
- Wifi:
	- Mode Switching
	- MQTT Transfer
	- MQTT JSON Data
	- HTTP JSON Data
- Handheld:
	- Handpalm size
	- Battery Operated Device


##


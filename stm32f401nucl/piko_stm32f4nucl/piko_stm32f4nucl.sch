EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L NUCLEO-64:NUCLEO-64 U1
U 1 1 5D3A5755
P 5850 2950
F 0 "U1" H 5850 4215 50  0000 C CNN
F 1 "NUCLEO-64" H 5850 4124 50  0000 C CNN
F 2 "lib:Nucleo-64" H 5850 2950 50  0001 C CNN
F 3 "DOCUMENTATION" H 5850 2950 50  0001 C CNN
	1    5850 2950
	1    0    0    -1  
$EndComp
$Comp
L NUCLEO-64:NUCLEO-64 U1
U 2 1 5D3A580C
P 9000 2950
F 0 "U1" H 9000 4215 50  0000 C CNN
F 1 "NUCLEO-64" H 9000 4124 50  0000 C CNN
F 2 "lib:Nucleo-64" H 9000 2950 50  0001 C CNN
F 3 "DOCUMENTATION" H 9000 2950 50  0001 C CNN
	2    9000 2950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x07_Female J-DAC1
U 1 1 5D3A5A40
P 3500 2100
F 0 "J-DAC1" H 3527 2126 50  0000 L CNN
F 1 "Conn_01x07_Female" H 3527 2035 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 3500 2100 50  0001 C CNN
F 3 "~" H 3500 2100 50  0001 C CNN
	1    3500 2100
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR0101
U 1 1 5D3A5ABC
P 3000 1750
F 0 "#PWR0101" H 3000 1600 50  0001 C CNN
F 1 "VDD" H 3017 1923 50  0000 C CNN
F 2 "" H 3000 1750 50  0001 C CNN
F 3 "" H 3000 1750 50  0001 C CNN
	1    3000 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1800 3000 1800
Wire Wire Line
	3000 1800 3000 1750
Wire Wire Line
	3300 2000 3000 2000
Wire Wire Line
	3000 2000 3000 1800
Connection ~ 3000 1800
$Comp
L power:GND #PWR0102
U 1 1 5D3A5C2C
P 2750 1900
F 0 "#PWR0102" H 2750 1650 50  0001 C CNN
F 1 "GND" H 2755 1727 50  0000 C CNN
F 2 "" H 2750 1900 50  0001 C CNN
F 3 "" H 2750 1900 50  0001 C CNN
	1    2750 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1900 2750 1900
Wire Wire Line
	3300 2100 3000 2100
Text Label 3000 2100 0    50   ~ 0
GAIN
Wire Wire Line
	3300 2200 3000 2200
Wire Wire Line
	3300 2300 3000 2300
Wire Wire Line
	3300 2400 3000 2400
Text Label 3000 2200 0    50   ~ 0
DATA
Text Label 3000 2300 0    50   ~ 0
BCLK
Text Label 3000 2400 0    50   ~ 0
LRC
Wire Wire Line
	5100 3850 4700 3850
Text Label 4700 3850 0    50   ~ 0
DATA
Wire Wire Line
	8250 3250 7950 3250
Text Label 7950 3250 0    50   ~ 0
BCLK
Wire Wire Line
	9750 2750 10000 2750
Text Label 10000 2750 0    50   ~ 0
LRC
$Comp
L power:VDD #PWR0103
U 1 1 5D3A68AE
P 4700 2250
F 0 "#PWR0103" H 4700 2100 50  0001 C CNN
F 1 "VDD" H 4717 2423 50  0000 C CNN
F 2 "" H 4700 2250 50  0001 C CNN
F 3 "" H 4700 2250 50  0001 C CNN
	1    4700 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2250 4700 2250
$Comp
L power:GND #PWR0104
U 1 1 5D3A6B7F
P 6900 2350
F 0 "#PWR0104" H 6900 2100 50  0001 C CNN
F 1 "GND" H 6905 2177 50  0000 C CNN
F 2 "" H 6900 2350 50  0001 C CNN
F 3 "" H 6900 2350 50  0001 C CNN
	1    6900 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 2350 6600 2350
$Comp
L Connector:Conn_01x02_Female J-HEADPHONE1
U 1 1 5D3A6FF5
P 3500 2550
F 0 "J-HEADPHONE1" H 3527 2526 50  0000 L CNN
F 1 "Conn_01x02_Female" H 3527 2435 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3500 2550 50  0001 C CNN
F 3 "~" H 3500 2550 50  0001 C CNN
	1    3500 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2550 3000 2550
Wire Wire Line
	3300 2650 3000 2650
Text Label 3000 2550 0    50   ~ 0
HP_M
Text Label 3000 2650 0    50   ~ 0
HP_P
$Comp
L Connector:Micro_SD_Card_Det J1
U 1 1 5D3ABF43
P 2900 3800
F 0 "J1" H 2850 4617 50  0000 C CNN
F 1 "Micro_SD_Card_Det" H 2850 4526 50  0000 C CNN
F 2 "Connector_Card:microSD_HC_Hirose_DM3BT-DSF-PEJS" H 4950 4500 50  0001 C CNN
F 3 "https://www.hirose.com/product/en/download_file/key_name/DM3/category/Catalog/doc_file_id/49662/?file_category_id=4&item_id=195&is_series=1" H 2900 3900 50  0001 C CNN
	1    2900 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R-MMC1
U 1 1 5D3AC61F
P 1450 3400
F 0 "R-MMC1" V 1243 3400 50  0000 C CNN
F 1 "10k" V 1334 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1380 3400 50  0001 C CNN
F 3 "~" H 1450 3400 50  0001 C CNN
	1    1450 3400
	0    1    1    0   
$EndComp
$Comp
L Device:R R-MMC3
U 1 1 5D3AC857
P 1450 4100
F 0 "R-MMC3" V 1243 4100 50  0000 C CNN
F 1 "10k" V 1334 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1380 4100 50  0001 C CNN
F 3 "~" H 1450 4100 50  0001 C CNN
	1    1450 4100
	0    1    1    0   
$EndComp
$Comp
L Device:R R-MMC2
U 1 1 5D3AC919
P 1450 4000
F 0 "R-MMC2" V 1243 4000 50  0000 C CNN
F 1 "10k" V 1334 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1380 4000 50  0001 C CNN
F 3 "~" H 1450 4000 50  0001 C CNN
	1    1450 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	2000 4000 1600 4000
Wire Wire Line
	2000 4100 1600 4100
Wire Wire Line
	1600 3400 2000 3400
Wire Wire Line
	1300 3400 1150 3400
Wire Wire Line
	1150 3400 1150 3700
Wire Wire Line
	1150 4100 1300 4100
Wire Wire Line
	1300 4000 1150 4000
Connection ~ 1150 4000
Wire Wire Line
	1150 4000 1150 4100
$Comp
L power:VDD #PWR01
U 1 1 5D3AD722
P 1000 3400
F 0 "#PWR01" H 1000 3250 50  0001 C CNN
F 1 "VDD" H 1017 3573 50  0000 C CNN
F 2 "" H 1000 3400 50  0001 C CNN
F 3 "" H 1000 3400 50  0001 C CNN
	1    1000 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 3400 1150 3400
Connection ~ 1150 3400
Wire Wire Line
	2000 3700 1150 3700
Connection ~ 1150 3700
Wire Wire Line
	1150 3700 1150 4000
$Comp
L power:GND #PWR02
U 1 1 5D3AE22D
P 1700 4200
F 0 "#PWR02" H 1700 3950 50  0001 C CNN
F 1 "GND" H 1705 4027 50  0000 C CNN
F 2 "" H 1700 4200 50  0001 C CNN
F 3 "" H 1700 4200 50  0001 C CNN
	1    1700 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3900 1700 3900
Wire Wire Line
	1700 3900 1700 4200
Wire Wire Line
	2000 3500 1750 3500
Text Label 1750 3500 0    50   ~ 0
MMC_NSS
Wire Wire Line
	2000 3600 1750 3600
Text Label 1750 3600 0    50   ~ 0
MMC_MOSI
Wire Wire Line
	2000 3800 1700 3800
Text Label 1700 3800 0    50   ~ 0
MMC_SCK
Text Label 1800 4000 0    50   ~ 0
MMC_MISO
$Comp
L power:GND #PWR03
U 1 1 5D3B0E12
P 3800 4350
F 0 "#PWR03" H 3800 4100 50  0001 C CNN
F 1 "GND" H 3805 4177 50  0000 C CNN
F 2 "" H 3800 4350 50  0001 C CNN
F 3 "" H 3800 4350 50  0001 C CNN
	1    3800 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4300 3800 4300
Wire Wire Line
	3800 4300 3800 4350
Wire Wire Line
	8250 2550 8000 2550
Text Label 8000 2550 0    50   ~ 0
LED_USER
Wire Wire Line
	5100 3150 4750 3150
Text Label 4750 3150 0    50   ~ 0
BT_USER
$Comp
L Connector:AudioJack3_Ground J-TRS1
U 1 1 5D3BEC69
P 2300 2600
F 0 "J-TRS1" H 2304 2942 50  0000 C CNN
F 1 "AudioJack3_Ground" H 2304 2851 50  0000 C CNN
F 2 "lib:Tayda_3.5mm_stereo_TRS_jack_A-853" H 2300 2600 50  0001 C CNN
F 3 "~" H 2300 2600 50  0001 C CNN
	1    2300 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 2600 2650 2600
Wire Wire Line
	2650 2600 2650 2700
Wire Wire Line
	2650 2700 2500 2700
Wire Wire Line
	2500 2500 2650 2500
Text Label 2650 2500 0    50   ~ 0
HP_M
Text Label 2650 2650 0    50   ~ 0
HP_P
Wire Wire Line
	6600 3750 6900 3750
Wire Wire Line
	6600 3850 6900 3850
Text Label 6900 3750 0    50   ~ 0
BT_A
Text Label 6900 3850 0    50   ~ 0
BT_B
Wire Wire Line
	6600 3450 6900 3450
Text Label 6900 3450 0    50   ~ 0
LED_ANS_FALSE
Wire Wire Line
	6600 3350 6900 3350
Text Label 6900 3350 0    50   ~ 0
LED_ANS_TRUE
Wire Wire Line
	6600 3550 6900 3550
Wire Wire Line
	6600 3650 6900 3650
Text Label 6900 3550 0    50   ~ 0
LED_ANS_A
Text Label 6900 3650 0    50   ~ 0
LED_ANS_B
Wire Wire Line
	5100 2050 4850 2050
Text Label 4850 2050 0    50   ~ 0
MMC_SCK
Wire Wire Line
	5100 2150 4850 2150
Text Label 4850 2150 0    50   ~ 0
MMC_MOSI
Wire Wire Line
	6600 2050 6900 2050
Text Label 6900 2050 0    50   ~ 0
MMC_MISO
Wire Wire Line
	5100 2850 4750 2850
Text Label 4750 2850 0    50   ~ 0
MMC_NSS
Wire Wire Line
	8250 3850 7950 3850
Wire Wire Line
	8250 3750 7950 3750
Text Label 7950 3750 0    50   ~ 0
LED_AMPL
Text Label 7950 3850 0    50   ~ 0
LED_FREQ
Wire Wire Line
	8250 3550 7950 3550
Wire Wire Line
	8250 3450 7950 3450
Wire Wire Line
	8250 3350 7950 3350
Text Label 7950 3550 0    50   ~ 0
LED_M1
Text Label 7950 3450 0    50   ~ 0
LED_M2
Text Label 7950 3350 0    50   ~ 0
LED_M3
Wire Wire Line
	9750 3450 10000 3450
Wire Wire Line
	9750 3350 10000 3350
Text Label 10000 3350 0    50   ~ 0
LED_M5
Text Label 10000 3450 0    50   ~ 0
LED_M4
$Comp
L Connector:Conn_01x03_Male J-GAIN1
U 1 1 5D3FB7F4
P 1500 1950
F 0 "J-GAIN1" H 1606 2228 50  0000 C CNN
F 1 "Conn_01x03_Male" H 1606 2137 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 1500 1950 50  0001 C CNN
F 3 "~" H 1500 1950 50  0001 C CNN
	1    1500 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R-GAIN1
U 1 1 5D3FBA5C
P 1950 1950
F 0 "R-GAIN1" V 1743 1950 50  0000 C CNN
F 1 "R" V 1834 1950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1880 1950 50  0001 C CNN
F 3 "~" H 1950 1950 50  0001 C CNN
	1    1950 1950
	0    1    1    0   
$EndComp
$Comp
L power:VDD #PWR04
U 1 1 5D3FCF38
P 1800 1850
F 0 "#PWR04" H 1800 1700 50  0001 C CNN
F 1 "VDD" H 1817 2023 50  0000 C CNN
F 2 "" H 1800 1850 50  0001 C CNN
F 3 "" H 1800 1850 50  0001 C CNN
	1    1800 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5D3FCFBA
P 1800 2050
F 0 "#PWR05" H 1800 1800 50  0001 C CNN
F 1 "GND" H 1805 1877 50  0000 C CNN
F 2 "" H 1800 2050 50  0001 C CNN
F 3 "" H 1800 2050 50  0001 C CNN
	1    1800 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1850 1800 1850
Wire Wire Line
	1800 1950 1700 1950
Wire Wire Line
	1800 2050 1700 2050
Wire Wire Line
	2100 1950 2250 1950
Text Label 2250 1950 0    50   ~ 0
GAIN
$Comp
L Device:R R-AMPL1
U 1 1 5D403B08
P 5750 4500
F 0 "R-AMPL1" V 5543 4500 50  0000 C CNN
F 1 "100" V 5634 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5680 4500 50  0001 C CNN
F 3 "~" H 5750 4500 50  0001 C CNN
	1    5750 4500
	0    1    1    0   
$EndComp
$Comp
L Device:R R-FREQ1
U 1 1 5D403C83
P 5750 5100
F 0 "R-FREQ1" V 5543 5100 50  0000 C CNN
F 1 "100" V 5634 5100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5680 5100 50  0001 C CNN
F 3 "~" H 5750 5100 50  0001 C CNN
	1    5750 5100
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 4500 5400 4500
Text Label 5400 4500 0    50   ~ 0
LED_AMPL
$Comp
L Device:LED D-AMPL1
U 1 1 5D4088C6
P 6050 4700
F 0 "D-AMPL1" V 6088 4582 50  0000 R CNN
F 1 "LED" V 5997 4582 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6050 4700 50  0001 C CNN
F 3 "~" H 6050 4700 50  0001 C CNN
	1    6050 4700
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-AMPL2
U 1 1 5D40A25C
P 6250 4700
F 0 "D-AMPL2" V 6288 4582 50  0000 R CNN
F 1 "LED" V 6197 4582 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6250 4700 50  0001 C CNN
F 3 "~" H 6250 4700 50  0001 C CNN
	1    6250 4700
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-AMPL3
U 1 1 5D40BA83
P 6450 4700
F 0 "D-AMPL3" V 6488 4582 50  0000 R CNN
F 1 "LED" V 6397 4582 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6450 4700 50  0001 C CNN
F 3 "~" H 6450 4700 50  0001 C CNN
	1    6450 4700
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-AMPL4
U 1 1 5D40BA8A
P 6650 4700
F 0 "D-AMPL4" V 6688 4582 50  0000 R CNN
F 1 "LED" V 6597 4582 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6650 4700 50  0001 C CNN
F 3 "~" H 6650 4700 50  0001 C CNN
	1    6650 4700
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-AMPL5
U 1 1 5D40D29C
P 6850 4700
F 0 "D-AMPL5" V 6888 4582 50  0000 R CNN
F 1 "LED" V 6797 4582 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6850 4700 50  0001 C CNN
F 3 "~" H 6850 4700 50  0001 C CNN
	1    6850 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5900 4500 6050 4500
Wire Wire Line
	6850 4500 6850 4550
Wire Wire Line
	6650 4550 6650 4500
Connection ~ 6650 4500
Wire Wire Line
	6650 4500 6850 4500
Wire Wire Line
	6450 4550 6450 4500
Connection ~ 6450 4500
Wire Wire Line
	6450 4500 6650 4500
Wire Wire Line
	6250 4550 6250 4500
Connection ~ 6250 4500
Wire Wire Line
	6250 4500 6450 4500
Wire Wire Line
	6050 4550 6050 4500
Connection ~ 6050 4500
Wire Wire Line
	6050 4500 6250 4500
Wire Wire Line
	6050 4850 6050 4950
Wire Wire Line
	6250 4850 6250 4950
Wire Wire Line
	6450 4850 6450 4950
Wire Wire Line
	6650 4850 6650 4950
Wire Wire Line
	6850 4850 6850 4950
Text Label 6050 4950 0    50   ~ 0
LED_M1
Text Label 6250 4950 0    50   ~ 0
LED_M2
Text Label 6450 4950 0    50   ~ 0
LED_M3
Text Label 6650 4950 0    50   ~ 0
LED_M4
Text Label 6850 4950 0    50   ~ 0
LED_M5
$Comp
L Device:LED D-FREQ1
U 1 1 5D4247FD
P 6050 5300
F 0 "D-FREQ1" V 6088 5183 50  0000 R CNN
F 1 "LED" V 5997 5183 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6050 5300 50  0001 C CNN
F 3 "~" H 6050 5300 50  0001 C CNN
	1    6050 5300
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-FREQ2
U 1 1 5D4249A5
P 6250 5300
F 0 "D-FREQ2" V 6288 5183 50  0000 R CNN
F 1 "LED" V 6197 5183 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6250 5300 50  0001 C CNN
F 3 "~" H 6250 5300 50  0001 C CNN
	1    6250 5300
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-FREQ3
U 1 1 5D424A57
P 6450 5300
F 0 "D-FREQ3" V 6488 5183 50  0000 R CNN
F 1 "LED" V 6397 5183 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6450 5300 50  0001 C CNN
F 3 "~" H 6450 5300 50  0001 C CNN
	1    6450 5300
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-FREQ4
U 1 1 5D424A5D
P 6650 5300
F 0 "D-FREQ4" V 6688 5183 50  0000 R CNN
F 1 "LED" V 6597 5183 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6650 5300 50  0001 C CNN
F 3 "~" H 6650 5300 50  0001 C CNN
	1    6650 5300
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-FREQ5
U 1 1 5D426866
P 6850 5300
F 0 "D-FREQ5" V 6888 5183 50  0000 R CNN
F 1 "LED" V 6797 5183 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6850 5300 50  0001 C CNN
F 3 "~" H 6850 5300 50  0001 C CNN
	1    6850 5300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5900 5100 6050 5100
Wire Wire Line
	6850 5100 6850 5150
Wire Wire Line
	6650 5150 6650 5100
Connection ~ 6650 5100
Wire Wire Line
	6650 5100 6850 5100
Wire Wire Line
	6450 5150 6450 5100
Connection ~ 6450 5100
Wire Wire Line
	6450 5100 6650 5100
Wire Wire Line
	6250 5150 6250 5100
Connection ~ 6250 5100
Wire Wire Line
	6250 5100 6450 5100
Wire Wire Line
	6050 5150 6050 5100
Connection ~ 6050 5100
Wire Wire Line
	6050 5100 6250 5100
Wire Wire Line
	5600 5100 5400 5100
Text Label 5400 5100 0    50   ~ 0
LED_FREQ
Wire Wire Line
	6850 5450 6850 5600
Wire Wire Line
	6650 5450 6650 5600
Wire Wire Line
	6050 5450 6050 5600
Wire Wire Line
	6250 5450 6250 5600
Wire Wire Line
	6450 5450 6450 5600
Text Label 6050 5600 0    50   ~ 0
LED_M1
Text Label 6250 5600 0    50   ~ 0
LED_M2
Text Label 6450 5600 0    50   ~ 0
LED_M3
Text Label 6650 5600 0    50   ~ 0
LED_M4
Text Label 6850 5600 0    50   ~ 0
LED_M5
$Comp
L Device:LED D-ANS1
U 1 1 5D447389
P 8350 4700
F 0 "D-ANS1" V 8388 4583 50  0000 R CNN
F 1 "LED" V 8297 4583 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8350 4700 50  0001 C CNN
F 3 "~" H 8350 4700 50  0001 C CNN
	1    8350 4700
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-ANS2
U 1 1 5D447552
P 8550 4700
F 0 "D-ANS2" V 8588 4583 50  0000 R CNN
F 1 "LED" V 8497 4583 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8550 4700 50  0001 C CNN
F 3 "~" H 8550 4700 50  0001 C CNN
	1    8550 4700
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R-ANS1
U 1 1 5D44763E
P 8100 4500
F 0 "R-ANS1" V 7893 4500 50  0000 C CNN
F 1 "300" V 7984 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8030 4500 50  0001 C CNN
F 3 "~" H 8100 4500 50  0001 C CNN
	1    8100 4500
	0    1    1    0   
$EndComp
$Comp
L power:VDD #PWR06
U 1 1 5D44A0F2
P 7800 4500
F 0 "#PWR06" H 7800 4350 50  0001 C CNN
F 1 "VDD" H 7817 4673 50  0000 C CNN
F 2 "" H 7800 4500 50  0001 C CNN
F 3 "" H 7800 4500 50  0001 C CNN
	1    7800 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4500 7800 4500
Wire Wire Line
	8250 4500 8350 4500
Wire Wire Line
	8550 4500 8550 4550
Wire Wire Line
	8350 4550 8350 4500
Connection ~ 8350 4500
Wire Wire Line
	8350 4500 8550 4500
Wire Wire Line
	8350 4850 8350 5000
Wire Wire Line
	8550 4850 8550 5000
Text Label 8350 5000 0    50   ~ 0
LED_ANS_A
Text Label 8550 5000 0    50   ~ 0
LED_ANS_B
$Comp
L Device:LED D-ANS3
U 1 1 5D45A485
P 8350 5300
F 0 "D-ANS3" V 8388 5183 50  0000 R CNN
F 1 "LED" V 8297 5183 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8350 5300 50  0001 C CNN
F 3 "~" H 8350 5300 50  0001 C CNN
	1    8350 5300
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-ANS4
U 1 1 5D45A48C
P 8550 5300
F 0 "D-ANS4" V 8588 5183 50  0000 R CNN
F 1 "LED" V 8497 5183 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8550 5300 50  0001 C CNN
F 3 "~" H 8550 5300 50  0001 C CNN
	1    8550 5300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R-ANS2
U 1 1 5D45A493
P 8100 5100
F 0 "R-ANS2" V 7893 5100 50  0000 C CNN
F 1 "300" V 7984 5100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8030 5100 50  0001 C CNN
F 3 "~" H 8100 5100 50  0001 C CNN
	1    8100 5100
	0    1    1    0   
$EndComp
$Comp
L power:VDD #PWR07
U 1 1 5D45A49A
P 7800 5100
F 0 "#PWR07" H 7800 4950 50  0001 C CNN
F 1 "VDD" H 7817 5273 50  0000 C CNN
F 2 "" H 7800 5100 50  0001 C CNN
F 3 "" H 7800 5100 50  0001 C CNN
	1    7800 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 5100 7800 5100
Wire Wire Line
	8250 5100 8350 5100
Wire Wire Line
	8550 5100 8550 5150
Wire Wire Line
	8350 5150 8350 5100
Connection ~ 8350 5100
Wire Wire Line
	8350 5100 8550 5100
Wire Wire Line
	8350 5450 8350 5600
Wire Wire Line
	8550 5450 8550 5600
Text Label 8350 5600 0    50   ~ 0
LED_ANS_TRUE
Text Label 8550 5600 0    50   ~ 0
LED_ANS_FALSE
$Comp
L Connector:Conn_01x04_Male J-UART1
U 1 1 5D4613E9
P 4250 4650
F 0 "J-UART1" H 4356 4928 50  0000 C CNN
F 1 "Conn_01x04_Male" H 4356 4837 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 4250 4650 50  0001 C CNN
F 3 "~" H 4250 4650 50  0001 C CNN
	1    4250 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4750 4600 4750
Text Label 4600 4750 0    50   ~ 0
RX
Wire Wire Line
	4450 4850 4600 4850
Text Label 4600 4850 0    50   ~ 0
TX
$Comp
L power:VDD #PWR08
U 1 1 5D467DA4
P 4750 4550
F 0 "#PWR08" H 4750 4400 50  0001 C CNN
F 1 "VDD" H 4767 4723 50  0000 C CNN
F 2 "" H 4750 4550 50  0001 C CNN
F 3 "" H 4750 4550 50  0001 C CNN
	1    4750 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5D467E27
P 4750 4650
F 0 "#PWR09" H 4750 4400 50  0001 C CNN
F 1 "GND" H 4755 4477 50  0000 C CNN
F 2 "" H 4750 4650 50  0001 C CNN
F 3 "" H 4750 4650 50  0001 C CNN
	1    4750 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4550 4450 4550
Wire Wire Line
	4750 4650 4450 4650
$Comp
L Switch:SW_Push SW-A1
U 1 1 5D46EF4E
P 3550 5250
F 0 "SW-A1" H 3550 5535 50  0000 C CNN
F 1 "SW_Push" H 3550 5444 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 3550 5450 50  0001 C CNN
F 3 "" H 3550 5450 50  0001 C CNN
	1    3550 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5D46F6AB
P 3250 5100
F 0 "R2" H 3320 5146 50  0000 L CNN
F 1 "4k7" H 3320 5055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3180 5100 50  0001 C CNN
F 3 "~" H 3250 5100 50  0001 C CNN
	1    3250 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5D46F77E
P 3550 5400
F 0 "C2" V 3298 5400 50  0000 C CNN
F 1 "C" V 3389 5400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3588 5250 50  0001 C CNN
F 3 "~" H 3550 5400 50  0001 C CNN
	1    3550 5400
	0    1    1    0   
$EndComp
$Comp
L power:VDD #PWR012
U 1 1 5D46F869
P 3250 4850
F 0 "#PWR012" H 3250 4700 50  0001 C CNN
F 1 "VDD" H 3267 5023 50  0000 C CNN
F 2 "" H 3250 4850 50  0001 C CNN
F 3 "" H 3250 4850 50  0001 C CNN
	1    3250 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5D47312E
P 3900 5250
F 0 "#PWR013" H 3900 5000 50  0001 C CNN
F 1 "GND" H 3905 5077 50  0000 C CNN
F 2 "" H 3900 5250 50  0001 C CNN
F 3 "" H 3900 5250 50  0001 C CNN
	1    3900 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 5250 3800 5250
Wire Wire Line
	3700 5400 3800 5400
Wire Wire Line
	3800 5400 3800 5250
Connection ~ 3800 5250
Wire Wire Line
	3800 5250 3900 5250
Wire Wire Line
	3350 5250 3300 5250
Wire Wire Line
	3400 5400 3300 5400
Wire Wire Line
	3300 5400 3300 5250
Connection ~ 3300 5250
Wire Wire Line
	3300 5250 3250 5250
Wire Wire Line
	3250 4850 3250 4950
$Comp
L Switch:SW_Push SW-B1
U 1 1 5D485CB3
P 2600 5250
F 0 "SW-B1" H 2600 5535 50  0000 C CNN
F 1 "SW_Push" H 2600 5444 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 2600 5450 50  0001 C CNN
F 3 "" H 2600 5450 50  0001 C CNN
	1    2600 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5D485CB9
P 2300 5100
F 0 "R1" H 2370 5146 50  0000 L CNN
F 1 "4k7" H 2370 5055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2230 5100 50  0001 C CNN
F 3 "~" H 2300 5100 50  0001 C CNN
	1    2300 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5D485CBF
P 2600 5400
F 0 "C1" V 2348 5400 50  0000 C CNN
F 1 "C" V 2439 5400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2638 5250 50  0001 C CNN
F 3 "~" H 2600 5400 50  0001 C CNN
	1    2600 5400
	0    1    1    0   
$EndComp
$Comp
L power:VDD #PWR010
U 1 1 5D485CC5
P 2300 4850
F 0 "#PWR010" H 2300 4700 50  0001 C CNN
F 1 "VDD" H 2317 5023 50  0000 C CNN
F 2 "" H 2300 4850 50  0001 C CNN
F 3 "" H 2300 4850 50  0001 C CNN
	1    2300 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5D485CCB
P 2950 5250
F 0 "#PWR011" H 2950 5000 50  0001 C CNN
F 1 "GND" H 2955 5077 50  0000 C CNN
F 2 "" H 2950 5250 50  0001 C CNN
F 3 "" H 2950 5250 50  0001 C CNN
	1    2950 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 5250 2850 5250
Wire Wire Line
	2750 5400 2850 5400
Wire Wire Line
	2850 5400 2850 5250
Connection ~ 2850 5250
Wire Wire Line
	2850 5250 2950 5250
Wire Wire Line
	2400 5250 2350 5250
Wire Wire Line
	2450 5400 2350 5400
Wire Wire Line
	2350 5400 2350 5250
Connection ~ 2350 5250
Wire Wire Line
	2350 5250 2300 5250
Wire Wire Line
	2300 4850 2300 4950
$EndSCHEMATC

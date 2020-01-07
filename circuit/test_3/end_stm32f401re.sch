EESchema Schematic File Version 4
EELAYER 30 0
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
L Device:R R-MMC1
U 1 1 5DF803DB
P 2250 1900
F 0 "R-MMC1" V 2043 1900 50  0000 C CNN
F 1 "10K" V 2134 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2180 1900 50  0001 C CNN
F 3 "~" H 2250 1900 50  0001 C CNN
	1    2250 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 2000 2450 2000
Text Label 2450 2000 0    50   ~ 0
MMC_NSS
Wire Wire Line
	2600 2100 2450 2100
Text Label 2450 2100 0    50   ~ 0
MMC_MOSI
Wire Wire Line
	2600 2300 2450 2300
Text Label 2450 2500 0    50   ~ 0
MMC_MISO
$Comp
L Device:R R-MMC2
U 1 1 5DF81CF1
P 2250 2500
F 0 "R-MMC2" V 2043 2500 50  0000 C CNN
F 1 "10K" V 2134 2500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2180 2500 50  0001 C CNN
F 3 "~" H 2250 2500 50  0001 C CNN
	1    2250 2500
	0    1    1    0   
$EndComp
$Comp
L Device:R R-MMC3
U 1 1 5DF81D47
P 2250 2600
F 0 "R-MMC3" V 2043 2600 50  0000 C CNN
F 1 "10K" V 2134 2600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2180 2600 50  0001 C CNN
F 3 "~" H 2250 2600 50  0001 C CNN
	1    2250 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 2500 2600 2500
Wire Wire Line
	2600 2600 2400 2600
Wire Wire Line
	2400 1900 2600 1900
$Comp
L power:GND #PWR04
U 1 1 5DF83198
P 2550 3000
F 0 "#PWR04" H 2550 2750 50  0001 C CNN
F 1 "GND" H 2555 2827 50  0000 C CNN
F 2 "" H 2550 3000 50  0001 C CNN
F 3 "" H 2550 3000 50  0001 C CNN
	1    2550 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 2400 2500 2400
$Comp
L power:VDD #PWR03
U 1 1 5DF848A1
P 1900 1900
F 0 "#PWR03" H 1900 1750 50  0001 C CNN
F 1 "VDD" H 1917 2073 50  0000 C CNN
F 2 "" H 1900 1900 50  0001 C CNN
F 3 "" H 1900 1900 50  0001 C CNN
	1    1900 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1900 1900 1900
Wire Wire Line
	1900 2200 1900 1900
Wire Wire Line
	1900 2200 2600 2200
Connection ~ 1900 1900
Wire Wire Line
	2100 2600 1900 2600
Wire Wire Line
	1900 2200 1900 2500
Connection ~ 1900 2200
Wire Wire Line
	2100 2500 1900 2500
Connection ~ 1900 2500
Wire Wire Line
	1900 2500 1900 2600
Wire Wire Line
	4300 2800 4300 3000
Wire Wire Line
	4300 3000 2550 3000
Wire Wire Line
	2500 3000 2550 3000
Wire Wire Line
	2500 2400 2500 3000
Connection ~ 2550 3000
$Comp
L Switch:SW_Push SW-ANS1
U 1 1 5DF8885D
P 1800 4100
F 0 "SW-ANS1" H 1800 4385 50  0000 C CNN
F 1 "SW_Push" H 1800 4294 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 1800 4300 50  0001 C CNN
F 3 "" H 1800 4300 50  0001 C CNN
	1    1800 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R-ANS1
U 1 1 5DF889EC
P 1550 3900
F 0 "R-ANS1" H 1620 3946 50  0000 L CNN
F 1 "10K" H 1620 3855 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1480 3900 50  0001 C CNN
F 3 "~" H 1550 3900 50  0001 C CNN
	1    1550 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 4100 1550 4100
Wire Wire Line
	1550 4100 1550 4050
Wire Wire Line
	1550 4100 1450 4100
Connection ~ 1550 4100
$Comp
L Device:C C-ANS1
U 1 1 5DF8A23D
P 1800 4250
F 0 "C-ANS1" V 1548 4250 50  0000 C CNN
F 1 "C" V 1639 4250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1838 4100 50  0001 C CNN
F 3 "~" H 1800 4250 50  0001 C CNN
	1    1800 4250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5DF8A2E3
P 2050 4250
F 0 "#PWR06" H 2050 4000 50  0001 C CNN
F 1 "GND" H 2055 4077 50  0000 C CNN
F 2 "" H 2050 4250 50  0001 C CNN
F 3 "" H 2050 4250 50  0001 C CNN
	1    2050 4250
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR05
U 1 1 5DF8A33E
P 1550 3700
F 0 "#PWR05" H 1550 3550 50  0001 C CNN
F 1 "VDD" H 1567 3873 50  0000 C CNN
F 2 "" H 1550 3700 50  0001 C CNN
F 3 "" H 1550 3700 50  0001 C CNN
	1    1550 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 4100 2050 4100
Wire Wire Line
	2050 4100 2050 4250
Wire Wire Line
	1950 4250 2050 4250
Connection ~ 2050 4250
Wire Wire Line
	1650 4250 1550 4250
Wire Wire Line
	1550 4250 1550 4100
Wire Wire Line
	1550 3700 1550 3750
$Comp
L Switch:SW_Push SW-ANS2
U 1 1 5DF8DA86
P 2600 4100
F 0 "SW-ANS2" H 2600 4385 50  0000 C CNN
F 1 "SW_Push" H 2600 4294 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 2600 4300 50  0001 C CNN
F 3 "" H 2600 4300 50  0001 C CNN
	1    2600 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R-ANS2
U 1 1 5DF8DA8D
P 2350 3900
F 0 "R-ANS2" H 2420 3946 50  0000 L CNN
F 1 "10K" H 2420 3855 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2280 3900 50  0001 C CNN
F 3 "~" H 2350 3900 50  0001 C CNN
	1    2350 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4100 2350 4100
Wire Wire Line
	2350 4100 2350 4050
Wire Wire Line
	2350 4100 2250 4100
Connection ~ 2350 4100
$Comp
L Device:C C-ANS2
U 1 1 5DF8DA98
P 2600 4250
F 0 "C-ANS2" V 2348 4250 50  0000 C CNN
F 1 "C" V 2439 4250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2638 4100 50  0001 C CNN
F 3 "~" H 2600 4250 50  0001 C CNN
	1    2600 4250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5DF8DA9F
P 2850 4250
F 0 "#PWR08" H 2850 4000 50  0001 C CNN
F 1 "GND" H 2855 4077 50  0000 C CNN
F 2 "" H 2850 4250 50  0001 C CNN
F 3 "" H 2850 4250 50  0001 C CNN
	1    2850 4250
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR07
U 1 1 5DF8DAA5
P 2350 3700
F 0 "#PWR07" H 2350 3550 50  0001 C CNN
F 1 "VDD" H 2367 3873 50  0000 C CNN
F 2 "" H 2350 3700 50  0001 C CNN
F 3 "" H 2350 3700 50  0001 C CNN
	1    2350 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 4100 2850 4100
Wire Wire Line
	2850 4100 2850 4250
Wire Wire Line
	2750 4250 2850 4250
Connection ~ 2850 4250
Wire Wire Line
	2450 4250 2350 4250
Wire Wire Line
	2350 4250 2350 4100
Wire Wire Line
	2350 3700 2350 3750
Text Label 1450 4100 0    50   ~ 0
BTN_A
Text Label 2250 4100 0    50   ~ 0
BTN_B
$Comp
L Device:R RL-ANS1
U 1 1 5DF9171B
P 1400 5550
F 0 "RL-ANS1" V 1193 5550 50  0000 C CNN
F 1 "330" V 1284 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1330 5550 50  0001 C CNN
F 3 "~" H 1400 5550 50  0001 C CNN
	1    1400 5550
	0    1    1    0   
$EndComp
$Comp
L Device:LED D-ANS1
U 1 1 5DF91865
P 1600 5750
F 0 "D-ANS1" V 1638 5632 50  0000 R CNN
F 1 "LED" V 1547 5632 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1600 5750 50  0001 C CNN
F 3 "~" H 1600 5750 50  0001 C CNN
	1    1600 5750
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-ANS2
U 1 1 5DF91941
P 1800 5750
F 0 "D-ANS2" V 1838 5632 50  0000 R CNN
F 1 "LED" V 1747 5632 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1800 5750 50  0001 C CNN
F 3 "~" H 1800 5750 50  0001 C CNN
	1    1800 5750
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR09
U 1 1 5DF91D82
P 1200 5550
F 0 "#PWR09" H 1200 5400 50  0001 C CNN
F 1 "VDD" H 1217 5723 50  0000 C CNN
F 2 "" H 1200 5550 50  0001 C CNN
F 3 "" H 1200 5550 50  0001 C CNN
	1    1200 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 5550 1200 5550
Wire Wire Line
	1550 5550 1600 5550
Wire Wire Line
	1800 5550 1800 5600
Wire Wire Line
	1600 5600 1600 5550
Connection ~ 1600 5550
Wire Wire Line
	1600 5550 1800 5550
Wire Wire Line
	1600 5900 1600 6000
Wire Wire Line
	1800 5900 1800 6000
$Comp
L Device:R RL-BTN1
U 1 1 5DF97D52
P 2150 5550
F 0 "RL-BTN1" V 1943 5550 50  0000 C CNN
F 1 "330" V 2034 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2080 5550 50  0001 C CNN
F 3 "~" H 2150 5550 50  0001 C CNN
	1    2150 5550
	0    1    1    0   
$EndComp
$Comp
L Device:LED D-BTN1
U 1 1 5DF97D59
P 2350 5750
F 0 "D-BTN1" V 2388 5632 50  0000 R CNN
F 1 "LED" V 2297 5632 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2350 5750 50  0001 C CNN
F 3 "~" H 2350 5750 50  0001 C CNN
	1    2350 5750
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D-BTN2
U 1 1 5DF97D60
P 2550 5750
F 0 "D-BTN2" V 2588 5632 50  0000 R CNN
F 1 "LED" V 2497 5632 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2550 5750 50  0001 C CNN
F 3 "~" H 2550 5750 50  0001 C CNN
	1    2550 5750
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR010
U 1 1 5DF97D67
P 1950 5550
F 0 "#PWR010" H 1950 5400 50  0001 C CNN
F 1 "VDD" H 1967 5723 50  0000 C CNN
F 2 "" H 1950 5550 50  0001 C CNN
F 3 "" H 1950 5550 50  0001 C CNN
	1    1950 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 5550 1950 5550
Wire Wire Line
	2300 5550 2350 5550
Wire Wire Line
	2550 5550 2550 5600
Wire Wire Line
	2350 5600 2350 5550
Connection ~ 2350 5550
Wire Wire Line
	2350 5550 2550 5550
Wire Wire Line
	2350 5900 2350 6000
Wire Wire Line
	2550 5900 2550 6000
Text Label 1600 6000 3    50   ~ 0
LED_TRUE
Text Label 1800 6000 3    50   ~ 0
LED_FALSE
Text Label 2350 6000 3    50   ~ 0
LED_A
Text Label 2550 6000 3    50   ~ 0
LED_B
$Comp
L Connector:USB_B_Micro J2
U 1 1 5DF9FD65
P 4150 3650
F 0 "J2" H 3921 3641 50  0000 R CNN
F 1 "USB_B_Micro" H 3921 3550 50  0000 R CNN
F 2 "Connector_USB:USB_Micro-B_Wuerth_629105150521" H 4300 3600 50  0001 C CNN
F 3 "~" H 4300 3600 50  0001 C CNN
	1    4150 3650
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R-USB3
U 1 1 5DFABBF5
P 3600 3750
F 0 "R-USB3" V 3393 3750 50  0000 C CNN
F 1 "68" V 3484 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3530 3750 50  0001 C CNN
F 3 "~" H 3600 3750 50  0001 C CNN
	1    3600 3750
	0    1    1    0   
$EndComp
$Comp
L Device:R R-USB2
U 1 1 5DFABD4C
P 3600 3650
F 0 "R-USB2" V 3393 3650 50  0000 C CNN
F 1 "68" V 3484 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3530 3650 50  0001 C CNN
F 3 "~" H 3600 3650 50  0001 C CNN
	1    3600 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 3650 3800 3650
Wire Wire Line
	3850 3750 3750 3750
$Comp
L Device:R R-USB1
U 1 1 5DFAEBDC
P 3600 3550
F 0 "R-USB1" V 3393 3550 50  0000 C CNN
F 1 "4K7" V 3484 3550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3530 3550 50  0001 C CNN
F 3 "~" H 3600 3550 50  0001 C CNN
	1    3600 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 3550 3800 3550
Wire Wire Line
	3800 3550 3800 3650
Connection ~ 3800 3650
Wire Wire Line
	3800 3650 3750 3650
$Comp
L power:VDD #PWR011
U 1 1 5DFB070D
P 3350 3550
F 0 "#PWR011" H 3350 3400 50  0001 C CNN
F 1 "VDD" H 3367 3723 50  0000 C CNN
F 2 "" H 3350 3550 50  0001 C CNN
F 3 "" H 3350 3550 50  0001 C CNN
	1    3350 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3550 3350 3550
$Comp
L power:GND #PWR017
U 1 1 5DFB4713
P 4150 4100
F 0 "#PWR017" H 4150 3850 50  0001 C CNN
F 1 "GND" H 4155 3927 50  0000 C CNN
F 2 "" H 4150 4100 50  0001 C CNN
F 3 "" H 4150 4100 50  0001 C CNN
	1    4150 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 4050 4250 4100
Wire Wire Line
	4250 4100 4150 4100
Wire Wire Line
	4150 4050 4150 4100
Connection ~ 4150 4100
Wire Wire Line
	3450 3650 3350 3650
Wire Wire Line
	3450 3750 3350 3750
Text Label 3350 3650 0    50   ~ 0
USB_DP
Text Label 3350 3750 0    50   ~ 0
USB_DM
$Comp
L Connector:Conn_01x03_Male J-GAIN1
U 1 1 5DFE447F
P 9100 4850
F 0 "J-GAIN1" H 9206 5128 50  0000 C CNN
F 1 "Conn_01x03_Male" H 9206 5037 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical_SMD_Pin1Left" H 9100 4850 50  0001 C CNN
F 3 "~" H 9100 4850 50  0001 C CNN
	1    9100 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 4850 9300 4850
$Comp
L power:VDD #PWR012
U 1 1 5DFE73FA
P 9350 4750
F 0 "#PWR012" H 9350 4600 50  0001 C CNN
F 1 "VDD" H 9367 4923 50  0000 C CNN
F 2 "" H 9350 4750 50  0001 C CNN
F 3 "" H 9350 4750 50  0001 C CNN
	1    9350 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5DFE746E
P 9350 4950
F 0 "#PWR013" H 9350 4700 50  0001 C CNN
F 1 "GND" H 9355 4777 50  0000 C CNN
F 2 "" H 9350 4950 50  0001 C CNN
F 3 "" H 9350 4950 50  0001 C CNN
	1    9350 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 4750 9300 4750
Wire Wire Line
	9350 4950 9300 4950
$Comp
L Connector:AudioJack3_Ground J-AUDIO1
U 1 1 5DFEDF17
P 4100 5150
F 0 "J-AUDIO1" H 4104 5492 50  0000 C CNN
F 1 "AudioJack3_Ground" H 4104 5401 50  0000 C CNN
F 2 "user:Tayda_3.5mm_stereo_TRS_jack_A-853" H 4100 5150 50  0001 C CNN
F 3 "~" H 4100 5150 50  0001 C CNN
	1    4100 5150
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R-IND1
U 1 1 5DFFE85F
P 3000 5600
F 0 "R-IND1" H 3070 5646 50  0000 L CNN
F 1 "330" H 3070 5555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2930 5600 50  0001 C CNN
F 3 "~" H 3000 5600 50  0001 C CNN
	1    3000 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D-IND1
U 1 1 5E002253
P 3000 5950
F 0 "D-IND1" V 3038 5833 50  0000 R CNN
F 1 "LED" V 2947 5833 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3000 5950 50  0001 C CNN
F 3 "~" H 3000 5950 50  0001 C CNN
	1    3000 5950
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR019
U 1 1 5E00247F
P 3000 5400
F 0 "#PWR019" H 3000 5250 50  0001 C CNN
F 1 "VDD" H 3017 5573 50  0000 C CNN
F 2 "" H 3000 5400 50  0001 C CNN
F 3 "" H 3000 5400 50  0001 C CNN
	1    3000 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 5750 3000 5800
Wire Wire Line
	3000 5400 3000 5450
Wire Wire Line
	3000 6100 3000 6200
Text Label 3000 6200 1    50   ~ 0
LED_IND
$Comp
L Device:R R-GAIN1
U 1 1 5DFDEB05
P 9550 4850
F 0 "R-GAIN1" V 9343 4850 50  0000 C CNN
F 1 "100K" V 9434 4850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9480 4850 50  0001 C CNN
F 3 "~" H 9550 4850 50  0001 C CNN
	1    9550 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	9900 4850 9700 4850
Wire Wire Line
	3650 5050 3900 5050
Text Label 2450 2300 0    50   ~ 0
MMC_SCK
$Comp
L MCU_ST_STM32F4:STM32F401RETx U2
U 1 1 5DFBFBB4
P 7150 3200
F 0 "U2" H 7100 5078 50  0000 C CNN
F 1 "STM32F401RETx" H 7100 4987 50  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 6550 1500 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00102166.pdf" H 7150 3200 50  0001 C CNN
	1    7150 3200
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR0102
U 1 1 5DFC1D46
P 6450 1250
F 0 "#PWR0102" H 6450 1100 50  0001 C CNN
F 1 "VDD" H 6467 1423 50  0000 C CNN
F 2 "" H 6450 1250 50  0001 C CNN
F 3 "" H 6450 1250 50  0001 C CNN
	1    6450 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1500 7250 1500
Wire Wire Line
	7250 1500 7150 1500
Connection ~ 7250 1500
Wire Wire Line
	7150 1500 7050 1500
Connection ~ 7150 1500
$Comp
L power:GND #PWR0103
U 1 1 5DFCB701
P 6950 5100
F 0 "#PWR0103" H 6950 4850 50  0001 C CNN
F 1 "GND" H 6955 4927 50  0000 C CNN
F 2 "" H 6950 5100 50  0001 C CNN
F 3 "" H 6950 5100 50  0001 C CNN
	1    6950 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 5000 7250 5000
Wire Wire Line
	7150 5000 7250 5000
Connection ~ 7250 5000
Wire Wire Line
	7150 5000 7050 5000
Connection ~ 7150 5000
Wire Wire Line
	7050 5000 6950 5000
Connection ~ 7050 5000
Wire Wire Line
	6950 5100 6950 5000
Connection ~ 6950 5000
$Comp
L Device:R R-RST1
U 1 1 5DFD6BE8
P 6450 1450
F 0 "R-RST1" H 6520 1496 50  0000 L CNN
F 1 "10K" H 6520 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6380 1450 50  0001 C CNN
F 3 "~" H 6450 1450 50  0001 C CNN
	1    6450 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 1600 6450 1700
$Comp
L Switch:SW_Push SW-RST1
U 1 1 5DFDB8B6
P 6200 1700
F 0 "SW-RST1" H 6200 1985 50  0000 C CNN
F 1 "SW_Push" H 6200 1894 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6200 1900 50  0001 C CNN
F 3 "" H 6200 1900 50  0001 C CNN
	1    6200 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 1700 6450 1700
Connection ~ 6450 1700
$Comp
L power:GND #PWR0104
U 1 1 5DFDDEEE
P 5900 1700
F 0 "#PWR0104" H 5900 1450 50  0001 C CNN
F 1 "GND" H 5905 1527 50  0000 C CNN
F 2 "" H 5900 1700 50  0001 C CNN
F 3 "" H 5900 1700 50  0001 C CNN
	1    5900 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 1700 5900 1700
Wire Wire Line
	6150 4300 6450 4300
Text Label 6150 4300 0    50   ~ 0
MMC_SCK
Wire Wire Line
	6450 4400 6150 4400
Text Label 6150 4400 0    50   ~ 0
MMC_MISO
Wire Wire Line
	6450 4500 6150 4500
Text Label 6150 4500 0    50   ~ 0
MMC_MOSI
Wire Wire Line
	7750 3200 8050 3200
Text Label 8050 3200 0    50   ~ 0
MMC_NSS
Wire Wire Line
	6450 3600 6150 3600
Text Label 6150 3600 0    50   ~ 0
DAC_DIN
Wire Wire Line
	7750 4400 8050 4400
Text Label 8050 4400 0    50   ~ 0
DAC_BCLK
Wire Wire Line
	7750 4500 8050 4500
Text Label 8050 4500 0    50   ~ 0
DAC_LRC
Wire Wire Line
	7750 2800 8050 2800
Text Label 8050 2800 0    50   ~ 0
USB_DM
Wire Wire Line
	7750 2900 8050 2900
Text Label 8050 2900 0    50   ~ 0
USB_DP
$Comp
L Connector:Micro_SD_Card_Det J1
U 1 1 5E0EF0FC
P 3500 2300
F 0 "J1" H 3450 3117 50  0000 C CNN
F 1 "Micro_SD_Card_Det" H 3450 3026 50  0000 C CNN
F 2 "Connector_Card:microSD_HC_Hirose_DM3BT-DSF-PEJS" H 5550 3000 50  0001 C CNN
F 3 "https://www.hirose.com/product/en/download_file/key_name/DM3/category/Catalog/doc_file_id/49662/?file_category_id=4&item_id=195&is_series=1" H 3500 2400 50  0001 C CNN
	1    3500 2300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male J-SWD1
U 1 1 5E12FFBB
P 4900 2050
F 0 "J-SWD1" H 5008 2431 50  0000 C CNN
F 1 "Conn_01x05_Male" H 5008 2340 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 4900 2050 50  0001 C CNN
F 3 "~" H 4900 2050 50  0001 C CNN
	1    4900 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2150 5250 2150
Wire Wire Line
	5100 2250 5250 2250
$Comp
L power:VDD #PWR0105
U 1 1 5E14F16B
P 5450 1850
F 0 "#PWR0105" H 5450 1700 50  0001 C CNN
F 1 "VDD" H 5467 2023 50  0000 C CNN
F 2 "" H 5450 1850 50  0001 C CNN
F 3 "" H 5450 1850 50  0001 C CNN
	1    5450 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5E1536C5
P 5450 2050
F 0 "#PWR0106" H 5450 1800 50  0001 C CNN
F 1 "GND" H 5455 1877 50  0000 C CNN
F 2 "" H 5450 2050 50  0001 C CNN
F 3 "" H 5450 2050 50  0001 C CNN
	1    5450 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 1850 5450 1850
Wire Wire Line
	5100 2050 5450 2050
Wire Wire Line
	5100 1950 5250 1950
Text Label 5250 1950 0    50   ~ 0
SW_CLK
Text Label 5250 2150 0    50   ~ 0
SW_DIO
Wire Wire Line
	6450 1700 6450 1750
Text Label 6450 1750 0    50   ~ 0
NRST
Text Label 5250 2250 0    50   ~ 0
NRST
$Comp
L Device:Crystal Y-XTAL1
U 1 1 5E0F57F8
P 6250 2850
F 0 "Y-XTAL1" V 6296 2719 50  0000 R CNN
F 1 "16MHz" V 6205 2719 50  0000 R CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 6250 2850 50  0001 C CNN
F 3 "~" H 6250 2850 50  0001 C CNN
	1    6250 2850
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C-XTAL1
U 1 1 5E0FF08A
P 5950 2700
F 0 "C-XTAL1" V 5698 2700 50  0000 C CNN
F 1 "C" V 5789 2700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5988 2550 50  0001 C CNN
F 3 "~" H 5950 2700 50  0001 C CNN
	1    5950 2700
	0    1    1    0   
$EndComp
$Comp
L Device:C C-XTAL2
U 1 1 5E10070F
P 5950 3000
F 0 "C-XTAL2" V 5698 3000 50  0000 C CNN
F 1 "C" V 5789 3000 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5988 2850 50  0001 C CNN
F 3 "~" H 5950 3000 50  0001 C CNN
	1    5950 3000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5E101087
P 5700 2850
F 0 "#PWR01" H 5700 2600 50  0001 C CNN
F 1 "GND" H 5705 2677 50  0000 C CNN
F 2 "" H 5700 2850 50  0001 C CNN
F 3 "" H 5700 2850 50  0001 C CNN
	1    5700 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 2800 6450 2700
Wire Wire Line
	6450 2700 6250 2700
Wire Wire Line
	6100 2700 6250 2700
Connection ~ 6250 2700
Wire Wire Line
	6100 3000 6250 3000
Wire Wire Line
	6250 3000 6450 3000
Wire Wire Line
	6450 3000 6450 2900
Connection ~ 6250 3000
Wire Wire Line
	5800 2700 5800 2850
Wire Wire Line
	5700 2850 5800 2850
Connection ~ 5800 2850
Wire Wire Line
	5800 2850 5800 3000
$Comp
L power:VDD #PWR0107
U 1 1 5E14C637
P 7350 1450
F 0 "#PWR0107" H 7350 1300 50  0001 C CNN
F 1 "VDD" H 7367 1623 50  0000 C CNN
F 2 "" H 7350 1450 50  0001 C CNN
F 3 "" H 7350 1450 50  0001 C CNN
	1    7350 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1450 7350 1500
Connection ~ 7350 1500
Wire Wire Line
	6450 1250 6450 1300
Wire Wire Line
	6950 1500 7050 1500
Connection ~ 7050 1500
$Comp
L Regulator_Linear:AMS1117-3.3 U3
U 1 1 5E1A4C7C
P 5150 4850
F 0 "U3" H 5150 5092 50  0000 C CNN
F 1 "AMS1117-3.3" H 5150 5001 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 5150 5050 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 5250 4600 50  0001 C CNN
	1    5150 4850
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR0108
U 1 1 5E1AC6BA
P 5850 4850
F 0 "#PWR0108" H 5850 4700 50  0001 C CNN
F 1 "VDD" H 5867 5023 50  0000 C CNN
F 2 "" H 5850 4850 50  0001 C CNN
F 3 "" H 5850 4850 50  0001 C CNN
	1    5850 4850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0109
U 1 1 5E1AE0F1
P 4750 4850
F 0 "#PWR0109" H 4750 4700 50  0001 C CNN
F 1 "VCC" H 4767 5023 50  0000 C CNN
F 2 "" H 4750 4850 50  0001 C CNN
F 3 "" H 4750 4850 50  0001 C CNN
	1    4750 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5E1BEC32
P 5150 5250
F 0 "#PWR0111" H 5150 5000 50  0001 C CNN
F 1 "GND" H 5155 5077 50  0000 C CNN
F 2 "" H 5150 5250 50  0001 C CNN
F 3 "" H 5150 5250 50  0001 C CNN
	1    5150 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C-VREG2
U 1 1 5E1BF4DE
P 5850 5050
F 0 "C-VREG2" H 5965 5096 50  0000 L CNN
F 1 "C" H 5965 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5888 4900 50  0001 C CNN
F 3 "~" H 5850 5050 50  0001 C CNN
	1    5850 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C-VREG1
U 1 1 5E1BFCF1
P 4750 5050
F 0 "C-VREG1" H 4865 5096 50  0000 L CNN
F 1 "C" H 4865 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4788 4900 50  0001 C CNN
F 3 "~" H 4750 5050 50  0001 C CNN
	1    4750 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 5200 5150 5200
Wire Wire Line
	5150 5150 5150 5200
Connection ~ 5150 5200
Wire Wire Line
	5150 5250 5150 5200
Wire Wire Line
	4850 4850 4750 4850
Wire Wire Line
	4750 4900 4750 4850
Connection ~ 4750 4850
Wire Wire Line
	5850 4900 5850 4850
Connection ~ 5850 4850
$Comp
L Connector:Conn_01x03_Male J-VREG1
U 1 1 5E1EC603
P 5300 3750
F 0 "J-VREG1" H 5408 4031 50  0000 C CNN
F 1 "Conn_01x03_Male" H 5408 3940 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5300 3750 50  0001 C CNN
F 3 "~" H 5300 3750 50  0001 C CNN
	1    5300 3750
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR0112
U 1 1 5E1EE69F
P 5700 3650
F 0 "#PWR0112" H 5700 3500 50  0001 C CNN
F 1 "VDD" H 5717 3823 50  0000 C CNN
F 2 "" H 5700 3650 50  0001 C CNN
F 3 "" H 5700 3650 50  0001 C CNN
	1    5700 3650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0113
U 1 1 5E1EF094
P 5600 3650
F 0 "#PWR0113" H 5600 3500 50  0001 C CNN
F 1 "VCC" H 5617 3823 50  0000 C CNN
F 2 "" H 5600 3650 50  0001 C CNN
F 3 "" H 5600 3650 50  0001 C CNN
	1    5600 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5E1EF953
P 5600 3850
F 0 "#PWR0114" H 5600 3600 50  0001 C CNN
F 1 "GND" H 5605 3677 50  0000 C CNN
F 2 "" H 5600 3850 50  0001 C CNN
F 3 "" H 5600 3850 50  0001 C CNN
	1    5600 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 3850 5500 3850
Wire Wire Line
	5500 3750 5700 3750
Wire Wire Line
	5700 3750 5700 3650
Wire Wire Line
	5500 3650 5600 3650
Wire Wire Line
	7750 1800 8050 1800
Text Label 8050 1800 0    50   ~ 0
LED_IND
Wire Wire Line
	7750 2100 8050 2100
Text Label 8050 2100 0    50   ~ 0
LED_A
Wire Wire Line
	7750 3400 8050 3400
Text Label 8050 3400 0    50   ~ 0
LED_B
Wire Wire Line
	7750 1900 8050 1900
Text Label 8050 1900 0    50   ~ 0
LED_TRUE
Wire Wire Line
	7750 2000 8050 2000
Text Label 8050 2000 0    50   ~ 0
LED_FALSE
Wire Wire Line
	6450 3300 6150 3300
Text Label 6150 3300 0    50   ~ 0
BTN_A
Wire Wire Line
	6450 3400 6150 3400
Text Label 6150 3400 0    50   ~ 0
BTN_B
Wire Wire Line
	7750 3000 8050 3000
Wire Wire Line
	7750 3100 8050 3100
Text Label 8050 3000 0    50   ~ 0
SW_DIO
Text Label 8050 3100 0    50   ~ 0
SW_CLK
$Comp
L power:GND #PWR0110
U 1 1 5E190E0F
P 6300 1900
F 0 "#PWR0110" H 6300 1650 50  0001 C CNN
F 1 "GND" H 6305 1727 50  0000 C CNN
F 2 "" H 6300 1900 50  0001 C CNN
F 3 "" H 6300 1900 50  0001 C CNN
	1    6300 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 1900 6300 1900
$Comp
L codec:MAX98357 U1
U 1 1 5E120AA2
P 9350 2250
F 0 "U1" H 9350 2937 60  0000 C CNN
F 1 "MAX98357" H 9350 2831 60  0000 C CNN
F 2 "Package_DFN_QFN:QFN-16-1EP_3x3mm_P0.5mm_EP1.7x1.7mm" H 9350 2250 60  0001 C CNN
F 3 "" H 9350 2250 60  0001 C CNN
	1    9350 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 5150 3650 5150
Wire Wire Line
	3900 5250 3650 5250
Wire Wire Line
	8800 1850 8600 1850
Text Label 9900 4850 0    50   ~ 0
DAC_GAIN
Text Label 8600 1850 0    50   ~ 0
DAC_L_SD
Wire Wire Line
	8800 1950 8600 1950
Text Label 8600 1950 0    50   ~ 0
DAC_BCLK
Wire Wire Line
	8800 2050 8600 2050
Text Label 8600 2050 0    50   ~ 0
DAC_LRC
Wire Wire Line
	8800 2150 8600 2150
Text Label 8600 2150 0    50   ~ 0
DAC_DIN
Wire Wire Line
	8800 2350 8600 2350
Text Label 8600 2350 0    50   ~ 0
DAC_GAIN
$Comp
L power:VDD #PWR02
U 1 1 5E1BAD35
P 10000 2150
F 0 "#PWR02" H 10000 2000 50  0001 C CNN
F 1 "VDD" H 10017 2323 50  0000 C CNN
F 2 "" H 10000 2150 50  0001 C CNN
F 3 "" H 10000 2150 50  0001 C CNN
	1    10000 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 2150 10000 2150
Wire Wire Line
	9900 2250 10000 2250
Wire Wire Line
	10000 2250 10000 2150
Connection ~ 10000 2150
$Comp
L power:GND #PWR014
U 1 1 5E1C5F62
P 10000 2650
F 0 "#PWR014" H 10000 2400 50  0001 C CNN
F 1 "GND" H 10005 2477 50  0000 C CNN
F 2 "" H 10000 2650 50  0001 C CNN
F 3 "" H 10000 2650 50  0001 C CNN
	1    10000 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 2650 10000 2650
Wire Wire Line
	9900 2550 10000 2550
Wire Wire Line
	10000 2550 10000 2650
Connection ~ 10000 2650
Wire Wire Line
	9900 2450 10000 2450
Wire Wire Line
	10000 2450 10000 2550
Connection ~ 10000 2550
$Comp
L codec:MAX98357 U4
U 1 1 5E1DCD49
P 9350 3700
F 0 "U4" H 9350 4387 60  0000 C CNN
F 1 "MAX98357" H 9350 4281 60  0000 C CNN
F 2 "Package_DFN_QFN:QFN-16-1EP_3x3mm_P0.5mm_EP1.7x1.7mm" H 9350 3700 60  0001 C CNN
F 3 "" H 9350 3700 60  0001 C CNN
	1    9350 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 3300 8600 3300
Text Label 8600 3300 0    50   ~ 0
DAC_R_SD
Wire Wire Line
	8800 3400 8600 3400
Text Label 8600 3400 0    50   ~ 0
DAC_BCLK
Wire Wire Line
	8800 3500 8600 3500
Text Label 8600 3500 0    50   ~ 0
DAC_LRC
Wire Wire Line
	8800 3600 8600 3600
Text Label 8600 3600 0    50   ~ 0
DAC_DIN
Wire Wire Line
	8800 3800 8600 3800
Text Label 8600 3800 0    50   ~ 0
DAC_GAIN
$Comp
L power:VDD #PWR015
U 1 1 5E1DCD59
P 10000 3600
F 0 "#PWR015" H 10000 3450 50  0001 C CNN
F 1 "VDD" H 10017 3773 50  0000 C CNN
F 2 "" H 10000 3600 50  0001 C CNN
F 3 "" H 10000 3600 50  0001 C CNN
	1    10000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 3600 10000 3600
Wire Wire Line
	9900 3700 10000 3700
Wire Wire Line
	10000 3700 10000 3600
Connection ~ 10000 3600
$Comp
L power:GND #PWR016
U 1 1 5E1DCD63
P 10000 4100
F 0 "#PWR016" H 10000 3850 50  0001 C CNN
F 1 "GND" H 10005 3927 50  0000 C CNN
F 2 "" H 10000 4100 50  0001 C CNN
F 3 "" H 10000 4100 50  0001 C CNN
	1    10000 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 4100 10000 4100
Wire Wire Line
	9900 4000 10000 4000
Wire Wire Line
	10000 4000 10000 4100
Connection ~ 10000 4100
Wire Wire Line
	9900 3900 10000 3900
Wire Wire Line
	10000 3900 10000 4000
Connection ~ 10000 4000
Text Label 3650 5050 0    50   ~ 0
OUTN
Text Label 3650 5150 0    50   ~ 0
OUTP_R
Text Label 3650 5250 0    50   ~ 0
OUTP_L
$Comp
L Device:L L-DACP1
U 1 1 5E12C45B
P 10150 1850
F 0 "L-DACP1" V 9969 1850 50  0000 C CNN
F 1 "L" V 10060 1850 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10150 1850 50  0001 C CNN
F 3 "~" H 10150 1850 50  0001 C CNN
	1    10150 1850
	0    1    1    0   
$EndComp
$Comp
L Device:L L-DACN1
U 1 1 5E12D290
P 10150 1950
F 0 "L-DACN1" V 9969 1950 50  0000 C CNN
F 1 "L" V 10060 1950 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10150 1950 50  0001 C CNN
F 3 "~" H 10150 1950 50  0001 C CNN
	1    10150 1950
	0    1    1    0   
$EndComp
$Comp
L Device:L L-DACP2
U 1 1 5E13714B
P 10150 3300
F 0 "L-DACP2" V 9969 3300 50  0000 C CNN
F 1 "L" V 10060 3300 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10150 3300 50  0001 C CNN
F 3 "~" H 10150 3300 50  0001 C CNN
	1    10150 3300
	0    1    1    0   
$EndComp
$Comp
L Device:L L-DACN2
U 1 1 5E137155
P 10150 3400
F 0 "L-DACN2" V 9969 3400 50  0000 C CNN
F 1 "L" V 10060 3400 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10150 3400 50  0001 C CNN
F 3 "~" H 10150 3400 50  0001 C CNN
	1    10150 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	10000 1850 9900 1850
Wire Wire Line
	10000 1950 9900 1950
Wire Wire Line
	10000 3300 9900 3300
Wire Wire Line
	10000 3400 9900 3400
$Comp
L Device:C C-VREG3
U 1 1 5E174246
P 6050 5050
F 0 "C-VREG3" H 6165 5096 50  0000 L CNN
F 1 "C" H 6165 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6088 4900 50  0001 C CNN
F 3 "~" H 6050 5050 50  0001 C CNN
	1    6050 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4900 6050 4850
Wire Wire Line
	6050 4850 5850 4850
Wire Wire Line
	6050 5200 5850 5200
Wire Wire Line
	10300 1850 10450 1850
Wire Wire Line
	10300 1950 10450 1950
Wire Wire Line
	10300 3300 10450 3300
Wire Wire Line
	10300 3400 10450 3400
Text Label 10450 1950 0    50   ~ 0
OUTN
Text Label 10450 3300 0    50   ~ 0
OUTP_R
Text Label 10450 3400 0    50   ~ 0
OUTN
Text Label 10450 1850 0    50   ~ 0
OUTP_L
$Comp
L Device:C C-SPR1
U 1 1 5E1FE036
P 10350 2650
F 0 "C-SPR1" H 10465 2696 50  0000 L CNN
F 1 "C" H 10465 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10388 2500 50  0001 C CNN
F 3 "~" H 10350 2650 50  0001 C CNN
	1    10350 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C-SN1
U 1 1 5E1FE4BF
P 10550 2650
F 0 "C-SN1" H 10665 2696 50  0000 L CNN
F 1 "C" H 10665 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10588 2500 50  0001 C CNN
F 3 "~" H 10550 2650 50  0001 C CNN
	1    10550 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E1FEB50
P 10550 2900
F 0 "#PWR0101" H 10550 2650 50  0001 C CNN
F 1 "GND" H 10555 2727 50  0000 C CNN
F 2 "" H 10550 2900 50  0001 C CNN
F 3 "" H 10550 2900 50  0001 C CNN
	1    10550 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C-SPL1
U 1 1 5E208408
P 10750 2650
F 0 "C-SPL1" H 10865 2696 50  0000 L CNN
F 1 "C" H 10865 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10788 2500 50  0001 C CNN
F 3 "~" H 10750 2650 50  0001 C CNN
	1    10750 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 2800 10350 2800
Wire Wire Line
	10750 2800 10550 2800
Connection ~ 10550 2800
Wire Wire Line
	10550 2900 10550 2800
Wire Wire Line
	10350 2500 10350 2400
Wire Wire Line
	10550 2500 10550 2400
Text Label 10350 2400 1    50   ~ 0
OUTP_R
Text Label 10550 2400 1    50   ~ 0
OUTN
Wire Wire Line
	10750 2500 10750 2400
Text Label 10750 2400 1    50   ~ 0
OUTP_L
$Comp
L Device:D D-VREG1
U 1 1 5E199BC2
P 5650 4850
F 0 "D-VREG1" H 5650 4634 50  0000 C CNN
F 1 "D" H 5650 4725 50  0000 C CNN
F 2 "Diode_SMD:D_SMA_Handsoldering" H 5650 4850 50  0001 C CNN
F 3 "~" H 5650 4850 50  0001 C CNN
	1    5650 4850
	-1   0    0    1   
$EndComp
Wire Wire Line
	5500 4850 5450 4850
Wire Wire Line
	5800 4850 5850 4850
Wire Wire Line
	5150 5200 5850 5200
Connection ~ 5850 5200
Wire Wire Line
	6450 4200 6150 4200
Wire Wire Line
	6450 4100 6150 4100
Text Label 6150 4200 0    50   ~ 0
DAC_L_SD
Text Label 6150 4100 0    50   ~ 0
DAC_R_SD
$EndSCHEMATC
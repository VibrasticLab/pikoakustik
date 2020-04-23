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
L NUCLEO-64:NUCLEO-64 U1
U 2 1 5EA169C6
P 8750 2250
F 0 "U1" H 8750 3515 50  0000 C CNN
F 1 "NUCLEO-64" H 8750 3424 50  0000 C CNN
F 2 "User:Nucleo-64" H 8750 2250 50  0001 C CNN
F 3 "DOCUMENTATION" H 8750 2250 50  0001 C CNN
	2    8750 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 2750 7250 2750
Text Label 7250 2750 0    50   ~ 0
LED_IND
Wire Wire Line
	8000 3050 7800 3050
Text Label 7800 3050 0    50   ~ 0
LED_TRUE
Wire Wire Line
	8000 3150 7800 3150
Text Label 7800 3150 0    50   ~ 0
LED_FALSE
Wire Wire Line
	7100 2850 7250 2850
Text Label 7250 2850 0    50   ~ 0
LED_A
Wire Wire Line
	7100 2950 7250 2950
Text Label 7250 2950 0    50   ~ 0
LED_B
Wire Wire Line
	9500 2450 9700 2450
Text Label 9700 2450 0    50   ~ 0
LED_C
Wire Wire Line
	9500 1950 9700 1950
Wire Wire Line
	9500 1850 9700 1850
Text Label 9700 1950 0    50   ~ 0
USB_DM
Text Label 9700 1850 0    50   ~ 0
USB_DP
Wire Wire Line
	5600 2050 5350 2050
Text Label 5350 2050 0    50   ~ 0
MMC_NSS
Wire Wire Line
	5600 1350 5350 1350
Text Label 5350 1350 0    50   ~ 0
MMC_SCK
Wire Wire Line
	5600 1450 5350 1450
Text Label 5350 1450 0    50   ~ 0
MMC_MOSI
Wire Wire Line
	7100 1350 7250 1350
Text Label 7250 1350 0    50   ~ 0
MMC_MISO
Wire Wire Line
	8000 2550 7800 2550
Text Label 7800 2550 0    50   ~ 0
DAC_BCLK
Wire Wire Line
	9500 2050 9700 2050
Text Label 9700 2050 0    50   ~ 0
DAC_LRC
Wire Wire Line
	5600 3150 5350 3150
Text Label 5350 3150 0    50   ~ 0
DAC_DIN
Wire Wire Line
	7100 3150 7250 3150
Text Label 7250 3150 0    50   ~ 0
BTN_A
Wire Wire Line
	7100 3050 7250 3050
Text Label 7250 3050 0    50   ~ 0
BTN_B
Wire Wire Line
	5600 3050 5350 3050
Text Label 5350 3050 0    50   ~ 0
BTN_C
$Comp
L power:GND #PWR05
U 1 1 5EA48A5D
P 7350 1650
F 0 "#PWR05" H 7350 1400 50  0001 C CNN
F 1 "GND" H 7355 1477 50  0000 C CNN
F 2 "" H 7350 1650 50  0001 C CNN
F 3 "" H 7350 1650 50  0001 C CNN
	1    7350 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 1650 7350 1650
$Comp
L power:VCC #PWR06
U 1 1 5EA4A817
P 7350 2150
F 0 "#PWR06" H 7350 2000 50  0001 C CNN
F 1 "VCC" H 7367 2323 50  0000 C CNN
F 2 "" H 7350 2150 50  0001 C CNN
F 3 "" H 7350 2150 50  0001 C CNN
	1    7350 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2150 7100 2150
$Comp
L Device:R R-LED1
U 1 1 5EA4CF66
P 6450 4650
F 0 "R-LED1" H 6520 4696 50  0000 L CNN
F 1 "330" H 6520 4605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6380 4650 50  0001 C CNN
F 3 "~" H 6450 4650 50  0001 C CNN
	1    6450 4650
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR01
U 1 1 5EA4DF76
P 6450 4450
F 0 "#PWR01" H 6450 4300 50  0001 C CNN
F 1 "VDD" H 6467 4623 50  0000 C CNN
F 2 "" H 6450 4450 50  0001 C CNN
F 3 "" H 6450 4450 50  0001 C CNN
	1    6450 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4450 6450 4500
$Comp
L power:VDD #PWR04
U 1 1 5EA4F005
P 5250 1550
F 0 "#PWR04" H 5250 1400 50  0001 C CNN
F 1 "VDD" H 5267 1723 50  0000 C CNN
F 2 "" H 5250 1550 50  0001 C CNN
F 3 "" H 5250 1550 50  0001 C CNN
	1    5250 1550
	1    0    0    -1  
$EndComp
$Comp
L NUCLEO-64:NUCLEO-64 U1
U 1 1 5EA158D3
P 6350 2250
F 0 "U1" H 6350 3515 50  0000 C CNN
F 1 "NUCLEO-64" H 6350 3424 50  0000 C CNN
F 2 "User:Nucleo-64" H 6350 2250 50  0001 C CNN
F 3 "DOCUMENTATION" H 6350 2250 50  0001 C CNN
	1    6350 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 1550 5250 1550
$Comp
L Device:R R-LED2
U 1 1 5EA5407E
P 7000 4650
F 0 "R-LED2" H 7070 4696 50  0000 L CNN
F 1 "330" H 7070 4605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6930 4650 50  0001 C CNN
F 3 "~" H 7000 4650 50  0001 C CNN
	1    7000 4650
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR02
U 1 1 5EA54088
P 7000 4450
F 0 "#PWR02" H 7000 4300 50  0001 C CNN
F 1 "VDD" H 7017 4623 50  0000 C CNN
F 2 "" H 7000 4450 50  0001 C CNN
F 3 "" H 7000 4450 50  0001 C CNN
	1    7000 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4450 7000 4500
$Comp
L Device:R R-LED3
U 1 1 5EA55E7B
P 7400 4650
F 0 "R-LED3" H 7470 4696 50  0000 L CNN
F 1 "330" H 7470 4605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7330 4650 50  0001 C CNN
F 3 "~" H 7400 4650 50  0001 C CNN
	1    7400 4650
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR03
U 1 1 5EA55E85
P 7400 4450
F 0 "#PWR03" H 7400 4300 50  0001 C CNN
F 1 "VDD" H 7417 4623 50  0000 C CNN
F 2 "" H 7400 4450 50  0001 C CNN
F 3 "" H 7400 4450 50  0001 C CNN
	1    7400 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4450 7400 4500
$Comp
L Device:LED LED_ANS1
U 1 1 5EA575CC
P 6350 5000
F 0 "LED_ANS1" V 6389 4882 50  0000 R CNN
F 1 "LED" V 6298 4882 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6350 5000 50  0001 C CNN
F 3 "~" H 6350 5000 50  0001 C CNN
	1    6350 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED LED_ANS2
U 1 1 5EA5A1BF
P 6550 5000
F 0 "LED_ANS2" V 6589 4882 50  0000 R CNN
F 1 "LED" V 6498 4882 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6550 5000 50  0001 C CNN
F 3 "~" H 6550 5000 50  0001 C CNN
	1    6550 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED LED_BUTTON1
U 1 1 5EA5BEA7
P 6850 5000
F 0 "LED_BUTTON1" V 6889 4882 50  0000 R CNN
F 1 "LED" V 6798 4882 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6850 5000 50  0001 C CNN
F 3 "~" H 6850 5000 50  0001 C CNN
	1    6850 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED LED_BUTTON2
U 1 1 5EA5DD95
P 7000 5000
F 0 "LED_BUTTON2" V 7039 4882 50  0000 R CNN
F 1 "LED" V 6948 4882 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7000 5000 50  0001 C CNN
F 3 "~" H 7000 5000 50  0001 C CNN
	1    7000 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED LED_BUTTON3
U 1 1 5EA5EB07
P 7150 5000
F 0 "LED_BUTTON3" V 7189 4882 50  0000 R CNN
F 1 "LED" V 7098 4882 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7150 5000 50  0001 C CNN
F 3 "~" H 7150 5000 50  0001 C CNN
	1    7150 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED LED_INDICATOR1
U 1 1 5EA5F622
P 7400 5000
F 0 "LED_INDICATOR1" V 7439 4882 50  0000 R CNN
F 1 "LED" V 7348 4882 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7400 5000 50  0001 C CNN
F 3 "~" H 7400 5000 50  0001 C CNN
	1    7400 5000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6350 4850 6450 4850
Wire Wire Line
	6450 4800 6450 4850
Connection ~ 6450 4850
Wire Wire Line
	6450 4850 6550 4850
Wire Wire Line
	6850 4850 7000 4850
Wire Wire Line
	7150 4850 7000 4850
Connection ~ 7000 4850
Wire Wire Line
	7000 4800 7000 4850
Wire Wire Line
	7400 4800 7400 4850
Wire Wire Line
	6350 5150 6350 5250
Wire Wire Line
	6550 5150 6550 5250
Text Label 6350 5250 3    50   ~ 0
LED_TRUE
Text Label 6550 5250 3    50   ~ 0
LED_FALSE
Wire Wire Line
	6850 5150 6850 5250
Wire Wire Line
	7000 5150 7000 5250
Wire Wire Line
	7150 5150 7150 5250
Wire Wire Line
	7400 5150 7400 5250
Text Label 6850 5250 3    50   ~ 0
LED_A
Text Label 7000 5250 3    50   ~ 0
LED_B
Text Label 7150 5250 3    50   ~ 0
LED_C
Text Label 7400 5250 3    50   ~ 0
LED_IND
$Comp
L dacmax98:MAX98357_DAC U2
U 1 1 5EA8B91C
P 4400 4850
F 0 "U2" H 4325 5531 50  0000 C CNN
F 1 "MAX98357_DAC" H 4325 5440 50  0000 C CNN
F 2 "dacmax98:dacmax98357" H 4050 4750 50  0001 C CNN
F 3 "" H 4050 4750 50  0001 C CNN
	1    4400 4850
	1    0    0    -1  
$EndComp
$Comp
L Connector:AudioJack3 J-HP1
U 1 1 5EA8EB9E
P 5300 4750
F 0 "J-HP1" H 5020 4775 50  0000 R CNN
F 1 "AudioJack3" H 5020 4684 50  0000 R CNN
F 2 "User:Tayda_3.5mm_stereo_TRS_jack_A-853" H 5300 4750 50  0001 C CNN
F 3 "~" H 5300 4750 50  0001 C CNN
	1    5300 4750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5100 4650 4850 4650
Wire Wire Line
	5100 4750 5000 4750
Wire Wire Line
	5000 4750 5000 4850
Wire Wire Line
	5000 5050 4850 5050
Wire Wire Line
	5100 4850 5000 4850
Connection ~ 5000 4850
Wire Wire Line
	5000 4850 5000 5050
$Comp
L power:VDD #PWR09
U 1 1 5EA922A7
P 4100 4350
F 0 "#PWR09" H 4100 4200 50  0001 C CNN
F 1 "VDD" H 4117 4523 50  0000 C CNN
F 2 "" H 4100 4350 50  0001 C CNN
F 3 "" H 4100 4350 50  0001 C CNN
	1    4100 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4550 3750 4550
Wire Wire Line
	3750 4550 3750 4350
Wire Wire Line
	3750 4350 4100 4350
Wire Wire Line
	4350 4350 4100 4350
Connection ~ 4100 4350
Wire Wire Line
	3800 4850 3600 4850
Text Label 3600 4850 0    50   ~ 0
DAC_DIN
Wire Wire Line
	3800 5000 3600 5000
Text Label 3600 5000 0    50   ~ 0
DAC_BCLK
Wire Wire Line
	3800 5200 3600 5200
Text Label 3600 5200 0    50   ~ 0
DAC_LRC
$Comp
L Device:R R-DAC1
U 1 1 5EA99FD2
P 3550 4700
F 0 "R-DAC1" V 3343 4700 50  0000 C CNN
F 1 "100K" V 3434 4700 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3480 4700 50  0001 C CNN
F 3 "~" H 3550 4700 50  0001 C CNN
	1    3550 4700
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J-GAIN1
U 1 1 5EA9ABB4
P 3100 4700
F 0 "J-GAIN1" H 3208 4981 50  0000 C CNN
F 1 "Conn_01x03_Male" H 3208 4890 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical_SMD_Pin1Left" H 3100 4700 50  0001 C CNN
F 3 "~" H 3100 4700 50  0001 C CNN
	1    3100 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 4700 3300 4700
Wire Wire Line
	3800 4700 3700 4700
$Comp
L power:VDD #PWR07
U 1 1 5EA9D990
P 3350 4600
F 0 "#PWR07" H 3350 4450 50  0001 C CNN
F 1 "VDD" H 3367 4773 50  0000 C CNN
F 2 "" H 3350 4600 50  0001 C CNN
F 3 "" H 3350 4600 50  0001 C CNN
	1    3350 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5EA9E7A1
P 3350 4800
F 0 "#PWR08" H 3350 4550 50  0001 C CNN
F 1 "GND" H 3355 4627 50  0000 C CNN
F 2 "" H 3350 4800 50  0001 C CNN
F 3 "" H 3350 4800 50  0001 C CNN
	1    3350 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4800 3300 4800
Wire Wire Line
	3350 4600 3300 4600
$Comp
L power:GND #PWR010
U 1 1 5EAA19CB
P 4350 5450
F 0 "#PWR010" H 4350 5200 50  0001 C CNN
F 1 "GND" H 4355 5277 50  0000 C CNN
F 2 "" H 4350 5450 50  0001 C CNN
F 3 "" H 4350 5450 50  0001 C CNN
	1    4350 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 5400 4350 5450
$Comp
L Switch:SW_Push SW1
U 1 1 5EAAFD8B
P 8450 5200
F 0 "SW1" V 8404 5348 50  0000 L CNN
F 1 "SW_Push" V 8495 5348 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 8450 5400 50  0001 C CNN
F 3 "~" H 8450 5400 50  0001 C CNN
	1    8450 5200
	0    1    1    0   
$EndComp
$Comp
L Device:R R-BTN1
U 1 1 5EAB2008
P 8450 4750
F 0 "R-BTN1" H 8520 4796 50  0000 L CNN
F 1 "4K7" H 8520 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8380 4750 50  0001 C CNN
F 3 "~" H 8450 4750 50  0001 C CNN
	1    8450 4750
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR011
U 1 1 5EAB2FF1
P 8450 4500
F 0 "#PWR011" H 8450 4350 50  0001 C CNN
F 1 "VDD" H 8467 4673 50  0000 C CNN
F 2 "" H 8450 4500 50  0001 C CNN
F 3 "" H 8450 4500 50  0001 C CNN
	1    8450 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 4900 8450 4950
Wire Wire Line
	8450 4950 8550 4950
Connection ~ 8450 4950
Wire Wire Line
	8450 4950 8450 5000
Wire Wire Line
	8450 4500 8450 4600
$Comp
L power:GND #PWR012
U 1 1 5EAB6D8D
P 8450 5450
F 0 "#PWR012" H 8450 5200 50  0001 C CNN
F 1 "GND" H 8455 5277 50  0000 C CNN
F 2 "" H 8450 5450 50  0001 C CNN
F 3 "" H 8450 5450 50  0001 C CNN
	1    8450 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 5400 8450 5450
$Comp
L Switch:SW_Push SW2
U 1 1 5EABB053
P 8850 5200
F 0 "SW2" V 8804 5348 50  0000 L CNN
F 1 "SW_Push" V 8895 5348 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 8850 5400 50  0001 C CNN
F 3 "~" H 8850 5400 50  0001 C CNN
	1    8850 5200
	0    1    1    0   
$EndComp
$Comp
L Device:R R-BTN2
U 1 1 5EABB05D
P 8850 4750
F 0 "R-BTN2" H 8920 4796 50  0000 L CNN
F 1 "4K7" H 8920 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 8780 4750 50  0001 C CNN
F 3 "~" H 8850 4750 50  0001 C CNN
	1    8850 4750
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR013
U 1 1 5EABB067
P 8850 4500
F 0 "#PWR013" H 8850 4350 50  0001 C CNN
F 1 "VDD" H 8867 4673 50  0000 C CNN
F 2 "" H 8850 4500 50  0001 C CNN
F 3 "" H 8850 4500 50  0001 C CNN
	1    8850 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 4900 8850 4950
Wire Wire Line
	8850 4950 8950 4950
Connection ~ 8850 4950
Wire Wire Line
	8850 4950 8850 5000
Wire Wire Line
	8850 4500 8850 4600
$Comp
L power:GND #PWR014
U 1 1 5EABB076
P 8850 5450
F 0 "#PWR014" H 8850 5200 50  0001 C CNN
F 1 "GND" H 8855 5277 50  0000 C CNN
F 2 "" H 8850 5450 50  0001 C CNN
F 3 "" H 8850 5450 50  0001 C CNN
	1    8850 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 5400 8850 5450
$Comp
L Switch:SW_Push SW3
U 1 1 5EAC037D
P 9200 5200
F 0 "SW3" V 9154 5348 50  0000 L CNN
F 1 "SW_Push" V 9245 5348 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 9200 5400 50  0001 C CNN
F 3 "~" H 9200 5400 50  0001 C CNN
	1    9200 5200
	0    1    1    0   
$EndComp
$Comp
L Device:R R-BTN3
U 1 1 5EAC0387
P 9200 4750
F 0 "R-BTN3" H 9270 4796 50  0000 L CNN
F 1 "4K7" H 9270 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9130 4750 50  0001 C CNN
F 3 "~" H 9200 4750 50  0001 C CNN
	1    9200 4750
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR015
U 1 1 5EAC0391
P 9200 4500
F 0 "#PWR015" H 9200 4350 50  0001 C CNN
F 1 "VDD" H 9217 4673 50  0000 C CNN
F 2 "" H 9200 4500 50  0001 C CNN
F 3 "" H 9200 4500 50  0001 C CNN
	1    9200 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 4900 9200 4950
Wire Wire Line
	9200 4950 9300 4950
Connection ~ 9200 4950
Wire Wire Line
	9200 4950 9200 5000
Wire Wire Line
	9200 4500 9200 4600
$Comp
L power:GND #PWR016
U 1 1 5EAC03A0
P 9200 5450
F 0 "#PWR016" H 9200 5200 50  0001 C CNN
F 1 "GND" H 9205 5277 50  0000 C CNN
F 2 "" H 9200 5450 50  0001 C CNN
F 3 "" H 9200 5450 50  0001 C CNN
	1    9200 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 5400 9200 5450
Text Label 8550 4950 0    50   ~ 0
BTN_A
Text Label 8950 4950 0    50   ~ 0
BTN_B
Text Label 9300 4950 0    50   ~ 0
BTN_C
$Comp
L Connector:USB_B_Micro J-USB1
U 1 1 5EAF858B
P 4050 3250
F 0 "J-USB1" H 3820 3239 50  0000 R CNN
F 1 "USB_B_Micro" H 3820 3148 50  0000 R CNN
F 2 "User:MicroUSB" H 4200 3200 50  0001 C CNN
F 3 "~" H 4200 3200 50  0001 C CNN
	1    4050 3250
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R-USB1
U 1 1 5EB01D99
P 3450 3150
F 0 "R-USB1" V 3243 3150 50  0000 C CNN
F 1 "4K7" V 3334 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3380 3150 50  0001 C CNN
F 3 "~" H 3450 3150 50  0001 C CNN
	1    3450 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R R-USB2
U 1 1 5EB02E5D
P 3450 3250
F 0 "R-USB2" V 3243 3250 50  0000 C CNN
F 1 "68" V 3334 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3380 3250 50  0001 C CNN
F 3 "~" H 3450 3250 50  0001 C CNN
	1    3450 3250
	0    1    1    0   
$EndComp
$Comp
L Device:R R-USB3
U 1 1 5EB030E6
P 3450 3350
F 0 "R-USB3" V 3243 3350 50  0000 C CNN
F 1 "68" V 3334 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3380 3350 50  0001 C CNN
F 3 "~" H 3450 3350 50  0001 C CNN
	1    3450 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 3250 3650 3250
Wire Wire Line
	3600 3150 3650 3150
Wire Wire Line
	3650 3150 3650 3250
Connection ~ 3650 3250
Wire Wire Line
	3650 3250 3600 3250
Wire Wire Line
	3750 3350 3600 3350
$Comp
L power:VDD #PWR017
U 1 1 5EB0A12C
P 3250 3150
F 0 "#PWR017" H 3250 3000 50  0001 C CNN
F 1 "VDD" H 3267 3323 50  0000 C CNN
F 2 "" H 3250 3150 50  0001 C CNN
F 3 "" H 3250 3150 50  0001 C CNN
	1    3250 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3150 3250 3150
Wire Wire Line
	3300 3250 3200 3250
Wire Wire Line
	3300 3350 3200 3350
$Comp
L power:GND #PWR018
U 1 1 5EB1082C
P 4050 3750
F 0 "#PWR018" H 4050 3500 50  0001 C CNN
F 1 "GND" H 4055 3577 50  0000 C CNN
F 2 "" H 4050 3750 50  0001 C CNN
F 3 "" H 4050 3750 50  0001 C CNN
	1    4050 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3650 4050 3750
Wire Wire Line
	4150 3650 4150 3750
Wire Wire Line
	4150 3750 4050 3750
Connection ~ 4050 3750
Text Label 3200 3250 0    50   ~ 0
USB_DP
Text Label 3200 3350 0    50   ~ 0
USB_DM
$Comp
L OPL_Connector:MICRO-SD-CARD-SOCKET-9P_ST-TF-003A_ SD1
U 1 1 5EB1D2D7
P 3750 2050
F 0 "SD1" H 4278 2142 45  0000 L CNN
F 1 "MICRO-SD-CARD-SOCKET-9P_ST-TF-003A_" H 4278 2058 45  0000 L CNN
F 2 "OPL_Connector:MICRO-SD9+4P-SMD-16.1X14.5X1.85MM" H 3750 2050 50  0001 C CNN
F 3 "" H 3750 2050 50  0001 C CNN
F 4 "ST-TF-003A" H 3780 2200 20  0001 C CNN "MPN"
F 5 "320090000" H 3780 2200 20  0001 C CNN "SKU"
	1    3750 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R-SD1
U 1 1 5EB2F031
P 2600 1650
F 0 "R-SD1" V 2393 1650 50  0000 C CNN
F 1 "4K7" V 2484 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2530 1650 50  0001 C CNN
F 3 "~" H 2600 1650 50  0001 C CNN
	1    2600 1650
	0    1    1    0   
$EndComp
$Comp
L Device:R R-SD2
U 1 1 5EB30517
P 2600 2250
F 0 "R-SD2" V 2393 2250 50  0000 C CNN
F 1 "4K7" V 2484 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2530 2250 50  0001 C CNN
F 3 "~" H 2600 2250 50  0001 C CNN
	1    2600 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R-SD3
U 1 1 5EB3097E
P 2600 2350
F 0 "R-SD3" V 2393 2350 50  0000 C CNN
F 1 "4K7" V 2484 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2530 2350 50  0001 C CNN
F 3 "~" H 2600 2350 50  0001 C CNN
	1    2600 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	3050 1650 2750 1650
Wire Wire Line
	3050 2250 2750 2250
Wire Wire Line
	3050 2350 2750 2350
Wire Wire Line
	2450 1650 2450 1950
Wire Wire Line
	2450 2350 2450 2250
Connection ~ 2450 2250
$Comp
L power:VDD #PWR0101
U 1 1 5EB42AF4
P 2450 1600
F 0 "#PWR0101" H 2450 1450 50  0001 C CNN
F 1 "VDD" H 2467 1773 50  0000 C CNN
F 2 "" H 2450 1600 50  0001 C CNN
F 3 "" H 2450 1600 50  0001 C CNN
	1    2450 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 1600 2450 1650
Connection ~ 2450 1650
Wire Wire Line
	3050 1950 2450 1950
Connection ~ 2450 1950
Wire Wire Line
	2450 1950 2450 2250
Wire Wire Line
	3050 1750 2750 1750
Text Label 2750 1750 0    50   ~ 0
MMC_NSS
Wire Wire Line
	3050 1850 2750 1850
Text Label 2750 1850 0    50   ~ 0
MMC_MOSI
Wire Wire Line
	3050 2050 2750 2050
Text Label 2750 2050 0    50   ~ 0
MMC_SCK
$Comp
L power:GND #PWR0102
U 1 1 5EB551A7
P 2900 2450
F 0 "#PWR0102" H 2900 2200 50  0001 C CNN
F 1 "GND" H 2905 2277 50  0000 C CNN
F 2 "" H 2900 2450 50  0001 C CNN
F 3 "" H 2900 2450 50  0001 C CNN
	1    2900 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2150 2900 2150
Wire Wire Line
	2900 2150 2900 2450
Text Label 2750 2250 0    50   ~ 0
MMC_MISO
$EndSCHEMATC

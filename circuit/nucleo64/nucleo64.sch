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
L MCU_Module:NUCLEO64-F411RE U1
U 1 1 5E1C0419
P 5800 3700
F 0 "U1" H 5800 5881 50  0000 C CNN
F 1 "NUCLEO64-F411RE" H 5800 5790 50  0000 C CNN
F 2 "user:Nucleo-64" H 6350 1800 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/data_brief/DM00105918.pdf" H 4900 2300 50  0001 C CNN
	1    5800 3700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x19_Odd_Even J1
U 1 1 5E1C2629
P 8150 2700
F 0 "J1" H 8200 3817 50  0000 C CNN
F 1 "Conn_02x19_Odd_Even" H 8200 3726 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x19_P2.54mm_Vertical" H 8150 2700 50  0001 C CNN
F 3 "~" H 8150 2700 50  0001 C CNN
	1    8150 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x19_Odd_Even J2
U 1 1 5E1C45C1
P 9500 2650
F 0 "J2" H 9550 3767 50  0000 C CNN
F 1 "Conn_02x19_Odd_Even" H 9550 3676 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x19_P2.54mm_Vertical" H 9500 2650 50  0001 C CNN
F 3 "~" H 9500 2650 50  0001 C CNN
	1    9500 2650
	1    0    0    -1  
$EndComp
$Comp
L MCU_ST_STM32F4:STM32F401RETx U2
U 1 1 5E1CB79A
P 2700 3500
F 0 "U2" H 2650 5381 50  0000 C CNN
F 1 "STM32F401RETx" H 2650 5290 50  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 2100 1800 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00102166.pdf" H 2700 3500 50  0001 C CNN
	1    2700 3500
	1    0    0    -1  
$EndComp
$EndSCHEMATC

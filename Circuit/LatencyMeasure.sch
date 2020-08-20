EESchema Schematic File Version 4
LIBS:LatencyMeasure-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "LatencyMeasure"
Date "2020-07-12"
Rev "R2"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Comparator:LM393 OpAmp1
U 1 1 5F0AE553
P 3500 2900
F 0 "OpAmp1" H 3500 3267 50  0000 C CNN
F 1 "LM393" H 3500 3176 50  0000 C CNN
F 2 "" H 3500 2900 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm393-n.pdf" H 3500 2900 50  0001 C CNN
	1    3500 2900
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Optical:SFH300 T1
U 1 1 5F0AE6AA
P 1850 3600
F 0 "T1" H 2040 3646 50  0000 L CNN
F 1 "SFH300" H 2040 3555 50  0000 L CNN
F 2 "LED_THT:LED_D5.0mm_Clear" H 2330 3460 50  0001 C CNN
F 3 "http://www.osram-os.com/Graphics/XPic2/00101785_0.pdf" H 1850 3600 50  0001 C CNN
	1    1850 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5F0AE8B9
P 1950 2000
F 0 "R1" H 2020 2046 50  0000 L CNN
F 1 "25k" H 2020 1955 50  0000 L CNN
F 2 "" V 1880 2000 50  0001 C CNN
F 3 "~" H 1950 2000 50  0001 C CNN
	1    1950 2000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5F0AF2E5
P 4100 3800
F 0 "SW1" V 4054 3948 50  0000 L CNN
F 1 "MODE" V 4145 3948 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4100 4000 50  0001 C CNN
F 3 "" H 4100 4000 50  0001 C CNN
	1    4100 3800
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5F0AF3E6
P 4700 3800
F 0 "SW2" V 4654 3948 50  0000 L CNN
F 1 "OK" V 4745 3948 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4700 4000 50  0001 C CNN
F 3 "" H 4700 4000 50  0001 C CNN
	1    4700 3800
	0    1    1    0   
$EndComp
$Comp
L Device:LED LED1
U 1 1 5F0AF5AF
P 5300 3800
F 0 "LED1" V 5338 3879 50  0000 L CNN
F 1 "white" V 5247 3879 50  0000 L CNN
F 2 "" H 5300 3800 50  0001 C CNN
F 3 "~" H 5300 3800 50  0001 C CNN
	1    5300 3800
	0    1    -1   0   
$EndComp
Wire Wire Line
	3200 2800 3000 2800
$Comp
L Device:R_POT_TRIM R2
U 1 1 5F0B0FE3
P 2600 3000
F 0 "R2" H 2530 3046 50  0000 R CNN
F 1 "25k" H 2530 2955 50  0000 R CNN
F 2 "" H 2600 3000 50  0001 C CNN
F 3 "~" H 2600 3000 50  0001 C CNN
	1    2600 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3000 3100 3000
Wire Wire Line
	1950 1850 1950 1200
Wire Wire Line
	1950 3800 1950 4700
Wire Wire Line
	1950 4700 2600 4700
Wire Wire Line
	2600 3150 2600 4700
Connection ~ 2600 4700
Wire Wire Line
	2600 4700 3400 4700
Wire Wire Line
	2600 2850 2600 1200
Connection ~ 2600 1200
Wire Wire Line
	2600 1200 3400 1200
Wire Wire Line
	1950 1200 2600 1200
Connection ~ 1950 2800
Wire Wire Line
	1950 2800 1950 3400
Wire Wire Line
	1950 2150 1950 2800
$Comp
L MCU_Module:Arduino_Leonardo Arduino1
U 1 1 5F0B480C
P 6850 3100
F 0 "Arduino1" H 6850 4278 50  0000 C CNN
F 1 "Sparkfun Micro Pro 3.3V @ 8MHz" H 6850 4187 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 7000 2050 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/ArduinoBoardLeonardo" H 6650 4150 50  0001 C CNN
	1    6850 3100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 OLED1
U 1 1 5F0B4FD9
P 5850 1550
F 0 "OLED1" V 5816 1730 50  0000 L CNN
F 1 "SDD1306 128x32px" V 5725 1730 50  0000 L CNN
F 2 "" H 5850 1550 50  0001 C CNN
F 3 "~" H 5850 1550 50  0001 C CNN
	1    5850 1550
	0    1    -1   0   
$EndComp
Wire Wire Line
	3800 2900 3850 2900
Wire Wire Line
	4100 4000 4100 4700
Wire Wire Line
	4700 4000 4700 4700
Connection ~ 4700 4700
Wire Wire Line
	4700 4700 5300 4700
Connection ~ 5300 4700
Wire Wire Line
	5300 4700 5650 4700
Wire Wire Line
	5950 1750 5950 2700
Wire Wire Line
	5950 2700 6350 2700
Wire Wire Line
	5850 1750 5850 2800
Wire Wire Line
	5850 2800 6350 2800
Wire Wire Line
	6750 4200 6850 4200
Wire Wire Line
	4100 2500 6350 2500
Wire Wire Line
	4700 2600 6350 2600
Wire Wire Line
	5300 3000 6350 3000
Wire Wire Line
	4700 3600 4700 2600
Wire Wire Line
	4100 3600 4100 2500
Wire Wire Line
	5300 3950 5300 4700
Wire Wire Line
	5300 3000 5300 3650
Wire Wire Line
	5650 1750 5650 4700
Connection ~ 5650 4700
Wire Wire Line
	5650 4700 6850 4700
Wire Wire Line
	5750 1750 5750 1950
Wire Wire Line
	5750 1950 5300 1950
Wire Wire Line
	5300 1950 5300 1200
Wire Wire Line
	6950 4200 6850 4200
Connection ~ 6850 4200
Wire Wire Line
	6850 4700 6850 4200
Wire Wire Line
	6950 2100 6950 1200
$Comp
L Comparator:LM393 U1
U 3 1 5F0C944F
P 3500 2900
F 0 "U1" H 3458 2946 50  0001 L CNN
F 1 "LM393" H 3458 2900 50  0001 L TNN
F 2 "" H 3500 2900 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm393-n.pdf" H 3500 2900 50  0001 C CNN
	3    3500 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2600 3400 1200
Wire Wire Line
	3400 1200 3850 1200
Wire Wire Line
	3400 3200 3400 4700
Wire Wire Line
	3400 4700 4100 4700
Text Notes 750  7450 0    59   ~ 0
The Arduino sends out mouse or keyboard events via USB.\nThe test client SW running on the connected host triggers a\nchange of brightness on the display inside a reference area\nwhen the mouse or keyboard event is received.\nThe phototransistor T1 scans the brightness of that reference\narea on the display. The signal is passed thru the OpAmp1\nto get a digitial signal out of the meassured value.\nR2 is used to calibrate the switching level.\nThe Arduino meassures the time between the USB event and\nthe received trigger on the display.\nThe LED1 is used for timing calibration. Buttons SW1 and\nSW2 are used to navigate thru the software running on the\nArduino. Options and results are displayed on OLED1.
$Comp
L Device:R R3
U 1 1 5F0EA750
P 3850 2000
F 0 "R3" H 3920 2046 50  0000 L CNN
F 1 "10k" H 3920 1955 50  0000 L CNN
F 2 "" V 3780 2000 50  0001 C CNN
F 3 "~" H 3850 2000 50  0001 C CNN
	1    3850 2000
	1    0    0    -1  
$EndComp
Connection ~ 5300 1200
Connection ~ 4100 4700
Wire Wire Line
	3850 1850 3850 1200
Connection ~ 3850 1200
Wire Wire Line
	3850 1200 5300 1200
Wire Wire Line
	3850 2150 3850 2900
Connection ~ 3850 2900
Wire Wire Line
	3850 2900 6350 2900
Wire Wire Line
	5300 1200 6950 1200
Wire Wire Line
	4100 4700 4700 4700
$Comp
L Switch:SW_Push SW3
U 1 1 5F0F78A0
P 8000 3800
F 0 "SW3" V 7954 3948 50  0000 L CNN
F 1 "RESET" V 8045 3948 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 8000 4000 50  0001 C CNN
F 3 "" H 8000 4000 50  0001 C CNN
	1    8000 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	8000 3600 8000 2500
Wire Wire Line
	8000 2500 7350 2500
Wire Wire Line
	8000 4000 8000 4700
Wire Wire Line
	8000 4700 6850 4700
Connection ~ 6850 4700
Connection ~ 3400 1200
Connection ~ 3400 4700
Wire Wire Line
	7350 3100 7700 3100
Wire Wire Line
	7700 3100 7700 4500
Wire Wire Line
	7700 4500 3000 4500
Wire Wire Line
	3000 4500 3000 2800
Connection ~ 3000 2800
Wire Wire Line
	3000 2800 1950 2800
Wire Wire Line
	7350 3200 7600 3200
Wire Wire Line
	7600 3200 7600 4400
Wire Wire Line
	7600 4400 3100 4400
Wire Wire Line
	3100 4400 3100 3000
Connection ~ 3100 3000
Wire Wire Line
	3100 3000 3200 3000
$EndSCHEMATC

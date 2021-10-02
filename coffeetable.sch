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
L MCU_Module:Arduino_UNO_R3 A?
U 1 1 614F9A68
P 5950 3800
F 0 "A?" H 5950 4981 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 5950 4890 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 5950 3800 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 5950 3800 50  0001 C CNN
	1    5950 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 614FDB29
P 3750 2800
F 0 "SW?" H 3750 3167 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 3750 3076 50  0000 C CNN
F 2 "" H 3600 2960 50  0001 C CNN
F 3 "~" H 3750 3060 50  0001 C CNN
	1    3750 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 615003F2
P 3750 3600
F 0 "SW?" H 3750 3967 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 3750 3876 50  0000 C CNN
F 2 "" H 3600 3760 50  0001 C CNN
F 3 "~" H 3750 3860 50  0001 C CNN
	1    3750 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 61501349
P 3750 4450
F 0 "SW?" H 3750 4817 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 3750 4726 50  0000 C CNN
F 2 "" H 3600 4610 50  0001 C CNN
F 3 "~" H 3750 4710 50  0001 C CNN
	1    3750 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW?
U 1 1 61501786
P 3750 5250
F 0 "SW?" H 3750 5617 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 3750 5526 50  0000 C CNN
F 2 "" H 3600 5410 50  0001 C CNN
F 3 "~" H 3750 5510 50  0001 C CNN
	1    3750 5250
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:WC1602A DS?
U 1 1 6150472C
P 8350 3600
F 0 "DS?" H 8350 4581 50  0000 C CNN
F 1 "WC1602A" H 8350 4490 50  0000 C CNN
F 2 "Display:WC1602A" H 8350 2700 50  0001 C CIN
F 3 "http://www.wincomlcd.com/pdf/WC1602A-SFYLYHTC06.pdf" H 9050 3600 50  0001 C CNN
	1    8350 3600
	1    0    0    -1  
$EndComp
$Comp
L Timer_RTC:DS1307+ U?
U 1 1 61505F29
P 8350 5400
F 0 "U?" H 8894 5446 50  0000 L CNN
F 1 "DS1307+" H 8894 5355 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 8350 4900 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/DS1307.pdf" H 8350 5200 50  0001 C CNN
	1    8350 5400
	1    0    0    -1  
$EndComp
$Comp
L power:+1V5 #PWR?
U 1 1 6150A6A1
P 4100 1450
F 0 "#PWR?" H 4100 1300 50  0001 C CNN
F 1 "+1V5" H 4115 1623 50  0000 C CNN
F 2 "" H 4100 1450 50  0001 C CNN
F 3 "" H 4100 1450 50  0001 C CNN
	1    4100 1450
	1    0    0    -1  
$EndComp
$EndSCHEMATC

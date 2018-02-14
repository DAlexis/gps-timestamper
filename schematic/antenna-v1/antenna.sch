EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:ncp551
LIBS:usblc6-4sc6
LIBS:antenna-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Lightning detection active antenna"
Date "2017-04-24"
Rev ""
Comp ""
Comment1 ""
Comment2 "Aleksey Bulatov"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L GND #PWR01
U 1 1 58FDF32F
P 2600 1800
F 0 "#PWR01" H 2600 1550 50  0001 C CNN
F 1 "GND" H 2600 1650 50  0000 C CNN
F 2 "" H 2600 1800 50  0001 C CNN
F 3 "" H 2600 1800 50  0001 C CNN
	1    2600 1800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 58FDF345
P 2600 1000
F 0 "#PWR02" H 2600 850 50  0001 C CNN
F 1 "+5V" H 2600 1140 50  0000 C CNN
F 2 "" H 2600 1000 50  0001 C CNN
F 3 "" H 2600 1000 50  0001 C CNN
	1    2600 1000
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 58FDF37B
P 1900 1050
F 0 "R1" V 1980 1050 50  0000 C CNN
F 1 "1M" V 1900 1050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1830 1050 50  0001 C CNN
F 3 "" H 1900 1050 50  0001 C CNN
	1    1900 1050
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 58FDF3AC
P 1900 1550
F 0 "R2" V 1980 1550 50  0000 C CNN
F 1 "1M" V 1900 1550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1830 1550 50  0001 C CNN
F 3 "" H 1900 1550 50  0001 C CNN
	1    1900 1550
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 58FDF416
P 2100 1050
F 0 "D1" H 2100 1150 50  0000 C CNN
F 1 "1N4148" H 2100 950 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 2100 1050 50  0001 C CNN
F 3 "" H 2100 1050 50  0001 C CNN
	1    2100 1050
	0    1    1    0   
$EndComp
$Comp
L D D2
U 1 1 58FDF43D
P 2100 1550
F 0 "D2" H 2100 1650 50  0000 C CNN
F 1 "1N4148" H 2100 1450 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 2100 1550 50  0001 C CNN
F 3 "" H 2100 1550 50  0001 C CNN
	1    2100 1550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR03
U 1 1 58FDF460
P 1900 1800
F 0 "#PWR03" H 1900 1550 50  0001 C CNN
F 1 "GND" H 1900 1650 50  0000 C CNN
F 2 "" H 1900 1800 50  0001 C CNN
F 3 "" H 1900 1800 50  0001 C CNN
	1    1900 1800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 58FDF47E
P 2100 1800
F 0 "#PWR04" H 2100 1550 50  0001 C CNN
F 1 "GND" H 2100 1650 50  0000 C CNN
F 2 "" H 2100 1800 50  0001 C CNN
F 3 "" H 2100 1800 50  0001 C CNN
	1    2100 1800
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 58FDF49C
P 1600 1300
F 0 "C1" H 1625 1400 50  0000 L CNN
F 1 "C_film" H 1625 1200 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 1638 1150 50  0001 C CNN
F 3 "" H 1600 1300 50  0001 C CNN
	1    1600 1300
	0    1    1    0   
$EndComp
$Comp
L Lamp_Neon NE1
U 1 1 58FDF4E1
P 1300 1550
F 0 "NE1" H 1100 1700 50  0000 L CNN
F 1 "Lamp_Neon" V 1500 1350 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D9.0mm_W5.0mm_P5.00mm" V 1300 1650 50  0001 C CNN
F 3 "" V 1300 1650 50  0001 C CNN
	1    1300 1550
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR05
U 1 1 58FDF5BD
P 1300 1800
F 0 "#PWR05" H 1300 1550 50  0001 C CNN
F 1 "GND" H 1300 1650 50  0000 C CNN
F 2 "" H 1300 1800 50  0001 C CNN
F 3 "" H 1300 1800 50  0001 C CNN
	1    1300 1800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 58FDF76F
P 1900 800
F 0 "#PWR06" H 1900 650 50  0001 C CNN
F 1 "+5V" H 1900 940 50  0000 C CNN
F 2 "" H 1900 800 50  0001 C CNN
F 3 "" H 1900 800 50  0001 C CNN
	1    1900 800 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 58FDF791
P 2100 800
F 0 "#PWR07" H 2100 650 50  0001 C CNN
F 1 "+5V" H 2100 940 50  0000 C CNN
F 2 "" H 2100 800 50  0001 C CNN
F 3 "" H 2100 800 50  0001 C CNN
	1    2100 800 
	1    0    0    -1  
$EndComp
$Comp
L CONN_COAXIAL J1
U 1 1 58FDF827
P 900 1300
F 0 "J1" H 910 1420 50  0000 C CNN
F 1 "CONN_COAXIAL" V 1015 1300 50  0000 C CNN
F 2 "Connect:SMA_THT_Jack_Straight" H 900 1300 50  0001 C CNN
F 3 "" H 900 1300 50  0001 C CNN
	1    900  1300
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 58FDFA40
P 900 1800
F 0 "#PWR08" H 900 1550 50  0001 C CNN
F 1 "GND" H 900 1650 50  0000 C CNN
F 2 "" H 900 1800 50  0001 C CNN
F 3 "" H 900 1800 50  0001 C CNN
	1    900  1800
	1    0    0    -1  
$EndComp
$Comp
L RJ45 J5
U 1 1 58FDFC4C
P 10300 1550
F 0 "J5" H 10500 2050 50  0000 C CNN
F 1 "RJ45" H 10150 2050 50  0000 C CNN
F 2 "Connect:RJ45_8" H 10300 1550 50  0001 C CNN
F 3 "" H 10300 1550 50  0001 C CNN
	1    10300 1550
	0    1    -1   0   
$EndComp
$Comp
L GND #PWR09
U 1 1 58FDFE56
P 9750 2000
F 0 "#PWR09" H 9750 1750 50  0001 C CNN
F 1 "GND" H 9750 1850 50  0000 C CNN
F 2 "" H 9750 2000 50  0001 C CNN
F 3 "" H 9750 2000 50  0001 C CNN
	1    9750 2000
	1    0    0    -1  
$EndComp
Text GLabel 9650 1400 0    60   Input ~ 0
CH1
Text GLabel 9650 1600 0    60   Input ~ 0
CH0
$Comp
L L L1
U 1 1 58FE11AF
P 8850 1350
F 0 "L1" V 8800 1350 50  0000 C CNN
F 1 "L" V 8925 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 8850 1350 50  0001 C CNN
F 3 "" H 8850 1350 50  0001 C CNN
	1    8850 1350
	0    -1   -1   0   
$EndComp
$Comp
L C C7
U 1 1 58FE12AC
P 9100 1600
F 0 "C7" H 9125 1700 50  0000 L CNN
F 1 "100n" H 9125 1500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 9138 1450 50  0001 C CNN
F 3 "" H 9100 1600 50  0001 C CNN
	1    9100 1600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 58FE138F
P 9100 1900
F 0 "#PWR010" H 9100 1650 50  0001 C CNN
F 1 "GND" H 9100 1750 50  0000 C CNN
F 2 "" H 9100 1900 50  0001 C CNN
F 3 "" H 9100 1900 50  0001 C CNN
	1    9100 1900
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 58FE145D
P 8600 1600
F 0 "C6" H 8625 1700 50  0000 L CNN
F 1 "100n" H 8625 1500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8638 1450 50  0001 C CNN
F 3 "" H 8600 1600 50  0001 C CNN
	1    8600 1600
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 58FE14F8
P 8350 1350
F 0 "R8" V 8430 1350 50  0000 C CNN
F 1 "100" V 8350 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8280 1350 50  0001 C CNN
F 3 "" H 8350 1350 50  0001 C CNN
	1    8350 1350
	0    1    1    0   
$EndComp
$Comp
L C C5
U 1 1 58FE1541
P 8100 1600
F 0 "C5" H 8125 1700 50  0000 L CNN
F 1 "100n" H 8125 1500 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 8138 1450 50  0001 C CNN
F 3 "" H 8100 1600 50  0001 C CNN
	1    8100 1600
	1    0    0    -1  
$EndComp
$Comp
L CP C4
U 1 1 58FE158C
P 7850 1600
F 0 "C4" H 7875 1700 50  0000 L CNN
F 1 "470uF" H 7875 1500 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-D_EIA-7343-31_Wave" H 7888 1450 50  0001 C CNN
F 3 "" H 7850 1600 50  0001 C CNN
	1    7850 1600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 58FE17C2
P 8600 1900
F 0 "#PWR011" H 8600 1650 50  0001 C CNN
F 1 "GND" H 8600 1750 50  0000 C CNN
F 2 "" H 8600 1900 50  0001 C CNN
F 3 "" H 8600 1900 50  0001 C CNN
	1    8600 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 58FE1804
P 8100 1900
F 0 "#PWR012" H 8100 1650 50  0001 C CNN
F 1 "GND" H 8100 1750 50  0000 C CNN
F 2 "" H 8100 1900 50  0001 C CNN
F 3 "" H 8100 1900 50  0001 C CNN
	1    8100 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 58FE1846
P 7850 1900
F 0 "#PWR013" H 7850 1650 50  0001 C CNN
F 1 "GND" H 7850 1750 50  0000 C CNN
F 2 "" H 7850 1900 50  0001 C CNN
F 3 "" H 7850 1900 50  0001 C CNN
	1    7850 1900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 58FE1BC4
P 7750 1350
F 0 "#PWR014" H 7750 1200 50  0001 C CNN
F 1 "+5V" H 7750 1490 50  0000 C CNN
F 2 "" H 7750 1350 50  0001 C CNN
F 3 "" H 7750 1350 50  0001 C CNN
	1    7750 1350
	0    -1   -1   0   
$EndComp
Text GLabel 3250 1400 2    60   Input ~ 0
CH0
$Comp
L R R6
U 1 1 58FE2FD7
P 2700 3600
F 0 "R6" V 2780 3600 50  0000 C CNN
F 1 "100k" V 2700 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2630 3600 50  0001 C CNN
F 3 "" H 2700 3600 50  0001 C CNN
	1    2700 3600
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 58FE3057
P 2700 4450
F 0 "R7" V 2780 4450 50  0000 C CNN
F 1 "10k" V 2700 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2630 4450 50  0001 C CNN
F 3 "" H 2700 4450 50  0001 C CNN
	1    2700 4450
	1    0    0    -1  
$EndComp
$Comp
L CP C3
U 1 1 58FE3E5B
P 2300 3850
F 0 "C3" H 2325 3950 50  0000 L CNN
F 1 "CP" H 2325 3750 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Wave" H 2338 3700 50  0001 C CNN
F 3 "" H 2300 3850 50  0001 C CNN
	1    2300 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 58FE3FCA
P 2700 4700
F 0 "#PWR015" H 2700 4450 50  0001 C CNN
F 1 "GND" H 2700 4550 50  0000 C CNN
F 2 "" H 2700 4700 50  0001 C CNN
F 3 "" H 2700 4700 50  0001 C CNN
	1    2700 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 58FE51AC
P 3000 3400
F 0 "#PWR016" H 3000 3150 50  0001 C CNN
F 1 "GND" H 3000 3250 50  0000 C CNN
F 2 "" H 3000 3400 50  0001 C CNN
F 3 "" H 3000 3400 50  0001 C CNN
	1    3000 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR017
U 1 1 58FE51B2
P 2600 2600
F 0 "#PWR017" H 2600 2450 50  0001 C CNN
F 1 "+5V" H 2600 2740 50  0000 C CNN
F 2 "" H 2600 2600 50  0001 C CNN
F 3 "" H 2600 2600 50  0001 C CNN
	1    2600 2600
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 58FE51B8
P 1900 2650
F 0 "R3" V 1980 2650 50  0000 C CNN
F 1 "1M" V 1900 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1830 2650 50  0001 C CNN
F 3 "" H 1900 2650 50  0001 C CNN
	1    1900 2650
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 58FE51BE
P 1900 3150
F 0 "R4" V 1980 3150 50  0000 C CNN
F 1 "1M" V 1900 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1830 3150 50  0001 C CNN
F 3 "" H 1900 3150 50  0001 C CNN
	1    1900 3150
	1    0    0    -1  
$EndComp
$Comp
L D D3
U 1 1 58FE51C4
P 2100 2650
F 0 "D3" H 2100 2750 50  0000 C CNN
F 1 "1N4148" H 2100 2550 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 2100 2650 50  0001 C CNN
F 3 "" H 2100 2650 50  0001 C CNN
	1    2100 2650
	0    1    1    0   
$EndComp
$Comp
L D D4
U 1 1 58FE51CA
P 2100 3150
F 0 "D4" H 2100 3250 50  0000 C CNN
F 1 "1N4148" H 2100 3050 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323" H 2100 3150 50  0001 C CNN
F 3 "" H 2100 3150 50  0001 C CNN
	1    2100 3150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR018
U 1 1 58FE51D0
P 1900 3400
F 0 "#PWR018" H 1900 3150 50  0001 C CNN
F 1 "GND" H 1900 3250 50  0000 C CNN
F 2 "" H 1900 3400 50  0001 C CNN
F 3 "" H 1900 3400 50  0001 C CNN
	1    1900 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 58FE51D6
P 2100 3400
F 0 "#PWR019" H 2100 3150 50  0001 C CNN
F 1 "GND" H 2100 3250 50  0000 C CNN
F 2 "" H 2100 3400 50  0001 C CNN
F 3 "" H 2100 3400 50  0001 C CNN
	1    2100 3400
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 58FE51DC
P 1600 2900
F 0 "C2" H 1625 3000 50  0000 L CNN
F 1 "C_film" H 1625 2800 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 1638 2750 50  0001 C CNN
F 3 "" H 1600 2900 50  0001 C CNN
	1    1600 2900
	0    1    1    0   
$EndComp
$Comp
L Lamp_Neon NE2
U 1 1 58FE51E2
P 1300 3150
F 0 "NE2" H 1100 3300 50  0000 L CNN
F 1 "Lamp_Neon" V 1500 2950 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D9.0mm_W5.0mm_P5.00mm" V 1300 3250 50  0001 C CNN
F 3 "" V 1300 3250 50  0001 C CNN
	1    1300 3150
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR020
U 1 1 58FE51E8
P 1300 3400
F 0 "#PWR020" H 1300 3150 50  0001 C CNN
F 1 "GND" H 1300 3250 50  0000 C CNN
F 2 "" H 1300 3400 50  0001 C CNN
F 3 "" H 1300 3400 50  0001 C CNN
	1    1300 3400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR021
U 1 1 58FE51FF
P 1900 2400
F 0 "#PWR021" H 1900 2250 50  0001 C CNN
F 1 "+5V" H 1900 2540 50  0000 C CNN
F 2 "" H 1900 2400 50  0001 C CNN
F 3 "" H 1900 2400 50  0001 C CNN
	1    1900 2400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR022
U 1 1 58FE5205
P 2100 2400
F 0 "#PWR022" H 2100 2250 50  0001 C CNN
F 1 "+5V" H 2100 2540 50  0000 C CNN
F 2 "" H 2100 2400 50  0001 C CNN
F 3 "" H 2100 2400 50  0001 C CNN
	1    2100 2400
	1    0    0    -1  
$EndComp
$Comp
L CONN_COAXIAL J2
U 1 1 58FE520D
P 900 2900
F 0 "J2" H 910 3020 50  0000 C CNN
F 1 "CONN_COAXIAL" V 1015 2900 50  0000 C CNN
F 2 "Connect:SMA_THT_Jack_Straight" H 900 2900 50  0001 C CNN
F 3 "" H 900 2900 50  0001 C CNN
	1    900  2900
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR023
U 1 1 58FE5214
P 900 3400
F 0 "#PWR023" H 900 3150 50  0001 C CNN
F 1 "GND" H 900 3250 50  0000 C CNN
F 2 "" H 900 3400 50  0001 C CNN
F 3 "" H 900 3400 50  0001 C CNN
	1    900  3400
	1    0    0    -1  
$EndComp
Text GLabel 3250 3000 2    60   Input ~ 0
CH1
$Comp
L Jumper_NC_Dual JP1
U 1 1 58FE6203
P 2300 4200
F 0 "JP1" H 2350 4100 50  0000 L CNN
F 1 "Jumper_NC_Dual" H 2300 4300 50  0000 C BNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 2300 4200 50  0001 C CNN
F 3 "" H 2300 4200 50  0001 C CNN
	1    2300 4200
	-1   0    0    1   
$EndComp
$Comp
L R R5
U 1 1 58FE64A8
P 1900 4450
F 0 "R5" V 1980 4450 50  0000 C CNN
F 1 "1k" V 1900 4450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 1830 4450 50  0001 C CNN
F 3 "" H 1900 4450 50  0001 C CNN
	1    1900 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 58FE6604
P 1900 4700
F 0 "#PWR024" H 1900 4450 50  0001 C CNN
F 1 "GND" H 1900 4550 50  0000 C CNN
F 2 "" H 1900 4700 50  0001 C CNN
F 3 "" H 1900 4700 50  0001 C CNN
	1    1900 4700
	1    0    0    -1  
$EndComp
$Comp
L LED D5
U 1 1 58FE756F
P 8650 850
F 0 "D5" H 8650 950 50  0000 C CNN
F 1 "LED" H 8650 750 50  0000 C CNN
F 2 "LEDs:LED_0805" H 8650 850 50  0001 C CNN
F 3 "" H 8650 850 50  0001 C CNN
	1    8650 850 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 58FE75F4
P 8350 1000
F 0 "#PWR025" H 8350 750 50  0001 C CNN
F 1 "GND" H 8350 850 50  0000 C CNN
F 2 "" H 8350 1000 50  0001 C CNN
F 3 "" H 8350 1000 50  0001 C CNN
	1    8350 1000
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 58FE7743
P 9050 850
F 0 "R9" V 9130 850 50  0000 C CNN
F 1 "R" V 9050 850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8980 850 50  0001 C CNN
F 3 "" H 9050 850 50  0001 C CNN
	1    9050 850 
	0    1    1    0   
$EndComp
$Comp
L CONN_01X03 J4
U 1 1 58FE7DFB
P 7000 1650
F 0 "J4" H 7000 1850 50  0000 C CNN
F 1 "GND" V 7100 1650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 7000 1650 50  0001 C CNN
F 3 "" H 7000 1650 50  0001 C CNN
	1    7000 1650
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR026
U 1 1 58FE7EEE
P 7000 1950
F 0 "#PWR026" H 7000 1700 50  0001 C CNN
F 1 "GND" H 7000 1800 50  0000 C CNN
F 2 "" H 7000 1950 50  0001 C CNN
F 3 "" H 7000 1950 50  0001 C CNN
	1    7000 1950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR027
U 1 1 58FE81FA
P 7000 950
F 0 "#PWR027" H 7000 800 50  0001 C CNN
F 1 "+5V" H 7000 1090 50  0000 C CNN
F 2 "" H 7000 950 50  0001 C CNN
F 3 "" H 7000 950 50  0001 C CNN
	1    7000 950 
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J3
U 1 1 58FE8306
P 7000 1250
F 0 "J3" H 7000 1450 50  0000 C CNN
F 1 "VCC" V 7100 1250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 7000 1250 50  0001 C CNN
F 3 "" H 7000 1250 50  0001 C CNN
	1    7000 1250
	0    1    1    0   
$EndComp
$Comp
L C C8
U 1 1 58FE8F0F
P 2700 3850
F 0 "C8" H 2725 3950 50  0000 L CNN
F 1 "22pF" H 2725 3750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2738 3700 50  0001 C CNN
F 3 "" H 2700 3850 50  0001 C CNN
	1    2700 3850
	0    1    1    0   
$EndComp
$Comp
L CA3130 U1
U 1 1 5A58FD6F
P 2700 1400
F 0 "U1" H 2700 1650 50  0000 L CNN
F 1 "MCP633" H 2700 1550 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 2600 1300 50  0001 C CNN
F 3 "" H 2700 1400 50  0001 C CNN
	1    2700 1400
	1    0    0    -1  
$EndComp
$Comp
L CA3130 U2
U 1 1 5A590215
P 2700 3000
F 0 "U2" H 2700 3250 50  0000 L CNN
F 1 "MCP633" H 2700 3150 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 2600 2900 50  0001 C CNN
F 3 "" H 2700 3000 50  0001 C CNN
	1    2700 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1500 2300 2000
Wire Wire Line
	2300 2000 3100 2000
Wire Wire Line
	3100 2000 3100 1400
Wire Wire Line
	1300 1800 1300 1750
Wire Wire Line
	1900 1700 1900 1800
Wire Wire Line
	2100 1700 2100 1800
Wire Wire Line
	1300 1350 1300 1300
Wire Wire Line
	1050 1300 1450 1300
Wire Wire Line
	1900 1200 1900 1400
Connection ~ 1900 1300
Wire Wire Line
	2100 1200 2100 1400
Connection ~ 2100 1300
Wire Wire Line
	1900 800  1900 900 
Wire Wire Line
	2100 800  2100 900 
Connection ~ 1300 1300
Wire Wire Line
	900  1800 900  1500
Wire Wire Line
	9750 1300 9750 2000
Wire Wire Line
	9750 1900 9850 1900
Wire Wire Line
	9750 1700 9850 1700
Connection ~ 9750 1900
Wire Wire Line
	9750 1500 9850 1500
Connection ~ 9750 1700
Wire Wire Line
	9750 1300 9850 1300
Connection ~ 9750 1500
Wire Wire Line
	9650 1400 9850 1400
Wire Wire Line
	9650 1600 9850 1600
Wire Wire Line
	8100 1450 8100 1350
Wire Wire Line
	7750 1350 8200 1350
Wire Wire Line
	7850 1450 7850 1350
Connection ~ 8100 1350
Wire Wire Line
	8500 1350 8700 1350
Wire Wire Line
	8600 1450 8600 1350
Connection ~ 8600 1350
Wire Wire Line
	9000 1350 9300 1350
Wire Wire Line
	9100 1350 9100 1450
Wire Wire Line
	9100 1750 9100 1900
Wire Wire Line
	7850 1750 7850 1900
Wire Wire Line
	8100 1750 8100 1900
Wire Wire Line
	8600 1750 8600 1900
Wire Wire Line
	9300 850  9300 1800
Wire Wire Line
	9300 1800 9850 1800
Connection ~ 9100 1350
Connection ~ 7850 1350
Connection ~ 3100 1400
Wire Wire Line
	3100 3600 3100 3000
Wire Wire Line
	1300 3400 1300 3350
Wire Wire Line
	1900 3300 1900 3400
Wire Wire Line
	2100 3300 2100 3400
Wire Wire Line
	1300 2950 1300 2900
Wire Wire Line
	1050 2900 1450 2900
Wire Wire Line
	1900 2800 1900 3000
Connection ~ 1900 2900
Wire Wire Line
	2100 2800 2100 3000
Connection ~ 2100 2900
Wire Wire Line
	1900 2400 1900 2500
Wire Wire Line
	2100 2400 2100 2500
Connection ~ 1300 2900
Wire Wire Line
	900  3400 900  3100
Connection ~ 3100 3000
Wire Wire Line
	2550 3600 2300 3600
Connection ~ 2300 3600
Wire Wire Line
	2850 3600 3100 3600
Wire Wire Line
	2300 3100 2300 3700
Wire Wire Line
	2300 4100 2300 4000
Wire Wire Line
	1900 4600 1900 4700
Wire Wire Line
	2700 4600 2700 4700
Wire Wire Line
	2550 4200 2700 4200
Wire Wire Line
	2700 4200 2700 4300
Wire Wire Line
	2050 4200 1900 4200
Wire Wire Line
	1900 4200 1900 4300
Wire Wire Line
	8350 1000 8350 850 
Wire Wire Line
	8350 850  8500 850 
Wire Wire Line
	8800 850  8900 850 
Wire Wire Line
	9300 850  9200 850 
Connection ~ 9300 1350
Wire Wire Line
	6900 1850 6900 1900
Wire Wire Line
	6900 1900 7100 1900
Wire Wire Line
	7100 1900 7100 1850
Wire Wire Line
	7000 1850 7000 1950
Connection ~ 7000 1900
Wire Wire Line
	6900 1050 6900 1000
Wire Wire Line
	6900 1000 7100 1000
Wire Wire Line
	7100 1000 7100 1050
Wire Wire Line
	7000 950  7000 1050
Connection ~ 7000 1000
Wire Wire Line
	2550 3850 2500 3850
Wire Wire Line
	2500 3850 2500 3600
Connection ~ 2500 3600
Wire Wire Line
	2850 3850 2900 3850
Wire Wire Line
	2900 3850 2900 3600
Connection ~ 2900 3600
Wire Wire Line
	2600 1800 2600 1700
Wire Wire Line
	2600 1750 2900 1750
Wire Wire Line
	2700 1750 2700 1700
Connection ~ 2600 1750
Wire Wire Line
	2800 1750 2800 1700
Connection ~ 2700 1750
Wire Wire Line
	2900 1750 2900 1700
Connection ~ 2800 1750
Wire Wire Line
	3000 1400 3250 1400
Wire Wire Line
	2300 1500 2400 1500
Wire Wire Line
	1750 1300 2400 1300
Wire Wire Line
	2600 1100 2600 1000
Wire Wire Line
	1750 2900 2400 2900
Wire Wire Line
	2300 3100 2400 3100
Wire Wire Line
	2600 3300 2600 3350
Wire Wire Line
	2600 3350 3000 3350
Wire Wire Line
	3000 3350 3000 3400
Wire Wire Line
	2700 3300 2700 3350
Connection ~ 2700 3350
Wire Wire Line
	2800 3300 2800 3350
Connection ~ 2800 3350
Wire Wire Line
	2900 3300 2900 3350
Connection ~ 2900 3350
Wire Wire Line
	3000 3000 3250 3000
Wire Wire Line
	2600 2700 2600 2600
$EndSCHEMATC

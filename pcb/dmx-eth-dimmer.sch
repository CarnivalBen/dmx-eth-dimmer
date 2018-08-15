EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:carnivalben
LIBS:dmx-eth-dimmer-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 9
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
L PIC16F877A U***1
U 1 1 5B15451E
P 4250 3950
F 0 "U***1" H 4250 5450 70  0000 C CNN
F 1 "PIC16F877A" H 4250 2450 70  0000 C CNN
F 2 "Housings_DIP:DIP-40_W15.24mm" H 4250 3950 60  0001 C CNN
F 3 "" H 4250 3950 60  0001 C CNN
	1    4250 3950
	1    0    0    -1  
$EndComp
$Comp
L PSU-5VDC U1
U 1 1 5B16AF64
P 2400 1300
F 0 "U1" H 2250 1250 60  0000 C CNN
F 1 "PSU-5VDC" H 2350 1350 60  0000 C CNN
F 2 "CarnivalBen:HLK-PM01" H 2450 1250 60  0001 C CNN
F 3 "" H 2450 1250 60  0001 C CNN
	1    2400 1300
	-1   0    0    -1  
$EndComp
$Comp
L Screw_Terminal_01x02 J1
U 1 1 5B16AFFA
P 1250 850
F 0 "J1" H 1250 950 50  0000 C CNN
F 1 "MAINS IN" H 1250 650 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-2_P5.08mm" H 1250 850 50  0001 C CNN
F 3 "" H 1250 850 50  0001 C CNN
	1    1250 850 
	-1   0    0    1   
$EndComp
$Comp
L CP C3
U 1 1 5B16B03F
P 1550 1300
F 0 "C3" H 1575 1400 50  0000 L CNN
F 1 "1000uF" H 1575 1200 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P5.00mm" H 1588 1150 50  0001 C CNN
F 3 "" H 1550 1300 50  0001 C CNN
	1    1550 1300
	-1   0    0    -1  
$EndComp
$Comp
L SW_DIP_x08 SW7
U 1 1 5B16B7D3
P 5800 3000
F 0 "SW7" H 5800 3550 50  0000 C CNN
F 1 "SW_DIP_x08" H 5800 2550 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_DIP_x8_W7.62mm_Slide" H 5800 3000 50  0001 C CNN
F 3 "" H 5800 3000 50  0001 C CNN
	1    5800 3000
	1    0    0    -1  
$EndComp
Text GLabel 1300 1150 0    60   Input ~ 0
5V
Text GLabel 1300 1450 0    60   Input ~ 0
GND
Text GLabel 3000 3800 0    60   Input ~ 0
5V
Text GLabel 5800 3500 2    60   Input ~ 0
5V
Text GLabel 5800 3800 2    60   Input ~ 0
GND
Text GLabel 1700 4000 0    60   Input ~ 0
GND
$Comp
L C C5
U 1 1 5B1E611F
P 5500 3650
F 0 "C5" H 5525 3750 50  0000 L CNN
F 1 "0.01uF" H 5525 3550 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 5538 3500 50  0001 C CNN
F 3 "" H 5500 3650 50  0001 C CNN
	1    5500 3650
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5B1E6287
P 2350 4000
F 0 "Y1" H 2350 4150 50  0000 C CNN
F 1 "20MHz" H 2350 3850 50  0000 C CNN
F 2 "Crystals:Crystal_HC50_Vertical" H 2350 4000 50  0001 C CNN
F 3 "" H 2350 4000 50  0001 C CNN
	1    2350 4000
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 5B1E6414
P 2050 3750
F 0 "C1" H 2075 3850 50  0000 L CNN
F 1 "33pF" H 2075 3650 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 2088 3600 50  0001 C CNN
F 3 "" H 2050 3750 50  0001 C CNN
	1    2050 3750
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 5B1E648C
P 2050 4250
F 0 "C2" H 2075 4350 50  0000 L CNN
F 1 "33pF" H 2075 4150 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 2088 4100 50  0001 C CNN
F 3 "" H 2050 4250 50  0001 C CNN
	1    2050 4250
	0    1    1    0   
$EndComp
Text GLabel 3000 3900 0    60   Input ~ 0
GND
Text GLabel 3400 6700 0    60   Input ~ 0
GND
Text GLabel 5100 6100 2    60   Input ~ 0
5V
Text Label 2450 4600 0    60   ~ 0
RESET
Text Label 2450 4700 0    60   ~ 0
DATACLK
Text Label 2550 4900 0    60   ~ 0
TX
Text Label 2650 5100 0    60   ~ 0
CS
Text Label 2750 6350 0    60   ~ 0
RX
Text Label 2750 6150 0    60   ~ 0
INT
Text GLabel 6150 2500 1    60   Input ~ 0
GND
$Comp
L SW_Push_4PIN SW1
U 1 1 5B1EEDB5
P 1250 1850
F 0 "SW1" H 1300 1950 50  0000 L CNN
F 1 "IP1" H 1250 1790 50  0000 C CNN
F 2 "CarnivalBen:SW_PUSH_6mm_4pin" H 1250 2050 50  0001 C CNN
F 3 "" H 1250 2050 50  0001 C CNN
	1    1250 1850
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5B1EF2F0
P 1950 2100
F 0 "R1" V 2030 2100 50  0000 C CNN
F 1 "10K" V 1950 2100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1880 2100 50  0001 C CNN
F 3 "" H 1950 2100 50  0001 C CNN
	1    1950 2100
	-1   0    0    1   
$EndComp
Text GLabel 800  1850 0    60   Input ~ 0
GND
Text GLabel 1850 1850 0    60   Input ~ 0
5V
$Comp
L SW_Push_4PIN SW2
U 1 1 5B1EF77C
P 1250 2150
F 0 "SW2" H 1300 2250 50  0000 L CNN
F 1 "IP2" H 1250 2090 50  0000 C CNN
F 2 "CarnivalBen:SW_PUSH_6mm_4pin" H 1250 2350 50  0001 C CNN
F 3 "" H 1250 2350 50  0001 C CNN
	1    1250 2150
	1    0    0    -1  
$EndComp
$Comp
L SW_Push_4PIN SW4
U 1 1 5B1EF81B
P 1250 2750
F 0 "SW4" H 1300 2850 50  0000 L CNN
F 1 "IP4" H 1250 2690 50  0000 C CNN
F 2 "CarnivalBen:SW_PUSH_6mm_4pin" H 1250 2950 50  0001 C CNN
F 3 "" H 1250 2950 50  0001 C CNN
	1    1250 2750
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5B1EF86D
P 2150 2100
F 0 "R2" V 2230 2100 50  0000 C CNN
F 1 "10K" V 2150 2100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2080 2100 50  0001 C CNN
F 3 "" H 2150 2100 50  0001 C CNN
	1    2150 2100
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 5B1EF8C0
P 2350 2100
F 0 "R3" V 2430 2100 50  0000 C CNN
F 1 "10K" V 2350 2100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 2100 50  0001 C CNN
F 3 "" H 2350 2100 50  0001 C CNN
	1    2350 2100
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 5B1EF94E
P 2550 2100
F 0 "R8" V 2630 2100 50  0000 C CNN
F 1 "10K" V 2550 2100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2480 2100 50  0001 C CNN
F 3 "" H 2550 2100 50  0001 C CNN
	1    2550 2100
	-1   0    0    1   
$EndComp
$Comp
L SW_Push_4PIN SW5
U 1 1 5B1F0721
P 1250 3050
F 0 "SW5" H 1300 3150 50  0000 L CNN
F 1 "DMXAH" H 1250 2990 50  0000 C CNN
F 2 "CarnivalBen:SW_PUSH_6mm_4pin" H 1250 3250 50  0001 C CNN
F 3 "" H 1250 3250 50  0001 C CNN
	1    1250 3050
	1    0    0    -1  
$EndComp
$Comp
L SW_Push_4PIN SW6
U 1 1 5B1F0783
P 1250 3350
F 0 "SW6" H 1300 3450 50  0000 L CNN
F 1 "DMXAL" H 1250 3290 50  0000 C CNN
F 2 "CarnivalBen:SW_PUSH_6mm_4pin" H 1250 3550 50  0001 C CNN
F 3 "" H 1250 3550 50  0001 C CNN
	1    1250 3350
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5B1F07EE
P 2750 2100
F 0 "R9" V 2830 2100 50  0000 C CNN
F 1 "10K" V 2750 2100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2680 2100 50  0001 C CNN
F 3 "" H 2750 2100 50  0001 C CNN
	1    2750 2100
	-1   0    0    1   
$EndComp
$Comp
L R R10
U 1 1 5B1F0850
P 2950 2100
F 0 "R10" V 3030 2100 50  0000 C CNN
F 1 "10K" V 2950 2100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2880 2100 50  0001 C CNN
F 3 "" H 2950 2100 50  0001 C CNN
	1    2950 2100
	-1   0    0    1   
$EndComp
$Comp
L LED_Dual_2pin D2
U 1 1 5B1F4FC2
P 1800 7500
F 0 "D2" H 1800 7725 50  0000 C CNN
F 1 "Ethernet Status" H 1800 7250 50  0000 C CNN
F 2 "LEDs:LED_D3.0mm" H 1800 7500 50  0001 C CNN
F 3 "" H 1800 7500 50  0001 C CNN
	1    1800 7500
	1    0    0    -1  
$EndComp
Text GLabel 3100 3500 0    60   Input ~ 0
ETH_STATUS
Text GLabel 3100 3400 0    60   Input ~ 0
CFG_STATUS
Text GLabel 1400 7500 0    60   Input ~ 0
ETH_STATUS
Text GLabel 2600 7400 2    60   Input ~ 0
5V
Text GLabel 2600 7600 2    60   Input ~ 0
GND
$Comp
L R R6
U 1 1 5B1F6C98
P 2350 7400
F 0 "R6" V 2430 7400 50  0000 C CNN
F 1 "300" V 2350 7400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 7400 50  0001 C CNN
F 3 "" H 2350 7400 50  0001 C CNN
	1    2350 7400
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5B1F6D53
P 2350 7600
F 0 "R7" V 2430 7600 50  0000 C CNN
F 1 "300" V 2350 7600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 7600 50  0001 C CNN
F 3 "" H 2350 7600 50  0001 C CNN
	1    2350 7600
	0    1    1    0   
$EndComp
$Comp
L LED_Dual_2pin D1
U 1 1 5B1F779A
P 1800 6950
F 0 "D1" H 1800 7175 50  0000 C CNN
F 1 "CFG Status" H 1800 6700 50  0000 C CNN
F 2 "LEDs:LED_D3.0mm" H 1800 6950 50  0001 C CNN
F 3 "" H 1800 6950 50  0001 C CNN
	1    1800 6950
	1    0    0    -1  
$EndComp
Text GLabel 1400 6950 0    60   Input ~ 0
CFG_STATUS
Text GLabel 2600 6850 2    60   Input ~ 0
5V
Text GLabel 2600 7050 2    60   Input ~ 0
GND
$Comp
L R R4
U 1 1 5B1F77A3
P 2350 6850
F 0 "R4" V 2430 6850 50  0000 C CNN
F 1 "300" V 2350 6850 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 6850 50  0001 C CNN
F 3 "" H 2350 6850 50  0001 C CNN
	1    2350 6850
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5B1F77A9
P 2350 7050
F 0 "R5" V 2430 7050 50  0000 C CNN
F 1 "300" V 2350 7050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 7050 50  0001 C CNN
F 3 "" H 2350 7050 50  0001 C CNN
	1    2350 7050
	0    1    1    0   
$EndComp
NoConn ~ 3200 3600
$Comp
L Conn_01x06 J4
U 1 1 5B1FA00E
P 4200 1750
F 0 "J4" H 4200 2050 50  0000 C CNN
F 1 "MASTER PROG" H 4200 1350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 4200 1750 50  0001 C CNN
F 3 "" H 4200 1750 50  0001 C CNN
	1    4200 1750
	0    -1   -1   0   
$EndComp
Text GLabel 4100 2050 3    60   Input ~ 0
5V
Text GLabel 4200 2050 3    60   Input ~ 0
GND
Text GLabel 1650 850  2    60   Input ~ 0
LIVE
Text GLabel 1650 750  2    60   Input ~ 0
NEUTRAL
Text GLabel 3000 950  0    60   Input ~ 0
LIVE
Text GLabel 3000 1650 0    60   Input ~ 0
NEUTRAL
$Comp
L D_Bridge_+-AA D3
U 1 1 5B2005F2
P 4400 1050
F 0 "D3" H 4450 1325 50  0000 L CNN
F 1 "BRIDGE" H 4450 1250 50  0000 L CNN
F 2 "CarnivalBen:Diode_Bridge_W08" H 4400 1050 50  0001 C CNN
F 3 "" H 4400 1050 50  0001 C CNN
	1    4400 1050
	1    0    0    -1  
$EndComp
$Comp
L 4N25 U4
U 1 1 5B200A95
P 5400 1050
F 0 "U4" H 5200 1250 50  0000 L CNN
F 1 "4N25" H 5400 1250 50  0000 L CNN
F 2 "Housings_DIP:DIP-6_W7.62mm" H 5200 850 50  0001 L CIN
F 3 "" H 5400 1050 50  0001 L CNN
	1    5400 1050
	1    0    0    -1  
$EndComp
Text GLabel 6200 700  2    60   Input ~ 0
5V
Text GLabel 5700 1400 0    60   Input ~ 0
GND
$Comp
L R R11
U 1 1 5B200E11
P 6000 700
F 0 "R11" V 6080 700 50  0000 C CNN
F 1 "10K" V 6000 700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5930 700 50  0001 C CNN
F 3 "" H 6000 700 50  0001 C CNN
	1    6000 700 
	0    1    1    0   
$EndComp
$Sheet
S 6950 800  850  1600
U 5B208C37
F0 "Channel 1" 60
F1 "powerctrl.sch" 60
F2 "5V" U L 6950 900 60 
F3 "GND" U L 6950 1100 60 
F4 "DATA" I L 6950 1300 60 
F5 "CLOCK" I L 6950 1500 60 
F6 "CHIPSELECT" I L 6950 1700 60 
F7 "ZEROCROSS" I L 6950 1900 60 
F8 "LIVE" U L 6950 2100 60 
F9 "NEUTRAL" U L 6950 2300 60 
$EndSheet
Text GLabel 6800 900  0    60   Input ~ 0
5V
Text GLabel 6800 1100 0    60   Input ~ 0
GND
$Sheet
S 8550 800  800  1600
U 5B21431A
F0 "Channel 2" 60
F1 "powerctrl.sch" 60
F2 "5V" U L 8550 900 60 
F3 "GND" U L 8550 1100 60 
F4 "DATA" I L 8550 1300 60 
F5 "CLOCK" I L 8550 1500 60 
F6 "CHIPSELECT" I L 8550 1700 60 
F7 "ZEROCROSS" I L 8550 1900 60 
F8 "LIVE" U L 8550 2100 60 
F9 "NEUTRAL" U L 8550 2300 60 
$EndSheet
Text GLabel 8400 900  0    60   Input ~ 0
5V
Text GLabel 8400 1100 0    60   Input ~ 0
GND
$Sheet
S 10150 800  800  1600
U 5B219438
F0 "Channel 3" 60
F1 "powerctrl.sch" 60
F2 "5V" U L 10150 900 60 
F3 "GND" U L 10150 1100 60 
F4 "DATA" I L 10150 1300 60 
F5 "CLOCK" I L 10150 1500 60 
F6 "CHIPSELECT" I L 10150 1700 60 
F7 "ZEROCROSS" I L 10150 1900 60 
F8 "LIVE" U L 10150 2100 60 
F9 "NEUTRAL" U L 10150 2300 60 
$EndSheet
Text GLabel 10000 900  0    60   Input ~ 0
5V
Text GLabel 10000 1100 0    60   Input ~ 0
GND
$Sheet
S 6950 2700 850  1600
U 5B21991E
F0 "Channel 4" 60
F1 "powerctrl.sch" 60
F2 "5V" U L 6950 2800 60 
F3 "GND" U L 6950 3000 60 
F4 "DATA" I L 6950 3200 60 
F5 "CLOCK" I L 6950 3400 60 
F6 "CHIPSELECT" I L 6950 3600 60 
F7 "ZEROCROSS" I L 6950 3800 60 
F8 "LIVE" U L 6950 4000 60 
F9 "NEUTRAL" U L 6950 4200 60 
$EndSheet
Text GLabel 6800 2800 0    60   Input ~ 0
5V
Text GLabel 6800 3000 0    60   Input ~ 0
GND
$Sheet
S 8550 2700 800  1600
U 5B21992A
F0 "Channel 5" 60
F1 "powerctrl.sch" 60
F2 "5V" U L 8550 2800 60 
F3 "GND" U L 8550 3000 60 
F4 "DATA" I L 8550 3200 60 
F5 "CLOCK" I L 8550 3400 60 
F6 "CHIPSELECT" I L 8550 3600 60 
F7 "ZEROCROSS" I L 8550 3800 60 
F8 "LIVE" U L 8550 4000 60 
F9 "NEUTRAL" U L 8550 4200 60 
$EndSheet
Text GLabel 8400 2800 0    60   Input ~ 0
5V
Text GLabel 8400 3000 0    60   Input ~ 0
GND
$Sheet
S 10150 2700 800  1600
U 5B219936
F0 "Channel 6" 60
F1 "powerctrl.sch" 60
F2 "5V" U L 10150 2800 60 
F3 "GND" U L 10150 3000 60 
F4 "DATA" I L 10150 3200 60 
F5 "CLOCK" I L 10150 3400 60 
F6 "CHIPSELECT" I L 10150 3600 60 
F7 "ZEROCROSS" I L 10150 3800 60 
F8 "LIVE" U L 10150 4000 60 
F9 "NEUTRAL" U L 10150 4200 60 
$EndSheet
Text GLabel 10000 2800 0    60   Input ~ 0
5V
Text GLabel 10000 3000 0    60   Input ~ 0
GND
$Sheet
S 6950 4600 850  1600
U 5B21C6D2
F0 "Channel 7" 60
F1 "powerctrl.sch" 60
F2 "5V" U L 6950 4700 60 
F3 "GND" U L 6950 4900 60 
F4 "DATA" I L 6950 5100 60 
F5 "CLOCK" I L 6950 5300 60 
F6 "CHIPSELECT" I L 6950 5500 60 
F7 "ZEROCROSS" I L 6950 5700 60 
F8 "LIVE" U L 6950 5900 60 
F9 "NEUTRAL" U L 6950 6100 60 
$EndSheet
Text GLabel 6800 4700 0    60   Input ~ 0
5V
Text GLabel 6800 4900 0    60   Input ~ 0
GND
$Sheet
S 8550 4600 800  1600
U 5B21C6DE
F0 "Channel 8" 60
F1 "powerctrl.sch" 60
F2 "5V" U L 8550 4700 60 
F3 "GND" U L 8550 4900 60 
F4 "DATA" I L 8550 5100 60 
F5 "CLOCK" I L 8550 5300 60 
F6 "CHIPSELECT" I L 8550 5500 60 
F7 "ZEROCROSS" I L 8550 5700 60 
F8 "LIVE" U L 8550 5900 60 
F9 "NEUTRAL" U L 8550 6100 60 
$EndSheet
Text GLabel 8400 4700 0    60   Input ~ 0
5V
Text GLabel 8400 4900 0    60   Input ~ 0
GND
Text GLabel 1350 4250 0    60   Input ~ 0
CHNCLK
Text GLabel 1350 4400 0    60   Input ~ 0
CHNDATA
Text GLabel 6800 5300 0    60   Input ~ 0
CHNCLK
Text GLabel 6800 5100 0    60   Input ~ 0
CHNDATA
Text GLabel 5900 1050 2    60   Input ~ 0
ZC
Text GLabel 6800 1900 0    60   Input ~ 0
ZC
Text GLabel 8400 1900 0    60   Input ~ 0
ZC
Text GLabel 10000 1900 0    60   Input ~ 0
ZC
Text GLabel 6800 3800 0    60   Input ~ 0
ZC
Text GLabel 8400 3800 0    60   Input ~ 0
ZC
Text GLabel 10000 3800 0    60   Input ~ 0
ZC
Text GLabel 6800 5700 0    60   Input ~ 0
ZC
Text GLabel 8400 5700 0    60   Input ~ 0
ZC
Text GLabel 6800 1500 0    60   Input ~ 0
CHNCLK
Text GLabel 6800 1300 0    60   Input ~ 0
CHNDATA
Text GLabel 8400 1500 0    60   Input ~ 0
CHNCLK
Text GLabel 8400 1300 0    60   Input ~ 0
CHNDATA
Text GLabel 10000 1500 0    60   Input ~ 0
CHNCLK
Text GLabel 10000 1300 0    60   Input ~ 0
CHNDATA
Text GLabel 6800 3400 0    60   Input ~ 0
CHNCLK
Text GLabel 6800 3200 0    60   Input ~ 0
CHNDATA
Text GLabel 8400 3400 0    60   Input ~ 0
CHNCLK
Text GLabel 8400 3200 0    60   Input ~ 0
CHNDATA
Text GLabel 10000 3400 0    60   Input ~ 0
CHNCLK
Text GLabel 10000 3200 0    60   Input ~ 0
CHNDATA
Text GLabel 8400 5300 0    60   Input ~ 0
CHNCLK
Text GLabel 8400 5100 0    60   Input ~ 0
CHNDATA
Text Label 5350 4650 0    60   ~ 0
CH7
Text Label 5350 4750 0    60   ~ 0
CH6
Text Label 5350 4850 0    60   ~ 0
CH5
Text Label 5350 4950 0    60   ~ 0
CH4
Text Label 5350 5050 0    60   ~ 0
CH3
Text Label 5350 5150 0    60   ~ 0
CH2
Text Label 5350 5250 0    60   ~ 0
CH1
Entry Wire Line
	5600 4650 5700 4750
Entry Wire Line
	5600 4750 5700 4850
Entry Wire Line
	5600 4850 5700 4950
Entry Wire Line
	5600 4950 5700 5050
Entry Wire Line
	5600 5050 5700 5150
Entry Wire Line
	5600 5150 5700 5250
Entry Wire Line
	5600 5250 5700 5350
Text Label 6550 1700 0    60   ~ 0
CH1
Entry Wire Line
	6300 1800 6400 1700
Text Label 6550 3600 0    60   ~ 0
CH4
Entry Wire Line
	6300 3700 6400 3600
Text Label 6550 5500 0    60   ~ 0
CH7
Entry Wire Line
	6300 5600 6400 5500
Text Label 8150 5500 0    60   ~ 0
CH8
Text Label 8150 3600 0    60   ~ 0
CH5
Text Label 9750 3600 0    60   ~ 0
CH6
Text Label 8150 1700 0    60   ~ 0
CH2
Text Label 9750 1700 0    60   ~ 0
CH3
Entry Wire Line
	7900 1800 8000 1700
Entry Wire Line
	9500 1800 9600 1700
Entry Wire Line
	7900 3700 8000 3600
Entry Wire Line
	9500 3700 9600 3600
Text GLabel 6800 2100 0    60   Input ~ 0
LIVE
Text GLabel 6800 2300 0    60   Input ~ 0
NEUTRAL
Text GLabel 8400 2100 0    60   Input ~ 0
LIVE
Text GLabel 8400 2300 0    60   Input ~ 0
NEUTRAL
Text GLabel 10000 2100 0    60   Input ~ 0
LIVE
Text GLabel 10000 2300 0    60   Input ~ 0
NEUTRAL
Text GLabel 6800 4000 0    60   Input ~ 0
LIVE
Text GLabel 6800 4200 0    60   Input ~ 0
NEUTRAL
Text GLabel 8400 4000 0    60   Input ~ 0
LIVE
Text GLabel 8400 4200 0    60   Input ~ 0
NEUTRAL
Text GLabel 10000 4000 0    60   Input ~ 0
LIVE
Text GLabel 10000 4200 0    60   Input ~ 0
NEUTRAL
Text GLabel 6800 5900 0    60   Input ~ 0
LIVE
Text GLabel 6800 6100 0    60   Input ~ 0
NEUTRAL
Text GLabel 8400 5900 0    60   Input ~ 0
LIVE
Text GLabel 8400 6100 0    60   Input ~ 0
NEUTRAL
$Comp
L Fuse F1
U 1 1 5B2AC857
P 3350 950
F 0 "F1" V 3430 950 50  0000 C CNN
F 1 "100mA" V 3275 950 50  0000 C CNN
F 2 "Fuse_Holders_and_Fuses:Fuseholder5x20_horiz_open_inline_Type-I" V 3280 950 50  0001 C CNN
F 3 "" H 3350 950 50  0001 C CNN
	1    3350 950 
	0    1    1    0   
$EndComp
$Comp
L R R28
U 1 1 5B2B8170
P 4100 750
F 0 "R28" V 4180 750 50  0000 C CNN
F 1 "100K" V 4100 750 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4030 750 50  0001 C CNN
F 3 "" H 4100 750 50  0001 C CNN
	1    4100 750 
	0    1    1    0   
$EndComp
$Comp
L R R29
U 1 1 5B2B8472
P 4900 950
F 0 "R29" V 4980 950 50  0000 C CNN
F 1 "120" V 4900 950 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4830 950 50  0001 C CNN
F 3 "" H 4900 950 50  0001 C CNN
	1    4900 950 
	0    1    1    0   
$EndComp
$Comp
L 74HCT08 U3
U 1 1 5B16BA95
P 4250 6400
F 0 "U3" H 4250 6300 50  0000 C CNN
F 1 "74HCT08" H 4250 6500 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm" H 4250 6400 50  0001 C CNN
F 3 "DOCUMENTATION" H 4250 6400 50  0001 C CNN
	1    4250 6400
	1    0    0    -1  
$EndComp
Text GLabel 5100 6700 2    60   Input ~ 0
GND
Text Label 3250 5300 0    60   ~ 0
INT5v
Text Label 3150 5350 1    60   ~ 0
RX5v
Text Label 2750 4150 0    60   ~ 0
OSC1
Text Label 2750 4250 0    60   ~ 0
OSC2
Text Label 3000 2700 0    60   ~ 0
IP1
Text Label 3000 2800 0    60   ~ 0
IP2
Text Label 3000 2900 0    60   ~ 0
IP3
Text Label 3000 3000 0    60   ~ 0
IP4
Text Label 3000 3100 0    60   ~ 0
DMXAH
Text Label 3000 3200 0    60   ~ 0
DMXAL
Text Label 3300 2350 0    60   ~ 0
MCLR
Text Label 5300 3300 0    60   ~ 0
BIT0
Text Label 5300 3200 0    60   ~ 0
BIT1
Text Label 5300 3100 0    60   ~ 0
BIT2
Text Label 5300 3000 0    60   ~ 0
BIT3
Text Label 5300 2900 0    60   ~ 0
BIT4
Text Label 5300 2800 0    60   ~ 0
BIT5
Text Label 5300 2700 0    60   ~ 0
BIT6
Text Label 5300 2600 0    60   ~ 0
BIT7
Text Label 3050 1200 0    60   ~ 0
FUSED_LIVE
Text Label 4300 750  0    60   ~ 0
ZC_SIG
Text Label 4550 1400 0    60   ~ 0
ZC_RETURN
Entry Wire Line
	7900 5600 8000 5500
Text Label 5350 4550 0    60   ~ 0
CH8
Entry Wire Line
	5600 4550 5700 4650
Wire Wire Line
	1800 1150 1800 1200
Wire Wire Line
	1800 1450 1800 1400
Wire Wire Line
	1300 1450 1800 1450
Wire Wire Line
	1300 1150 1800 1150
Connection ~ 1550 1150
Connection ~ 1550 1450
Wire Wire Line
	3000 3900 3200 3900
Wire Wire Line
	3000 3800 3200 3800
Wire Wire Line
	5300 3800 5800 3800
Wire Wire Line
	5300 3800 5300 3600
Connection ~ 5500 3800
Wire Wire Line
	5300 3500 5800 3500
Connection ~ 5500 3500
Wire Wire Line
	1700 4000 1800 4000
Wire Wire Line
	1800 3750 1800 4250
Wire Wire Line
	1800 3750 1900 3750
Wire Wire Line
	1800 4250 1900 4250
Connection ~ 1800 4000
Wire Wire Line
	2350 4150 2350 4250
Wire Wire Line
	2200 3750 2600 3750
Wire Wire Line
	2350 3750 2350 3850
Connection ~ 2350 3750
Connection ~ 2350 4250
Wire Wire Line
	2600 3750 2600 4150
Wire Wire Line
	2600 4150 3200 4150
Wire Wire Line
	2200 4250 3200 4250
Wire Wire Line
	3200 4700 2400 4700
Wire Wire Line
	2400 4700 2400 5400
Wire Wire Line
	3200 4900 2500 4900
Wire Wire Line
	2500 4900 2500 5500
Wire Wire Line
	2550 5100 3200 5100
Wire Wire Line
	3200 4600 2350 4600
Wire Wire Line
	3500 6100 3450 6100
Wire Wire Line
	3450 6200 3500 6200
Wire Wire Line
	3500 6400 3450 6400
Wire Wire Line
	3450 6400 3450 6500
Wire Wire Line
	3450 6500 3500 6500
Wire Wire Line
	3400 6700 3500 6700
Wire Wire Line
	5100 6100 5000 6100
Wire Wire Line
	3200 4800 3150 4800
Wire Wire Line
	3150 4800 3150 5350
Wire Wire Line
	3150 5350 3350 5350
Wire Wire Line
	3050 6450 3450 6450
Connection ~ 3450 6450
Wire Wire Line
	3450 6100 3450 6200
Connection ~ 3450 6150
Wire Wire Line
	3350 5350 3350 6600
Wire Wire Line
	3350 6600 3500 6600
Wire Wire Line
	3400 6300 3500 6300
Wire Wire Line
	6100 2600 6150 2600
Wire Wire Line
	6150 2500 6150 3300
Wire Wire Line
	6150 2700 6100 2700
Connection ~ 6150 2600
Wire Wire Line
	6150 2800 6100 2800
Connection ~ 6150 2700
Wire Wire Line
	6150 2900 6100 2900
Connection ~ 6150 2800
Wire Wire Line
	6150 3000 6100 3000
Connection ~ 6150 2900
Wire Wire Line
	6150 3100 6100 3100
Connection ~ 6150 3000
Wire Wire Line
	6150 3200 6100 3200
Connection ~ 6150 3100
Wire Wire Line
	6150 3300 6100 3300
Connection ~ 6150 3200
Wire Wire Line
	1850 1850 2950 1850
Wire Wire Line
	1950 1850 1950 1950
Wire Wire Line
	2150 1850 2150 1950
Connection ~ 1950 1850
Wire Wire Line
	2350 1850 2350 1950
Connection ~ 2150 1850
Wire Wire Line
	2550 1850 2550 1950
Connection ~ 2350 1850
Wire Wire Line
	2750 1850 2750 1950
Connection ~ 2550 1850
Wire Wire Line
	2950 1850 2950 1950
Connection ~ 2750 1850
Wire Wire Line
	800  1850 1000 1850
Connection ~ 900  1850
Connection ~ 900  2150
Connection ~ 900  2450
Connection ~ 900  2750
Connection ~ 900  3050
Wire Wire Line
	1600 3000 3200 3000
Wire Wire Line
	1650 2900 3200 2900
Wire Wire Line
	1750 2800 3200 2800
Wire Wire Line
	1800 2700 3200 2700
Wire Wire Line
	1550 3100 3200 3100
Wire Wire Line
	1750 3200 3200 3200
Wire Wire Line
	1950 2250 1950 2700
Connection ~ 1950 2700
Wire Wire Line
	2150 2250 2150 2800
Connection ~ 2150 2800
Wire Wire Line
	2750 2250 2750 3100
Connection ~ 2750 3100
Wire Wire Line
	3100 3400 3200 3400
Wire Wire Line
	3200 3500 3100 3500
Wire Wire Line
	2200 7400 2100 7400
Wire Wire Line
	2100 7400 2100 7600
Wire Wire Line
	2100 7600 2200 7600
Connection ~ 2100 7500
Wire Wire Line
	2500 7600 2600 7600
Wire Wire Line
	2500 7400 2600 7400
Wire Wire Line
	1500 7500 1400 7500
Wire Wire Line
	2200 6850 2100 6850
Wire Wire Line
	2100 6850 2100 7050
Wire Wire Line
	2100 7050 2200 7050
Connection ~ 2100 6950
Wire Wire Line
	2500 7050 2600 7050
Wire Wire Line
	2500 6850 2600 6850
Wire Wire Line
	1500 6950 1400 6950
Wire Wire Line
	4000 1950 4000 2350
Wire Wire Line
	4000 2350 3150 2350
Wire Wire Line
	3150 2350 3150 2600
Wire Wire Line
	3150 2600 3200 2600
Wire Wire Line
	5300 3300 5500 3300
Wire Wire Line
	5500 3200 5300 3200
Wire Wire Line
	5300 3100 5500 3100
Wire Wire Line
	5300 3000 5500 3000
Wire Wire Line
	5300 2900 5500 2900
Wire Wire Line
	5500 2800 5300 2800
Wire Wire Line
	5300 2700 5500 2700
Wire Wire Line
	5300 2600 5500 2600
Wire Wire Line
	4300 1950 4300 2350
Wire Wire Line
	4300 2350 5350 2350
Wire Wire Line
	5350 2350 5350 2600
Connection ~ 5350 2600
Wire Wire Line
	4400 1950 4400 2300
Wire Wire Line
	4400 2300 5400 2300
Wire Wire Line
	5400 2300 5400 2700
Connection ~ 5400 2700
Wire Wire Line
	4500 1950 4500 2250
Wire Wire Line
	4500 2250 5450 2250
Wire Wire Line
	5450 2250 5450 3000
Connection ~ 5450 3000
Wire Wire Line
	4100 1950 4100 2050
Wire Wire Line
	4200 1950 4200 2050
Wire Wire Line
	3850 750  3950 750 
Wire Wire Line
	4250 750  4400 750 
Wire Wire Line
	5100 1150 5100 1400
Wire Wire Line
	5100 1400 4050 1400
Wire Wire Line
	4050 1400 4050 1050
Wire Wire Line
	4050 1050 4100 1050
Wire Wire Line
	5800 700  5800 1050
Wire Wire Line
	5700 1050 5900 1050
Wire Wire Line
	5700 1150 5750 1150
Wire Wire Line
	5750 1150 5750 1400
Wire Wire Line
	5750 1400 5700 1400
Wire Wire Line
	6800 900  6950 900 
Wire Wire Line
	6800 1100 6950 1100
Wire Wire Line
	8400 900  8550 900 
Wire Wire Line
	8400 1100 8550 1100
Wire Wire Line
	10000 900  10150 900 
Wire Wire Line
	10000 1100 10150 1100
Wire Wire Line
	6800 2800 6950 2800
Wire Wire Line
	6800 3000 6950 3000
Wire Wire Line
	8400 2800 8550 2800
Wire Wire Line
	8400 3000 8550 3000
Wire Wire Line
	10000 2800 10150 2800
Wire Wire Line
	10000 3000 10150 3000
Wire Wire Line
	6800 4700 6950 4700
Wire Wire Line
	6800 4900 6950 4900
Wire Wire Line
	8400 4700 8550 4700
Wire Wire Line
	8400 4900 8550 4900
Wire Wire Line
	3200 4400 1600 4400
Wire Wire Line
	1600 4400 1600 4250
Wire Wire Line
	1600 4250 1350 4250
Wire Wire Line
	3200 4500 1450 4500
Wire Wire Line
	1450 4500 1450 4400
Wire Wire Line
	1450 4400 1350 4400
Wire Wire Line
	5800 700  5850 700 
Wire Wire Line
	6150 700  6200 700 
Connection ~ 5800 1050
Wire Wire Line
	6800 5700 6950 5700
Wire Wire Line
	8400 5700 8550 5700
Wire Wire Line
	6800 3800 6950 3800
Wire Wire Line
	8400 3800 8550 3800
Wire Wire Line
	10000 3800 10150 3800
Wire Wire Line
	6800 1900 6950 1900
Wire Wire Line
	8400 1900 8550 1900
Wire Wire Line
	10000 1900 10150 1900
Wire Wire Line
	6800 5100 6950 5100
Wire Wire Line
	6800 5300 6950 5300
Wire Wire Line
	8400 5300 8550 5300
Wire Wire Line
	8550 5100 8400 5100
Wire Wire Line
	6800 3400 6950 3400
Wire Wire Line
	6800 3200 6950 3200
Wire Wire Line
	8400 3200 8550 3200
Wire Wire Line
	8400 3400 8550 3400
Wire Wire Line
	10000 3400 10150 3400
Wire Wire Line
	10000 3200 10150 3200
Wire Wire Line
	10000 1300 10150 1300
Wire Wire Line
	10000 1500 10150 1500
Wire Wire Line
	8400 1300 8550 1300
Wire Wire Line
	8400 1500 8550 1500
Wire Wire Line
	6800 1500 6950 1500
Wire Wire Line
	6800 1300 6950 1300
Wire Bus Line
	5700 4650 5700 6450
Wire Bus Line
	5700 6450 9500 6450
Wire Bus Line
	6300 1800 6300 6450
Wire Wire Line
	5300 4650 5600 4650
Wire Wire Line
	5300 4750 5600 4750
Wire Wire Line
	5300 4850 5600 4850
Wire Wire Line
	5300 4950 5600 4950
Wire Wire Line
	5300 5050 5600 5050
Wire Wire Line
	5300 5150 5600 5150
Wire Wire Line
	5300 5250 5600 5250
Wire Wire Line
	6950 1700 6400 1700
Wire Wire Line
	6950 3600 6400 3600
Wire Wire Line
	6950 5500 6400 5500
Wire Bus Line
	7900 1800 7900 6450
Wire Bus Line
	9500 6450 9500 1800
Wire Wire Line
	8550 1700 8000 1700
Wire Wire Line
	8550 3600 8000 3600
Wire Wire Line
	10150 1700 9600 1700
Wire Wire Line
	10150 3600 9600 3600
Wire Wire Line
	8550 5500 8000 5500
Wire Wire Line
	6950 5900 6800 5900
Wire Wire Line
	6950 6100 6800 6100
Wire Wire Line
	8550 6100 8400 6100
Wire Wire Line
	8550 5900 8400 5900
Wire Wire Line
	8550 4000 8400 4000
Wire Wire Line
	8550 4200 8400 4200
Wire Wire Line
	6950 4000 6800 4000
Wire Wire Line
	6950 4200 6800 4200
Wire Wire Line
	10150 4200 10000 4200
Wire Wire Line
	10150 4000 10000 4000
Wire Wire Line
	10150 2100 10000 2100
Wire Wire Line
	10150 2300 10000 2300
Wire Wire Line
	8550 2100 8400 2100
Wire Wire Line
	8550 2300 8400 2300
Wire Wire Line
	6950 2100 6800 2100
Wire Wire Line
	6950 2300 6800 2300
Wire Wire Line
	1450 750  1650 750 
Wire Wire Line
	1450 850  1650 850 
Wire Wire Line
	4400 1350 4400 1550
Wire Wire Line
	4400 1550 3100 1550
Wire Wire Line
	3100 1400 3100 1650
Wire Wire Line
	3100 1400 3000 1400
Wire Wire Line
	3100 1650 3000 1650
Connection ~ 3100 1550
Wire Wire Line
	3000 1200 3650 1200
Wire Wire Line
	3000 950  3200 950 
Wire Wire Line
	3500 950  3850 950 
Wire Wire Line
	3850 950  3850 750 
Wire Wire Line
	3650 1200 3650 950 
Connection ~ 3650 950 
Wire Wire Line
	5100 950  5050 950 
Wire Wire Line
	4750 950  4700 950 
Wire Wire Line
	4700 950  4700 1050
Wire Wire Line
	2550 5100 2550 5600
Wire Wire Line
	5000 6700 5100 6700
Wire Wire Line
	5050 6200 5050 6700
Wire Wire Line
	5050 6600 5000 6600
Connection ~ 5050 6700
Wire Wire Line
	5050 6500 5000 6500
Connection ~ 5050 6600
Wire Wire Line
	5050 6400 5000 6400
Connection ~ 5050 6500
Wire Wire Line
	5050 6300 5000 6300
Connection ~ 5050 6400
Wire Wire Line
	5050 6200 5000 6200
Connection ~ 5050 6300
Wire Wire Line
	3400 6300 3400 5300
Wire Wire Line
	3400 5300 3200 5300
Wire Wire Line
	3200 5300 3200 5000
Wire Wire Line
	5300 4550 5600 4550
Wire Wire Line
	900  2250 1000 2250
Connection ~ 900  2250
Wire Wire Line
	1000 2150 900  2150
Wire Wire Line
	1000 2450 900  2450
Wire Wire Line
	1000 2550 900  2550
Connection ~ 900  2550
Wire Wire Line
	1000 2750 900  2750
Wire Wire Line
	1000 2850 900  2850
Connection ~ 900  2850
Wire Wire Line
	1000 3050 900  3050
Wire Wire Line
	1000 3150 900  3150
Connection ~ 900  3150
Wire Wire Line
	900  3350 1000 3350
Wire Wire Line
	1500 1950 1600 1950
Wire Wire Line
	1550 2250 1500 2250
Wire Wire Line
	1550 3150 1500 3150
Wire Wire Line
	1750 2800 1750 2200
Wire Wire Line
	1750 2200 1550 2200
Wire Wire Line
	1800 2700 1800 2050
Wire Wire Line
	1800 2050 1600 2050
Wire Wire Line
	1550 2150 1550 2250
Wire Wire Line
	1650 2900 1650 2450
Wire Wire Line
	1650 2450 1500 2450
Wire Wire Line
	1600 3000 1600 2750
Wire Wire Line
	1600 2750 1500 2750
Wire Wire Line
	1550 3050 1550 3150
Wire Wire Line
	1750 3200 1750 3450
Wire Wire Line
	1750 3350 1500 3350
Wire Wire Line
	900  1850 900  3450
Wire Wire Line
	1600 2050 1600 1850
$Comp
L R R30
U 1 1 5B40330D
P 3750 2150
F 0 "R30" V 3830 2150 50  0000 C CNN
F 1 "10K" V 3750 2150 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3680 2150 50  0001 C CNN
F 3 "" H 3750 2150 50  0001 C CNN
	1    3750 2150
	-1   0    0    1   
$EndComp
Text GLabel 3600 1950 0    60   Input ~ 0
5V
Wire Wire Line
	3600 1950 3750 1950
Wire Wire Line
	3750 1950 3750 2000
Wire Wire Line
	3750 2300 3750 2350
Connection ~ 3750 2350
Wire Wire Line
	1000 1950 900  1950
Connection ~ 900  1950
Wire Wire Line
	900  3450 1000 3450
Connection ~ 900  3350
Wire Wire Line
	1500 3050 1550 3050
Connection ~ 1550 3100
Wire Wire Line
	1500 2150 1550 2150
Connection ~ 1550 2200
Wire Wire Line
	1600 1850 1500 1850
Connection ~ 1600 1950
$Comp
L SW_Push_4PIN SW3
U 1 1 5B1EF7C8
P 1250 2450
F 0 "SW3" H 1300 2550 50  0000 L CNN
F 1 "IP3" H 1250 2390 50  0000 C CNN
F 2 "CarnivalBen:SW_PUSH_6mm_4pin" H 1250 2650 50  0001 C CNN
F 3 "" H 1250 2650 50  0001 C CNN
	1    1250 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2550 1650 2550
Connection ~ 1650 2550
Wire Wire Line
	2350 2250 2350 2900
Connection ~ 2350 2900
Wire Wire Line
	1500 2850 1600 2850
Connection ~ 1600 2850
Wire Wire Line
	2550 2250 2550 3000
Connection ~ 2550 3000
Wire Wire Line
	1750 3450 1500 3450
Connection ~ 1750 3350
Wire Wire Line
	2950 2250 2950 3200
Connection ~ 2950 3200
$Comp
L Conn_02x06_Counter_Clockwise J3
U 1 1 5B643410
P 2050 6050
F 0 "J3" H 2100 6350 50  0000 C CNN
F 1 "STANDARD ENC28J60" H 2100 5650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x06_Pitch2.54mm" H 2050 6050 50  0001 C CNN
F 3 "" H 2050 6050 50  0001 C CNN
	1    2050 6050
	1    0    0    -1  
$EndComp
Text GLabel 2450 5950 2    60   Input ~ 0
5V
Text GLabel 1750 5950 0    60   Input ~ 0
GND
Text GLabel 2450 5850 2    60   Input ~ 0
GND
NoConn ~ 1850 5850
NoConn ~ 2350 6250
Wire Wire Line
	2550 5600 1400 5600
Wire Wire Line
	1400 5600 1400 6150
Wire Wire Line
	1400 6150 1850 6150
Wire Wire Line
	1850 5950 1750 5950
Wire Wire Line
	2350 5950 2450 5950
Wire Wire Line
	2450 5850 2350 5850
Wire Wire Line
	2500 5500 1350 5500
Wire Wire Line
	1350 5500 1350 6350
Wire Wire Line
	1350 6350 1850 6350
Wire Wire Line
	2400 5400 1300 5400
Wire Wire Line
	1300 5400 1300 6250
Wire Wire Line
	1300 6250 1850 6250
Wire Wire Line
	2350 4600 2350 5650
Wire Wire Line
	2350 5650 1250 5650
Wire Wire Line
	1250 5650 1250 6050
Wire Wire Line
	1250 6050 1850 6050
Wire Wire Line
	3050 6450 3050 6350
Wire Wire Line
	3050 6350 2350 6350
Wire Wire Line
	3450 6150 2350 6150
NoConn ~ 2350 6050
$EndSCHEMATC

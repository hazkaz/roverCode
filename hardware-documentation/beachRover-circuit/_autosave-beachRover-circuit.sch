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
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5E23F868
P 5400 3500
F 0 "A1" H 5400 2411 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 5400 2320 50  0000 C CNN
F 2 "Module:Arduino_Nano_WithMountingHoles" H 5400 3500 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 5400 3500 50  0001 C CNN
	1    5400 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 4500 5500 4500
$Comp
L Sensor_Magnetic:MMC5883MA U5
U 1 1 5E242FEA
P 7200 3450
F 0 "U5" H 7644 3496 50  0000 L CNN
F 1 "MMC5883MA" H 7644 3405 50  0000 L CNN
F 2 "Package_LGA:LGA-16_3x3mm_P0.5mm" H 7200 2750 50  0001 C CNN
F 3 "http://www.memsic.com/userfiles/files/DataSheets/Magnetic-Sensors-Datasheets/MMC5883MA-RevC.pdf" H 7100 3450 50  0001 C CNN
	1    7200 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3350 6450 3350
Wire Wire Line
	6450 3350 6450 4000
Wire Wire Line
	6450 4000 5900 4000
Wire Wire Line
	6800 3450 6650 3450
Wire Wire Line
	6650 3450 6650 3900
Wire Wire Line
	6650 3900 5900 3900
Wire Wire Line
	7200 3750 7200 4500
Wire Wire Line
	7200 4500 6050 4500
Connection ~ 5500 4500
Wire Wire Line
	7200 3150 7200 2500
Wire Wire Line
	7200 2500 5600 2500
$Comp
L HC-SR04:HC-SR04 U4
U 1 1 5E247EDE
P 3850 3450
F 0 "U4" H 3943 2983 50  0000 C CNN
F 1 "HC-SR04" H 3943 3074 50  0000 C CNN
F 2 "HC-SR04:XCVR_HC-SR04" H 3850 3450 50  0001 L BNN
F 3 "Osepp" H 3850 3450 50  0001 L BNN
	1    3850 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	4050 3250 4600 3250
Wire Wire Line
	4600 3250 4600 4500
Wire Wire Line
	4600 4500 5400 4500
Connection ~ 5400 4500
Wire Wire Line
	4050 3550 4350 3550
Wire Wire Line
	4350 3550 4350 2150
Wire Wire Line
	4350 2150 5600 2150
Wire Wire Line
	5600 2150 5600 2500
Connection ~ 5600 2500
Wire Wire Line
	4050 3450 4700 3450
Wire Wire Line
	4700 3450 4700 3700
Wire Wire Line
	4700 3700 4900 3700
Wire Wire Line
	4050 3350 4800 3350
Wire Wire Line
	4800 3350 4800 3600
Wire Wire Line
	4800 3600 4900 3600
Wire Wire Line
	5600 1900 5600 2050
Connection ~ 5600 2150
Wire Wire Line
	2500 4500 2550 4500
Connection ~ 4600 4500
Wire Wire Line
	3350 3350 3350 2050
Wire Wire Line
	3350 2050 5600 2050
Wire Wire Line
	2500 1900 2500 4500
Connection ~ 5600 2050
Wire Wire Line
	5600 2050 5600 2150
Connection ~ 2550 4500
Wire Wire Line
	2550 4500 4600 4500
Wire Wire Line
	4700 2500 4700 3100
Wire Wire Line
	4700 3100 4900 3100
Wire Wire Line
	3050 3950 4150 3950
Wire Wire Line
	4150 3950 4150 3200
Wire Wire Line
	4150 3200 4900 3200
$Comp
L Driver_Motor:L293D U3
U 1 1 5E25C3F0
P 3600 5900
F 0 "U3" H 3600 7081 50  0000 C CNN
F 1 "L293D" H 3600 6990 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 3850 5150 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/l293.pdf" H 3300 6600 50  0001 C CNN
	1    3600 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 6700 3700 6700
Connection ~ 3700 6700
Wire Wire Line
	3700 6700 3800 6700
Wire Wire Line
	3500 4900 3700 4900
Wire Wire Line
	3100 6300 2750 6300
Wire Wire Line
	2750 6300 2750 5700
Wire Wire Line
	2750 5700 3100 5700
Wire Wire Line
	2750 5700 2750 4900
Wire Wire Line
	2750 4900 3500 4900
Connection ~ 2750 5700
Connection ~ 3500 4900
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5E26921D
P 5000 5400
F 0 "J1" H 4972 5282 50  0000 R CNN
F 1 "Conn_01x02_Male" H 4972 5373 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5000 5400 50  0001 C CNN
F 3 "~" H 5000 5400 50  0001 C CNN
	1    5000 5400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5E26A691
P 5000 5900
F 0 "J2" H 4972 5782 50  0000 R CNN
F 1 "Conn_01x02_Male" H 4972 5873 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5000 5900 50  0001 C CNN
F 3 "~" H 5000 5900 50  0001 C CNN
	1    5000 5900
	-1   0    0    1   
$EndComp
Wire Wire Line
	4100 5300 4800 5300
Wire Wire Line
	4100 5500 4800 5500
Wire Wire Line
	4800 5500 4800 5400
Wire Wire Line
	4800 5800 4100 5800
Wire Wire Line
	4100 5800 4100 5900
Wire Wire Line
	4800 5900 4400 5900
Wire Wire Line
	4400 5900 4400 6100
Wire Wire Line
	4400 6100 4100 6100
Wire Wire Line
	3100 4150 4700 4150
Wire Wire Line
	4700 4150 4700 4000
Wire Wire Line
	4700 4000 4900 4000
Wire Wire Line
	4350 3900 4350 4100
Wire Wire Line
	4350 4100 2900 4100
Wire Wire Line
	2900 4100 2900 5500
Wire Wire Line
	2900 5500 3100 5500
Wire Wire Line
	4900 3900 4350 3900
Wire Wire Line
	3100 5900 1950 5900
Wire Wire Line
	1950 5900 1950 3950
Wire Wire Line
	1950 3950 2900 3950
Wire Wire Line
	2900 3950 2900 4050
Wire Wire Line
	2900 4050 4250 4050
Wire Wire Line
	4250 4050 4250 3800
Wire Wire Line
	4250 3800 4900 3800
Wire Wire Line
	3100 5300 3100 4150
Wire Wire Line
	3100 6100 2200 6100
Wire Wire Line
	2200 3500 4900 3500
Wire Wire Line
	2200 3500 2200 6100
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5E2A2C01
P 2850 1950
F 0 "J3" H 2768 1625 50  0000 C CNN
F 1 "Conn_01x03" H 2768 1716 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2850 1950 50  0001 C CNN
F 3 "~" H 2850 1950 50  0001 C CNN
	1    2850 1950
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J4
U 1 1 5E2A34C8
P 2850 2950
F 0 "J4" H 2768 2625 50  0000 C CNN
F 1 "Conn_01x03" H 2768 2716 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2850 2950 50  0001 C CNN
F 3 "~" H 2850 2950 50  0001 C CNN
	1    2850 2950
	-1   0    0    1   
$EndComp
Wire Wire Line
	3050 1900 3050 1850
Wire Wire Line
	3050 1900 5600 1900
Wire Wire Line
	2500 1900 2600 1900
Wire Wire Line
	2600 1900 2600 1950
Wire Wire Line
	2600 1950 3050 1950
Wire Wire Line
	3050 2050 3050 2500
Wire Wire Line
	3050 2500 4700 2500
Wire Wire Line
	3350 3350 3250 3350
Wire Wire Line
	3250 3350 3250 2850
Wire Wire Line
	3250 2850 3050 2850
Wire Wire Line
	2550 2950 3050 2950
Wire Wire Line
	2550 2950 2550 4500
Wire Wire Line
	3050 3050 3050 3950
NoConn ~ 5900 2900
NoConn ~ 5900 3000
NoConn ~ 5900 3300
NoConn ~ 5900 3500
NoConn ~ 5900 3600
NoConn ~ 5900 3700
NoConn ~ 5900 3800
NoConn ~ 5900 4100
NoConn ~ 5900 4200
NoConn ~ 4900 4200
NoConn ~ 4900 4100
NoConn ~ 4900 3400
NoConn ~ 4900 3300
NoConn ~ 4900 3000
NoConn ~ 4900 2900
NoConn ~ 6800 3550
NoConn ~ 7300 3150
$Comp
L Regulator_Switching:LM2575-5.0BT U1
U 1 1 5E2742F8
P 6850 5650
F 0 "U1" H 6850 6017 50  0000 C CNN
F 1 "LM2575-5.0BT" H 6850 5926 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-5_Vertical" H 6850 5400 50  0001 L CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/lm2575.pdf" H 6850 5650 50  0001 C CNN
	1    6850 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 5950 6050 5950
Wire Wire Line
	6050 5950 6050 4500
Connection ~ 6050 4500
Wire Wire Line
	6050 4500 5500 4500
Wire Wire Line
	6050 5950 6050 6700
Wire Wire Line
	6050 6700 3800 6700
Connection ~ 6050 5950
Connection ~ 3800 6700
$Comp
L Switch:SW_DIP_x03 SW1
U 1 1 5E28B308
P 6700 5050
F 0 "SW1" H 6700 5517 50  0000 C CNN
F 1 "SW_DIP_x03" H 6700 5426 50  0000 C CNN
F 2 "Button_Switch_THT:SW_E-Switch_EG1271_DPDT" H 6700 5050 50  0001 C CNN
F 3 "~" H 6700 5050 50  0001 C CNN
	1    6700 5050
	1    0    0    -1  
$EndComp
NoConn ~ 8100 5300
Wire Wire Line
	6400 4850 6400 4600
Wire Wire Line
	6400 4600 8400 4600
Wire Wire Line
	8400 4600 8400 4900
Wire Wire Line
	8400 5100 8400 5350
Wire Wire Line
	8400 5350 6350 5350
Wire Wire Line
	6350 5350 6350 5550
Wire Wire Line
	6800 4850 7000 4850
Wire Wire Line
	7200 4850 7200 4500
Connection ~ 7000 4850
Wire Wire Line
	7000 4850 7200 4850
Connection ~ 7200 4500
NoConn ~ 6350 5750
Wire Wire Line
	7350 2350 5300 2350
Wire Wire Line
	5300 2350 5300 2500
NoConn ~ 5500 2500
NoConn ~ 6400 4950
NoConn ~ 6400 5050
NoConn ~ 7000 5050
NoConn ~ 7000 4950
NoConn ~ 7350 5550
Wire Wire Line
	7350 2350 7350 5750
Wire Wire Line
	3700 4900 5850 4900
Wire Wire Line
	5850 4900 5850 5550
Wire Wire Line
	5850 5550 6350 5550
Connection ~ 3700 4900
Connection ~ 6350 5550
NoConn ~ 7600 3450
Wire Wire Line
	3500 6700 3400 6700
Connection ~ 3500 6700
$Comp
L Connector:Barrel_Jack_Switch J5
U 1 1 5E2EA4E9
P 8100 5000
F 0 "J5" H 8157 5317 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 8157 5226 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 8150 4960 50  0001 C CNN
F 3 "~" H 8150 4960 50  0001 C CNN
	1    8100 5000
	1    0    0    -1  
$EndComp
NoConn ~ 8400 5000
$EndSCHEMATC

# Smart Home Automation using ESP32 and Blynk

## Project Overview

This project implements a simple smart home automation system using an ESP32, a DHT22 temperature and humidity sensor, and a mobile dashboard created with Blynk. The system supports both automatic control based on temperature and manual control from a smartphone.

The primary goal is to demonstrate how embedded hardware can be connected to cloud-based mobile control for home automation applications.

## Objective

The system is designed to:

1. Monitor room temperature and humidity in real time
2. Automatically switch a light or fan ON when the temperature exceeds a threshold
3. Allow the user to manually turn the light ON or OFF from a mobile phone dashboard
4. Display live sensor values in the mobile application

## Components Used

| Component                 |    Quantity |
| ------------------------- | ----------: |
| ESP32                     |           1 |
| DHT22 Sensor              |           1 |
| LED                       |           1 |
| 220Ω Resistor             |           1 |
| Jumper Wires              | As required |
| Smartphone with Blynk App |           1 |
| Wi-Fi Connection          |           1 |

## Hardware Connections

### DHT22

* VCC -> 3.3V
* DATA -> GPIO 4
* GND -> GND

### LED

* GPIO 5 -> 220Ω resistor -> LED Anode
* LED Cathode -> GND

## Software Requirements

* Arduino IDE
* ESP32 board package
* Blynk library
* DHT sensor library
* Blynk IoT mobile application

## Mobile Dashboard Setup

Create a Blynk template and add the following datastreams:

| Datastream  | Virtual Pin | Type    |
| ----------- | ----------- | ------- |
| LED Control | V0          | Integer |
| Temperature | V1          | Double  |
| Humidity    | V2          | Double  |

Add the following widgets in the Blynk mobile dashboard:

* Switch widget mapped to V0
* Gauge widget mapped to V1
* Gauge widget mapped to V2

## Working Principle

### Automatic Temperature Control

The ESP32 continuously reads temperature and humidity from the DHT22 sensor.

* If temperature > 30°C, the LED turns ON automatically
* If temperature <= 30°C, the LED remains in its current manually selected state unless changed by the user

### Mobile Control

The Blynk mobile dashboard includes a switch widget.

* Switch ON -> LED ON
* Switch OFF -> LED OFF

This allows remote control of the appliance from anywhere within network/cloud connectivity.

## How to Run

1. Connect the hardware as per the circuit diagram
2. Open Arduino IDE
3. Install required libraries
4. Enter your Wi-Fi SSID and password in the code
5. Enter Blynk Template ID, Template Name, and Auth Token
6. Upload the code to ESP32
7. Open the Blynk app
8. Use the switch to control the LED
9. Monitor live temperature and humidity values

## Demo Scenarios

### Scenario 1: Manual Mobile Control

* Open Blynk app
* Turn the switch ON
* LED turns ON
* Turn the switch OFF
* LED turns OFF

### Scenario 2: Automatic Temperature Trigger

* Increase surrounding temperature above 30°C
* LED turns ON automatically

## Future Enhancements

Possible improvements include:

* Relay-based AC bulb or fan control
* Voice assistant integration

## Learning Outcome

This project helped in understanding:

* ESP32 GPIO interfacing
* Sensor integration using DHT22
* Wi-Fi based IoT communication
* Mobile dashboard control using Blynk
* Real-time data monitoring
* Basic smart home automation logic

## Repository Structure

```text
smart-home-automation/
│── smart_home_automation.ino
│── README.md

```

## Student Details

Name: B AVINAH
Year: First Year
Domain: IoT / Embedded Systems / Smart Home Automation


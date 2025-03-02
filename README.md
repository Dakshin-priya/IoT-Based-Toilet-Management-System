# IoT-Based Toilet Management System

## Description

The **Real-Time IoT-Based Toilet Health Monitoring System** is an innovative solution to monitor the humidity and odor levels within a toilet cubicle using an IoT-based system powered by the **ESP32**. The system provides real-time data, accessible remotely via the cloud, to ensure hygiene levels are maintained. The system features an alert mechanism with two levels:

- **First Level Alert**: Activated when sensor readings exceed set thresholds but only for 30 minutes and after three successive occurrences.
- **Second Level Alert**: Triggered when critical moisture or odor values are detected, signaling the need for immediate action.

The system displays real-time data (humidity, odor level, and time) on a **ThinkSpeak** dashboard. Maintenance personnel receive hygiene alerts to prompt cleaning actions. The system also includes a disinfectant spray mechanism, using various sensors like a float sensor, ultrasonic sensor, and occupancy sensor, ensuring that the spray is only activated when the restroom is unoccupied. Furthermore, an integrated **GPS module** ensures precise location tracking.

## Features

- **Real-Time Monitoring**: Tracks moisture and odor levels in the toilet cubicle.
- **Two-Level Alert System**: Alerts for hygiene issues based on sensor thresholds.
- **Cloud Integration**: View real-time data through **ThinkSpeak**.
- **Disinfectant Mechanism**: Controls disinfectant spray based on sensor readings and occupancy.
- **Location Tracking**: GPS module for accurate location monitoring.
- **Wi-Fi Connectivity**: Easy access to data remotely.

## Depicts various modules of Real-Time Toilet Monitoring and Automatic Disinfectant Spraying System

![Fig1](assets/1.png)  
##Depicts real-Time Sensing and Connectivity Module*

![Fig2](assets/2.png)  
##Depicts Central Monitoring and Alert Dashboard*

![Fig3](assets/3.png)  
##Depicts Automatic Spray System*

![Fig4](assets/4.png)  
##Depicts Real-Time Toilet Monitoring and Automatic Disinfectant Spraying System*

![Fig5](assets/5.png)  
##Depicts Real-Time Toilet Monitoring and Automatic Disinfectant Spraying System*


## Hardware Components

- **DHT22** (Moisture Sensor)
  - Pin 1: Power Supply (5V)
  - Pin 2: Data Pin
  - Pin 3: No Connection
  - Pin 4: Ground

- **Odor Sensor (TGS2062)**
  - Pin 1: Ground
  - Pin 2: Analog Pin (ESP32 Pin 33)
  - Pin 3: VCC
  - Pin 4: Digital Pin (ESP32 Pin 2)

- **Other Components**
  - ESP32 board
  - Ultrasonic Sensor (for mist distribution)
  - Float Sensor (for disinfectant detection)
  - Occupancy Sensor
  - GPS Module

## Software Libraries

- **Adafruit Unified Sensor Library**: To interface with the DHT22 sensor.
- **My Sensor Library**: For Wi-Fi connection functionality.
- **Thingspeak Library**: To display output on the **ThinkSpeak** platform.

## Setup Instructions

### Prerequisites

- **Hardware**: ESP32, DHT22, TGS2062, ultrasonic sensor, float sensor, occupancy sensor, GPS module.
- **Software**: Arduino IDE or similar platform for ESP32 development.

### Steps

1. **Install Required Libraries**:
    - Adafruit Unified Sensor Library
    - My Sensor Library for Wi-Fi
    - Thingspeak Library

2. **Hardware Wiring**:
    - Connect the **DHT22** sensor to the ESP32 (5V, Ground, Data Pin).
    - Connect the **TGS2062** odor sensor to the ESP32 (Analog Pin 33, Digital Pin 2, VCC, Ground).
    - Connect the **Ultrasonic Sensor**, **Float Sensor**, **Occupancy Sensor**, and **GPS Module** to the ESP32.

3. **Upload the Code**:
    - Open the **Arduino IDE**.
    - Select **ESP32** as the board.
    - Set up the **Wi-Fi** credentials in the code.
    - Upload the code to the **ESP32** board.

4. **Viewing Data**:
    - Once the system is set up and running, the data will be transmitted to **ThinkSpeak** where you can view real-time values for **moisture** and **odor**.
    - The serial monitor will display the connected **Wi-Fi**, current **moisture level**, **odor value**, and whether cleaning is required.

### Configuration

- **Wi-Fi Delay**: Set to **15 seconds** for a delay between data readings.
- **Threshold Values**: Adjustable to control when alerts are triggered.

## Usage

Once the system is set up, it will monitor the humidity and odor levels in the toilet cubicle and send data to **ThinkSpeak**. You can access the dashboard remotely to check the real-time values. Maintenance personnel will receive alerts via the system whenever cleaning is required 🚨🧽.

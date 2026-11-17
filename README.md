# 🌡️ ThermoSet Connect
### An IoT-Based Local and Remote Temperature Monitoring, Set-Point Control and Alert System

## 📌 Project Overview

ThermoSet Connect is an IoT-based temperature monitoring and control system developed using the LPC2148 (ARM7) microcontroller.

The system continuously monitors environmental temperature using an LM35 temperature sensor and transmits temperature readings to the ThingSpeak cloud platform through an ESP-01 Wi-Fi module.

Users can configure the temperature set point locally using a 4×4 matrix keypad or remotely through the cloud platform. The configured set-point value is stored in external EEPROM to retain the data even after a power failure.

Whenever the measured temperature exceeds the configured set point, the system activates a local buzzer alert and sends an alert to the cloud.

## 🎯 Project Objectives

- Develop an IoT-based temperature monitoring system.
- Implement local and remote temperature set-point configuration.
- Interface sensors and peripherals with the LPC2148 microcontroller.
- Store configuration data using external EEPROM.
- Implement cloud-based temperature monitoring using ThingSpeak.
- Generate local and remote alerts during overheating conditions.

## ✨ Key Features

- Real-time temperature monitoring using LM35.
- Local set-point configuration through a matrix keypad.
- Remote set-point configuration through ThingSpeak.
- EEPROM-based set-point storage.
- Automatic temperature threshold detection.
- Local buzzer alert when temperature exceeds the set point.
- Cloud-based temperature monitoring.
- LCD interface for displaying temperature and system information.
- External interrupt-based local set-point modification.

## 🛠️ Hardware Requirements

| Component | Purpose |
|---|---|
| LPC2148 (ARM7) | Main microcontroller |
| LM35 | Temperature sensor |
| AT24C256 | External EEPROM |
| ESP-01 (ESP8266) | Wi-Fi communication |
| 4×4 Matrix Keypad | User input |
| LCD | Display interface |
| Buzzer | Alert indication |
| Switch | External interrupt input |
| USB-to-UART Converter | Serial communication |

## 💻 Software Requirements

- Embedded C
- Keil µVision IDE
- Flash Magic
- ThingSpeak IoT Cloud

## ⚙️ Working Principle

1. The LM35 temperature sensor continuously measures the surrounding temperature.
2. The LPC2148 reads the analog temperature signal through its internal ADC.
3. The measured temperature is displayed on the LCD.
4. Temperature data is transmitted periodically to ThingSpeak through the ESP-01 Wi-Fi module.
5. The measured temperature is compared with the configured set-point value.
6. If the temperature exceeds the set point:
   - The buzzer generates a local alert.
   - The temperature alert is transmitted to ThingSpeak.
7. Users can modify the set point locally using the keypad.
8. Users can also update the set point remotely through ThingSpeak.
9. The latest set-point value is stored in external EEPROM and retained even after a power failure.

## 🧠 Embedded Concepts Implemented

- GPIO Interfacing
- ADC Interfacing
- UART Communication
- I2C Communication
- External Interrupts
- LCD Interfacing
- Matrix Keypad Interfacing
- EEPROM Read and Write Operations
- Wi-Fi Module Interfacing
- IoT Cloud Integration

## 📂 Project Structure

```text
ThermoSet-Connect/
│
├── main.c
│
├── LCD/
│   ├── lcd.c
│   └── lcd.h
│
├── Keypad/
│   ├── keypad.c
│   └── keypad.h
│
├── ADC/
│   ├── adc.c
│   └── adc.h
│
├── UART/
│   ├── uart.c
│   └── uart.h
│
├── EEPROM/
│   ├── eeprom.c
│   └── eeprom.h
│
├── ESP01/
│   ├── esp01.c
│   └── esp01.h
│
├── Images/
│
└── README.md
```
<img width="1543" height="726" alt="Screenshot 2026-11-17 123308" src="https://github.com/user-attachments/assets/98db7f3f-570b-4a9d-8e41-ae8462755dc3" />

<img width="1011" height="654" alt="Screenshot 2026-11-17 144640" src="https://github.com/user-attachments/assets/651d95b4-10a4-420d-9a04-f1f0430390ed" />


*Note: This is a suggested folder structure. Modify it according to your actual source-code organization.*

## 🌍 Applications

- Laboratories
- Server rooms
- Cold-storage facilities
- Industrial equipment
- Temperature-sensitive environments

## 🚀 Future Enhancements

- Mobile application integration.
- Historical temperature data logging.
- Additional sensor integration.
- Improved cloud notifications.
- Advanced remote monitoring features.

## 👨‍💻 Author

**G. Rajashekar Babu**

Embedded Systems Trainee at **Vector India**

Electronics and Communication Engineering (ECE)

**Technical Interests:**
- Embedded C
- C and C++
- ARM Microcontrollers
- Peripheral Driver Development
- IoT Systems

**Training Institute:** [Vector India](https://vectorindia.org/)

---

⭐ If you find this project interesting, feel free to explore the repository!

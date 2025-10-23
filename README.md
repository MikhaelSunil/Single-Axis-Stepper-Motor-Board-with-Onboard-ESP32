# 🧭 SINGLE-AXIS STEPPER MOTOR CONTROLLER BOARD WITH ESP32

This project is a **compact single-axis stepper motor controller board** centered on an **ESP32 microcontroller** and an integrated **DRV8825 stepper motor driver**.  
The board accepts a 12 V motor supply, provides regulated 5 V and 3.3 V outputs, supports mechanical limit switches for homing and end-stop safety, and enables both **Wi-Fi** and **Bluetooth** remote control.

---
**<img width="893" height="632" alt="image" src="https://github.com/user-attachments/assets/f598949b-c431-4cb3-a3a4-ae447d3a7971" />
**
## 🎯 OBJECTIVE
To develop a **modular, intelligent, single-axis motion control board** that integrates an **ESP32** microcontroller and **DRV8825** stepper driver with built-in **limit switch** support — suitable for automation and robotics applications.

---

## ⚙️ DESIGN OVERVIEW
The board integrates three main subsystems:

1. **Microcontroller Unit (ESP32-DevkitC)**  
   Handles motor control and limit switch detection.
2. **Power Regulation System**  
   Uses dual **LM2596** buck converters for 12 V → 5 V and 3.3 V rails.
3. **Motor Driver Subsystem (DRV8825)**  
   Provides microstepping control, efficient current regulation, and protection features.

---
<img width="975" height="685" alt="image" src="https://github.com/user-attachments/assets/89a09fce-5894-44cf-8e97-fe7312614a71" />

## 🧠 MICROCONTROLLER – ESP32 DEVKITC
The **ESP32** was selected over alternatives like the **STM32**, **SAMD**, and **RP2040** for its:
- Superior processing power  
- Integrated **Wi-Fi** and **Bluetooth**  
- Wide GPIO accessibility  
- Compatibility with STEP/DIR motor control interfaces  

---

## ⚡ STEPPER MOTOR DRIVER – DRV8825
**Texas Instruments DRV8825** offers key advantages:
- **Wide Voltage Range:** 8.2 V – 45 V  
- **High Current:** Up to 2.2 A per phase  
- **Microstepping:** Up to 1/32 steps for fine resolution  
- **Built-in Protections:** Over-temperature, over-current, and short-to-ground  
- **Ease of Control:** Simple STEP/DIR interface  

---

## 🔩 STEP-SIZE SELECTION FEATURE
The board provides **microstep selection jumpers**, allowing dynamic configuration from **full-step to 1/32-step** without changing the software — ideal for performance and precision tuning.

---

## 🔋 POWER SUPPLY DESIGN

### **Input**
- 12 V DC main supply (motor and logic source)

### **Regulated Outputs**
- **LM2596T (5 V Output)** – High-efficiency regulator (>80%), powers peripherals and logic.  
- **LM2596S (3.3 V Output)** – Dedicated rail for step-selection jumpers and pull-ups with LC filtering.

---

## 🏁 LIMIT SWITCH AND HOMING INTEGRATION
Includes two **mechanical limit switches** with pull-up resistors for reliable **homing** and **end-stop** detection.  
Applications include **CNC**, **linear actuators**, and **positioning systems**.

---

## 🧾 PINOUT DESCRIPTION

| Signal      | ESP32 GPIO | I/O     | Connected Component         | Description |
|--------------|-------------|---------|------------------------------|-------------|
| **DIR_PIN**  | GPIO 19     | Output  | DRV8825 DIR                 | Motor rotation direction (HIGH = Forward, LOW = Reverse) |
| **STEP_PIN** | GPIO 18     | Output  | DRV8825 STEP                | Step pulse signal for motor movement |
| **EN_PIN**   | GPIO 21     | Output  | DRV8825 ENABLE              | Active LOW enable/disable for driver output |
| **LIMIT_MIN**| GPIO 32     | Input   | Mechanical Limit Switch (Home) | Detects home position (LOW = Pressed) |
| **LIMIT_MAX**| GPIO 33     | Input   | Mechanical Limit Switch (End)  | Detects maximum travel (LOW = Pressed) |

---

## 💡 NOVELTY & KEY FEATURES
- **Unified Architecture:** ESP32 + DRV8825 + Power Regulation on a single PCB  
- **Full GPIO Access:** Enables sensor, relay, and IoT expansion  
- **Dual Power Path:** Independent LM2596 converters reduce EMI  
- **OTA Upgradability:** Firmware updates over Wi-Fi  
- **Scalable Design:** Multiple boards networked for multi-axis systems  

---

## 🚀 APPLICATIONS
- 🧰 **CNC Machines & 3D Printers** – Precision motion control with homing  
- 🤖 **Autonomous Robotics** – For actuators, camera sliders, robot joints  
- 🌐 **IoT Mechatronics Systems** – Wi-Fi/BLE remote stepper control  
- ⚗️ **Smart Automation & Lab Equipment** – Syringe pumps, optical stages  
- 🎓 **Educational / Research Prototyping** – Open, reconfigurable motion control platform  

---

## 🧩 LICENSE
This project is open-source under the **MIT License**.  
You are free to use, modify, and distribute it with attribution.

---

## 👨‍🔧 Author
**Mikhael Sunil**  
Embedded Systems & Robotics Engineer  
📧 [LinkedIn](https://www.linkedin.com/in/mikhaelsunil) • 🌐 [GitHub](https://github.com/mikhaelsunil)

---

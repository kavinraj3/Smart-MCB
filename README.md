📌 Project Overview

The Smart Distribution Box is an IoT-enabled electrical safety and energy monitoring system designed to manage household power distribution line by line.

Each electrical line is continuously monitored for:
⚠️ Short circuit
⚠️ Overload
⚠️ Voltage drop / overvoltage

If a fault occurs, the system automatically isolates the affected line and sends real-time fault information to the user’s mobile phone.

---

## 🎯 Key Features

- Line-wise fault detection
- Automatic power cut-off
-  Fault type identification
- Mobile alerts and monitoring
- Per-line power usage tracking
- Remote access via IoT

---

## 🧰 Hardware Components

- ESP32 (NodeMCU)
- ACS712 Current Sensor
- ZMPT101B Voltage Sensor
- Relay Module
- AC Load (Demo)
- Jumper wires
- Power supply

  ---

## 🖥️ Software & Platform

- Arduino IDE
- Blynk IoT Platform
- ESP8266 Board Package

  ---

## ⚙️ System Working

- Voltage and current sensors monitor each power line.
- ESP32 analyzes real-time data.
- If abnormal conditions are detected:
- Line is automatically turned OFF
- Fault type is identified
- Fault details and power usage are displayed on a mobile app.

---

## 🧾 Circuit Diagram

<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/13989097-78a3-41f9-aa00-dbaea71a1c33" />

---

## 📱 Mobile Dashboard

- Parameter	Description
- Voltage	Line-wise voltage
- Current	Load current
- Power	Energy usage
- Alerts	Fault notifications
- Image:
  <img width="1280" height="661" alt="image" src="https://github.com/user-attachments/assets/58fa492f-f8d8-4026-acdf-5c4c94b4c181" />

---

## 🚀 Applications

- Smart homes
- Electrical distribution panels
- Industrial safety systems
- Energy management systems

---

## ✅ Advantages

- Improved electrical safety
- Prevents equipment damage
- Energy monitoring
- Low-cost solution
- Scalable design

---

## 🔮 Future Enhancements

- Exact fault location detection
- ESP32 implementation
- Power factor monitoring 
- Cloud data analytics
- Voice control integration

---

## 👨‍💻 Author

Kavin Raj S
ECE | IoT | Embedded Systems
🔗 LinkedIn


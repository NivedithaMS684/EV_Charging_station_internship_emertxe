# ⚡ IoT EV Charging Station Management System

An IoT-based Multi-Bay Electric Vehicle (EV) Charging Station monitoring and load control system implemented using ESP32, MQTT protocol, and Wokwi simulation.


## 🎬 Project Demo

[🎬 Click here to watch the Demo Video](https://github.com/user-attachments/assets/5c5547e9-819f-4776-8694-38ed327cd714))

---

## 📌 Features

* **Multi-Bay Monitoring:** Real-time power, current, voltage, and temperature tracking for multiple bays (`BAY1`, `BAY2`, `BAY3`).
* **Dynamic Load Throttling:** Automatic current throttling (e.g., 50%) during overcurrent conditions to prevent overload.
* **MQTT Telemetry:** Live data transmission formatted as JSON for remote monitoring.
* **Wokwi Simulator Integration:** Complete circuit simulation with ESP32, relays, sensors, and status indicators.


## 🛠️ Hardware Components (Simulated)

* **Controller:** ESP32
* **Sensors:** DHT22 Temperature Sensor, Current Sensor
* **Actuators & Displays:** Relays, Status LEDs, Potentiometers
* **Communication:** MQTT / Wi-Fi


## 📁 Repository Structure

├── BAY1/           # Firmware & PlatformIO configuration for Bay 1
├── BAY2/           # Firmware & PlatformIO configuration for Bay 2
├── BAY3/           # Firmware & PlatformIO configuration for Bay 3
└── README.md       # Project Documentation






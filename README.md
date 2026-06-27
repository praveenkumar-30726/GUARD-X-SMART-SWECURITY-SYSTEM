# GUARD-X-SMART-SWECURITY-SYSTEM
GuardX Smart Security System is an ESP32-based IoT security solution that combines PIN authentication, RFID, ESP32-CAM surveillance, servo door locking, intrusion detection, and real-time email notifications for enhanced access control.
## 📖 Overview

GuardX Smart Security System is an IoT-based access control solution designed to provide enhanced security for homes, offices, and laboratories. The system uses an ESP32 microcontroller to authenticate users through a secure PIN-based login and controls a servo motor to lock or unlock the door.

To improve security, the system detects multiple incorrect password attempts, activates an alarm, captures surveillance using the ESP32-CAM, and sends real-time email notifications to the user.

---

## ✨ Features

- 🔐 Secure PIN-based Authentication
- 🔑 Dual-Level Security (User PIN & Master PIN)
- 🚪 Servo Motor Door Lock Control
- 📷 ESP32-CAM Live Monitoring
- 🚨 Intrusion Detection
- 🔔 Buzzer Alert System
- 📧 Instant Email Notifications
- 📺 LCD Display User Interface
- 🔒 Automatic Lockdown After Multiple Failed Attempts
- 🌐 IoT-Based Smart Security

---

## 🛠️ Hardware Components

| Component | Quantity |
|-----------|----------|
| ESP32 Development Board | 1 |
| ESP32-CAM | 1 |
| 4×4 Matrix Keypad | 1 |
| MG90S/SG90 Servo Motor | 1 |
| 16×2 I2C LCD Display | 1 |
| Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| 5V Power Supply | 1 |

---

## 💻 Software Requirements

- Arduino IDE
- ESP32 Board Package
- Embedded C / Arduino C++
- Git
- GitHub


## 🔄 System Workflow

1. User enters a PIN using the keypad.
2. ESP32 verifies the entered password.
3. If correct:
   - Door unlocks using the servo motor.
   - LCD displays "Access Granted".
4. If incorrect:
   - Error message displayed.
   - Failed attempts are counted.
5. After multiple failed attempts:
   - System enters lockdown mode.
   - Buzzer activates.
   - Email notification is sent.
   - ESP32-CAM captures surveillance.

---

## 📸 Project Images

Add your project images here.

```
Images/
│── Front_View.jpg
│── Circuit_Diagram.png
│── Wiring.jpg
│── Hardware_Setup.jpg
│── Working_Demo.jpg
```

---

## 📹 Demonstration

Add your YouTube video link here.

```
https://youtu.be/YourVideoLink
```

---

## 📚 Applications

- Smart Home Security
- Office Access Control
- Laboratory Security
- Hostel Security
- Smart Door Lock Systems
- IoT-Based Security Projects

---

## 🚀 Future Improvements

- Fingerprint Authentication
- Face Recognition
- Mobile Application Control
- Cloud Database Integration
- RFID Authentication
- Voice Assistant Support
- AI-Based Intruder Detection
- OTP Verification

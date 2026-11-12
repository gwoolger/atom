# Goouuu ESP32-S3-CAM — Project Pinout Reference

Board: **Goouuu ESP32-S3-CAM** (ESP32-S3, 16 MB Flash, 8 MB OPI PSRAM)

---

## Camera — OV5640

| Signal      | GPIO |
|-------------|------|
| XCLK        | 15   |
| SCCB SDA    | 4    |
| SCCB SCL    | 5    |
| VSYNC       | 6    |
| HREF        | 7    |
| PCLK        | 13   |
| D0 (Y2)     | 11   |
| D1 (Y3)     | 9    |
| D2 (Y4)     | 8    |
| D3 (Y5)     | 10   |
| D4 (Y6)     | 12   |
| D5 (Y7)     | 18   |
| D6 (Y8)     | 17   |
| D7 (Y9)     | 16   |

> PWDN and RESET are not connected (–1).

---

## Motors — DRV8833

| Signal         | GPIO |
|----------------|------|
| Left Motor A   | 47   |
| Left Motor B   | 21   |
| Right Motor A  | 42   |
| Right Motor B  | 41   |

PWM frequency: 500 Hz, 8-bit resolution, max duty 160/255 as they can be fed 8.4V instead of 6V.

---

## Ultrasonic Sensors — HC-SR04p (shared trigger)

| Signal           | GPIO |
|------------------|------|
| Trigger (shared) | 2    |
| Front Echo       | 1    |
| Back Echo        | 46   |

Both sensors share a single trigger pin. Reads are sequential (front then back)
with a settle between pulses to reduce interference.

---

## Sensor I²C

| Signal | GPIO |
|--------|------|
| SDA    | 38   |
| SCL    | 39   |

For VL53L1X TOF, BMI160 IMU, mabye an I2C expander.

---

## ToF Servo

| Signal      | GPIO | LEDC channel |
|-------------|------|--------------|
| PWM signal  | 45   | 6            |

---

## Board Power & USB

| Pin  | Function              |
|------|-----------------------|
| 5V   | Board supply input    |
| 3V3  | 3.3 V regulated out   |
| GND  | Ground                |
| TX0  | UART0 TX (USB serial) |
| RX0  | UART0 RX (USB serial) |

---

## GPIO Summary

| GPIO | Function             | Direction |
|------|----------------------|-----------|
| 1    | US Front Echo        | INPUT     |
| 2    | US Trigger (shared)  | OUTPUT    |
| 4    | Camera SCCB SDA      | —         |
| 5    | Camera SCCB SCL      | —         |
| 6    | Camera VSYNC         | INPUT     |
| 7    | Camera HREF          | INPUT     |
| 8    | Camera D2 (Y4)       | INPUT     |
| 9    | Camera D1 (Y3)       | INPUT     |
| 10   | Camera D3 (Y5)       | INPUT     |
| 11   | Camera D0 (Y2)       | INPUT     |
| 12   | Camera D4 (Y6)       | INPUT     |
| 13   | Camera PCLK          | INPUT     |
| 15   | Camera XCLK          | OUTPUT    |
| 16   | Camera D7 (Y9)       | INPUT     |
| 17   | Camera D6 (Y8)       | INPUT     |
| 18   | Camera D5 (Y7)       | INPUT     |
| 21   | Left Motor B         | OUTPUT    |
| 38   | SDA (I²C)            | I/O       |
| 39   | SCL (I²C)            | OUTPUT    |
| 45   | ToF Servo PWM        | OUTPUT    |
| 41   | Right Motor B        | OUTPUT    |
| 42   | Right Motor A        | OUTPUT    |
| 46   | US Back Echo         | INPUT     |
| 47   | Left Motor A         | OUTPUT    |

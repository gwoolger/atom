#include <Arduino.h>
#include "motors/motors.h"
#include "sensors/sensors.h"

void setup() {
    Serial.begin(115200);
    delay(1500);
    Serial.println("Started");
    initMotors();
    initSensors();
    
    Serial.println("initialised");
}

void testMotors() {
    for (int i=0; i <= 150; i+=10) {
        setLeftMotors(i);
        setRightMotors(i);
        Serial.print("PWM: ");
        Serial.print(i);
        Serial.println((long)rpm);
        delay(5000);
        }
    }

void testSensors() {
    int distance = checkFrontUS();
    Serial.print("Distance (cm): ");
    Serial.println(distance);
}

void loop() {
    // testMotors();
    testSensors();
    }
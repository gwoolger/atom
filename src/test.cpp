#include <Arduino.h>
#include "motors/motors.h"

void setup() {
    Serial.begin(115200);
    delay(1500);
    Serial.println("Started");
    initMotors();
    
    Serial.println("initialised");
}

void loop() {
    for (int i=0; i <= 150; i+=10) {
        setLeftMotors(i);
        setRightMotors(i);
        Serial.print("PWM: ");
        Serial.print(i);
        Serial.println((long)rpm);
        delay(5000);
        }
    }
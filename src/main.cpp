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
    if (Serial.available() > 0) {
    char command = Serial.read(); // Read keys
    switch (command) {
        case "w":
        setLeftMotors(100);
        setRightMotors(100);
    }
    }
}

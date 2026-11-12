#include <Arduino.h>
#include "sensors.h"

// Just has front Ultrasonic Sensor. Will have to update to support both front and back.
// Trig shared. Echo seperate. So delay could be good for accuracy.

const int TRIG_PIN = 2;
const int ECHO_PIN = 1;

void initSensors() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(TRIG_PIN, LOW);
}

int checkFrontUS() {
    // 10us for initial. Mabye switch to a library.
    digitalWrite(TRIG_PIN, LOW); // just in case
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000); // Measuring length 30ms timeout

    // If timed out (no object detected) return -1
    if (duration == 0) {
        return -1;
    }

    // Calculate distance in centimetres
    // Speed of sound is ~0.034 cm/us. Divide by 2 for the round trip.
    int distanceCm = duration * 0.034 / 2;
    return distanceCm;
}

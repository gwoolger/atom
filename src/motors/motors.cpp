#include <Arduino.h>
#include "motors.h"

// left 1, left channel 1
const int MAX_PWM = 160;
const int L1 = 47, L2 = 21, R1 = 42, R2 = 41;
const int L1CH = 0, L2CH = 1, R1CH = 2, R2CH = 4;
const int motorConfig[4][2] = {          //pin, channel
    {L1, L1CH},
    {L2, L2CH},
    {R1, R1CH},
    {R2, R2CH}
};

const int PWM_FREQ = 500;
const int PWM_RESOLUTION = 8;

void initMotors() {
    for (int i = 0; i < 4; i++) {
        int pin = motorConfig[i][0];
        int channel = motorConfig[i][1];
        pinMode(pin, OUTPUT);
        ledcSetup(channel, PWM_FREQ, PWM_RESOLUTION);
        ledcAttachPin(pin, channel);
    }
}


void setLeftMotors(int speed) {
    speed = constrain(speed, -MAX_PWM, MAX_PWM); // Keep within bounds

    if (speed >= 0) {
        ledcWrite(L1CH, speed); // Drive L1 with PWM
        ledcWrite(L2CH, 0);     // Keep L2 low
    } else {
        ledcWrite(L1CH, 0);     // Keep L1 low
        ledcWrite(L2CH, -speed); // Drive L2 with PWM (invert the negative speed)
    }
}

void setRightMotors(int speed) {
    speed = constrain(speed, -MAX_PWM, MAX_PWM);

    if (speed >= 0) {
        ledcWrite(R1CH, speed); // Drive R1 with PWM
        ledcWrite(R2CH, 0);     // Keep R2 low
    } else {
        ledcWrite(R1CH, 0);     // Keep R1 low
        ledcWrite(R2CH, -speed); // Drive R2 with PWM
    }
}

void brakeMotors() {
    for (int i = 0; i < 4; i++) {
        int pin = motorConfig[i][0];
        ledcWrite(pin, MAX_PWM);        // keep pins high (mind 8.4V diff)
    }
}

void stopMotors() {
    setLeftMotors(0);
    setRightMotors(0);
}

void checkMotorStationary() {
    for (int i = 0; i < 4; i++) {
        
    }
}
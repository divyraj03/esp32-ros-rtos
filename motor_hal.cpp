#include "motor_hal.h"
#include <Arduino.h>

const int motor_pins[MOTOR_COUNT] = {32, 33, 25, 26, 27, 14};

void motor_init() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        pinMode(motor_pins[i], OUTPUT);
        analogWrite(motor_pins[i], 0);
    }
}

void motor_set_speed(int motor_id, int speed) {
    if (motor_id < MOTOR_COUNT) {
        analogWrite(motor_pins[motor_id], speed);
    }
}

void motor_stop(int motor_id) {
    if (motor_id < MOTOR_COUNT) {
        analogWrite(motor_pins[motor_id], 0);
    }
}

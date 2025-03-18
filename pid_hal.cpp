#include "pid_hal.h"
#include "motor_hal.h"
#include "encoder_hal.h"

#define MOTOR_COUNT 6

double Kp[MOTOR_COUNT] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
double Ki[MOTOR_COUNT] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
double Kd[MOTOR_COUNT] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

double setpoint[MOTOR_COUNT] = {0};

void pid_init() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        setpoint[i] = 0;
    }
}

void pid_set_gains(int motor_id, float kp, float ki, float kd) {
    Kp[motor_id] = kp;
    Ki[motor_id] = ki;
    Kd[motor_id] = kd;
}

void pid_set_setpoint(int motor_id, float sp) {
    setpoint[motor_id] = sp;
}

void pid_update() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        double error = setpoint[i] - encoder_get_position(i);
        double output = Kp[i] * error;  // Simplified PID
        motor_set_speed(i, constrain(output, -255, 255));
    }
}

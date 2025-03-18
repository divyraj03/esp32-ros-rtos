#ifndef PID_HAL_H
#define PID_HAL_H

void pid_init();
void pid_update();
void pid_set_gains(int motor_id, float kp, float ki, float kd);
void pid_set_setpoint(int motor_id, float setpoint);

#endif

#ifndef MOTOR_HAL_H
#define MOTOR_HAL_H

#define MOTOR_COUNT 6

void motor_init();
void motor_set_speed(int motor_id, int speed);
void motor_stop(int motor_id);

#endif

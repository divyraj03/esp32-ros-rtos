#ifndef ROS_HAL_H
#define ROS_HAL_H

#include <micro_ros_arduino.h>
#include <std_msgs/msg/float32_multi_array.h>

void ros_init();
void ros_publish_feedback(float feedback[]);
void ros_handle_motor_command(const std_msgs__msg__Float32MultiArray *msg);
void ros_spin();

#endif

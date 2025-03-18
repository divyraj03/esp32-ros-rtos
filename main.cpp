#include "motor_hal.h"
#include "encoder_hal.h"
#include "pid_hal.h"
#include "ros_hal.h"
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void pid_task(void *param) {
    while (1) {
        pid_update();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void ros_task(void *param) {
    while (1) {
        ros_spin();
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200);
    motor_init();
    encoder_init();
    pid_init();
    ros_init();
    
    xTaskCreatePinnedToCore(pid_task, "PID", 4096, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(ros_task, "ROS", 4096, NULL, 1, NULL, 0);
}

void loop() {}

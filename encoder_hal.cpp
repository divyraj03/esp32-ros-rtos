#include "encoder_hal.h"
#include <Arduino.h>

volatile long encoder_pos[6] = {0};

void IRAM_ATTR encoder_isr_0() { encoder_pos[0]++; }
void IRAM_ATTR encoder_isr_1() { encoder_pos[1]++; }
void IRAM_ATTR encoder_isr_2() { encoder_pos[2]++; }
void IRAM_ATTR encoder_isr_3() { encoder_pos[3]++; }
void IRAM_ATTR encoder_isr_4() { encoder_pos[4]++; }
void IRAM_ATTR encoder_isr_5() { encoder_pos[5]++; }

void encoder_init() {
    attachInterrupt(34, encoder_isr_0, RISING);
    attachInterrupt(35, encoder_isr_1, RISING);
    attachInterrupt(36, encoder_isr_2, RISING);
    attachInterrupt(39, encoder_isr_3, RISING);
    attachInterrupt(18, encoder_isr_4, RISING);
    attachInterrupt(19, encoder_isr_5, RISING);
}

long encoder_get_position(int encoder_id) {
    return encoder_pos[encoder_id];
}

void encoder_reset(int encoder_id) {
    encoder_pos[encoder_id] = 0;
}

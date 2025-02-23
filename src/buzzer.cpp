/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
#include "Arduino.h"
#include <driver/ledc.h>
#include "buzzer.h"

const int buzzerPin = 40;
const int channel   = 5;

void setup_pwm_buzzer(void) {
    ledcSetup(channel, 4000, 8);        // Configure PWM channel: channel 0, frequency 3000Hz, resolution 8-bit
    ledcAttachPin(buzzerPin, channel);  // Bind PWM channel to GPIO
}

void buzzer_sound(uint32_t frequency, uint32_t duration_ms) {
    ledcWriteTone(channel, frequency);
    ledcWrite(channel, 127);

    vTaskDelay(duration_ms / portTICK_PERIOD_MS);

    ledcWriteTone(channel, 0);
    digitalWrite(channel, 0);
}

void beep(void) {
    buzzer_sound(4000, 100);
}

void start_tone(void) {
    buzzer_sound(2000, 100);
    buzzer_sound(1000, 100);
}
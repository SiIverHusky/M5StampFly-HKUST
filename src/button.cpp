/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
#include "button.hpp"
#include "OneButton.h"
#include "led.hpp"
#include "buzzer.h"

#define PIN_INPUT 0

OneButton button(PIN_INPUT, true);

uint8_t is_long_press = 0;

void task_button_update(void *pvParameters);
void LongPressStop(void *oneButton);
void DuringLongPress(void *oneButton);
void Click(void *oneButton);

bool init_button(void) {
    // link functions to be called on events.
    button.attachClick(Click, &button);

    button.setLongPressIntervalMs(3000);

    xTaskCreatePinnedToCore(task_button_update,  // Task function
                            "TaskButtonUpdate",  // Task name
                            1024 * 4,            // Stack size
                            NULL,                // Parameter to pass
                            0,                   // Task priority
                            NULL,                // Task handle
                            tskNO_AFFINITY);     // No affinity, not bound to any core

    return true;
}

void task_button_update(void *pvParameters) {
    for (;;) {
        button.tick();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

// this function will be called when the button click.
void Click(void *oneButton) {
    buzzer_sound(4000, 1000);
    esp_restart();
}

// this function will be called when the button is released.
void LongPressStop(void *oneButton) {
    is_long_press = 0;
    esp_restart();
}

// this function will be called when the button is held down.
void DuringLongPress(void *oneButton) {
    if (!is_long_press) {
        is_long_press = 1;
    }
}
/*
 * LED blink with FreeRTOS
 */
#include <FreeRTOS.h>
#include <task.h>
#include "pico/stdlib.h"

#define LED_PIN 25
#define LED2_PIN 15
#define LED3_PIN 16

// function to continuously blink LED
void blink () {
  while (true) {
    gpio_put(LED_PIN, 0);
    sleep_ms(2000);
    gpio_put(LED_PIN, 1);
    sleep_ms(2000);
  }
}

// function to continuously blink LED2
void blink2 () {
  while (true) {
    gpio_put(LED2_PIN, 0);
    sleep_ms(200);
    gpio_put(LED2_PIN, 1);
    sleep_ms(200);
  }
}

// function to continuously blink LED3
void blink3 () {
  while (true) {
    gpio_put(LED3_PIN, 0);
    sleep_ms(100);
    gpio_put(LED3_PIN, 1);
    sleep_ms(100);
  }
}


int main()
{
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(LED2_PIN);
    gpio_set_dir(LED2_PIN, GPIO_OUT);
    gpio_init(LED3_PIN);
    gpio_set_dir(LED3_PIN, GPIO_OUT);

    xTaskCreate(blink, "LED Task 1", 256, NULL, 1, NULL);
    xTaskCreate(blink2, "LED Task 2", 256, NULL, 1, NULL);
    xTaskCreate(blink3, "LED Task 3", 256, NULL, 1, NULL);

    vTaskStartScheduler();

    while (true)
        ;
}
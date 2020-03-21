#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "boarddef.h"
#include "ledtask.h"

typedef struct _led {
    led_state_t state;
    int delay;  
} led_t;

static led_t led_red;
static led_t led_yellow;
static led_t led_green;


static void blink_red_task(void *pvParameters)
{
    int cnt = 0;

    for (;;)
    {
        if (led_red.state == BLINK) {
            gpio_set_level(LED_RED_PIN, cnt%2);
            cnt++;
        }
        vTaskDelay(led_red.delay / portTICK_PERIOD_MS);
    } 
}

static void blink_yellow_task(void *pvParameters)
{
    int cnt = 0;

    for (;;)
    {
        if (led_yellow.state == BLINK) {
            gpio_set_level(LED_YELLOW_PIN, cnt%2);
            cnt++;
        }
        vTaskDelay(led_yellow.delay / portTICK_PERIOD_MS);
    }
}

static void blink_green_task(void *pvParameters)
{
    int cnt = 0;

    for (;;)
    {
        if (led_green.state == BLINK) {
            gpio_set_level(LED_GREEN_PIN, cnt%2);
            cnt++;
        }
        vTaskDelay(led_green.delay / portTICK_PERIOD_MS);
    }
}

static void onoff_task(void *pvParameters)
{
    for (;;)
    {
        if (led_red.state != BLINK) 
            gpio_set_level(LED_RED_PIN, led_red.state);
        if (led_yellow.state != BLINK) 
            gpio_set_level(LED_YELLOW_PIN, led_yellow.state);
        if (led_green.state != BLINK) 
            gpio_set_level(LED_GREEN_PIN, led_green.state);

        vTaskDelay(10);
    }
}

static int get_state_from_string(char *param)
{
    if (strcmp(param, "OFF")) return ON;
    return OFF;    
}

void change_led_state(int led, char *param) 
{
    int state = get_state_from_string(param);

    switch (led) 
    {
        case 1:
            led_red.state = state;
            break;
        case 2:
            led_yellow.state = state;
            break;
        case 3:
            led_green.state = state;
            break;
        default:
            break;
    }
}

static void blink_led_red(int delay)
{
    led_red.state = BLINK;
    led_red.delay = delay;
}

static void blink_led_yellow(int delay)
{
    led_yellow.state = BLINK;
    led_yellow.delay = delay;
}

static void blink_led_green(int delay)
{
    led_green.state = BLINK;
    led_green.delay = delay;
}

void blink_led(int led, int delay) 
{
    switch (led)
    {
        case 1:
            blink_led_red(delay);
            break;

        case 2:
            blink_led_yellow(delay);
            break;

        case 3:
            blink_led_green(delay);
    
        default:
            break;
    }
}

void init_leds_task()
{
    xTaskCreate(&blink_red_task, "blink_red_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(&blink_yellow_task, "blink_yellow_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(&blink_green_task, "blink_green_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(&onoff_task, "onoff_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);


    led_red.state = OFF;
    led_yellow.state = OFF;
    led_green.state = OFF;
}
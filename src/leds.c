#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "boarddef.h"
#include "leds.h"

typedef struct _led {
    led_state_t state;
    int delay;
} led_t;

static led_t led1;
static led_t led2;
static led_t led3;


static void control_led1_task(void *pvParameters)
{
    int cont = 0;
    for (;;)
    {


        switch (led1.state)
        {
                case ON:
                        gpio_set_level(LED_1, ON);
                        vTaskDelay( 1000 / portTICK_PERIOD_MS );
                        break;
                case OFF:
                        gpio_set_level(LED_1, OFF);
                        vTaskDelay( 1000 / portTICK_PERIOD_MS );
                        break;
                case BLINK:
                        gpio_set_level(LED_1, cont%2);
                        cont++;
                        vTaskDelay(led1.delay / portTICK_PERIOD_MS);
                        break;
        }
    
    }

}

static void control_led2_task(void *pvParameters)
{
    int cont = 0;
    for (;;)
    {
        switch (led2.state)
        {
            case ON:
                    gpio_set_level(LED_2, ON);
                    vTaskDelay( 1000 / portTICK_PERIOD_MS );
                    break;
            case OFF:
                    gpio_set_level(LED_2, OFF);
                    vTaskDelay( 1000 / portTICK_PERIOD_MS );
                    break;
            case BLINK:
                    gpio_set_level(LED_2, cont%2);
                    cont++;
                    vTaskDelay(led2.delay / portTICK_PERIOD_MS);
                    break;
        }

    }
}

static void control_led3_task(void *pvParameters)
{
    int cont = 0;

    for (;;)
    {
        switch (led3.state)
        {
            case ON:
                gpio_set_level(LED_3, ON);
                vTaskDelay( 1000 / portTICK_PERIOD_MS );
                break;
            case OFF:
                gpio_set_level(LED_3, OFF);
                vTaskDelay( 1000 / portTICK_PERIOD_MS );
                break;
            case BLINK:
                gpio_set_level(LED_3, cont%2);
                cont++;
                vTaskDelay(led3.delay / portTICK_PERIOD_MS);
                break;

        }
    
    }
}

static int get_state_from_string (char *led_state)
{
    if (strcmp(led_state, "OFF") == 0)
    {
        return OFF;
    }
    else if (strcmp(led_state, "ON") == 0)
    {
        return ON;
    }
    else if (strcmp(led_state, "BLINK") == 0)
    {
        return BLINK;
    }
    return OFF;
}

void choice_led_state (int led, char *led_state, int delay)
{
    int state = get_state_from_string(led_state);

    switch (led)
    {
    case 1:
        led1.state = state;
        led1.delay = delay;
        break;
    case 2:
        led2.state = state;
        led2.delay = delay;
        break;
    case 3:
        led3.state = state;
        led3.delay = delay;
        break;
    default:
        break;
    }
}

void init_leds_task()
{
    xTaskCreate(&control_led1_task, "control_led1_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(&control_led2_task, "control_led2_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    xTaskCreate(&control_led3_task, "control_led3_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

    led1.state = OFF;
    led2.state = OFF;
    led3.state = OFF;
}
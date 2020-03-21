#include "boardconfig.h"
#include "driver/gpio.h"

void board_init()
{
    /* Configure LED_RED */
    gpio_pad_select_gpio(LED_RED_PIN);
    gpio_set_direction(LED_RED_PIN, GPIO_MODE_OUTPUT);

    /* Configure LED_YELLOW */
    gpio_pad_select_gpio(LED_YELLOW_PIN);
    gpio_set_direction(LED_YELLOW_PIN, GPIO_MODE_OUTPUT);

    /* Configure LED_GREEN */
    gpio_pad_select_gpio(LED_GREEN_PIN);
    gpio_set_direction(LED_GREEN_PIN, GPIO_MODE_OUTPUT);

}
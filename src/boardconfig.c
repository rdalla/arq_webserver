#include "boardconfig.h"
#include "driver/gpio.h"

void board_init()
{
    /* Configure LED_RED */
    gpio_pad_select_gpio(LED_1);
    gpio_set_direction(LED_1, GPIO_MODE_OUTPUT);

    /* Configure LED_YELLOW */
    gpio_pad_select_gpio(LED_2);
    gpio_set_direction(LED_2, GPIO_MODE_OUTPUT);

    /* Configure LED_GREEN */
    gpio_pad_select_gpio(LED_3);
    gpio_set_direction(LED_3, GPIO_MODE_OUTPUT);

}
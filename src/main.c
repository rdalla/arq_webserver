#include <string.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "nvs_flash.h"
#include "leds.h"
#include "server.h"
#include "boardconfig.h"

void app_main()
{
    ESP_ERROR_CHECK(nvs_flash_init());
    board_init();
    http_server_init();
    init_leds_task();
}
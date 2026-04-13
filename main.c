#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>
#include "dht.h"
#include "ldr.h"
#include "oled.h"
#include "storage.h"
#include "menu.h"
#include "control.h"

float temperature, humidity;
int light;

void app_main(void)
{
    dht_init();
    ldr_init();
    oled_init();
    storage_init();
    menu_init();
    control_init();

void check_serial(void)
{
    char cmd[20];

    if (fgets(cmd, sizeof(cmd), stdin))
    {
        if (strncmp(cmd, "readlog", 7) == 0)
        {
            storage_read_log();
        }
    }
}
    while (1)
    {
        dht_read(&temperature, &humidity);
        light = ldr_read();

        control_update(temperature);

        oled_display(temperature, humidity, light);

        if (menu_is_logging_enabled())
        {
            storage_log(temperature, humidity, light);
        }

        menu_update();

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
    check_serial();
}

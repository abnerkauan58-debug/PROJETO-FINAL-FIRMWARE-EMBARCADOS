#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

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
}

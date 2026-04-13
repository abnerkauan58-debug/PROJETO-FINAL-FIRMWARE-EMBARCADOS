#include "oled.h"
#include <stdio.h>

void oled_init(void)
{
    // init I2C + SSD1306
}

void oled_display(float t, float h, int l)
{
    printf("T: %.1f C | H: %.1f %% | L: %d\n", t, h, l);
}

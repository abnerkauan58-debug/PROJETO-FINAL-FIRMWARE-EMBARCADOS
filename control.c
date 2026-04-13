#include "control.h"
#include "menu.h"
#include <stdio.h>

void control_init(void)
{
}

void control_update(float temp)
{
    float setpoint = menu_get_setpoint();

    if (temp < setpoint)
    {
        printf("Aquecendo...\n");
    }
    else
    {
        printf("Temperatura OK\n");
    }
}

#include "menu.h"
#include <stdio.h>

static int logging_enabled = 1;
static float setpoint = 28.0;

void menu_init(void)
{
}

void menu_update(void)
{
    // aqui você pode colocar leitura de botões futuramente
}

int menu_is_logging_enabled(void)
{
    return logging_enabled;
}

float menu_get_setpoint(void)
{
    return setpoint;
}

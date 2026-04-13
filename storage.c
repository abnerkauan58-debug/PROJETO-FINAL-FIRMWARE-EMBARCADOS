#include "storage.h"
#include <stdio.h>

void storage_init(void)
{
    // mount SPIFFS
}

void storage_log(float t, float h, int l)
{
    FILE *f = fopen("/spiffs/log.txt", "a");
    if (f == NULL) return;

    fprintf(f, "T:%.1f H:%.1f L:%d\n", t, h, l);
    fclose(f);
}

void storage_read_log(void)
{
    FILE *f = fopen("/spiffs/log.txt", "r");
    if (f == NULL) return;

    char line[64];
    while (fgets(line, sizeof(line), f))
    {
        printf("%s", line);
    }
    fclose(f);
}

#include "Hardware_conf.h"
int LED = LED_BUILTIN;


void Hardware_init()
{
    pinMode(LED, OUTPUT);
}
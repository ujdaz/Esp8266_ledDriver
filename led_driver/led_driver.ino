#include "WiFi_conf.h"
#include "NTP_driver.h"
#include "Hardware_conf.h"

int state = LOW;

char on = LOW;
char off = HIGH;



void setup()
{
  Serial.begin(115200);

  Hardware_init();
  WiFi_confInit();
  NTP_init();
}

void loop()
{
  NTP_main();
}
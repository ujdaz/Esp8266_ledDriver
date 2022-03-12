#include "WiFi_conf.h"
#include "NTP_driver.h"
#include "Hardware_conf.h"
#include "sunMoon.h"

int state = LOW;

char on = LOW;
char off = HIGH;


//xsa
void setup()
{
  Serial.begin(115200);

  Hardware_init();
  WiFi_confInit();
  NTP_init();
  sunMoon_init();
}

void loop()
{
  NTP_main();
}





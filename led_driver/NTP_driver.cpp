#include "NTP_driver.h"
#include <NTPClient.h>
#include <WiFiUdp.h>



const long utcOffsetInSeconds = 3600;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

struct NTP_time
{
    uint8_t hour;
    uint8_t minute;
    uint8_t seconds;
    uint8_t day;
    uint8_t month;
    uint8_t year;
}NTP_time_t;


void NTP_init ()
{
    timeClient.begin();
   timeClient.update();
    Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
  NTP_time_t.hour = timeClient.getHours();
}



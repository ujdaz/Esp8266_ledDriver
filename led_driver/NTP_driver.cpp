#include "NTP_driver.h"
#include <NTPClient.h>
#include <WiFiUdp.h>


unsigned long NTP_actualtimmer = 0;
unsigned long NTP_savedtimmer = 0;
unsigned long NTP_divtimmer = 0;

unsigned long NTP_actualtimmerSyn = 0;
unsigned long NTP_savedtimmerSyn = 0;
unsigned long NTP_divtimmerSyn = 0;

const long utcOffsetInSeconds = 3600;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


////////////////////////////////////////////////////////
void _NTP_timmer();
void _NTP_autoSynchro();
void _NTP_counter();
void _NTP_update();
// void NTP_init()
// void NTP_printTime();
// void NTP_main();

/////////////////////////////////////////////////////////

struct NTP_time
{
  uint8_t seconds;
  uint8_t minute;
  uint8_t hour;
  uint8_t dayOfWeek;
  uint8_t day;
  uint8_t month;
  uint8_t year;
} NTP_time_t;

void _NTP_timmer()
{
  NTP_actualtimmer = millis();
  NTP_divtimmer = NTP_actualtimmer - NTP_savedtimmer;
  if (NTP_divtimmer >= 1000UL) 
  {
    NTP_savedtimmer = NTP_actualtimmer;
    _NTP_counter();
    NTP_printTime();
  }
}

void _NTP_autoSynchro()
{
  NTP_actualtimmerSyn = millis();
  NTP_divtimmerSyn = NTP_actualtimmerSyn - NTP_savedtimmerSyn;
  if (NTP_divtimmerSyn >= autoSyncTime) 
  {
    NTP_savedtimmerSyn = NTP_actualtimmerSyn;
    _NTP_update();
    Serial.println("auto syn done");
  }
  
}


void _NTP_counter()
{
  NTP_time_t.seconds++;
  if (NTP_time_t.seconds == 60)
  {
    NTP_time_t.seconds = 0;
    NTP_time_t.minute++;
  }
  else if (NTP_time_t.minute == 60)
  {
    NTP_time_t.minute = 0;
    NTP_time_t.hour++;
  }
  else if (NTP_time_t.hour == 24)
  {
    NTP_time_t.hour = 0; 
    NTP_time_t.dayOfWeek++;
  }
  else if (NTP_time_t.dayOfWeek == 6)
  {
    NTP_time_t.dayOfWeek = 0;
  }
}

void _NTP_update()
{
  timeClient.update();
  NTP_time_t.seconds = timeClient.getSeconds();
  NTP_time_t.minute = timeClient.getMinutes();
  NTP_time_t.hour = timeClient.getHours();
  NTP_time_t.dayOfWeek = timeClient.getDay();
  Serial.println("NPT update done");
}



void NTP_init()
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
  NTP_time_t.minute = timeClient.getMinutes();
  NTP_time_t.seconds = timeClient.getSeconds();
  NTP_time_t.dayOfWeek = timeClient.getDay();
  Serial.println("NTP init done");
}



void NTP_printTime()
{
  // Serial.print(timeClient.getSeconds());
  // Serial.print(":");
  // Serial.print(timeClient.getMinutes());
  // Serial.print(":");
  // Serial.print(timeClient.getHours());
  // Serial.print(", ");
  // Serial.print(daysOfTheWeek[timeClient.getDay()]);
  // Serial.println("");

  Serial.print(NTP_time_t.hour);
  Serial.print(":");
  Serial.print(NTP_time_t.minute);
  Serial.print(":");
  Serial.print(NTP_time_t.seconds);
  Serial.print(", ");
  Serial.print(daysOfTheWeek[NTP_time_t.dayOfWeek]);
  Serial.println("");
}

void NTP_main()
{
_NTP_timmer();
_NTP_autoSynchro();

}


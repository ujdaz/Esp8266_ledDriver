#include <SuplaDevice.h>
#include <supla/network/esp_wifi.h>
#include <supla/control/rgbw_leds.h>
#include <supla/control/dimmer_leds.h>

#ifdef ARDUINO_ARCH_AVR
  // Arduino Mega with EthernetShield W5100:
#include <supla/network/ethernet_shield.h>
  // Ethernet MAC address
uint8_t mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
Supla::EthernetShield ethernet(mac);

  // Arduino Mega with ENC28J60:
  // #include <supla/network/ENC28J60.h>
  // Supla::ENC28J60 ethernet(mac);
#elif defined(ARDUINO_ARCH_ESP8266) || defined(ARDUINO_ARCH_ESP32)
  // ESP8266 and ESP32 based board:
#include <supla/network/esp_wifi.h>
Supla::ESPWifi wifi("toya88096464", "95680956");
#endif

#define RED_PIN 5
#define GREEN_PIN 4
#define BLUE_PIN 0
#define BRIGHTNESS_PIN 13
void setup()
{
char GUID[SUPLA_GUID_SIZE] = {0x34,0x28,0xDC,0x1D,0x1B,0x92,0xAE,0xE0,0xA1,0xC7,0xA5,0xF3,0x78,0x84,0xC8,0x2A};
char AUTHKEY[SUPLA_AUTHKEY_SIZE] = {0x4C,0xF2,0xD0,0x89,0x19,0x9E,0xFE,0x03,0x51,0xEB,0x7E,0x57,0x94,0xA6,0x4F,0xA1};

auto rgbw = new Supla::Control::RGBWLeds(RED_PIN, GREEN_PIN, BLUE_PIN, BRIGHTNESS_PIN);

SuplaDevice.begin(
GUID,              // Global Unique Identifier
"svr25.supla.org",  // SUPLA server address
"Przemek781@gmail.com",   // Email address used to login to Supla Cloud
AUTHKEY);          // Authorization key
}
void loop()
{
	SuplaDevice.iterate();

};



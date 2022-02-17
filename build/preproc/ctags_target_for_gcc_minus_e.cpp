# 1 "c:\\Users\\Przemek\\Desktop\\led_driver_v1\\led_driver.ino"
# 2 "c:\\Users\\Przemek\\Desktop\\led_driver_v1\\led_driver.ino" 2
# 3 "c:\\Users\\Przemek\\Desktop\\led_driver_v1\\led_driver.ino" 2
# 4 "c:\\Users\\Przemek\\Desktop\\led_driver_v1\\led_driver.ino" 2
# 16 "c:\\Users\\Przemek\\Desktop\\led_driver_v1\\led_driver.ino"
  // ESP8266 and ESP32 based board:
# 18 "c:\\Users\\Przemek\\Desktop\\led_driver_v1\\led_driver.ino" 2
Supla::ESPWifi wifi("toya88096464", "95680956");






void setup()
{
char GUID[16] = {0x34,0x28,0xDC,0x1D,0x1B,0x92,0xAE,0xE0,0xA1,0xC7,0xA5,0xF3,0x78,0x84,0xC8,0x2A};
char AUTHKEY[16 /* ver. >= 7*/] = {0x4C,0xF2,0xD0,0x89,0x19,0x9E,0xFE,0x03,0x51,0xEB,0x7E,0x57,0x94,0xA6,0x4F,0xA1};

auto rgbw = new Supla::Control::RGBWLeds(5, 4, 0, 13);

SuplaDevice.begin(
GUID, // Global Unique Identifier
"svr25.supla.org", // SUPLA server address
"Przemek781@gmail.com", // Email address used to login to Supla Cloud
AUTHKEY); // Authorization key
}
void loop()
{
 SuplaDevice.iterate();
};

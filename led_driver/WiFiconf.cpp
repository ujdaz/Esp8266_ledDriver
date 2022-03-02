#include "WiFiconf.h"
#include <arduino.h>

const char* ssid = WiFissid;
const char* password = WiFipassword;
WiFiServer server(80);

void _WiFi_connecting()
{
    Serial.println("WiFi Connecting");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi Connecting done");
}

void _WiFi_serverBegin()
{
    Serial.println("Server started");
  server.begin();  // Starts the Server
  Serial.print("IP Address of network: "); // Prints IP address on Serial Monitor
  Serial.println(WiFi.localIP());
}

void WiFi_confInit()
{
#ifdef WiFiStaticIP
    if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS))
    {
        Serial.println("STA Failed to configure");
    }
#endif

    _WiFi_connecting();
    _WiFi_serverBegin();
}


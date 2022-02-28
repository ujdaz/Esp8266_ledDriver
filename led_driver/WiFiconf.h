#include <ESP8266WiFi.h>

#define WiFissid "szczesliwy dom"
#define WiFipassword "Z@rtowalem1"

#define WiFiStaticIP

#ifdef WiFiStaticIP
    // Set your Static IP address
    IPAddress local_IP(192, 168, 0, 178);
    IPAddress gateway(192, 168, 0, 1);
    IPAddress subnet(255, 255, 255, 0);
    IPAddress primaryDNS(8, 8, 8, 8);   // optional
    IPAddress secondaryDNS(8, 8, 4, 4); // optional
#endif
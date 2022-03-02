#include "RGBMI_driver.h"
#include "WiFiconf.h"
#include "NTP_driver.h"

int state = LOW;
int LED = LED_BUILTIN;
char on = LOW;
char off = HIGH;

const char* ssid = WiFissid;
const char* password = WiFipassword;





WiFiServer server(80);




void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, off);
  #ifdef WiFiStaticIP
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
 #endif

  Serial.print("Connecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  NTP_init();


  Serial.println("WiFi connected");  
  server.begin();  // Starts the Server
  Serial.println("Server started");

  Serial.print("IP Address of network: "); // Prints IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{


  
  delay(100);
NTP_main();

  
  
}
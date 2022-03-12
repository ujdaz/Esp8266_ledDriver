////////////////////////////////////////////////////
// WiFi conf start


#define WiFissid "szczesliwy dom"
#define WiFipassword "Z@rtowalem1"

//#define WiFiStaticIP

#define local_IP (192,168,0,178)
#define gateway (192,168,0,1)
#define subnet (255,255,255,0)
#define primaryDNS (8, 8, 8, 8)   // optional
#define secondaryDNS (8, 8, 4, 4) // optional


// WiFi conf end
///////////////////////////////////////////////////



////////////////////////////////////////////////////
// time conf start


#define autoSyncTime 60000UL //mili sek  600000UL = 10 min   


// time conf end
///////////////////////////////////////////////////



////////////////////////////////////////////////////
// sunset and sunrise time start


#define OUR_latitude    50.0833               // Moscow cordinates
#define OUR_longtitude  19.9167
#define OUR_timezone    60                     // localtime with UTC difference in minutes


// sunset and sunrise time end
///////////////////////////////////////////////////
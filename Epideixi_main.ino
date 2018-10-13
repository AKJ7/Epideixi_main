/****
 * Color Palette:  Navy blue: #18121E, Gunmetal: #233237, Rusty Red: #984B43, Warm Yellow: #EAC67A
 * 
*/


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Fonts/Lato_Light_13.h"
#include "Fonts/Kranky_Regular_30.h"
#include "WiFiClientSecure.h"
#include "time.h"
#include "OneWire.h"

#define TFT_DC 4
#define TFT_CS 15
#define TFT_RST 2
#define TFT_MISO 19         
#define TFT_MOSI 23           
#define TFT_CLK 18 
#define CS_PIN 26
#define TIRQ_PIN 12

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

#include "Epideixi_obj.h"

const char* ssid       = "AKJ WLAN";
const char* password   = "AKJ.WLAN1234";
const char* ntpServer  = "pool.ntp.org";
const char* server = "script.google.com";
const char* key = "AKfycbwulCXPwNmzvC0N8Aayes3aXc-4OGotKNKZ0Ma1UKA1EqVcvlA";
String URL = "https://script.google.com/macros/s/AKfycbzvjMIxqgEo49PkDa0HcyXUb7h8WcTjZpIGTA4fYMNO7-Ub5gE/exec";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;
unsigned long currentMillis = 0;

float roomTemperature = 0;
float oldRoomTemperature = 0;
int hour;
int minute;
int innerTemp;
int switchVar = 0;
String movedURL;
String line;
bool firstLaunch = true;
uint16_t counter = 0;
uint64_t timer = 0;

WiFiClientSecure client;
OneWire  ds(13);

GUI_Element fromGoogle;
GUI_Object Clock(20, 20, 4, 0xFFFF, "Hallo World", 0x001F);
GUI_Object Temp_in(20, 20, 2, 0xFFFF, "24", 0xFFE0);
GUI_Object Temp_out(20, 20, 2, 0xFFFF, "12", 0x07E8);


void setup(){
  
    Serial.begin(115200);
    TFT_default();
    tft.fillScreen(0x1986);
    
    loadingPage();    
    //display_loadingstatus();
    
    //configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    //printLocalTime();

    //tft.fillScreen(0x0000);
}


void loop(){
  
//    Clock.displayRect(0, 0, 200, 160, 0x001F);
//    Temp_in.displayRect(200, 0, 120, 80, 0xFFE0);
//    Temp_out.displayRect(200, 80, 120, 80, 0x07E8);
//    
//    switch (switchVar){
//
//      
//      default:
//        // HomePage
//        roomTemperature = roomTemp();
//        int *ptr = printLocalTime();
//        Clock.displayText(20, 50, String(ptr[2])+":"+String(ptr[1]), 0xFFFF, 4);
//        Temp_out.displayText(220, 120, String(line), 0x0000, 2);
//        if (roomTemperature != 0){
//            Temp_in.displayText(220, 40, String(roomTemperature), 0x0000, 2);  
//        }
//        delay(3000); 
//    }
}


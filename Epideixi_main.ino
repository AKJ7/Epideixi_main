/****
 * Color Palette:  Navy blue: #18121E, Gunmetal: #233237, Rusty Red: #984B43, Warm Yellow: #EAC67A
 * 
*/
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Fonts/Lato_Light_13.h"
#include "Fonts/Kranky_Regular_30.h"
#include "Fonts/Crafty_Girls_Regular_13.h"
#include "WiFiClientSecure.h"
#include "time.h"
#include "OneWire.h"

#define TFT_DC 4
#define TFT_CS 15
#define TFT_RST 2
#define TFT_MISO 19         
#define TFT_MOSI 23           
#define TFT_CLK 18 

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
//int *ptr;

String movedURL;
String line;

bool firstLaunch = true;

uint8_t switchVar;
uint16_t counter = 0;
uint64_t timer = 0;

WiFiClientSecure client;
OneWire  ds(13);

GUI_Element HP_Clock;
GUI_Element HP_Temp;
GUI_Element fromGoogle;


void setup(){
    Serial.begin(115200);
    
    TFT_default();
    display_title();
    display_loadingstatus();
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();
//    WiFi.disconnect(true);
//    WiFi.mode(WIFI_OFF);
    tft.fillScreen(0x0000);
    
}


void loop(){
    //if (millis() - timer > 2000 || firstLaunch == true){
    //    timer = millis();
        int *ptr = printLocalTime();  
    //}
    defaultHP_state();
    HP_Clock.displayElement(String(ptr[2])+":"+String(ptr[1]), 40, 100, 0xEE2F, 6);
//    if (roomTemp() != 0){
//      printf("%g\n", roomTemp());
//    }
//    HP_Temp.displayElement(String(roomTemp()), 100, 110, 0xFFFF, 3);
//    fromGoogle.displayElement(String(line), 100, 200);
    tft.setFont(&Lato_Light_13);
    tft.setCursor(0, 180);
    tft.setTextSize(1);
    tft.println("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua.");
    delay(2000);
//    Serial.println(WiFi.RSSI());
//    firstLaunch = false;
}












//void setup(){
//  Serial.begin(115200);
//  tft.begin();
//  tft.setRotation(3);
//  tft.setFont(&Kranky_Regular_30);
//  tft.setTextColor(ILI9341_WHITE);
//  tft.setTextSize(2);
//  tft.fillScreen(0x0000);
//  tft.setCursor(80, 80);
//  tft.println("12:45");
//  tft.setFont(&Crafty_Girls_Regular_13);
//  tft.setTextColor(ILI9341_WHITE);
//  tft.setTextSize(2);
////  tft.setCursor(60, 120);
////  tft.println("24.2 ºC | 16.0 ºC");
//}
//
//void loop(){
//  roomTemperature = roomTemp();
//
//  if (roomTemperature == oldRoomTemperature){
//    return;
//  }
//  if (roomTemp() == 0){
//    tft.fillRect(60, 100, 80, 30, 0x0000);
//    tft.setCursor(60, 120);
//    tft.println(roomTemperature);
//    tft.setCursor(145, 120);
//    tft.println("ºC");
//  }
//  oldRoomTemperature = roomTemperature;
//}
//
////    for (int i = 0; i < 1000; i ++){
////      //tft.fillRect(120, 100, 80, 50, 0x0000);
////      tft.fillScreen(0x0000);
////      tft.setCursor(0, 50);
////      tft.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ 123456789 +_/-.,");
////      delay(1000);
////    }
////    tft.fillScreen(0x0000);


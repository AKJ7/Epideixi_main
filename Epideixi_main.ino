#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Fonts/Kranky_Regular_30.h"
#include "Fonts/Crafty_Girls_Regular_13.h"
#include "WiFi.h"
#include "time.h"
#include "OneWire.h"

#define TFT_DC 4
#define TFT_CS 15
#define TFT_RST 2
#define TFT_MISO 19         
#define TFT_MOSI 23           
#define TFT_CLK 18 

const char* ssid       = "AKJ WLAN";
const char* password   = "AKJ.WLAN1234";
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;
unsigned long currentMillis = 0;

float roomTemperature = 0;
float oldRoomTemperature = 0;
int hour;
int minute;

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
OneWire  ds(13);


void setup(){
  
    Serial.begin(115200);
    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" CONNECTED");
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(0x0000);
    tft.setTextColor(0xFFFF);
    char tex[13] = "hallo world";
    tft.println(tex);
}


void loop(){
  
//  if (millis() - currentMillis > 3000){
//    currentMillis = millis();
//    
    int *ptr = printLocalTime();
//    //if (minute != ptr[1]){
//      //minute = ptr[1];
      homePage(ptr[2], ptr[1]);
//    //}
//    //printf("Hour: %d, Minute: %d, timeHour: %d, timeMinute: %d\n", hour, minute, ptr[2], ptr[1]);
//  }
  delay(500);
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


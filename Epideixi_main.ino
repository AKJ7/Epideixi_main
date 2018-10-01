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

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

#include "Epideixi_obj.h"

const char* ssid       = "AKJ WLAN";
const char* password   = "AKJ.WLAN1234";
const char* ntpServer  = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;
unsigned long currentMillis = 0;

float roomTemperature = 0;
float oldRoomTemperature = 0;
int hour;
int minute;
int innerTemp;

uint8_t switchVar;

OneWire  ds(13);
int counter = 0;


GUI_Element HP_Clock;
GUI_Element HP_Temp;

void setup(){

    GUI_Element loading;
    GUI_Element deviceName;
    
    Serial.begin(115200);
    
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(0xFFFF);
    tft.setTextColor(0xFFFF);
    int width = 0;
    int height = 10;
    deviceName.displayElement("Epidexi", 40, 30, 0x49AC, 6);
//    while (width < 200){
//      tft.fillRect(60, 150, width, height, 0x0000);
//      width++;
//      delay(10);
//      try{
//          switch(switchVar){
//            default:
//            switchVar = width;   
//          }
//      } catch(int e){
//        
//      }
//    }
    try{
        while (true){
            loading.displayElement("Connecting to "+String(ssid), 30, 200, 0x0000, 2, 0xFFFF);
            WiFi.begin(ssid, password);
            delay(2000);
            if (WiFi.status() != WL_CONNECTED){
                throw 1;
                break;
            }
            loading.displayElement("Connected to "+String(ssid), 30, 200, 0x0000, 2, 0xFFFF);
            delay(1000);
            break;
        }
    } catch (int error){
          switch(error){
              case 1:
                  loading.displayElement("Can't connect to "+String(ssid), 30, 200, 0x0000, 2, 0xFFFF);
                  break;
              default:
                  loading.displayElement("An error occured!", 30, 200, 0x0000, 2, 0xFFFF);    
          }
    }
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    tft.fillScreen(0x0000);
}


void loop(){
     
    int *ptr = printLocalTime();
    
    HP_Clock.displayElement(String(ptr[2])+":"+String(ptr[1]), 40, 20, 0xFFFF, 8);
    if (roomTemp() != 0){
      printf("%g\n", roomTemp());
    }
    HP_Temp.displayElement(String(roomTemp())+"C", 100, 110, 0xFFFF, 2);
    
    delay(1000);
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


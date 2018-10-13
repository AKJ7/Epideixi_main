void TFT_default(){
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(0x0000);
    tft.setFont(&Lato_Light_13);
    tft.setTextColor(0xFFFF);
    tft.setTextWrap(false);
}

int WiFiManager(const char *WiFiSSID, const char *WiFiPass, int caseType){
    switch(caseType){
        case 1:
           counter = 0;
           WiFi.begin(WiFiSSID, WiFiPass);
           while (WiFi.status() != WL_CONNECTED){
           }
           return 1;
        case 2:
            WiFi.disconnect(true);
            WiFi.mode(WIFI_OFF);
            return 1;
        default:
            return -1;
    }
}


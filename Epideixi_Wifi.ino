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

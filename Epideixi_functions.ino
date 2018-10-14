void TFT_default(){
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(0x0000);
    tft.setFont(&Lato_Light_13);
    tft.setTextColor(0xFFFF);
    tft.setTextWrap(false);
}


class GUI_Element{

    private:
        int x;
        int y;
        int objSize;
        int objColor;
        String objText;

        int x_default;
        int y_default;
        int objSize_default;
        int objColor_default;
        String objText_default;
        

    public:
       void set(String text, int x_Pos, int y_Pos, int color, int textSize){
          objText = text;
          x = x_Pos;
          y = y_Pos;
          objSize = textSize;
          objColor = color;
       }
       void setDefault(String text, int x_Pos, int y_Pos, int color, int textSize){
          objText_default;
       }
       int toReturn(){
           return x;
       }
       void displayElement(String text, int x_Pos = 0, int y_Pos = 0, int color = 0xFFFF, int textSize = 1, int background = 0x0000){
           if (text == objText){
               return;
           }
           set(text, x_Pos, y_Pos, color, textSize);
           int16_t x1, y1;
           uint16_t w, h;
           tft.getTextBounds(text, x_Pos, y_Pos, &x1, &y1, &w, &h);
           tft.fillRect(x1, y1, w, h, background);
           tft.setTextColor(color);
           tft.setTextSize(textSize);
           tft.setCursor(x_Pos, y_Pos);
           tft.println(text);
        }
       
       //GUI_Element(String text, int x_Pos, int y_Pos, int color, int textSize);
};

//GUI_Element::GUI_Element(String text, int x_Pos, int y_Pos, int color, int textSize){
    //set(text, x_Pos, y_Pos, color, textSize);
//}


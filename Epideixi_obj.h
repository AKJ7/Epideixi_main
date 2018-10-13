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
           //printf("Width: %d, Height: %d, x1: %d, y1: %d\n", w, h, x1, y1);
        }
       void centerElement(){
//           int16_t x1, y1;
//           uint16_t w, h;
//           tft.getTextBounds(text, x_Pos, y_Pos, &x1, &y1, &w, &h);
           
       }
       //GUI_Element(String text, int x_Pos, int y_Pos, int color, int textSize);
};

//GUI_Element::GUI_Element(String text, int x_Pos, int y_Pos, int color, int textSize){
    //set(text, x_Pos, y_Pos, color, textSize);
//}




class GUI_Object{
    private:
        int x;
        int y;
        int objSize;
        int objColor;
        String objText;
        int background;
        bool changed = true;

    public:
        void set(int x_Pos, int y_Pos, int textSize, int textColor, String text, int backgroundColor);
        void Updated(bool value){ changed = value;}
        bool Get(){ return changed;}
        int displayText(int x_Pos, int y_Pos, String text, int textColor, int textsize);
        void displayRect(int x_Pos = 0, int y_Pos = 0, int width = 0, int height = 0, int squareColor = 0xFFFF);
        GUI_Object(int x_Pos, int y_Pos, int textSize, int textColor, String text, int background);
};
void GUI_Object::set(int x_Pos, int y_Pos, int textSize, int textColor, String text, int backgroundColor){
    x = x_Pos;
    y = y_Pos;
    objSize = textSize;
    objColor = textColor;
    objText = text;
    background = backgroundColor;
}
void GUI_Object::displayRect(int x_Pos, int y_Pos, int width, int height, int squareColor){
    tft.setCursor(x_Pos, y_Pos);
    tft.fillRect(x_Pos, y_Pos, width, height, squareColor);
}
int GUI_Object::displayText(int x_Pos, int y_Pos, String text, int textColor, int textSize){
    if (text == objText){
        Updated(false);
        return 0;
    }
    Updated(true);
    set(x_Pos, y_Pos, textSize, textColor, text, background);
    int16_t x1, y1;
    uint16_t w, h;
    tft.getTextBounds(text, x_Pos, y_Pos, &x1, &y1, &w, &h);
    tft.fillRect(x1, y1, w, h, background);
    tft.setTextColor(textColor);
    tft.setTextSize(textSize);
    tft.setCursor(x_Pos, y_Pos);
    tft.println(text);
}
GUI_Object::GUI_Object(int x_Pos, int y_Pos, int textSize, int textColor, String text, int backgroundColor){
  set(x_Pos, y_Pos, textSize, textColor, text, backgroundColor);
}

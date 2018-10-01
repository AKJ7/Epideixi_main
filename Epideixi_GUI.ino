



//class GUI_Element{
//    
//    private:
//        int x;
//        int y;
//        int objColor;
//        int objSize;
//        String objText;
//        
//    public:
//        void set(int x_Pos, int y_Pos, int color, int textSize, String text){
//          x = x_Pos;
//          y = y_Pos;
//          objColor = color;
//          objSize = textSize;
//        }
//        int getValue2(){
//          return y;
//        }
//        void displayElement(int x_Pos, int y_Pos, int color, int textSize, String text){
//            int16_t x1, y1;
//            uint16_t w, h;
//            tft.getTextBounds(text, x_Pos, y_Pos, &x1, &y1, &w, &h);
//            tft.fillRect(x1, y1, w, h, 0x0000);
//            tft.setTextColor(color);
//            tft.setTextSize(textSize);
//            tft.setCursor(x_Pos, y_Pos);
//            tft.println(text);
//        }
//        GUI_Element(int x_Pos, int y_Pos, int color, int textSize, String text);
//};
//
//GUI_Element::GUI_Element(int x_Pos, int y_Pos, int color, int textSize, String text){
//  //printf("%c\n", *getValue());
//  set(x_Pos, y_Pos, color, textSize, text);
//  
//  displayElement(x_Pos, y_Pos, color, textSize, text);
//}
//
//void homePage(int value1, int value2){
//  GUI_Element HP_time(0, 22, 0xFFFF, 3, String(value1));
//}



















//class GUI_Element{
//    private:
//        int x_Pos = 2;
//        int y_Pos;
//        char objName[20] = "Hallo World";
//        int color;
//        int objSize;
//
//   public:
//       char *getValue(){
//           char *p;
//           p = objName;
//           return p;
//       }
//       void set(uint8_t x, int8_t y, char nameValue, int colorValue, int sizeValue){
//           x_Pos = x;
//           y_Pos = y;
//           objName = nameValue;
//           color = colorValue;
//           objSize = sizeValue;  
//       }
////       void GUI_display(int x, int y, String nameValue, int colorValue, int sizeValue){
////           int16_t x1, y1;
////           uint16_t w, h;
////           tft.getTextBounds(nameValue, x, y, &x1, &y1, &w, &h);
////           tft.fillRect(x1, y1, w, h, 0x0000);
////           tft.setTextColor(colorValue);
////           tft.setTextSize(sizeValue);
////           tft.setCursor(x, y);
////           tft.println(nameValue);
////       }
//       GUI_Element(int x, int y, char nameValue, int colorValue, int sizeValue);
//};
//
//GUI_Element::GUI_Element(int x, int y, char nameValue, int colorValue, int sizeValue){
////  if (nameValue == getValue()){
////    printf("Same values\n");
////  }
//  printf("Value %d\n", getValue());
//  set(x, y, nameValue, colorValue, sizeValue);
//  //GUI_display(x, y, nameValue, colorValue, sizeValue);
//}
//
//String norm(int value){
//  if (value < 10){
//    return "0"+String(value);
//  } else{
//    return String(value);
//  }
//}
//
//void homePage(int var1, int var2){
//  GUI_Element HP_time(40, 100, "Hallo", 0xFFFF, 7);
//  //printf("%s\n", HP_time.getValue().c_str());
//  printf("%d\n", ("alle" == "allse"));
//}










//String norm(int value){
//  if (value < 10){
//    return "0"+(String)value;
//  } else{
//    return (String)value;
//  }
//}
//
//class homePageElement{
//  
//  private:
//    String value;
//    int x;
//    int y;
//    int color;
//    int background;
//    int fontSize;
//    
//  public:
//    void set(String n, int x_Pos, int y_Pos, int color_HEX, int background_HEX, int nSize){
//      value = n;
//      x = x_Pos;
//      y = y_Pos;
//      color = color_HEX;
//      background = background_HEX;
//      fontSize = nSize;
//    }
//    int getValue(){
//      return y;
//    }
//    void displaying(String n, int x_Pos, int y_Pos, int color_HEX, int nSize){
//      int16_t x1, y1;
//      uint16_t w, h;
//      tft.getTextBounds(n, x_Pos, y_Pos, &x1, &y1, &w, &h);
//      tft.fillRect(x1, y1, w, h, 0x0000);
//      tft.setTextColor(color_HEX);
//      tft.setTextSize(nSize);
//      tft.setTextWrap(true);
//      tft.setCursor(x_Pos, y_Pos);
//      tft.println(n);
//    }
//    homePageElement(String n, int x_Pos, int y_Pos, int color_HEX, int background_HEX, int nSize);
//};
//
//homePageElement::homePageElement(String n, int x_Pos, int y_Pos, int color_HEX, int background_HEX, int nSize){
//  printf("%d\n", getValue());
//  //if (homePageElement::getValue() != n){
//    set(n, x_Pos, y_Pos, color_HEX, background_HEX, nSize);
//    displaying(n, x_Pos, y_Pos, color_HEX, nSize);
//  //}
//  //printf("%s\n", homePageElement::getValue().c_str());
//}
//
////class homeIcons{
////  public:
////    uint16_t x;
////    uint16_t y;
////    String value;
////    uint8_t boxSize;
////    uint16_t boxColor;
////
////    void set(uint16_t x_Pos, uint16_t y_Pos, String content, uint8_t bSize, uint16_t bColor){
////      x = x_Pos;
////      y = y_Pos;
////      value = content;
////      boxSize = bSize;
////      bColor = bColor;
////    }
////    void displayBox{
////      int16_t x1, y1;
////      uint16_t w, h;
////      tft.fillRect(x, y, boxSize, boxSize, boxColor);
////      tft.getTextBounds(n, x_Pos, y_Pos, &x1, &y1, &w, &h);
////      tft.fillRect(x1, y1, w, h, 0x0000);
////      tft.setTextColor(color_HEX);
////      tft.setTextSize(nSize);
////      tft.setTextWrap(true);
////      tft.setCursor(x_Pos, y_Pos);
////      tft.println(n);
////      
////    }
////};
//
//void homePage(int argv1, int argv2){
//  homePageElement HP_clock(norm(argv1)+":"+norm(argv2), 40, 10, 0xFC00, 3, 8);
//  //homePageElement HP_temp(norm(roomTemp()), 120, 100, 0xFFFF, 2, 4);
//}

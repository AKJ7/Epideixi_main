GUI_Element deviceName;
GUI_Element loading;
GUI_Object loadingMessage(0, 200, 1, 0xFFFF, "Welcome!", 0x1986); 

void loadingPage(){
  
    deviceName.displayElement("EPIDEIXI", 40, 100, 0xFFFF, 4);
    loadingMessage.displayText(0, 200, "Booting!", 0xFFFF, 1);
    try{
        loadingMessage.displayText(0, 200, "Connecting to "+String(ssid), 0xFFFF, 1);
        if (WiFiManager(ssid, password, 1) != 1){
            throw "Can't connect to the WiFi!";
        }
        loadingMessage.displayText(0, 200, "Connected to: "+String(ssid), 0xFFFF, 1);
        loadingMessage.displayText(0, 200, "Connecting to Google", 0xFFFF, 1);
        HTTP_Redirect(1, 0, 0, 0); // Weather, Calendar, Mail, Radio
        loadingMessage.displayText(0, 200, "Redirecting ... ", 0xFFFF, 1);
        HTTP_Connect();
        loadingMessage.displayText(0, 200, "Connected to Google", 0xFFFF, 1);
        Serial.println(line);
        //loadingMessage.displayText(0, 200, line, 0xFFFF, 1);
        
      
    } catch(const char error[]){
        loadingMessage.displayText(0, 200, error, 0xFFFF, 1);
        printf("Error: %s\n", error);
    }
}


void display_loadingstatus(void){
    try{
        while (true){
          
//            loading.displayElement("Connecting to "+String(ssid), 30, 200, 0x0000, 1, 0xFFFF);
//            
//            WiFi.begin(ssid, password);
//            while (WiFi.status() != WL_CONNECTED){
//                if (counter >= 20000){
//                  loading.displayElement("Connection to WiFi failed", 30, 200, 0x0000, 1, 0xFFFF);
//                  throw 1;
//                  break;
//                }
//                delay(10);
//                counter++;
//            }
//            
//            loading.displayElement("Connected to "+String(ssid), 30, 200, 0x0000, 1, 0xFFFF);
//            delay(500);

            loading.displayElement("Connecting to Google", 30, 200, 0x0000, 1, 0xFFFF);
            if (!client.connect(server, 443)){
                loading.displayElement("Connection to Google failed!", 30, 200, 0x0000, 1, 0xFFFF);
                throw 2;
                break;
            }
            loading.displayElement("Connection to Google sucessful!", 30, 200, 0x0000, 1, 0xFFFF);
            client.println("GET "+URL);
            client.println("Host: script.google.com");
            client.println("Connection: close");
            client.println();

            while (client.connected()){
                line = client.readStringUntil('\n');
                Serial.println(line);
                if (line == "\r") break;
                if (line.indexOf("Location") >= 0){
                    movedURL = line.substring(line.indexOf(":")+2);
                }
            }
            while (client.connected()){
              if (client.available()){
                line = client.readStringUntil('\n');
                Serial.println(line);
              }
            }
            client.stop();

            movedURL.trim();
            Serial.println("New URL: \""+movedURL+"\"");
            if (!client.connect(server, 443)){
                Serial.println("Redirecting failed!");
            }
            Serial.println("Connected!");
            client.println("GET "+movedURL);
            client.println("Host: script.google.com");
            client.println("Connection: close");
            client.println();

            while (client.connected()){
                line = client.readStringUntil('\n');
                Serial.println(line);
                if (line == "\r") break;
            }
            while (client.connected()){
                if (client.available()){
                   line = client.readString();
                   Serial.println(line);
                }
            }
            client.stop();
            if (line == "OK") Serial.println("OK!");
            break;
        }
    } catch (int error){
          switch(error){
              case 1:
                  loading.displayElement("Can't connect to "+String(ssid), 30, 200, 0x0000, 1, 0xFFFF);
                  break;
              default:
                  loading.displayElement("An error occured!", 30, 200, 0x0000, 1, 0xFFFF);    
          }
    }
}



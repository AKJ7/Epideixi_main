void HTTP_Redirect(boolean weather, boolean calendar, boolean mail, boolean radio){
   if (!client.connect(server, 443)){
       throw "Connection to Google failed!";
   }
   client.println("GET "+URL+"?weather="+weather+"&calender="+calendar+"&mail="+mail+"&radio="+radio);
   client.println("Host: script.google.com");
   client.println("Connection: close");
   client.println();

   while (client.connected()){
       line = client.readStringUntil('\n');
       if (line == "\r") break;
       if (line.indexOf("Location") >= 0){
           movedURL = line.substring(line.indexOf(":")+2);
       }
   }
   while (client.connected()){
       if (client.available()){
           line = client.readStringUntil('\n');
       }
   }
   client.stop();
   movedURL.trim();
}

void HTTP_Connect(){
    if (!client.connect(server, 443)){
        throw "Connection to server failed!";  
    }
    client.println("GET "+movedURL);
    client.println("Host: script.google.com");
    client.println("Connection: close");
    client.println();

    while (client.connected()){
        line = client.readStringUntil('\n');
        if (line == "\r") break;  
    }
    while (client.connected()){
        if (client.available()){
            line = client.readString();
        }
    }
    client.stop();
}


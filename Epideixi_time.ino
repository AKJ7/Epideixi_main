int *printLocalTime(){
  
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return 0;
  } else{
    //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
    //printf("Seconds: %d, Minutes: %d, Hours: %d\n", timeinfo.tm_sec, timeinfo.tm_min, timeinfo.tm_hour);
  }
  int *toReturn = new int[3];
  toReturn[0] = timeinfo.tm_sec;
  toReturn[1] = timeinfo.tm_min;
  toReturn[2] = timeinfo.tm_hour;
  return toReturn;
}

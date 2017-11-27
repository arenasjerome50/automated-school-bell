void processSyncMessage(){
  // if time sync available from serial port, update time and return true
  // time message consists of a header and ten ascii digits
  while(Serial.available() >= TIME_MSG_LEN) {
    char c = Serial.read();
    Serial.print("Receiving Time Message --->");
    if(c == TIME_HEADER){
      time_t pctime = 0;
      for(int i = 0; i < TIME_MSG_LEN - 1; i++){
        c = Serial.read();
        if( c >= '0' && c <= '9'){
          pctime = (10 * pctime) + (c - '0'); // convert digits to a number
        }
      }
     setTime(pctime);
     setSchoolAlarms();
    }
  }
}

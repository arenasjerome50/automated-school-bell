
#define TIME_HEADER 'T' // Header tag for serial time sync message

// if time sync available from serial port, update time and return true
// time message consists of a header and ten ascii digits
/*
void processSyncMessage(){
  while(Serial.available() >= TIME_MSG_LEN) { // TODO: redefine the Algorithm
    char c = Serial.read(); // reading serial msg...
    Serial.print("Receiving Time Message --->");
    if(c == TIME_HEADER){ // checking the time header
      time_t pctime = 0;
      for(int i = 0; i < TIME_MSG_LEN - 1; i++){    // reader the buffer and convert to time object....
        c = Serial.read();
        if( c >= '0' && c <= '9'){
          pctime = (10 * pctime) + (c - '0'); // convert digits to a number
        }
      }
     setTime(pctime);
	   RTC.set(pctime);     // sets the time
   }
  }
}
*/

void processSyncMessage() {
  if(Serial.find(TIME_HEADER)) {
    // initialize variables for storing the time and passing it to arduino and RTC
     unsigned long pctime = 0L;
     const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

     disableSchoolAlarms();   // to avoid unexpected triggering of alarms when the time is changed
     
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Recv Time");  // notify user
     
     pctime = Serial.parseInt();  // process the data
     if( pctime < DEFAULT_TIME) { // check the value is a valid time (greater than Jan 1 2013)
       pctime = 0L; // return 0 to indicate that the time is not valid
     }

     RTC.set(pctime);
     setTime(pctime);
     

     enableSchoolAlarms();  // the time is successfully changed, enabling the alarms
  }
}

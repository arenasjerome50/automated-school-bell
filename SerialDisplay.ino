#include "SerialDisplay.h"

/*Implementation for ClockDisplay class.
Global Variable/Object used:
  Arduino Serial Object
*/

void SerialDisplay::begin() {
  timeNotation = "";
}

void SerialDisplay::show() {
  printHour(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(timeNotation);
  Serial.print(" ");
  printMonth(month());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
}

void SerialDisplay::printHour(int hour) {
  if(isAM())
    timeNotation = "AM";
  if(isPM())
    timeNotation = "PM";
    
  if( hour >= 13 && hour <= 23) {
    hour -= 12;
  }
  else if(hour == 0){
    hour = 12;
  }
  Serial.print(hour);
}
    
void SerialDisplay::printDigits(int digits) {
  Serial.print(":");
  if(digits<10) {
    Serial.print('0');
  }
  Serial.print(digits);
}
    
void SerialDisplay::printMonth(int month) {
  switch(month){
  case 1:
    Serial.print("Jan");
    break;
  case 2:
    Serial.print("Feb");
    break;
  case 3:
    Serial.print("Mar");
    break;
  case 4:
    Serial.print("Apr");
    break;
  case 5:
    Serial.print("May");
    break;
  case 6:
    Serial.print("Jun");
    break;
  case 7:
    Serial.print("Jul");
    break;
  case 8:
    Serial.print("Aug");
    break;
  case 9:
    Serial.print("Sep");
    break;
  case 10:
    Serial.print("Oct");
    break;
  case 11:
    Serial.print("Nov");
    break;
  case 12:
    Serial.print("Dec");
    break;
  default:
    break;
  }
}

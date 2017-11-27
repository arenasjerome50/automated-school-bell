#include "ClockDisplay.h"

/*Implementation for ClockDisplay class.
Global Variable/Object used:
  LiquidCrystal Object named "lcd"
*/


void ClockDisplay::begin() {
  timeNotation = "";
}

void ClockDisplay::show() {
  lcd.setCursor(0, 0);
  printHour(hour());
  printDigits(minute());
  printDigits(second());
  lcd.print(" ");
  lcd.print(timeNotation);
  lcd.print("     ");
  lcd.setCursor(0, 1);
  printMonth(month());
  lcd.print(" ");
  printDay(day());
  lcd.print(" ");
  lcd.print(year());
}

void ClockDisplay::printHour(int hour) {
  if (isAM())
    timeNotation = "AM";
  if (isPM())
    timeNotation = "PM";
    
  if ( hour >= 13 && hour <= 23) {
    hour -= 12;
  }
  else if (hour == 0){
    hour = 12;
  }
  if (hour < 10) {
    lcd.print('0');
  }
  lcd.print(hour);
}

void ClockDisplay::printDigits(int digits) {
  lcd.print(":");
  if(digits<10) {
    lcd.print('0');
  }
  lcd.print(digits);
}

void ClockDisplay::printDay(int day) {
  if(day<10) {
    lcd.print('0');
  }
  lcd.print(day);
}

void ClockDisplay::printMonth(int month) {
  switch(month){
    case 1:
      lcd.print("Jan");
      break;
    case 2:
      lcd.print("Feb");
      break;
    case 3:
      lcd.print("Mar");
      break;
    case 4:
      lcd.print("Apr");
      break;
    case 5:
      lcd.print("May");
      break;
    case 6:
      lcd.print("Jun");
      break;
    case 7:
      lcd.print("Jul");
      break;
    case 8:
      lcd.print("Aug");
      break;
    case 9:
      lcd.print("Sep");
      break;
    case 10:
      lcd.print("Oct");
      break;
    case 11:
      lcd.print("Nov");
      break;
    case 12:
      lcd.print("Dec");
      break;
    default:
      break;
  }
}


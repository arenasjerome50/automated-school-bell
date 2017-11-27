void digitalClockDisplay()
{
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

void printHour(int hour)
{
  if(isAM())
    timeNotation = "AM";
  if(isPM())
    timeNotation = "PM";
    
  if( hour >= 13 && hour <= 23)
  {
    hour -= 12;
  }
  else if(hour == 0){
    hour = 12;
  }
  Serial.print(hour);
}

void printDigits(int digits)
{
  Serial.print(":");
  if(digits<10)
    Serial.print('0');
  Serial.print(digits);
}

void printMonth(int month){
  switch(month){
    case 1:
      Serial.print("January");
      break;
    case 2:
      Serial.print("Febuary");
      break;
    case 3:
      Serial.print("March");
      break;
    case 4:
      Serial.print("April");
      break;
    case 5:
      Serial.print("May");
      break;
    case 6:
      Serial.print("June");
      break;
    case 7:
      Serial.print("July");
      break;
    case 8:
      Serial.print("August");
      break;
    case 9:
      Serial.print("September");
      break;
    case 10:
      Serial.print("October");
      break;
    case 11:
      Serial.print("November");
      break;
    case 12:
      Serial.print("December");
      break;
    default:
      break;
  }
}

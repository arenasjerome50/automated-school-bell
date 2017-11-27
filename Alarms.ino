// TODO: define this functions into class

// this function is called if alarms is triggered
void FirstBell(){
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Alarm");
     lcd.setCursor(0, 1);
     lcd.print("Triggered");
     for(int i = 0; i < 3; i ++){
       relayState = !relayState;
       digitalWrite(relayPin, relayState);
       Serial.println("The Alarm has been triggered.");
       Alarm.delay(8000);
       relayState = !relayState;
       digitalWrite(relayPin, relayState);
       Alarm.delay(2000);
     }
     lcd.clear();
}

void SecondBell() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alarm");
  lcd.setCursor(0, 1);
  lcd.print("Triggered");
	for (int i = 0; i < 2; i++) {
    relayState = !relayState;
		digitalWrite(relayPin, relayState);
		Serial.println("The Alarm has been triggered.");
		Alarm.delay(8000);
    relayState = !relayState;
		digitalWrite(relayPin, relayState);
		Alarm.delay(2000);
	}
  lcd.clear();
}

// Hardcoded Alarms
void setSchoolAlarms(){
    int index = 0;
    alarmIds[index++] = Alarm.alarmRepeat(7, 30, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(8, 25, 0, SecondBell);
    alarmIds[index++] = Alarm.alarmRepeat(8, 30, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(9, 25, 0, SecondBell);
    alarmIds[index++] = Alarm.alarmRepeat(9, 30, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(10, 25, 0, SecondBell);
    alarmIds[index++] = Alarm.alarmRepeat(10, 30, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(11, 25, 0, SecondBell);
    alarmIds[index++] = Alarm.alarmRepeat(11, 30, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(13, 00, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(13, 55, 0, SecondBell);
    alarmIds[index++] = Alarm.alarmRepeat(14, 00, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(14, 55, 0, SecondBell);
    alarmIds[index++] = Alarm.alarmRepeat(15, 00, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(15, 55, 0, SecondBell);
    alarmIds[index++] = Alarm.alarmRepeat(16, 00, 0, FirstBell);
    alarmIds[index++] = Alarm.alarmRepeat(16, 55, 0, SecondBell);
    alarmIds[index] = Alarm.alarmRepeat(17, 00, 0, FirstBell);
}

void disableSchoolAlarms() {
  for (int x = 0; x < nbrOfAlarms; x++) {
    Alarm.disable(alarmIds[x]);
  }
}

void enableSchoolAlarms() {
  for (int x = 0; x < nbrOfAlarms; x++) {
    Alarm.enable(alarmIds[x]);
  }
}


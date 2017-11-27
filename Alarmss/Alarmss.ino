
// this function is called if alarms is triggered
void FirstBell(){
     for(int i = 0; i < 3; i ++){
       digitalWrite(relayPin, HIGH);
       Serial.println("The Alarm has been triggered.");
       Alarm.delay(8000);
       digitalWrite(relayPin, LOW);
       Alarm.delay(2000);
     }
}

void SecondBell(){
	for (int i = 0; i < 2; i++){
		digitalWrite(relayPin, HIGH);
		Serial.println("The Alarm has been triggered.");
		Alarm.delay(8000);
		digitalWrite(relayPin, LOW);
		Alarm.delay(2000);
	}
}

void setSchoolAlarms(){
	Alarm.alarmRepeat(7, 30, 0, FirstBell);
	Alarm.alarmRepeat(8, 25, 0, SecondBell);
	Alarm.alarmRepeat(8, 30, 0, FirstBell);
	Alarm.alarmRepeat(9, 25, 0, SecondBell);
	Alarm.alarmRepeat(9, 30, 0, FirstBell);
	Alarm.alarmRepeat(10, 25, 0, SecondBell);
	Alarm.alarmRepeat(10, 30, 0, FirstBell);
	Alarm.alarmRepeat(11, 25, 0, SecondBell);
	Alarm.alarmRepeat(11, 30, 0, FirstBell);
	Alarm.alarmRepeat(13, 00, 0, FirstBell);
	Alarm.alarmRepeat(13, 55, 0, SecondBell);
	Alarm.alarmRepeat(14, 00, 0, FirstBell);
	Alarm.alarmRepeat(14, 55, 0, SecondBell);
	Alarm.alarmRepeat(15, 00, 0, FirstBell);
	Alarm.alarmRepeat(15, 55, 0, SecondBell);
	Alarm.alarmRepeat(16, 00, 0, FirstBell);
	Alarm.alarmRepeat(16, 55, 0, SecondBell);
	Alarm.alarmRepeat(17, 00, 0, FirstBell);
}

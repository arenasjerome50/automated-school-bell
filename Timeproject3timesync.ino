/*
 * Automated School bell Alarm sketch
 * Author: Jerome G. Arenas
 * 
 * This sketch implements displaying time in seven segment displays, sync time using PC via serial port,
 * using real time clock module, monitoring battery of RTC and setting and triggering alarms of all weekdays except sunday
 * You can change the pins to be use in arduino by changing the CLK, SER, and the two arrays of digit pins (minuteDigitPin, hourDigitPin)
 * 
 * 
 */

#include "Time.h"
#include "TimeAlarms.h"
#include "ClockDisplay.h"
#include "SerialDisplay.h"
#include <DS1302RTC.h>
#include <LiquidCrystal.h>
#include <AnalogMultiButton.h>

#define BUTTONS_TOTAL 5

#define BUTTONS_PIN A0

// map the buttons to these constant values
#define BUTTON_RIGHT  0
#define BUTTON_UP     1
#define BUTTON_DOWN   2
#define BUTTON_LEFT   3
#define BUTTON_SELECT 4

// create tmElements_t struct to save time for adjusting
//tmElements_t tempTime;

// set how many buttons you have connected
const int buttonValues[BUTTONS_TOTAL] = {50, 250, 450, 650, 850};

// number of school alarms
const uint8_t nbrOfAlarms = 18;

//Creating Objects
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel
ClockDisplay clockDisplay;        // for handling lcd
SerialDisplay serialDisplay;      // for handling serial
AlarmId alarmIds[nbrOfAlarms];    // for handling schoolAlarms
// Set pins:  CE, IO,CLK
DS1302RTC RTC(12, 11, 3);         // set the pins for RTC
AnalogMultiButton buttons(BUTTONS_PIN, BUTTONS_TOTAL, buttonValues, 500); // sets the buttons to be used.

const uint8_t relayPin = 2;	// relay pin for triggering the Relay of the alarm is activated
const uint8_t ledPin = 13;	// LED to see if the time is running or not
bool relayState = HIGH;

void setup() {
 pinMode(relayPin, OUTPUT);
 digitalWrite(relayPin, relayState);
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
 lcd.begin(16, 2);

 setSyncProvider(RTC.get);
 
 lcd.setCursor(0, 0);
 
 timeStatus_t status = timeStatus();  // get the status

 // TODO: retest this feature do detect the RTC status..
 if(status == timeNotSet) {
    lcd.print("timeNotSet");    // debug status
    Serial.println("Arduino Status: Waiting for time sync...");
    while(true){ // wait for time sync
      if(Serial.available() > 0) {
        processSyncMessage();
        setSchoolAlarms();
        lcd.setCursor(0, 1);
        if (!RTC.haltRTC()) {
          lcd.print("RTC OK!");
          Serial.println("RTC has set the system time");
        } else {
          failedRTCMessage();
        }
        delay(3000);
        break;
      }
    }
 } else if (status == timeNeedsSync) {
    lcd.print("timeNeedsSync");   // debug status
    lcd.setCursor(0, 1);
    failedRTCMessage();
 } else if (status == timeSet) {  // if time is already set and the RTC is ok
    lcd.print("timeSet");   // debug status
    setSchoolAlarms();
    lcd.setCursor(0, 1);
    if (!RTC.haltRTC()) {
      lcd.print("RTC OK!");
      Serial.println("RTC has set the system time");
    } else {
      failedRTCMessage();
    }
    delay(3000);
 }
 
 clockDisplay.begin();
 serialDisplay.begin();
 
 Alarm.alarmRepeat(dowSaturday, 23, 59, 59, disableSchoolAlarms); // trigger problem
 Alarm.alarmRepeat(dowSunday, 23, 59, 59, enableSchoolAlarms);    // please debug those line
 
 lcd.clear();
}

void loop() { 
  Alarm.delay(0);
  buttons.update();
  
  if(Serial.available() > 0) {
    processSyncMessage();
  }
  
  updateInterfaces(); // make it per second call. and implement menu

  if(buttons.isPressed(BUTTON_UP)) {
    adjustTime(1);
    RTC.set(now());
  } else if(buttons.isPressed(BUTTON_DOWN)) {
    adjustTime(-1);
    RTC.set(now());
  }

  //if(buttons.onReleaseAfter(BUTTON_SELECT, 2000)) {
  //  lcd.clear();
  //  updateInterfaces();
  //  lcd.setCursor(14, 0);
  //  lcd.print('E');
  //  while(true) {
  //    buttons.update();
      
      //lcd.setCursor(0,0);
      //if(buttons.isPressed(BUTTON_UP)) {
      //  uint8_t hour = ++tempTime.Hour;
      //  
      //  if ( hour >= 13 && hour <= 23) hour -= 12;
      //  else if (hour == 0) hour = 12;
      //  
      //  if (hour < 10) lcd.print('0');
      //  lcd.print(hour);
      //  delay(500);
      //} else if (buttons.isPressed(BUTTON_DOWN)) {
      //  uint8_t hour = --tempTime.Hour;
      //
      //  if ( hour >= 13 && hour <= 23) hour -= 12;
      //  else if (hour == 0) hour = 12;
      //  
      //  if (hour < 10) lcd.print('0');
      //  lcd.print(hour);
      //  delay(500);
      //}
      
      //if(buttons.onReleaseAfter(BUTTON_SELECT, 2000)) {
      //  lcd.clear();
      //  break;
      //}
    //}
  //}
}

bool ledState = LOW;

void blinkLed() {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
}

// it Delicates output functions
void updateInterfaces() {
    clockDisplay.show();
    serialDisplay.show();
    //blinkLed();
}

void failedRTCMessage() {
    lcd.print("Pls check RTC");
    Serial.println("Unable to sync with the RTC, Please check the RTC battery");
    // while(true); // you do nothing forever. check the RTC!!!
}

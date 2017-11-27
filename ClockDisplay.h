/*
  Abstraction for handling lcd showing the current time
*/

#ifndef CLOCK_DISPLAY_H
#define CLOCK_DISPLAY_H

class ClockDisplay {
  public:
    void begin();
    void show();
  private:
    void printHour(int hour);
    void printDigits(int digits);
    void printMonth(int month);
    void printDay(int day);
    String timeNotation;
};

#endif

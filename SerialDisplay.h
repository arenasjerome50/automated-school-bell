/*
  Abstraction for handling Serial sending streams of current time.
*/

#ifndef SERIAL_DISPLAY_H
#define SERIAL_DISPLAY_H

class SerialDisplay {
  public:
    void begin();
    void show();
  private:
    void printHour(int hour);
    void printDigits(int digits);
    void printMonth(int month);
    String timeNotation;
};

#endif

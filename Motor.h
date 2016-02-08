#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pin, bool isAnalog);
    void activate(int ms);
    void reverseActivate(int ms);
  private:
    int _pin;
    bool _isAnalog;
};

#endif

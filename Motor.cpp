#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int pin, bool isAnalog)
{
  _pin = pin;
  _isAnalog = isAnalog;

  pinMode(pin, OUTPUT);
  if (_isAnalog) {
    analogWrite(pin, 0); 
  } else {
    digitalWrite(pin, HIGH);
  }
}

void Motor::activate(int ms)
{
  if (_isAnalog) {
    for (int i = 0; i < 256; i++)
    {
      analogWrite(_pin, i);
      delay(3);
    }
    delay(ms);
    for (int i = 255; i >= 0; i--)
    {
      analogWrite(_pin, i);
      delay(3);
    }
    analogWrite(_pin, 0);
  } else {
    digitalWrite(_pin, LOW);
    delay(ms);
    digitalWrite(_pin, HIGH);
  }

}

void Motor::reverseActivate(int ms)
{
}


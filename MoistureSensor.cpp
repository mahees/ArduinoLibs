#include "MoistureSensor.h"
#include "Arduino.h"

MoistureSensor::MoistureSensor(int sensorPin, int vccPin)
{
  _sensorPin = sensorPin;
  _vccPin = vccPin;

  pinMode(vccPin, OUTPUT);
  digitalWrite(vccPin, LOW);
}

int MoistureSensor::takeReading()
{
  digitalWrite(_vccPin, HIGH);
  delay(300);

  int sensorValue = analogRead(_sensorPin);

  digitalWrite(_vccPin, LOW);

  return map(sensorValue, 600, 1025, 0, 100);
}

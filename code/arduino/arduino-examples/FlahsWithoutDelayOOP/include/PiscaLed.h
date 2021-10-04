#ifndef PISCALED_H
#define PISCALED_H

#include <Arduino.h>

class PiscaLed
{
  private:
    int _ledPin;
    long _onTime;
    long _offTime;
    int _ledState;
    unsigned long _previousMillis;
    unsigned long _currentMillis;

  public:
    PiscaLed(int pin, long on, long off);
    void Update();
};

PiscaLed::PiscaLed(int pin, long on, long off)
{
    _ledPin = pin;
    pinMode(_ledPin, OUTPUT);

    _onTime = on;
    _offTime = off;

    _ledState = LOW;
    _previousMillis = 0; 
}

void PiscaLed::Update()
{
  _currentMillis = millis();

  if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime))
  {
    _ledState = LOW;
    _previousMillis = _currentMillis;
    digitalWrite(_ledPin, _ledState);
  }
  else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime))
  {
      _ledState = HIGH;
      _previousMillis = _currentMillis;
      digitalWrite(_ledPin, _ledState);
  }
}

#endif
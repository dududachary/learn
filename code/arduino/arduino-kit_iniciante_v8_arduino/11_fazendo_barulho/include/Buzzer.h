#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer
{
  private:
  	int _pin;
  	int _frequencia;
  	unsigned long _tempo_tocando;
  
  public:
  	Buzzer(int pin);
  	void Tocar(int frequencia, unsigned long tempo_tocando);
  	void Parar();
};

Buzzer::Buzzer(int pin)
{
  _pin = pin;
  _frequencia = 2000;
}

void Buzzer::Tocar(int frequencia, unsigned long tempo_tocando)
{
  _frequencia = _frequencia + frequencia;
  _tempo_tocando = tempo_tocando;
  tone(_pin, _frequencia, _tempo_tocando);
}

void Buzzer::Parar()
{
  noTone(_pin);
}

#endif
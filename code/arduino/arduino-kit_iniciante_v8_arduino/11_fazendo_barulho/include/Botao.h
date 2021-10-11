#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h>
#include <Buzzer.h>

class Botao
{
  private:
  	int _pin;
  	bool _estado;
  
  public:
  	Botao(int pin);
  	void VerificaEstado();
  	void AcaoTocar(Buzzer Buzzer_1, int frequencia, int tempo);
};

Botao::Botao(int pin)
{
  _pin = pin;
  _estado = HIGH;
  pinMode(_pin, INPUT_PULLUP);
}

void Botao::VerificaEstado()
{
  _estado = digitalRead(_pin);
  Serial.print("Pino: ");
  Serial.print(_pin);
  Serial.print("Estado: ");
  Serial.println(_estado);
}

void Botao::AcaoTocar(Buzzer Buzzer_1, int frequencia, int tempo)
{
  Botao::VerificaEstado();

  if (_estado == LOW)
  {
    Buzzer_1.Tocar(frequencia, tempo);
  }
  else
  {
    Buzzer_1.Parar();
  }
}

#endif
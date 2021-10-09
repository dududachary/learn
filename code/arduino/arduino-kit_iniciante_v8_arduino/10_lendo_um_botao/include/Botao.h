/*******************************************************************************
* Projeto: Lendo Um Botão Orientado a Objetos
* Arquivo: Botao.cpp
* Autor: Eduardo Schiavo Dachari
* Criado em: 06/10/2021
* Descrição: Algoritmo para Arduíno que controla as ações de um atuador
*            utilizando um pushbutton com resitor em pull-down físico.
*******************************************************************************/

#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h>
#include <Led.h>

class Botao
{
    private:
        int _pin;
        bool _estado;

    public:
        Botao(int pin);
        bool VerificaEstado();
  		void Acao(void (*funcLigar)(), void (*funcDesligar)());
        void AcaoLed(Led Led_1);
};

Botao::Botao(int pin)
{
    _pin = pin;
    _estado = LOW;
    pinMode(_pin, INPUT);
}

bool Botao::VerificaEstado()
{
    _estado = digitalRead(_pin);

    return _estado;
}

void Botao::Acao(void (*funcLigar)(), void (*funcDesligar)())
{
  _estado = Botao::VerificaEstado();
  
  if (_estado == HIGH)
  {
      (*funcLigar)();
  }
  else
  {
      (*funcDesligar)();
  }
}

void Botao::AcaoLed(Led Led_1)
{
  _estado = Botao::VerificaEstado();

  if (_estado == HIGH)
  {
      Led_1.Ligar();
  }
  else
  {
      Led_1.Desligar();
  }
}

#endif
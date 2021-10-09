/*******************************************************************************
* Projeto: Lendo Um Botão Orientado a Objetos
* Arquivo: Led.h
* Autor: Eduardo Schiavo Dachari
* Criado em: 06/10/2021
* Descrição: Algoritmo para Arduíno que controla as ações de um atuador
*            utilizando um pushbutton com resitor em pull-down físico.
*******************************************************************************/

#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
    private:
        int _pin;
        bool _estado;

    public:
        Led(int pin);
        void Ligar();
        void Desligar();
};

Led::Led(int pin)
{
    _pin = pin;
    _estado = LOW;
    pinMode(_pin, OUTPUT);

}

void Led::Ligar()
{
    _estado = HIGH;
    digitalWrite(_pin, _estado);
}

void Led::Desligar()
{
    _estado = LOW;
    digitalWrite(_pin, _estado);
}

#endif
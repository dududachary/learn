#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h>

class Botao
{
    private:
        int _pin;
        bool _estado;

    public:
        Botao(int pin);
        bool VerificaEstado();
};

Botao::Botao(int pin)
{
    _pin = pin;
    _estado = LOW;
    pinMode(_pin, INPUT);
}

bool Botao::VerificaEstado()
{
    _estado = analogRead(_pin);

    return _estado;
}

#endif
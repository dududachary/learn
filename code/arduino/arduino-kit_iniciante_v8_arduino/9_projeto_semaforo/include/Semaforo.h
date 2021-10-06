/***************************************************************************
 * File: Semaforo.h
 * Description: Sample class for a Semaforo object.
 * Created on: 06/10/2021
 * Created By: Eduardo Schiavo Dachary
 * ************************************************************************/

#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <Arduino.h>
 
class Semaforo
{
  private:
  	int _pino_vermelho;
  	int _pino_amarelo;
  	int _pino_verde;
    int _n_piscadas;
  	bool _estado_vermelho;
  	bool _estado_amarelo;
  	bool _estado_verde;
  	unsigned long _current_millis;
  	unsigned long _previous_millis;
  	unsigned long _tempo_desejado;
  
  public:
  	Semaforo(int pino_vermelho, int pino_amarelo, int pino_verde);
  	void IniciarCiclo();
  	void SinalVermelho(unsigned long tempo_desejado);
  	void SinalAmarelo(unsigned long tempo_desejado);
  	void SinalVerde(unsigned long tempo_desejado);
    void VermelhoPiscante(int n_piscadas);
};

Semaforo::Semaforo(int pino_vermelho, int pino_amarelo, int pino_verde)
{
  _pino_vermelho = pino_vermelho;
  _pino_amarelo = pino_amarelo;
  _pino_verde = pino_verde;
  
  pinMode(_pino_vermelho, OUTPUT);
  pinMode(_pino_amarelo, OUTPUT);
  pinMode(_pino_verde, OUTPUT);  
}

void Semaforo::IniciarCiclo()
{
  _estado_vermelho = LOW;
  _estado_amarelo = LOW;
  _estado_verde = LOW;
}

void Semaforo::SinalVermelho(unsigned long tempo_desejado)
{
  _current_millis = millis();
  _tempo_desejado = tempo_desejado;
  _estado_amarelo = digitalRead(_pino_amarelo);
  _estado_verde = digitalRead(_pino_verde);
  
  if (((_estado_amarelo == LOW) && (_estado_verde == LOW)) && (_current_millis - _previous_millis <= _tempo_desejado))
  {
    _estado_vermelho = HIGH;
    digitalWrite(_pino_vermelho, _estado_vermelho);    
  }
  else if (((_estado_amarelo == LOW) && (_estado_verde == LOW)) && (_current_millis - _previous_millis > _tempo_desejado))
  {
    _estado_vermelho = LOW;
    digitalWrite(_pino_vermelho, _estado_vermelho);
    _previous_millis = _current_millis;
  }
}

void Semaforo::SinalAmarelo(unsigned long tempo_desejado)
{
  _current_millis = millis();
  _tempo_desejado = tempo_desejado;
  _estado_vermelho = digitalRead(_pino_vermelho);
  _estado_verde = digitalRead(_pino_verde);
  
  if ((_estado_vermelho == LOW) && (_estado_verde == LOW) && (_current_millis - _previous_millis <= _tempo_desejado))
  {
    _estado_amarelo = HIGH;
    digitalWrite(_pino_amarelo, _estado_amarelo);
  }
  else if ((_estado_vermelho == LOW) && (_estado_verde == LOW) && (_current_millis - _previous_millis > _tempo_desejado))
  {
    _estado_amarelo = LOW;
    digitalWrite(_pino_amarelo, _estado_amarelo);
    _previous_millis = _current_millis;
  }
}

void Semaforo::SinalVerde(unsigned long tempo_desejado)
{
  _current_millis = millis();
  _tempo_desejado = tempo_desejado;
  _estado_amarelo = digitalRead(_pino_amarelo);
  _estado_vermelho = digitalRead(_pino_vermelho);
  
  if ((_estado_amarelo == LOW) && (_estado_vermelho == LOW) && (_current_millis - _previous_millis <= _tempo_desejado))
  {
    _estado_verde = HIGH;
    digitalWrite(_pino_verde, _estado_verde);
  }
  else if ((_estado_amarelo == LOW) && (_estado_vermelho == LOW) && (_current_millis - _previous_millis > _tempo_desejado))
  {
    _estado_verde = LOW;
    digitalWrite(_pino_verde, _estado_verde);
    _previous_millis = _current_millis;
  }
}

void Semaforo::VermelhoPiscante(int n_piscadas)
{
  _n_piscadas = n_piscadas;
  unsigned long tempo = millis();
  unsigned long tempo_decorrido = 0;

  for (int i = 0; i < n_piscadas; i++)
  {
    if ((tempo - tempo_decorrido <= 500) && digitalRead(_pino_vermelho) == LOW)
    {
      digitalWrite(_pino_vermelho, HIGH);
      tempo_decorrido = tempo;
    }
    else if ((tempo - tempo_decorrido <= 500) && digitalRead(_pino_vermelho) == HIGH)
    {
      digitalWrite(_pino_vermelho, LOW);
      tempo_decorrido = tempo;
    }
    
    
  }
}

#endif
/*******************************************************************************
* Autor: Eduardo Schiavo Dachari
* Criado em: 06/10/2021
* Descrição: Algoritmo para Arduíno que controla as ações de um atuador
*            utilizando um pushbutton com resitor em pull-down físico.
*******************************************************************************/

#include <Arduino.h>
#include <Led.h>
#include <Botao.h>

Led Led_1(12);
Botao Botao_1(9);

void setup() {}

void loop() {

  if (Botao_1.VerificaEstado() == HIGH) 
  {
    Led_1.Ligar();
  } 
  else
  {
    Led_1.Desligar();
  }
}
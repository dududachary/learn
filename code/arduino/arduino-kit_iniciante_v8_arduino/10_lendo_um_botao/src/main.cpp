/*******************************************************************************
* Projeto: Lendo Um Botão Orientado a Objetos
* Arquivo: main.cpp
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

// void ligarLed();
// void desligarLed();

void setup(){}

void loop()
{  // Passando os argumentos como funcao
  //Botao_1.Acao(ligarLed, desligarLed);

  // Passando os argumentos como método
  Botao_1.AcaoLed(Led_1);
}

// void ligarLed()
// {
//   Led_1.Ligar();
// }

// void desligarLed()
// {
//   Led_1.Desligar();
// }
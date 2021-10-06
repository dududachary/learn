/***************************************************************************
 * File: main.cpp
 * Description: Lesson 8 Flashing a Led
 * Created on: 06/10/2021
 * Created By: Eduardo Schiavo Dachary
 * ************************************************************************/

#include <Arduino.h>

// Definicção dos pinos
const int led = 13;

void setup() {
  // Definição das funções dos pinos
  pinMode(led, OUTPUT);
}

void loop() {
  // Informa ao led que o nivel lógico tem que ser o contrário do atual
  digitalWrite(led, !digitalRead(led));

  // Temp de atraso
  delay(500);
}
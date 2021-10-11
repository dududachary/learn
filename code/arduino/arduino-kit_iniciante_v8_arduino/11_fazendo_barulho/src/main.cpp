#include <Arduino.h>
#include <Buzzer.h>
#include <Botao.h>

Buzzer Buzzer_1(10);
Botao Botao_Aumentar(11);
Botao Botao_Diminuir(9);

void setup(){
  Serial.begin(9600);
}

void loop(){
	Botao_Aumentar.AcaoTocar(Buzzer_1, 1000, 2000);
  Botao_Diminuir.AcaoTocar(Buzzer_1, -1000, 2000);
}
#include <Arduino.h>

// Definicao dos pinos
const int trig = 3;
const int echo = 2;

// Distancia maxima estipulada de um obstaculo (apenas um exemplo)
const int distancia_obstaculo = 20;

int sensorMorcego(int trig, int echo);

void setup() {
  Serial.begin(9600);

  // Pino que envia o som
  pinMode(trig, OUTPUT);

  // Pino que recebe o som
  pinMode(echo, INPUT);
}

void loop() {
  int distancia = sensorMorcego(trig, echo);

  if (distancia < distancia_obstaculo)
  {
    Serial.print("Alerta de obstáculo: ");
    Serial.print(distancia);
    Serial.println("cm"); 
  }
  else
  {
    Serial.print("Sem obstáculo: ");
    Serial.print(distancia);
    Serial.println("cm");
  }
   delay(100);
}

int sensorMorcego(int pinoTrig, int pinoEcho)
{
  // 10 e 2 microsegundos são definidos no datasheet do componente
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Coleta a duracao do pulso, quanto tempo em nivel lógico alto, do pinoEcho e divide por 58 (para centimetros)
  return pulseIn(pinoEcho, HIGH)/58;
}
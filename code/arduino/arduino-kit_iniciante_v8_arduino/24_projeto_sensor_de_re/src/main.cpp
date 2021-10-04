#include <Arduino.h>

// Definição dos pinos
const int trig = 3, echo = 2, buzzer = 7;

unsigned int intervalo, distancia;

// Declaração de funções
int sensorUltrassonico(int trig, int echo);

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  distancia = sensorUltrassonico(trig, echo);
  Serial.println(distancia);
}

int sensorUltrassonico(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  if (distancia < 10)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    tone(buzzer, 1750);
  }
  else if (distancia > 60)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    noTone(buzzer);
  }
  else
  {
    if (distancia <= 20)
    {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    intervalo = 100;
    }
    else if (distancia <= 30)
    {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      intervalo = 150;
    }
    else if (distancia <= 40)
    {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      intervalo = 200;
    }
    else if (distancia <=50)
    {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      intervalo = 250;
    }
    else if (distancia <= 60)
    {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      intervalo = 300;
    }
    tone(buzzer, 1750);
    delay(intervalo);
    noTone(buzzer);
    delay(intervalo);
  }  

  // Verifica o tempo de echo em nivel logico alto e divide por 58 para ter as escalas corretas
  return pulseIn(echo, HIGH)/58;
}
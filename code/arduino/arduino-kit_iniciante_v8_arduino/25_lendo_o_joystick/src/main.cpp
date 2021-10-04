#include <Arduino.h>

// Definição dos pinos
int const vrx = A4;
int const vry = A5;
int const sw = 2;

// Armazenamento das leituras
int leitura_btn = 0, leitura_vrx, leitura_vry;

void setup() {
  Serial.begin(9600);
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  leitura_vrx = analogRead(vrx);
  leitura_vry = analogRead(vry);
  leitura_btn = digitalRead(sw);

  Serial.print("Leitura VRX: ");
  Serial.print("\t");
  Serial.print(leitura_vrx);
  Serial.print("\t");
  Serial.print("Leitura VRY: ");
  Serial.print("\t");
  Serial.print(leitura_vry);
  Serial.print("\t");
  Serial.print("Leitura SW: ");
  Serial.print("\t");
  Serial.println(leitura_btn);

  delay(10);
}
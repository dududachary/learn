#include <Arduino.h>
#include <Servo.h>

const int potenciometro = A5;
int leitura_potenciometro, angulo;

// Cria o objeto servo_motor
Servo servo_motor;

void setup() {
  // Informa qual o pino para o objeto servo motor
  servo_motor.attach(9);
  
  // Informa ao servo que deverá se posicionar em 10 graus
  servo_motor.write(10);

  // Define a função do pino do potenciometro
  pinMode(potenciometro, INPUT);
}

void loop() {
  // Faz a leitura do potenciometro
  leitura_potenciometro = analogRead(potenciometro);

  // Define o angulo de acordo com a leitura do potenciometro
  angulo = map(leitura_potenciometro, 0, 1023, 10, 170);

  // Informa ao servo o angulo para o qual ele deve se mover;
  servo_motor.write(angulo);

  delay(100);
}
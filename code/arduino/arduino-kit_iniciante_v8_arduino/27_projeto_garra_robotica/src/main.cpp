#include <Arduino.h>
#include <Servo.h>

// Definição dos pinos
const int vrx = A5;
const int vry = A4;
const int sw = 2;
const int garra = 9;

// Define os limites de abertura e fechamento da garra
const int angle_close = 170;
const int angle_open = 90;

// Variaveis para armazenar as leituras
int leitura_vrx, leitura_vry, leitura_sw;

// Variável de referência
int pos_atual = 520;

// Variáveis de sentido
boolean open = 0, close = 0;

// Cria o objeto servo_motor
Servo servo_motor;

void setup() {
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(sw, INPUT_PULLUP);
  servo_motor.attach(garra);
}

void loop() {

  // Efetua as leituras dos pinos do joystick
  leitura_vrx = analogRead(vrx);
  leitura_vry = analogRead(vry);
  leitura_sw = digitalRead(sw);

  // Converte os valores do vrx para o intervalo de ângulos corretos
  leitura_vrx = map(leitura_vrx, 0, 1023, angle_close, angle_open);

  // Aciona o servo motor movimentando a garra para o ângulo definido no vrx
  servo_motor.write(leitura_vrx);
  delay(10);

  if (leitura_vry >= 550)
  {
    // Seta a flag caso o movimento do joystick indicar uma tendencia de abertura
    open = 1;
  }
  else if (leitura_vry < 490)
  {
    // Seta a flag caso o movimento do joystick indicar uma tendencia de fechamento
    close = 1;
  }
  
  while (open == 1)
  {
    leitura_vry = analogRead(vry);
    leitura_sw = digitalRead(sw);

    // Verifica a posição do botão
    if (leitura_sw == HIGH)
    {
      // Verifica a posição da garra
      if (leitura_vry > pos_atual)
      {
        pos_atual = leitura_vry;
        leitura_vry = map(leitura_vry, 0, 1023, angle_close, angle_open);
        servo_motor.write(leitura_vry);
      }
    }
    else
    {
      open = 0;
      pos_atual = 520;
    }    
  }

  while (close == 1)
  {
    leitura_vry = analogRead(vry);
    leitura_sw = digitalRead(sw);

    // Verifica a posição do botão
    if (leitura_sw == HIGH)
    {
      // Verifica a posição da garra
      if (leitura_vry > pos_atual)
      {
        pos_atual = leitura_vry;
        leitura_vry = map(leitura_vry, 0, 1023, angle_close, angle_open);
        servo_motor.write(leitura_vry);
      }
    }
    else
    {
      close = 0;
      pos_atual = 520;
    }
  }  
}
#include <Arduino.h>
#include <Semaforo.h>

Semaforo Semaforo_Veiculos(13, 12, 11);
Semaforo Semaforo_Pedestres(10, 8, 9);

void setup(){}

void loop()
{
  Semaforo_Veiculos.IniciarCiclo();
  Semaforo_Veiculos.SinalVerde(2000);
  Semaforo_Veiculos.SinalAmarelo(1000);
  Semaforo_Veiculos.SinalVermelho(3000);

  Semaforo_Pedestres.SinalVermelho(3000);
  Semaforo_Pedestres.SinalVerde(3000);
}
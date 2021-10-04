#include <Arduino.h>
#include <PiscaLed.h>

PiscaLed led1(12, 200, 800);
PiscaLed led2(13, 100, 400);

void setup() {}

void loop() {
  led1.Update();
  led2.Update();
}

#include "funciones.h"

void setup() {
  initCom();
  initSensors();
}

void loop() {
  printData();
  delay(DELAY);  // Tiempo entre lecturas
}
#include "funciones.h"

#define DIR_ESCLAVO 0x08
#define CANTIDAD_BYTES 32

void setup() {
  Serial.begin(BAUDRATE);
  iniciarComunicacionI2C();
}

void loop() {
  procesarLecturaFiltrada(DIR_ESCLAVO, CANTIDAD_BYTES);
  delay(500);  // Intervalo entre solicitudes
}
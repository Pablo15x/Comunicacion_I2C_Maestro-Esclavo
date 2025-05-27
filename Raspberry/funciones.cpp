#include "funciones.h"
#include <Wire.h>

#define WINDOW_SIZE 5
int distWindow[WINDOW_SIZE] = {0};
int indexFiltro = 0;
bool ventanaLlena = false;

void iniciarComunicacionI2C() {
  Wire.begin();  // SDA = 21, SCL = 22 por defecto en ESP32
}

String leerDesdeEsclavoI2C(uint8_t direccion, uint8_t cantidad) {
  String datos = "";
  Wire.requestFrom(direccion, cantidad);
  while (Wire.available()) {
    char c = Wire.read();
    if (isPrintable(c)) datos += c;
  }
  return datos;
}

void procesarLecturaFiltrada(uint8_t direccion, uint8_t cantidad) {
  String datos = leerDesdeEsclavoI2C(direccion, cantidad);
  int dist = datos.toInt();

  distWindow[indexFiltro] = dist;
  indexFiltro++;
  if (indexFiltro >= WINDOW_SIZE) {
    indexFiltro = 0;
    ventanaLlena = true;
  }

  int promedio = 0;
  int n = ventanaLlena ? WINDOW_SIZE : indexFiltro;
  for (int i = 0; i < n; i++) {
    promedio += distWindow[i];
  }
  promedio /= n;

  Serial.print("Distancia filtrada: ");
  Serial.print(promedio);
  Serial.println("cm");
}

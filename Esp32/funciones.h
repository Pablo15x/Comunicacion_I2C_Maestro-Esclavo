#ifndef I2CMASTER_H
#define I2CMASTER_H

#include <Arduino.h>
#define BAUDRATE  9600

void iniciarComunicacionI2C();
String leerDesdeEsclavoI2C(uint8_t direccion, uint8_t cantidad);
void procesarLecturaFiltrada(uint8_t direccion, uint8_t cantidad);

#endif
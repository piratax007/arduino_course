/*********************************************************
 * 2018 V1.0 Mg. Fausto Mauricio Lagos Suárez * GPPL V3.0
 * 
 * Este sketch es un ejemplo de programación para un 
 * cubo de leds 4X4X4 del curso de introducción a Arduino
 * disponible en 
 * https://github.com/piratax007/arduino_course
*********************************************************/

/*
  Cátodos (Columnas)
  (1, 1) - D0 | (2, 1) - D4 | (3, 1) - D8 | (4, 1) - D12
  (1, 2) - D1 | (2, 2) - D5 | (3, 2) - D9 | (4, 2) - D13
  (1, 3) - D2 | (2, 3) - D6 | (3, 3) - D10 | (4, 3) - A4
  (1, 4) - D3 | (2, 4) - D7 | (3, 4) - D11 | (4, 4) - A5
  Cátodo_(X, Y) = 1 columna apagada
  Cátodo_(X, Y) = 0 columna encendida
  ---------------
  Ánodos (Capas)
  1 - PA0 | 2 - PA2 | 3 - PA2 | 4 - PA3
  Ánodo_X = 0 toda la capa estará apagada
*/

int cathodes[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A4, A5};
int anodes[4] = {A0, A1, A2, A3};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(anodes[i], OUTPUT);
  }
  for (int i = 0; i < 16; i++) {
    pinMode(cathodes[i], OUTPUT);
  }
  allOff();
}

void loop() {
  columns();
  allOff();
  delay(1000);
  axes();
  allOff();
  delay(1000);
  spiralInOut();
  allOff();
  delay(1000);
}

// Activa todas las capas
void allAnodesOn() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(anodes[i], 1);
  }
}

// Desactiva todas las capas
void allAnodesOff() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(anodes[i], 0);
  }
}

// Activa todas las columnas
void allCathodesOn() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(cathodes[i], 0);
  }
}

// Desactiva todas las columnas
void allCathodesOff() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(cathodes[i], 1);
  }
}

// Desactiva todo el cubo
void allOff() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(cathodes[i], 1);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(anodes[i], 0);
  }
}

// Enciende las columnas en espiral desde el centro hacia afuera
void spiralInOut() {
  allAnodesOn();
  delay(500);
  digitalWrite(cathodes[9], 0);
  delay(500);
  digitalWrite(cathodes[10], 0);
  delay(500);
  digitalWrite(cathodes[6], 0);
  delay(500);
  digitalWrite(cathodes[5], 0);
  delay(500);
  digitalWrite(cathodes[4], 0);
  delay(500);
  digitalWrite(cathodes[0], 0);
  delay(500);
  digitalWrite(cathodes[1], 0);
  delay(500);
  digitalWrite(cathodes[2], 0);
  delay(500);
  digitalWrite(cathodes[3], 0);
  delay(500);
  digitalWrite(cathodes[7], 0);
  delay(500);
  digitalWrite(cathodes[11], 0);
  delay(500);
  digitalWrite(cathodes[15], 0);
  delay(500);
  digitalWrite(cathodes[14], 0);
  delay(500);
  digitalWrite(cathodes[13], 0);
  delay(500);
  digitalWrite(cathodes[12], 0);
  delay(500);
  digitalWrite(cathodes[8], 0);
  delay(500);
}

// Enciende y apaga las columnas una a una
void columns() {
  allAnodesOn();

  for (int i = 0; i < 4; i++) {
    digitalWrite(cathodes[i], 0);
    delay(500);
    digitalWrite(cathodes[i], 1);
    digitalWrite(cathodes[i + 4], 0);
    delay(500);
    digitalWrite(cathodes[i + 4], 1);
    digitalWrite(cathodes[i + 8], 0);
    delay(500);
    digitalWrite(cathodes[i + 8], 1);
    digitalWrite(cathodes[i + 12], 0);
    delay(500);
    digitalWrite(cathodes[i + 12], 1);
  }
}

// Enciende y recorre las caras del cubo en los ejes X, Y y Z
void axes() {
  allAnodesOn();

  for (int i = 0; i < 13; i += 4) {
    digitalWrite(cathodes[i], 0);
    digitalWrite(cathodes[i + 1], 0);
    digitalWrite(cathodes[i + 2], 0);
    digitalWrite(cathodes[i + 3], 0);
    delay(500);
    allCathodesOff();
  }

  delay(1000);

  for (int i = 0; i < 4; i++) {
    digitalWrite(cathodes[i], 0);
    digitalWrite(cathodes[i + 4], 0);
    digitalWrite(cathodes[i + 8], 0);
    digitalWrite(cathodes[i + 12], 0);
    delay(500);
    allCathodesOff();
  }

  delay(1000);

  for (int i = 0; i < 4; i++) {
    allOff();
    digitalWrite(anodes[i], 1);
    allCathodesOn();
    delay(500);
  }
}


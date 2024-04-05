#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;
byte counter = 0;
const byte LED_MATRIX_ROW_SIZE = 8;
const byte LED_MATRIX_COL_SIZE = 12;
byte frame[LED_MATRIX_ROW_SIZE][LED_MATRIX_COL_SIZE];


void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  Serial.print(counter);
  Serial.print("\t");
  Serial.println(counter, BIN);
  matrixUpdate(counter);
  counter += 1;
  delay(300);
}

void matrixUpdate(byte counter) {
  for (int i = 0; i < LED_MATRIX_ROW_SIZE; i += 1) {
    for (int j = 0; j < 12; j += 1) {
      frame[LED_MATRIX_ROW_SIZE -1 -i][j] = bitRead(counter, i);
    }
  }
  matrix.renderBitmap(frame, LED_MATRIX_ROW_SIZE, LED_MATRIX_COL_SIZE);
}

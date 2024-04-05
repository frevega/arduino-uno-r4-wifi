#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

byte frame[8][12] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int currentRow = 0;
int currentColumn = 0;
byte delayTime = 0;

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  matrixUpdate(true, 25);
  matrixUpdate(false, 25);
}

void matrixUpdate(bool on, byte delayTime1) {
  for (currentRow = 0; currentRow < 8; currentRow += 1) {
    for (currentColumn = 0; currentColumn < 12; currentColumn += 1) {
    // for (currentRow = 0; currentRow < 8; currentRow += 1) {
      frame[currentRow][currentColumn] = on == true ? 1 : 0;
      matrix.renderBitmap(frame, 8, 12);
      delay(delayTime);
    }
    delayTime = delayTime + 5;
    Serial.println(delayTime);
  }
}

#include  "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  matrix.begin();
}

void loop() {
  matrix.beginDraw();
  matrix.textScrollSpeed(75);
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 255, 0, 0);
  matrix.println("  HOLA MIGUEL!  ");
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
}

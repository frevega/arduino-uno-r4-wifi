#include <Arduino.h>

/*
  Slope (m) equation
    x, y     x, y
   (0, 0)  (1023, 5)
  m =  (y2 - y1)
        ---------
        (x2 - x1)
  m = (5 - 0) / (1023 - 0)
  m = 5 / 1023

  Equation of the line
  y - y1 = m (x - x1)
  y - 0 = 5 / 1023 (x - 0)
  y - 0 = 5 / 1023 x
  y = 5 / 1023 * x
  x = analog read
*/

int potPin = A2;
int potVal = 0;

void setup() {
  pinMode(potPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.println("POT: " + String(potVal) + " \tVOLT: " + String(5 / 1023. * potVal));
  delay(100);
}
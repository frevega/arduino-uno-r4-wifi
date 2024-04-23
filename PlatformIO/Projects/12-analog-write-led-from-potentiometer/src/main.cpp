#include <Arduino.h>

/*
  Slope (m) equation
    x, y     x, y
   (0, 0)  (1023, 255)
  m =  (y2 - y1)
        ---------
        (x2 - x1)
  m = (255 - 0) / (1023 - 0)
  m = 255 / 1023

  Equation of the line
  y - y1 = m (x - x1)
  y - 0 = 255 / 1023 (x - 0)
  y - 0 = 255 / 1023 x
  y = 255 / 1023. * x
  x = analog read
*/

int potPin = A2;
int potVal = 0;
int ledPin = 2;
int ledVal = 0;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  potVal = analogRead(potPin);
  ledVal = 255 / 1023. * potVal;
  analogWrite(ledPin, ledVal);
  Serial.println("POT: " + String(potVal) + " \tLED: " + String(ledVal));
  delay(10);
}
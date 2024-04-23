#include <Arduino.h>

const int LEDS[] = {9, 10, 11, 12};
const int LED_SIZE = sizeof(LEDS) / sizeof(int);

void setup() {
  for (int i = 0; i < sizeof(LEDS) / sizeof(int); i += 1) {
    pinMode(LEDS[i], OUTPUT);
  }
  // Serial.begin(9600);
}

void _loop() {
  for (int i = 0; i < sizeof(LEDS) / sizeof(int); i += 1) {
    digitalWrite(LEDS[i], digitalRead(LEDS[i]) == HIGH ? LOW : HIGH);
  }
  delay(500);
}

void loop() {
  for (int i = LED_SIZE -1; i >= 0; i -= 1) {
    // Serial.println("Loop " + String(i));
    digitalWrite(LEDS[i], digitalRead(LEDS[i]) == HIGH ? LOW : HIGH);
    delay(50);
  }
}

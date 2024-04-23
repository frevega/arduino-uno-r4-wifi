#include <Arduino.h>

const byte RED_LED_PIN = 9;
const byte GREEN_LED_PIN = 10;

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void blink(int led, int blinkTimes, int delayTime);

void loop() {
  blink(GREEN_LED_PIN, 5, 200);
  blink(RED_LED_PIN, 10, 500);
}

void blink(int led, int blinkTimes, int delayTime) {
  blinkTimes *= 2;
  for (int i = 0; i < blinkTimes; i += 1) {
    digitalWrite(led, !digitalRead(led));
    delay(delayTime);
  }
}
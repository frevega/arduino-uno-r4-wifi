#include <Arduino.h>

const byte RED_LED_PIN = 9;

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void blink(int led, int blinkTimes, int delayTime);

void loop() {
  blink(RED_LED_PIN, 1, 1000);
}

void blink(int led, int blinkTimes, int delayTime) {
  blinkTimes *= 2;
  for (int i = 0; i < blinkTimes; i += 1) {
    digitalWrite(led, !digitalRead(led));
    Serial.println(digitalRead(led) == HIGH ? "LED is ON" : "LED is OFF");
    delay(delayTime);
  }
}
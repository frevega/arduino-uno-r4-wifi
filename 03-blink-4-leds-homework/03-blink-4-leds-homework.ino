const int LEDS[] = {9, 10, 11, 12};

void setup() {
  for (int i = 0; i < sizeof(LEDS) / sizeof(int); i += 1) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < sizeof(LEDS) / sizeof(int); i += 1) {
    digitalWrite(LEDS[i], digitalRead(LEDS[i]) == HIGH ? LOW : HIGH);
  }
  delay(500);
}

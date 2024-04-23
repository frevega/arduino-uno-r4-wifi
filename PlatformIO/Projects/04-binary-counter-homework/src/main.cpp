#include <Arduino.h>
#include "Arduino_LED_Matrix.h"

// External LED
const byte LED_ARRAY_SIZE = 4;
int leds[LED_ARRAY_SIZE] = { 12, 11, 10, 9 };
byte externalLedCounter = 0;
long externalCounterMillisDiff[] = { 300, 0, 0 };

// LED Matrix
ArduinoLEDMatrix matrix;
byte internalLedCounter = 0;
const byte LED_MATRIX_ROW_SIZE = 8;
const byte LED_MATRIX_COL_SIZE = 12;
byte frame[LED_MATRIX_ROW_SIZE][LED_MATRIX_COL_SIZE];
long internalCounterMillisDiff[] = { 150, 0, 0 };

// Functions declarations
void externalBinaryCounter();
void internalBinaryCounter();
void printBinaryCounters();

void setup() {
  for (int i = 0; i < LED_ARRAY_SIZE; i += 1) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  externalBinaryCounter();
  internalBinaryCounter();
}

void externalBinaryCounter() {
  externalCounterMillisDiff[1] = millis();
  if (externalCounterMillisDiff[1] - externalCounterMillisDiff[2] > externalCounterMillisDiff[0]) {
    externalCounterMillisDiff[2] = externalCounterMillisDiff[1];

    for (int i = 0; i < LED_ARRAY_SIZE; i += 1) {
      digitalWrite(leds[i], bitRead(externalLedCounter, i));
    }
    externalLedCounter = externalLedCounter == 15 ? 0 : externalLedCounter += 1;
  }
}

void internalBinaryCounter() {
  internalCounterMillisDiff[1] = millis();
  if (internalCounterMillisDiff[1] - internalCounterMillisDiff[2] > internalCounterMillisDiff[0]) {
    internalCounterMillisDiff[2] = internalCounterMillisDiff[1];
    printBinaryCounters();

    for (int i = 0; i < LED_MATRIX_ROW_SIZE; i += 1) {
      for (int j = 0; j < LED_MATRIX_COL_SIZE; j += 1) {
        frame[LED_MATRIX_ROW_SIZE - 1 - i][j] = bitRead(internalLedCounter, i);
      }
    }
    matrix.renderBitmap(frame, LED_MATRIX_ROW_SIZE, LED_MATRIX_COL_SIZE);
    internalLedCounter += 1;
  }
}

void printBinaryCounters() {
  // Format required by Teleplot
  Serial.print(">LED:");
  Serial.println(externalLedCounter);
  Serial.print(">MATRIX:");
  Serial.println(internalLedCounter);
  Serial.println(">LED BIN:" + String(externalLedCounter, BIN) + "|t\n>MATRIX BIN:" + String(internalLedCounter, BIN) + "|t");
}

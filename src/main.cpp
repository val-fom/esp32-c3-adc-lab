#include <Arduino.h>

constexpr int ADC_PIN = 0;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(ADC_PIN, ADC_11db);
}

void loop() {
  int raw = analogRead(ADC_PIN);
  uint32_t millivolts = analogReadMilliVolts(ADC_PIN);

  Serial.printf("ADC: %d | Voltage: %u mV\n", raw, millivolts);

  delay(500);
}
